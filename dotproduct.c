#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void x8664 ();


void dotProductx86(size_t n, double* result, double* arr1, double* arr2) {
}

void dotProduct(size_t n, double* result, double* arr1, double* arr2) {
    int i;
    for (i=0;i<n;i++) {
        result[i] += arr1[i] * arr2[i];
    }
}

void dotProduct(size_t n, double* result, double* arr1, double* arr2) {
    int i;
    for (i=0;i<n;i++) {
        result[i] += arr1[i] * arr2[i];
    }
}

int main() {
    const size_t N = 1 << 5;
    const size_t ARRAY_BYTES = N * sizeof(int);

    clock_t begin, end;

    double time_taken;
    double average_time;

    double* array1; 
    double* array2;
    double* answer1;
    double* answer2;
    array1 = (double*)malloc(N*sizeof(int));
    array2 = (double*)malloc(N*sizeof(int));
    answer1 = (double*)malloc(N*sizeof(int));

    int i;
    for (i=0; i<N;i++) {
        array1[i] = 1;
        array2[i] = 2;
    }

    dotProduct(N, answer1, array1, array2);
    
    int loop = 30;

    begin = clock();
        for(int j=0; j<loop; j++) {
            dotProduct(N, answer1, array1, array2);
        }
    end = clock();

    time_taken = ((double)(end-begin)) * 1e3 / CLOCKS_PER_SEC;
    average_time = time_taken / loop;
    
    printf("C functions takes %lf milliseconds for array size %zu \n", average_time, N);

// -------------x86-64-------------
    x8664(N, answer2, array1, array2);

    int loop = 30;

    begin = clock();
        for(int j=0; j<loop; j++) {
            dotProduct(N, answer2, array1, array2);
        }
    end = clock();

    time_taken = ((double)(end-begin)) * 1e3 / CLOCKS_PER_SEC;
    average_time = time_taken / loop;
    
    printf("C functions takes %lf milliseconds for array size %zu \n", average_time, N);

    free(array1);
    free(array2);
    free(answer2);

    return 0;

}