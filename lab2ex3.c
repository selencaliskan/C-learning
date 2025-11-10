#include <stdio.h>

int main() {
    //kaç satır olacağını bulayım.
    int rows;
    printf("Enter how many rows the Pascal triangle is going to have.");
    scanf("%d",&rows);

    //matrixle çözmek en mantıklısı.
    int matrix[rows][rows];
    matrix[0][0]=1;
for (int i=1; i<rows; i++){    
    matrix[i][0]=1;
    matrix[i][i]=1;

for(int j=1; j<rows;j++){
    if(j != i){
    matrix[i][j]= matrix[i-1][j-1] + matrix[i-1][j];
    }
}
}

    printf("Triangle:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}