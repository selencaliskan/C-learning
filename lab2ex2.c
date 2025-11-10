#include <stdio.h>

// Fonksiyon prototipleri
void printArray(int *arr, int size);
void findMinMax(int *arr, int size, int *min, int *max);
void reverseArray(int *arr, int size);

// bu genel bir pointer ile yazdırma fonksiyonu.
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i)); // pointer ile elemanı al. arr[i] demekle aynı şey bu.
    }
    printf("\n");
}

// Minimum ve maksimumu bulma
void findMinMax(int *arr, int size, int *min, int *max) {
    *min = *arr; // ilk elemanı min olarak al
    *max = *arr; // ilk elemanı max olarak al
    for (int i = 1; i < size; i++) {
        if (*(arr + i) < *min) *min = *(arr + i);
        if (*(arr + i) > *max) *max = *(arr + i);
    }
}

// Array'i ters çevirme
void reverseArray(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    // 1️⃣ Array'i tanımla ve başlat
    int numbers[10] = {5, 12, 7, 3, 18, 9, 21, 1, 14, 6};
    int size = 10;

    // 2️⃣ Array'i pointer ile yazdır
    printf("Original array: ");
    printArray(numbers, size);  //buraya numbers girdiğim için *arr, numbers ı görecek.

    // 3️⃣ Maximum ve Minimum değerleri bul
    int min, max;
    findMinMax(numbers, size, &min, &max);
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    // 4️⃣ Array'i ters çevir
    reverseArray(numbers, size);
    printf("Reversed array: ");
    printArray(numbers, size);

    return 0;
}

