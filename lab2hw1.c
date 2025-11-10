#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void encode(char *input) {
    int count = 1;
    int len = strlen(input);

    printf("Encoded string: ");
    for (int i = 0; i < len; i++) {
        if (input[i] == input[i+1]) {
            count++;
        } else {
            printf("%d%c", count, input[i]);
            count = 1;
        }
    }
    printf("\n");
}

void decode(char *input) {
    printf("Decoded string: ");
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        if (isdigit(input[i])) { //eğer bir sayıysa.
            int count = input[i] - '0'; // karakteri sayıya çeviriyoruz
            char c = input[i+1]; //sayının sonrasındaki yazacağımız karakteri aldık.
            for (int j = 0; j < count; j++) { //sembolu count kere yaz demek.
                printf("%c", c);
            }
            i++; //hem rakamı hem harfi atlamak için bir i++ daha koyduk. harfi çoktan işledik.
        }
    }
    printf("\n");
}

int main() {
    char option;
    char input[1000];

    while (1) {
        printf("(E)ncode (D)ecode e(X)it >>> ");
        scanf(" %c", &option);

        if (option == 'X' || option == 'x') {
            break;
        } else if (option == 'E' || option == 'e') {
            printf("String to encode >>> ");
            scanf("%s", input);
            encode(input);
        } else if (option == 'D' || option == 'd') {
            printf("String to decode >>> ");
            scanf("%s", input);
            decode(input);
        } else {
            printf("Invalid option!\n");
        }
    }
    return 0;
}
