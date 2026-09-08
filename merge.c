#include <stdio.h>
#include <stddef.h> // size_t için

// Fonksiyon tanımı
int *mergeVectors(int *vec1, size_t size1, int *vec2, size_t size2, int merged[]) {
    if (!vec1 || !vec2 || size1 == 0 || size2 == 0) {
        return NULL; // koşullar sağlanmazsa NULL döndür
    }

    int *lastElem = &vec1[size1 - 1];  // Son elemana pointliyo.

    for (size_t i = 0; i < size1; i++)
        merged[i] = vec1[i]; //ilk vektörün elemanlarını merge e attık.

    for (size_t j = 0; j < size2; j++)
        merged[size1 + j] = vec2[j];

    return lastElem; // vec1'in son elemanına pointer döndür
}

int main() {
    int vec1[] = {1, 2, 3, 4};
    int vec2[] = {5, 6, 7};

    size_t size1 = 4;
    size_t size2 = 3;
    size_t total = size1 + size2;

    int merged[total]; //toplam boyut kadar yer ayırdık.

    int *lastElem = mergeVectors(vec1, size1, vec2, size2, merged); //fonksiyonun döndürdüğü elemana pointer.

    printf("Last element of vec1 before merge: %d\n", *lastElem);

    printf("Merged array: ");
    for (size_t i = 0; i < total; i++)
        printf("%d ", merged[i]);
    printf("\n");

    *lastElem = 99;

    for (size_t i = 0; i < size1; i++)
    merged[i] = vec1[i]; 
    for (size_t j = 0; j < size2; j++)
    merged[size1 + j] = vec2[j];

    printf("New array: ");
    for (size_t i = 0; i < total; i++)
        printf("%d ", merged[i]);
    printf("\n");

    return 0;
}
