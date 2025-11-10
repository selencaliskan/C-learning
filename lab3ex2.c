#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_LEN 128   // ASCII tablosu kadar
#define M_CODE_LEN 10      // her Morse kodu en fazla 10 karakter

void loadMorseCodes(char morse_codes[ALPHABET_LEN][M_CODE_LEN]) {
    FILE *fp = fopen("alphabet.in", "r"); //dosyayı "read" modunda açıp okuduk. 
//Eğer açma başarılı olursa: fopen() bir FILE * (adres) döndürür. Bu adresi fp değişkenine koyuyoruz.
// yani *fp = file in adresi.
    if (!fp) {
        printf("Error: alphabet.in not found.\n"); //dosya adresi yok diyo.
        return;
    }

    char letter, code[M_CODE_LEN];

    //bir dosyadan okumak isteyince fscanf kullancaz.
    while (fscanf(fp, "%c\t%s\n", &letter, code) != EOF) {   //A .- gibi bişey.
        morse_codes[(int)letter][0] = '\0';  //burdaki letteri ascii değerine çevirip morse codes diye bir şeye kopyalicaz. morse codesı her dönüşte boşaltıyoruz.
        strcpy(morse_codes[(int)letter], code); //morsecodes[A] ya eşleşen code u kopyalama fonksiyonu. morsecodes[A] = .- gibi
    }
    fclose(fp);
}

void encode(char morse_codes[ALPHABET_LEN][M_CODE_LEN], const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");
    if (!in || !out) {
        printf("Error opening files.\n");
        return;
    }

    char ch;
    printf("Encoded message: ");
    while ((ch = fgetc(in)) != EOF) { //dosyadan bir karakter okur ve okunan karakterin ASCII değerini döndürür.
        if (ch == ' ') {
            fprintf(out, "/ ");
            printf("/ ");
        } else if (ch == '\n') {
            fprintf(out, "/ ");
            printf("/ ");
        } else {
            ch = toupper(ch);
            if (morse_codes[(int)ch][0] != '\0') { //büyük harfe çevrilmiş karakterin ASCII indisine karşılık gelen Morse stringini verir.
                fprintf(out, "%s ", morse_codes[(int)ch]);
                printf("%s ", morse_codes[(int)ch]);
            }
        }
    }
    printf("\nEncoded message saved to file %s\n", output_file);
    fclose(in);
    fclose(out);
}

void decode(char morse_codes[ALPHABET_LEN][M_CODE_LEN], const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");
    if (!in || !out) {
        printf("Error opening files.\n");
        return;
    }

    char code[M_CODE_LEN];
    printf("Decoded message: ");

    while (fscanf(in, "%s", code) != EOF) {
        if (strcmp(code, "/") == 0) { //string compare, eğer stringler aynıysa 0 döndürür.
            //str1 < str2 ise negatif değer, str1 > str2 ise pozitif değer.
            fprintf(out, " ");
            printf(" ");
        } else {
            for (int i = 0; i < ALPHABET_LEN; i++) {
                if (strcmp(code, morse_codes[i]) == 0) {
                    fprintf(out, "%c", i);
                    printf("%c", i);
                    break;
                }
            }
        }
    }
    printf("\nDecoded message saved to file %s\n", output_file);
    fclose(in);
    fclose(out);
}

int main() {
    char morse_codes[ALPHABET_LEN][M_CODE_LEN] = {0};
    loadMorseCodes(morse_codes);

    char choice;
    char input_file[50], output_file[50];

    while (1) {
        printf("(E)ncode (D)ecode e(X)it >>> ");
        scanf(" %c", &choice);
        choice = tolower(choice);

        if (choice == 'x') break;

        printf("Input file name > ");
        scanf("%s", input_file);
        printf("Output file name > ");
        scanf("%s", output_file);

        switch (choice) {
            case 'e': encode(morse_codes, input_file, output_file); break;
            case 'd': decode(morse_codes, input_file, output_file); break;
            default: printf("Invalid option.\n");
        }
    }

    return 0;
}
