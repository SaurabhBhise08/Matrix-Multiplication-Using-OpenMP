#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(int argc, char* argv[]) {

    int i, j, k, result = 0;
    int size_matrix;
    int **a;
    int **b;
    int **c;
    double total_time;
    clock_t start, end;

    /* Get number of size_matrix */
    size_matrix = atoi(argv[1]);

    
    /* Dynamic memory allocation for the matrices */
    a = (int**)malloc(size_matrix * sizeof(int*));
    b = (int**)malloc(size_matrix * sizeof(int*));
    c = (int**)malloc(size_matrix * sizeof(int*));

    for(i = 0; i < size_matrix; i++){
        a[i] = (int*)malloc(size_matrix * sizeof(int));
        b[i] = (int*)malloc(size_matrix * sizeof(int));
        c[i] = (int*)malloc(size_matrix * sizeof(int));
    } 

    /* Generating matrices */
    srand(time(NULL));
    for(i = 0; i < size_matrix; i++){
        for (j = 0; j < size_matrix; j++) {
            a[i][j] = rand() % 100;
            b[i][j] = rand() % 100;
            c[i][j] = -1;
        }
    } 

    /* Calculating start time */
    start = clock(); // start time counting

    /* Performing multiplication of the matrices */
    for (i = 0; i < size_matrix; i++) {
        for (j = 0; j < size_matrix; j++) {
            for (k = 0; k < size_matrix; k++) {
                result += a[i][k] * b[k][j];
            }
            c[i][j] = result;
            result = 0;
        }
    } 

    /*Calculating end time */
    end = clock();
    
   total_time = (double) (end - start) / CLOCKS_PER_SEC;
   printf("Matrix Size = %d --> Execution Time = %f\n", size_matrix, total_time);
    
}