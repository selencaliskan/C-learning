#include <stdio.h>
#include <stdlib.h>

int main(){
    char filename[20];
    printf("Reading matrix M x N\n");
    printf("---------------------\n");
    printf("Enter the file name: ");
    scanf("%s", &filename);

    FILE *fp = fopen(filename, "r"); //read modunda açtık file ı.
        if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int number;
    char c;
    int currentCols = 0;
    int rows = 0;
    int cols = 0;
    //fscanf, scanf in dosya versiyonu.
    while(fscanf(fp, "%d", &number) == 1){ //yani fscanf düzgün şekilde bir sayı okuduysa (return value su 1 ise)
        c = fgetc(fp);
        if (c == '\t')
        currentCols++;
    else if (c == '\n' || c == EOF) {
        rows++;
        if (cols == 0) //yani ilk satırdayız, cols henüz tanımlanmamış.
            cols = currentCols + 1;
        currentCols = 0;
    }}

    rewind(fp); //dosyanın başına dön.
    
    //şimdi matrixi yazdırmak için olan adımlara geçelim.

    //bellek ayır.
    int **matrix = (int ** )malloc(rows*sizeof(int*));
    for (int i=0; i<rows; i++){
        matrix[i]= (int*)malloc(cols* sizeof(int));
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            fscanf(fp, "%d", &matrix[i][j]);

    fclose(fp); //dosyayı kapat, onla artık işimiz yok.

    printf("Read matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d\t", matrix[i][j]);
        printf("\n");}

    //Belleği serbest bırak
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);


    return 0;
}

/*
for homework:

for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows - 1; i++) {
            for (int k = i + 1; k < rows; k++) {  //i,j ve i+1,j yi karşılaştırıyor.
                if (matrix[i][j] > matrix[k][j]) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[k][j];
                    matrix[k][j] = temp;  //i daha büyükse swaplıyo.
                }
            }
        }
    }

    // yazdırmak için:
    FILE *out = fopen("output.out", "w");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            fprintf(out, "%d\t", matrix[i][j]);
        fprintf(out, "\n");


*/