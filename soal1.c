/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 03
 *   Hari dan Tanggal    : Senin, 27 April 2026
 *   Nama (NIM)          : M Agni Aulia Fadhly Saepudin (13224042)
 *   Nama File           : soal1.c
 *   Deskripsi           : 
 
    [SOAL 1]
    Membaca data dan disimpan ke dalam array dinamis, kemudian
    mengeluarkan data yang sudah diurutkan dan mengetahui median.
    
/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
*/

#include <stdio.h>
#include <stdlib.h>

// Jumlahkan isi array dinamis arr dengan ukuran arr_size.
int sum_arr(int* arr, int arr_size) {
    int sum = 0;
    for (int i = 0; i < arr_size; ++i) {
    sum += arr[i];
    }
    return sum;
}

int main() {
    // Deklarasi array dinamis
   int* arr = NULL;
   int arr_size = 0;
   int temp;

   int count=0;

    // Input array secara dinamis hingga input -1
    scanf("%d", &temp);
    // Looping selama input tidak sama dengan -1
    while (temp != -1) {
        // Catat penambahan ukuran array
        ++arr_size;

    // Alokasi memori tambahan 
    if (arr_size == 1) {
        // Bila array belum diinisialisasi
        // Reservasi memori sebesar 1 buah integer dengan malloc
        arr = (int*) malloc(sizeof(int));
    } else {
        // Bila array sudah diinisialisasi
        // Alokasi ulang dengan ukuran sebesar arr_size buah integer dengan realloc
        arr = (int*) realloc(arr, arr_size * sizeof(int));
    }

    // Assign nilai elemen terakhir array dengan input
    arr[arr_size - 1] = temp;

    // Input elemen berikutnya
    scanf("%d", &temp);
    }

    // cari Count
    count = arr_size;

    // SORT  array
    for (int i = 0; i < arr_size; ++i) {
        for (int j=i+1; j<arr_size; ++j) {
            int temp;
            if (arr[i] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
            
        }
    }
    

    // OUTPUT
    printf("COUNT %d ", count);
    printf("SORTED ");
    // Print sorted array
    for (int i = 0; i < arr_size; ++i) {
        printf("%d ", arr[i]);
    }

    // cari MEDIAN
    if (count%2==1) {
        //int temp = (count+1) / 2;
        //printf("%d\n", temp);
        int median = arr[(count+1) / 2 -1];
        printf("MEDIAN  %d", median);
    } else if (count%2==0) {
        float a = (arr[count/2-1]+arr[count/2]);
        float b = 2.00;
        float median = a/b;
        printf("MEDIAN  %.2f", median);
    } else {
        printf("error\n");    
    }


    // Reset isi array
    // Free memori yang digunakan
    free(arr);

    return 0;
}
/*
REFERENSI
[1] https://stackoverflow.com/questions/16221776/why-dividing-two-integers-doesnt-get-a-float
[2] https://stackoverflow.com/questions/13530209/how-to-convert-int-to-float-in-c
[3] Stefen S. Tutorial Praktikum Modul 03 - Structures and Dynamics Array. Bandung: Institut Teknologi Bandung.
[4] https://stackoverflow.com/questions/24723180/c-convert-floating-point-to-int
*/
