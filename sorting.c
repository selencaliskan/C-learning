void InsertionSort (int A[], int n) { 
    int i, j, x; 
    
    for (i=1; i<n; i++) { 
        x = A[i];         // Elemanı çek (Extract) 
        j = i - 1;      
        
        while (j>=0 && x<A[j]) { //eğer A[i]<A[j]:
            A[j+1] = A[j]; //A[i]=A[j] gibi. öncekini sonraki yapıyor.
            j--; 
        }
        A[j+1] = x; // Bir önceki yere insert.
    }
    return; 
}


void SelectionSort (int A[], int n) {
  int i, j, min, temp;

  for (i=0; i<n-1; i++) {
    min = i; //min i inci eleman diyor.
    for (j=i+1; j<n; j++) {
      if (A[j] < A[min]) {
        min = j; //min j'nci eleman diyor.
      }
    }
    temp = A[i];
    A[i] = A[min];
    A[min] = temp;
  }

  return;
}

void BubbleSort (int A[], int n){
  int i, j, temp;

  for (i=0; i<n-1; i++) {
    for (j=0; j<(n-i-1); j++) {
      if (A[j] > A[j+1]) {
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
    }
  }
  return;
} //selectionla neredeyse aynı. sadece aynı sayı gelirse swaplamıyor.

/*
Insertion Sort, sadece komşu elemanları karşılaştırır ve yer değiştirir. B
u nedenle, dizinin başındaki çok küçük bir elemanın dizinin sonuna taşınması gerekiyorsa, 
bu işlem çok sayıda küçük yer değiştirme (swap) gerektirir ve verimsizdir.
Shellsort, bu sorunu çözmek için (h-step) veya $h$ mesafesi adı verilen bir mekanizma kullanır.
*/
void ShellSort (int A[], int n) { 
    int i, j, x, h;
    h=1; 
    
    // h'nin başlangıç değerini hesapla (Knuth's sequence: h = 3*h + 1). sonradan h yi küçültcez.
    while (h < n/3) 
        h = 3*h+1;
        
    while (h >= 1) { 
        // h-adımında Insertion Sort uygula
        for (i=h; i<n; i++) {
            x = A[i]; 
            j = i - h; 
            
            while (j>=0  && x<A[j]) { 
                A[j+h] = A[j]; //yine A[i]=A[j] gibi.
                j -= h; 
            }
            A[j+h] = x; 
        }
        h = h/3; // Bir sonraki h değerine geç.
    }
}

#define MAX 100
void CountingSort(int A[], int n, int k) {
    int i, C[MAX], B[MAX]; 

    // 1. C'yi sıfırla
    for (i=0; i<k; i++) 
        C[i] = 0; 
        
    // 2. Basit sıklıkları bul (A dizisindeki o anki değer neyse C dizisindeki o değer indeksine git ve sayacı bir artır.)
    for (i=0; i<n; i++) 
        C[A[i]]++;
        
    // 3. Kümülatif sıklıkları hesapla (O(k))
    for (i=1; i<k; i++) 
        C[i] += C[i-1]; 
        
    // 4. A'dan B'ye kopyala (Tersten) (O(n))
    for (i=n-1; i>=0; i--) { 
        B[C[A[i]]-1] = A[i]; //sıralanacak değer olan A[i] yi yeni bir B dizisine kopyalamak amaç.
        C[A[i]]--; 
    }
    
    // 5. B'yi A'ya kopyala (O(n))
    for (i=0; i<n; i++) 
        A[i] = B[i]; 
}