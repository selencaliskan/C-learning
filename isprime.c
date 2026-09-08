#include <stdio.h>

int main() {
    int prime;
    int divisor;

    printf("Enter 10 numbers:\n");

    for (int k = 0; k < 10; k++) {   // 10 sayı alacağız
        scanf("%d", &prime);

        if (prime <= 1) {
            printf("The number %d is not a valid number\n", prime);
            continue;  
        }

        divisor = 2;

        while ((prime % divisor != 0) && (divisor < prime / 2)) {
            divisor++; 
        }

        if (prime % divisor == 0) {
            printf("%d is not a prime number!\n", prime);
        } else {
            printf("%d is a prime number!\n", prime);
        }
    }

    return 0;
}
