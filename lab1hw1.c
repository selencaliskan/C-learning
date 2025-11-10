#include <stdio.h>
#include <string.h>

int main() {
    char dna1[101];
    char dna2[101];
    printf("Hamming Distance Calculator for DNA Strands\n");
    printf("-------------------------------------------\n");

    printf("Please enter the first DNA strand.");
    scanf("%s",dna1);
    printf("Please enter the second DNA strand.");
    scanf("%s",dna2);

    if (strlen(dna1) != strlen(dna2)){
    printf("Two DNA strans need to have the same length.");
            return 0;
    }
    printf("DNA Strand 1: %s/n", dna1);
    printf("DNA Strand 2: %s/n", dna2);
    printf("Differences : ");
    
    int i=0;
    int distance=0;
    for (i = 0; dna1[i] != '\0'; i++) {
        if (dna1[i] != dna2[i]) {
            printf("^");   // farklıysa ^ koy
            distance++;
        } else {
            printf(" ");   // aynıysa boşluk koy
        }
    }
    printf("\n");

    printf("Result: The Hamming Distance between the two DNAs is %d.", distance);


    return 0;
}