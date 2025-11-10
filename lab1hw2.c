#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char binary[101];   // max 100 karakterlik binary sayı
    int len, i, decimal = 0;

    printf("Binary to Decimal Converter\n");
    printf("---------------------------\n");

    printf("Enter a binary number: ");
    scanf("%100s", binary);

    len = strlen(binary);

    // Geçersiz karakter kontrolü
    for (i = 0; i < len; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("Error: Invalid input. Only 0 and 1 are allowed.\n");
            return 0;
        }
    }

    // Binary → Decimal dönüşümü 
    for (i = 0; i < len; i++) {
        int bit = binary[len - 1 - i] - '0'; // len-1 dizinin son basamağı çünkü sıfırdan başlıyor. sonuncu -1 li.
        //len-1-i sondan i.nci basamak.  -"0" ascii kodundaki 0 ı çıkarıp integer a çevirmek için.
        decimal += bit * (int)pow(2, i);     // 2^i çarpımı
    }

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}
