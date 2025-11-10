#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Bilgisayarın akıllı hamle yapması için yardımcı fonksiyon
int smart_move(int marbles) {
    int powers[] = {3, 7, 15, 31, 63};  // 2^k - 1 bilgisayar hedef boyutları.
    int target = 0;
    for (int i = 4; i >= 0; i--) {
        if (marbles > powers[i]) {
            target = powers[i];
            break;
        }
    }
    if (target == 0) {
        // Eğer pile zaten 2^k - 1 ise yani target değiştirilmediyse rastgele valid hamle yap.
        return rand() % (marbles / 2) + 1; 
    } else {
        return marbles - target;
    }
}

// Ana program
int main(void) {
    int marbles;
    int user_first;
    int computer_smart;
    int user_take, computer_take;

    srand(time(NULL));

    // Rastgele başlangıç
    marbles = rand() % 91 + 10; // 10-100 arası
    user_first = rand() % 2;    // 0 = computer first, 1 = user first
    computer_smart = rand() % 2; // 0 = random, 1 = smart

    printf("Welcome to the Nim Game!\n");
    printf("-------------------------\n");
    printf("The initial pile has %d marbles.\n", marbles);
    if (user_first)
        printf("You will play first.\n");
    else
        printf("Computer will play first.\n");

    while (marbles > 0) {
        // Kullanıcı sırası
        if (user_first) {
            int max_take = marbles / 2;
            if (max_take == 0) {max_take = 1; //1 taş kalsıysa onu alman gerek.
            }

            printf("Your turn! How many marbles will you take (1-%d)? ", max_take);
            scanf("%d", &user_take);

            while (user_take < 1 || user_take > max_take) {
                printf("Invalid move! Enter a number between 1 and %d: ", max_take);
                scanf("%d", &user_take);
            }

            marbles = marbles - user_take;
            if (marbles == 0) {
                printf("Oops! You took the last marble. You lose.\n");
                break;
            }
            printf("Marbles left: %d\n", marbles);
        }

        // Bilgisayar sırası
        int max_take = marbles / 2;
        if (max_take == 0) {max_take = 1;
        }
        if (computer_smart) {
            computer_take = smart_move(marbles);
            if (computer_take < 1 || computer_take > max_take)
                computer_take = rand() % max_take + 1; // fallback
        } else {
            computer_take = rand() % max_take + 1; // random
        }

        printf("Computer took %d marbles.\n", computer_take);
        marbles = marbles - computer_take;
        if (marbles == 0) {
            printf("Computer took the last marble. You win!\n");
            break;
        }
        printf("Marbles left: %d\n", marbles);

        // Sırayı değiştir
        user_first = 1;
    }

    return 0;
}

