#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_CITIZENS 100

typedef struct {
    char name[MAX_LENGTH];
    char id[10];          // 9 karakter + '\0'
    char birth_place[MAX_LENGTH];
    char birth_date[11];  // DD/MM/YYYY + '\0'
    char issuing[11];     // DD/MM/YYYY + '\0'
} citizen_t; 


int main(){
    citizen_t citizens[MAX_CITIZENS];
    int choice;
    int count = 0; //kaç vatandaş kayıtlı saymak için.

    while(1){
        printf("Welcomme to the ID System.\n");
        printf("1. Add a new citizen\n");
        printf("2. Search by ID\n");
        printf("3. List database\n");
        printf("4. Exit\n");
        printf("Choice >>> ");
        scanf("%d",&choice);

    switch (choice) {
            case 1:
                add_citizen(citizens, &count);
                break;
            case 2:
                search_by_id(citizens, count);
                break;
            case 3:
                list_database(citizens, count);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
    }}
    return 0;
}

void add_citizens(int *count, citizen_t citizens[]){
    if (*count >= MAX_CITIZENS){
        printf("The database is full. You can not add more citizens.");
        return;
    }

    citizen_t new_citizen;
    printf("Enter citizen name:");
    fgets(new_citizen.name, MAX_LENGTH, stdin); //new_citizen.name e kaydet, max karakter uzunluğu, stdin yani klavyeden veriyi alacaksın demek.
    new_citizen.name[strcspn(new_citizen.name, "\n")] = '\0'; // \n yi temizle.

    printf("Enter ID:");
    fgets(new_citizen.id, 10,stdin);
    new_citizen.id[strcspn(new_citizen.id, "\n")]= '\0';

    //ID zaten var mı kontrol et.
    for(int i=0; i < *count; i++){
        if(strcmp(citizens[i].id, new_citizen.id == 0)){ //string compare.
            printf("ID already exists.");
            return;
        }

    }

    printf("Enter birth place: ");
    fgets(new_citizen.birth_place, MAX_LENGTH, stdin);
    new_citizen.birth_place[strcspn(new_citizen.birth_place, "\n")] = '\0';

    printf("Enter birth date (DD/MM/YYYY): ");
    fgets(new_citizen.birth_date, 11, stdin);
    new_citizen.birth_date[strcspn(new_citizen.birth_date, "\n")] = '\0';

    printf("Enter issuing date (DD/MM/YYYY): ");
    fgets(new_citizen.issuing, 11, stdin);
    new_citizen.issuing[strcspn(new_citizen.issuing, "\n")] = '\0';

    citizens[*count] = new_citizen;
    (*count)++; //countu bir arttır.

    printf("Citizen added successfully!\n");

}

void searchbyid(int count, citizen_t citizens[]){
    char search_id[10];
    printf("Enter ID to search: ");
    fgets(search_id, 10, stdin);
    search_id[strcspn(search_id, "\n")] = '\0';

    for(int i=0; i< count;i++){
        if(strcmp(citizens[i].id, search_id == 0)){
            printf("Citizen found. Name: %s, ID : %d , Birth place : %s , Birthdate : %s , Issuing : %s",citizens[i].name, citizens[i].id, citizens[i].birth_place, citizens[i].birth_date, citizens[i].issuing);
        return;
        } else{
            printf("Citizen not found.");
        }
    }

}

void list_database(citizen_t citizens[], int count) {
    if (count == 0) {
        printf("Database is empty.\n");
        return;
    }

    printf("\n--- Citizens Database ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, ID: %s, Birth place: %s, Birth date: %s, Issuing: %s\n",
               citizens[i].name, citizens[i].id, citizens[i].birth_place,
               citizens[i].birth_date, citizens[i].issuing);
    }
}