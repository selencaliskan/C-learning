#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct student {
    char *ID;
    char *name;
    char *surname;
    int assignedSlot;
} student_t;

// Prototipler
int load_data(char *filename, student_t **students);
void bubble_sort(student_t *students, int n);
void insertion_sort(student_t *students, int n);
void selection_sort(student_t *students, int n);
int assign_slots(student_t *students, int n, int m);
void display_data(student_t *students, int n, int numSlots);

int load_data(char *filename, student_t **students){
    FILE *fp = fopen(filename, "r");
    if (!fp){
        printf("Error opening the file.");
        return -1;
    }

    char name[50], surname[50], id[20];
    int count = 0;
    *students = NULL;

    while (fscanf(fp, "%s %s %s", name, surname, id) == 3) {
        *students = realloc(*students, (count + 1) * sizeof(student_t));
        (*students)[count].name = strdup(name);
        (*students)[count].surname = strdup(surname);
        (*students)[count].ID = strdup(id);
        (*students)[count].assignedSlot = 0;
        count++;
    }

    fclose(fp);
    return count;
}

void bubble_sort(student_t *students, int n){
    for(int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if((strcmp(students[j].surname,students[j+1].surname) >0)){
                student_t temp =students[j];
                students[j]=students[j+1];
                students[j+1]=temp;
            }

        }

    }
}

void insertion_sort(student_t *students, int n){
        for (int i = 1; i < n; i++) {
        student_t key = students[i];
        int j = i - 1;
        while (j >= 0 && strcmp(students[j].surname, key.surname) > 0) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

void selection_sort(student_t *students, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(students[j].surname, students[min_idx].surname) < 0)
                min_idx = j;
        }
        if (min_idx != i) {
            student_t temp = students[i];
            students[i] = students[min_idx];
            students[min_idx] = temp;
        }
    }
}

int assign_slots(student_t *students, int n, int maxPerSlot) {
    int slot = 1;
    for (int i = 0; i < n; i++) {
        students[i].assignedSlot = slot;
        if ((i + 1) % maxPerSlot == 0)
            slot++;
    }
    return slot;
}

void print_slots(student_t *students, int n, int totalSlots) {
    printf("The number of assigned slots is %d!\n", totalSlots - 1);
    for (int s = 1; s < totalSlots; s++) {
        printf("Slot %d:\n", s);
        for (int i = 0; i < n; i++) {
            if (students[i].assignedSlot == s) {
                printf("%s %s %s\n",
                       students[i].name,
                       students[i].surname,
                       students[i].ID);
            }
        }
    }
}

int main(int argc,char *argv[]){
    char *filename = argv[1];
    char *sortType = argv[2];
    int maxPerSlot = atoi(argv[3] + 1); // "-4" gibi argümandan 4’ü alır.
    
    student_t *students = NULL;
    int n = load_data(filename, &students); //so n = count = number of students.
    if (n == 0) {
        printf("No students found or file not readable.\n");
        return 1;
    }

        if (strcmp(sortType, "-B") == 0)
        bubble_sort(students, n);
    else if (strcmp(sortType, "-I") == 0)
        insertion_sort(students, n);
    else if (strcmp(sortType, "-S") == 0)
        selection_sort(students, n);
    else {
        printf("Invalid sort option.\n");
        return 1;
    }

    int slots = assign_slots(students, n, maxPerSlot);
    print_slots(students, n, slots);
        for (int i = 0; i < n; i++) {
        free(students[i].name);
        free(students[i].surname);
        free(students[i].ID);
    }
    free(students);


    return 0;
}
