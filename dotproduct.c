#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dotProduct(int n, int* vecadd, int* arr1, int* arr2) {
    int i;
    int result;
    for (i=0;i<n;i++) {
        result += arr1[i] * arr2[i];
    }
}

int main() {
    const size_t N = 1 << 28;
    const size_t ARRAY_BYTES = N * sizeof(int);

    clock_t begin, end;
    double time_taken;
    double average_time;

    int* array1; 
    int* array2;
    int* answer;
    array1 = (int*)malloc(N*sizeof(int));
    array2 = (int*)malloc(N*sizeof(int));
    answer = (int*)malloc(N*sizeof(int));

    int i;
    for (i=0; i<N;i++) {
        array1[i] = 1;
        array2[i] = 2;
    }

    dotProduct(N, array1, array2, answer);
    
    int loop = 30;

    begin = clock();
        for(int j=0; j<loop; j++) {
            dotProduct(N, array1, array2, answer);
            time_taken = ((double)(end-begin)) * 1e3 / CLOCKS_PER_SEC;
        }
    end = clock();

    average_time = time_taken / loop;
    
    printf("C functions takes %lf milliseconds for array size %zu \n", average_time, N);

    free(array1);
    free(array2);
    free(answer);

    return 0;

}