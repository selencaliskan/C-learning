#include <stdio.h>
#include <time.h>

int main() {
    int tries=1;
    int goal;
    goal = srand(time(0)) % 100+1;  //%101 yapsaydın 0 ile 100 arasında olurdu, 0 ı istemiyoruz.

    // we have done the randomizing thing.
    int guess;
    printf("I have chosen a number between 1 and 100. Guess/n");
    scanf("%d", &guess);

while (guess != goal) {
    if (guess > goal) {
        printf("Your number is too high. Guess again.\n");
    } else if (guess< goal) {
        printf("Your number is too low. Guess again.\n");
    }


    scanf("%d", &guess);
    tries++;
}
printf("You have guessed the correct number in %d tries.",tries);
    return 0;

}