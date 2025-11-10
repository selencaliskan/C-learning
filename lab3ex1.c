#include <stdio.h>
#include <string.h> //strlen burda.
#include <ctype.h> //isalpha, isdigit, toupper ve tolower burda.
#include <stdlib.h>  //aatoi ve atof burda.

int atoifunc(){
    char input[100];
    int tokens;

    printf("Please choose the quantity of tokens to deposit : ");
    scanf("%[^\n]", input);

    tokens = atoi(input);
    printf("The tokens value you entered is: %d\n", tokens);

        return 0;
}

int atoffunc(){
    char input[100];
    int tokens;

    printf("Please choose the quantity of tokens to deposit : ");
    scanf("%[^\n]", input);

    tokens = atof(input);
    printf("The tokens value you entered is: %.2f\n", tokens); //2 ondalık basamak göster demek.

        return 0;
}

int passport(){
    char input[20];

    printf("Please enter the passport number : ");
    scanf("%s", input);

    int valid = 1;

    if (strlen(input != 9)){
        valid = 0;
    }
    else{
            if (!isalpha(input[0]) || !isalpha(input[1]))
            valid = 0;
        for (int i = 2; i < 9; i++) {
            if (!isdigit(input[i])) {
                valid = 0;
                break;
    }
}
    }

if (valid)
            printf("The passport you entered is: %s\n", passport);
else
        printf("The passport you entered is invalid.\n");

            return 0;
}

int uporlow(){
    char input;

    printf("Digit (Y) to continue and (N) to quit :");
    scanf("%c",input);

    input = toupper(input);

    if(input == "Y"){
        printf("Continuing the application.");
    }
    else if (input == "N"){
        printf("Quitting.");
    }
    else{
        printf("Error.");
    }

    return 0;
}
