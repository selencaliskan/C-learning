#include <stdio.h>

int main(void) {
    float balance = 500.0f;  // your initial amount of money.
    int choice;  //1 → deposit, 2 → withdraw, 3 → check balance, 4 → exit.
    float amount;  //the amount that people want to deposit or withdraw.

    printf("A&P Bank Virtual ATM\n");
    printf("---------------------\n");

    while (1) {
        printf("Please choose an option:\n");
        printf("1. Deposit funds\n");
        printf("2. Withdraw funds\n");
        printf("3. Check balance\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Deposit
                printf("Enter the amount to deposit: ");
                scanf("%f", &amount);
                if (amount <= 0) {
                    printf("Deposit must be positive. Transaction cancelled.\n");
                } else {
                    balance = balance + amount;
                    printf("Transaction successful! New balance: %f EUR\n", balance);
                }
                break;

            case 2: // Withdraw
                printf("Enter the amount to withdraw: ");
                scanf("%f", &amount);
                if (amount <= 0) {
                    printf("Withdrawal must be positive. Transaction cancelled.\n");
                } else if (amount > balance) {
                    printf("Insufficient funds. Transaction cancelled.\n");
                } else {
                    balance = balance - amount;
                    printf("Transaction successful! New balance: %f EUR\n", balance);
                }
                break;

            case 3: // Check balance
                printf("Current balance: %f EUR\n", balance);
                break;

            case 4: // Exit
                printf("Thank you for using A&P Bank Virtual ATM. Goodbye!\n");
                return 0;

        }
    }

    return 0;
}
