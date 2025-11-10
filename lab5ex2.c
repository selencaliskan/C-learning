#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    char id[5];
    double x1, y1;
    double x2, y2;
    double area;
    double perimeter;
    int points_read;
} Rectangle;

int main(){
    FILE *fp;
    char filename[50];
    printf("Enter the filename:");
    scanf("%s",&filename);

    fp=fopen(filename,'r');
    if(fp== NULL){
        printf("Error opening file");
        return -1;
    }

    Rectangle *rects = NULL;   // struct dizimizi tutacak pointer
    int count = 0;             // kaç farklı dikdörtgen var
    char id[5];
    double x, y;

    return 0;

    while (fscanf(fp, "%s %lf %lf", id, &x, &y) == 3) {
        int found = 0;

        //ID daha önce okundu mu?
        for (int i = 0; i < count; i++) {
            if (strcmp(rects[i].id, id) == 0) {
                // Aynı ID'yi (dikdörtgeni) bulduk → ikinci köşe burada
                rects[i].x2 = x;
                rects[i].y2 = y;
                rects[i].points_read++;
                found = 1;
                break; //counta dokunmadık çünkü bu yeni bir dikdörtgen değil.
            }
        }

        // 🟥 Yeni bir ID ise → yeni struct ekle
        if (!found) {
            rects = realloc(rects, (count + 1) * sizeof(Rectangle)); // Belleği 1 struct kadar büyüt.
            if (rects == NULL) {
                printf("Memory allocation error!\n");
                fclose(fp);
                return 1;
            }

            strcpy(rects[count].id, id); // ID kopyala
            rects[count].x1 = x;         // İlk köşe
            rects[count].y1 = y;
            rects[count].points_read = 1;
            count++;
        }

    }

    fclose(fp);

    //Her dikdörtgenin alan ve çevresini hesapla
    for (int i = 0; i < count; i++) {
        if (rects[i].points_read == 2) {
            double width = fabs(rects[i].x2 - rects[i].x1);
            double height = fabs(rects[i].y2 - rects[i].y1);
            rects[i].area = width * height;
            rects[i].perimeter = 2 * (width + height);
        } else {
            rects[i].area = 0;
            rects[i].perimeter = 0;
        }
    }

    //ALANA göre büyükten küçüğe sıralama
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (rects[j].area > rects[i].area) {
                Rectangle temp = rects[i];
                rects[i] = rects[j];
                rects[j] = temp;
            }
        }
    }

    // 🟩 area.out dosyasına yaz
    FILE *fa = fopen("area.out", "w");
    if (fa == NULL) {
        printf("Error opening area.out file.\n");
        free(rects);
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fa, "%s\n", rects[i].id);
    }
    fclose(fa);

    //ÇEVREYE göre büyükten küçüğe sıralama
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (rects[j].perimeter > rects[i].perimeter) {
                Rectangle temp = rects[i];
                rects[i] = rects[j];
                rects[j] = temp;
            }
        }
    }

    // 🟩 perimeter.out dosyasına yaz
    FILE *fp2 = fopen("perimeter.out", "w");
    if (fp2 == NULL) {
        printf("Error opening perimeter.out file.\n");
        free(rects);
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp2, "%s\n", rects[i].id);
    }

    fclose(fp2);
    free(rects); // 🔚 Belleği serbest bırak

    printf("Output stored in area.out and perimeter.out files.\n");
    return 0;
}