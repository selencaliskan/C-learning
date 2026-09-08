#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//read matrix ve matrix size yerine dinamik olarak tek seferde okicaz.
int** readMatrixDynamic(const char *filename, int *rows, int *cols) { 
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Initial capacity for rows
    int row_capacity = 2;  // Start small, will grow as needed, we can use realloc if needed anyways.
    int **matrix = (int **)malloc(row_capacity * sizeof(int *));
    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    *rows = 0;
    *cols = 0;
    int temp;
    char ch;

    // Read the file line by line
    while (!feof(file)) { //The feof() function is used to check whether the file pointer to a stream is pointing to the end of the file or not.
        if (*rows >= row_capacity) {
            row_capacity *= 2;  // Double the capacity
            int **new_matrix = (int **)realloc(matrix, row_capacity * sizeof(int *));
            if (new_matrix == NULL) {
                printf("Memory reallocation failed\n");
                // Bellek yetmezse → program duruyor ve önceki satırlar serbest bırakılıyor.
                for (int i = 0; i < *rows; i++) {
                    free(matrix[i]);
                }
                free(matrix);
                exit(1);
            }
            matrix = new_matrix;
        }

        // her satır için başta 2 sütunluk yer ayırıyoruz.
        int col_capacity = 2;
        int current_cols = 0;
        int *row = (int *)malloc(col_capacity * sizeof(int));
        if (row == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        // Read all numbers in the current row
        while (fscanf(file, "%d", &temp) == 1) {
            // buraya current_cols 2 olana kadar girmicez, ama zaten sütunlar bitene kadar döngü döncek, sıkıntı yok.
            if (current_cols >= col_capacity) {
                col_capacity *= 2;  // Double the capacity
                int *new_row = (int *)realloc(row, col_capacity * sizeof(int));
                if (new_row == NULL) {
                    printf("Memory reallocation failed\n");
                    free(row);
                    exit(1);
                }
                row = new_row;
            }

            // Store the value
            row[current_cols] = temp;
            current_cols++;

            // Check what comes after this number
            ch = fgetc(file);
            if (ch == '\n' || ch == EOF) {
                break;  // End of line
            }
            // If it's a space/tab, continue reading
            ungetc(ch, file);  // Put the character back
        }

        // If we read any columns, add this row to the matrix
        if (current_cols > 0) {
            // Set number of columns from first row
            if (*rows == 0) {
                *cols = current_cols;
            }

            // Verify all rows have the same number of columns
            if (current_cols != *cols) {
                printf("Error: Matrix rows have different lengths\n");
                free(row);
                exit(1);
            }

            // Resize row to exact size (optional optimization)
            if (current_cols < col_capacity) {
                int *trimmed_row = (int *)realloc(row, current_cols * sizeof(int));
                if (trimmed_row != NULL) {
                    row = trimmed_row;
                }
            }

            matrix[*rows] = row;
            (*rows)++;
        } else {
            // Empty line or end of file
            free(row);
            break;
        }
    }

    fclose(file);

    // Trim the matrix to exact size (optional optimization)
    if (*rows < row_capacity) {
        int **trimmed_matrix = (int **)realloc(matrix, (*rows) * sizeof(int *));
        if (trimmed_matrix != NULL) {
            matrix = trimmed_matrix;
        }
    }

    return matrix;
}

void manipulateMatrix(int** matrix, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            int exponent = i+j;
            matrix[i][j] = (int) pow(matrix[i][j], exponent);
        }
    }
}

void writeMatrix(char* filename, int** matrix, int rows, int cols) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Impossibile to open the file!\n");
        exit(1);
    }

    for(int i=0; i <rows; i++) {
        for(int j=0; j<cols; j++) {
            fprintf(file, "%d\t", matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void freeMatrix(int** matrix, int rows) {
    if(matrix != NULL) {
        for(int i=0; i < rows; i++) {
            free(matrix[i]);
            matrix[i] = NULL;
        }
        free(matrix);
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for(int i=0; i <rows; i++) {
        printf("Row %d:\t", i);
        for(int j=0; j<cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int rows=0, cols=0;
    int** matrix = NULL;

    if(argc != 3) {
       printf("Please pass input file and output file names!\n");
       printf("Usage: %s <input.txt> <output.txt>\n", argv[0]) ;
       return -1;
    }

    printf("Input file: %s\n", argv[1]);
    printf("Output file: %s\n", argv[2]);

    // read and allocate matrix dynamically
    matrix = readMatrixDynamic(argv[1], &rows, &cols);
    
    // Manipulate matrix
    manipulateMatrix(matrix, rows, cols);

    // If you want to print the updated matrix uncomment the following funciton
    // printMatrix(matrix, rows, cols);

    // Write result to output file
    writeMatrix(argv[2], matrix, rows, cols);
    printf("Updated matrix written to file: %s\n", argv[2]);

    // Free memory
    freeMatrix(matrix, rows);
    matrix = NULL;

    return 0;
}
