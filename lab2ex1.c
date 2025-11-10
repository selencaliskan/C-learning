#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    char input[100];
    printf("Enter a number to see if its suitable for Luhn algorithm.");
    scanf("%[^\n]", &input); //yeni satıra kadar al, inputa ata demek.

int a=0;
int digits[100]; //rakamları boşluksuz bu arraya atcam.

for(int i=0; i < strlen(input) ; i++ ){
    if(input[i]>= '0' && input[i] <= '9'){
        digits[a] = input[i] - '0'; //char -> int.
        a++;
    }
      else if (input[i] == ' ' || input[i] == '\n') {
        // boşluk ve newline görmezden gelinir.
    } 
    else {
        printf("Error: invalid character detected.\n");
}
}

if (a <= 1){
    printf("Number is not valid.");
    return 0;
}
//şimdi luhn a geçebiliriz.

int sum = 0;
int doubleDigit = 0; // 1 = çift basamak, 0 = tek basamak

for (int i = a - 1; i >= 0; i--) {
    int d = digits[i];

    if (doubleDigit) {
        d *= 2;
        if (d > 9) {
            d = d- 9;  // tek basamak yap
        }
    }

    sum = sum + d;
    doubleDigit = 1 - doubleDigit;  // 0 ↔ 1 değiştir
}
    if (sum % 10 == 0) {
        printf("Number is valid.");
    } else {
        printf("Number is not valid.");
    }

}