/*
 * This program allocates 2 matrices A, B of user-specified dimensions,
 * performs matrix multiplication if dimensions are compatible,
 * and prints the results.
 *
 * M        =   A       *   B
 * [r1xc2]      [r1xc1]     [r2xc2]
 *
 * Condition: c1 == r2
*/

#include <stdio.h>
#include <stdlib.h>

int multiplyMatrices(int **A, int **B, int **M, int r1, int c1, int c2) {

    // check pointers to matrices
    if (A == NULL || B == NULL || M == NULL) {
        fprintf(stderr, "Invalid pointer(s)!\n");
        return -1;
    }

    // Perform matrix multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            M[i][j] = 0;
            for (int k = 0; k < c1; k++) { //c1=r2
                M[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return 0;
}

int main() {

    int r1, c1, r2, c2; // Operands dimensions

    // Get dimensions from the user
    printf("This program performs matrix multiplication M = A * B.\n");
    fflush(stdout);
    //printf() veya fprintf() gibi fonksiyonlarla bir şeyler yazdırdığınızda, bu veriler hemen ekranda görünmeyebilir; önce tampona gider.
    //fflush(stdout) fonksiyonu, tamponun otomatik olarak temizlenmesini beklemeden, tampondaki verileri zorla (hemen) ekrana göndermeye yarar.

    printf("Enter the dimensions of matrix A:");
    fflush(stdout);
    scanf("%d %d", &r1, &c1);

    printf("Enter the dimensions of matrix B:\n");
    fflush(stdout);
    scanf("%d %d", &r2, &c2);

    // Check matrix dimensions for compatibility
    if (c1 != r2) {
        printf("Matrix multiplication not possible.\n");
        return -1;
    }

    // Allocate matrices
    int **A = (int **)malloc(r1 * sizeof(int *)); // A has r1 rows
    int **B = (int **)malloc(r2 * sizeof(int *)); // B has r2 rows
    int **M = (int **)malloc(r1 * sizeof(int *)); // M has r1 rows
    for (int i = 0; i < r1; i++) A[i] = (int *)malloc(c1 * sizeof(int)); // A has c1 columns
    for (int i = 0; i < r2; i++) B[i] = (int *)malloc(c2 * sizeof(int)); // B has c2 columns
    for (int i = 0; i < r1; i++) M[i] = (int *)malloc(c2 * sizeof(int)); // M has c2 columns

    // Ask user to insert matrix elements
    printf("Enter elements matrix A:\n");
    for (int i = 0; i < r1; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < c1; j++) scanf("%d", &A[i][j]);
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < r2; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < c2; j++) scanf("%d", &B[i][j]);
    }

    // Print inserted matrices
    printf("Matrix A:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) printf("%d ", A[i][j]);
        printf("\n");
    }
    printf("Matrix B:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) printf("%d ", B[i][j]);
        printf("\n");
    }

    // Perform multiplication and check for errors
    if (multiplyMatrices(A, B, M, r1, c1, c2) == 0) { //sorunsuz çalıştıysa yani.

        // Print result
        printf("Multiplied matrix M:\n");
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) printf("%d ", M[i][j]);
            printf("\n");
        }
    } else {
        // Print error message
        fprintf(stderr, "Matrix multiplication failed.\n");
    }

    // Deallocate the row arrays
    // Deallocate arrays of pointers to rows
    // and set pointers to NULL
    if (A != NULL) {
        for (int i = 0; i < r1; i++) free(A[i]);
        free(A);
        A = NULL;
    }

    if (B != NULL) {
        for (int i = 0; i < r2; i++) free(B[i]);
        free(B);
        B = NULL;
    }

    if (M != NULL) {
        for (int i = 0; i < r1; i++) free(M[i]);
        free(M);
        M = NULL;
    }

    return 0;
}