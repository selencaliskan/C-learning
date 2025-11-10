#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 7

void printGrid(char grid[size][size]) {
    for (int i = 0; i < size; i++) { //i satırı gösteriyor. 7 kez dönecek.
        for (int j = 0; j < size; j++) { //j sütunu gösteriyor. 
            printf("%c ", grid[i][j]); //o sayıyı alıyor ve doğru grid yerine yerleştiriyor. bir boşluk bırakıyor grid düzgün gözüksün diye.
        }
        printf("\n"); //sütunlar bitince yeni satıra geçmek için \n
    }
}


int main() {
int playerX = 0, playerY = 0;
int treasures = 2, obstacles = 4;
char grid[size][size];

srand(time(NULL));
    // Gridi yaratmak için
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = '.';
        }
    }

    // Oyuncu başlangıç konumu
    grid[playerX][playerY] = 'P';

for (int t = 0; t < treasures; t++) {
    int x = rand() % size;
    int y = rand() % size;

    while (grid[x][y] != '.') {
        x = rand() % size;
        y = rand() % size;
    }
    grid[x][y] = 'T';  // ilk dümdüz boş bi yere koydum. while a girmedim. eğer daha önce koyduğu yere randomizelarsa while a gircek.
}

for (int o = 0; o < obstacles; o++) {
    int x = rand() % size;
    int y = rand() % size;

    while (grid[x][y] != '.') {
        x = rand() % size;
        y = rand() % size;
    }
    grid[x][y] = 'X';  // ilk dümdüz boş bi yere koydum. while a girmedim. eğer daha önce koyduğu yere randomizelarsa while a gircek.
}
char move; //oyuncunun ne seçtiğini bulcam.
    while (1) {
        printGrid(grid);
        printf("Your move (N, S, E, W): ");
        scanf("%c", &move);

        int newX = playerX;
        int newY = playerY;

        if (move == 'N' || move == 'n') newX--;
        else if (move == 'S' || move == 's') newX++;
        else if (move == 'E' || move == 'e') newY++;
        else if (move == 'W' || move == 'w') newY--;  //satır-sütun güncellemesi.
        else {
            printf("Invalid input! Use N, S, E, W.\n");
            continue;
        }

        // Grid dışına çıkma kontrolü
        if (newX < 0 || newX >= size || newY < 0 || newY >= size) {
            printf("You can't move outside the island!\n");
            continue;
        }

        // Hedef hücreyi kontrol et
        if (grid[newX][newY] == 'T') {
            printf("Congratulations! You found a treasure!\n");
            break;
        } else if (grid[newX][newY] == 'X') {
            printf("Oh no! You hit an obstacle. Game Over.\n");
            break; //oyun bitsin diye break koyduk.
        }

        // Hareketi güncelle
        grid[playerX][playerY] = '.'; // eski yer boşalır
        playerX = newX;
        playerY = newY;
        grid[playerX][playerY] = 'P';
    }


    return 0;
}
