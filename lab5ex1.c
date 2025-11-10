#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { //cyclist diye bir veri tipi oluşturduk burada.
    char name[30];
    int id;
    int laps;
    float *times; //times dümdüz bir sayı değil de arraya pointlesin diye pointer kullandık.
} Cyclist;

float averageTime(Cyclist c) {
    float sum = 0;
    for (int i = 0; i < c.laps; i++)
        sum += c.times[i];
    return sum / c.laps;
}

Cyclist *readFile(const char *filename, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fscanf(file, "%d", count); //count=kişi sayısı.
    Cyclist *group = (Cyclist*)malloc((*count) * sizeof(Cyclist));

    for (int i = 0; i < *count; i++) {
        fscanf(file, "%s %d %d", group[i].name, &group[i].id, &group[i].laps);
        group[i].times = (float*)malloc((group[i].laps) * sizeof(float));
        for (int j = 0; j < group[i].laps; j++) {
            fscanf(file, "%f", &group[i].times[j]);
        }
    }

    fclose(file);
    return group;
}

void listCyclists(Cyclist *group, int count) {
    printf("Number of athletes: %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("Name: %s #Id: %d #Laps: %d\n",
               group[i].name, group[i].id, group[i].laps);
    }
}

void detailCyclist(Cyclist *group, int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(group[i].name, name) == 0) {
            printf("#Id: %d #Laps: %d Times: ", group[i].id, group[i].laps);
            for (int j = 0; j < group[i].laps; j++)
                printf("%.2f ", group[i].times[j]);
            printf("\n");
            return;
        }
    }
    printf("Athlete not found.\n");
}

void bestCyclist(Cyclist *group, int count) {
    int bestIndex = 0;
    float bestAvg = averageTime(group[0]);

    for (int i = 1; i < count; i++) {
        float avg = averageTime(group[i]);
        if (avg < bestAvg) {
            bestAvg = avg;
            bestIndex = i;
        }
    }

    Cyclist c = group[bestIndex];
    printf("Name: %s #Id number: %d Laps: %d\nTimes: ",
           c.name, c.id, c.laps);
    for (int j = 0; j < c.laps; j++)
        printf("%.2f ", c.times[j]);
    printf("(Average: %.2f)\n", bestAvg);
}

int main() {
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);

    int count;
    Cyclist *group = readFile(filename, &count);

    char command[50];
    while (1) {
        printf("Command >>> ");
        scanf("%s", command);

        if (strcmp(command, "list") == 0)
            listCyclists(group, count);
        else if (strcmp(command, "best") == 0)
            bestCyclist(group, count);
        else if (strcmp(command, "detail") == 0) {
            char name[30];
            scanf("%s", name);
            detailCyclist(group, count, name);
        } else if (strcmp(command, "stop") == 0) {
            break;
        } else {
            printf("Unknown command.\n");
        }
    }

    // Free memory
    for (int i = 0; i < count; i++)
        free(group[i].times);
    free(group);

    return 0;
}
