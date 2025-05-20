//FormAI DATASET v1.0 Category: Matrix operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NTHREADS 4

typedef struct{
    int **matrix;
    int size;
    int scalar;
} MatrixOperation;

void* matrix_sum(void* arg){
    MatrixOperation *mo = (MatrixOperation*) arg;
    int sum = 0;
    int i, j;

    for(i=0; i<mo->size; i++){
        for(j=0; j<mo->size; j++){
            sum += mo->matrix[i][j];
        }
    }

    printf("The sum of all elements is: %d\n", sum);

    pthread_exit(NULL);
}

void* matrix_scalar_multiplication(void* arg){
    MatrixOperation *mo = (MatrixOperation*) arg;
    int i, j;

    for(i=0; i<mo->size; i++){
        for(j=0; j<mo->size; j++){
            mo->matrix[i][j] *= mo->scalar;
        }
    }

    printf("The matrix after scalar multiplication is:\n");

    for(i=0; i<mo->size; i++){
        for(j=0; j<mo->size; j++){
            printf("%d ", mo->matrix[i][j]);
        }
        printf("\n");
    }

    pthread_exit(NULL);
}

void* matrix_transpose(void* arg){
    MatrixOperation *mo = (MatrixOperation*) arg;
    int i, j;
    int **new_matrix = (int**) malloc(mo->size * sizeof(int*));

    for(i=0; i<mo->size; i++){
        new_matrix[i] = (int*) malloc(mo->size * sizeof(int));
    }

    for(i=0; i<mo->size; i++){
        for(j=0; j<mo->size; j++){
            new_matrix[j][i] = mo->matrix[i][j];
        }
    }

    printf("The transposed matrix is:\n");

    for(i=0; i<mo->size; i++){
        for(j=0; j<mo->size; j++){
            printf("%d ", new_matrix[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<mo->size; i++){
        free(new_matrix[i]);
    }
    free(new_matrix);

    pthread_exit(NULL);
}

void* matrix_multiplication(void* arg){
    MatrixOperation *mo = (MatrixOperation*) arg;
    int i, j, k;
    int **new_matrix = (int**) malloc(mo->size * sizeof(int*));

    for(i=0; i<mo->size; i++){
        new_matrix[i] = (int*) malloc(mo->size * sizeof(int));
    }

    for(i=0; i<mo->size; i++){
        for(j=0; j<mo->size; j++){
            new_matrix[i][j] = 0;
            for(k=0; k<mo->size; k++){
                new_matrix[i][j] += mo->matrix[i][k] * mo->matrix[k][j];
            }
        }
    }

    printf("The multiplied matrix is:\n");

    for(i=0; i<mo->size; i++){
        for(j=0; j<mo->size; j++){
            printf("%d ", new_matrix[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<mo->size; i++){
        free(new_matrix[i]);
    }
    free(new_matrix);

    pthread_exit(NULL);
}

int main(){
    int i, j;
    int **matrix;
    pthread_t threads[NTHREADS];
    MatrixOperation mos[NTHREADS];

    matrix = (int**) malloc(3 * sizeof(int*));
    for(i=0; i<3; i++){
        matrix[i] = (int*) malloc(3 * sizeof(int));
    }

    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;

    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;

    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;

    for(i=0; i<NTHREADS; i++){
        mos[i].matrix = matrix;
        mos[i].size = 3;

        if(i==0){
            pthread_create(&threads[i], NULL, matrix_sum, (void*) &mos[i]);
        } else if(i==1){
            mos[i].scalar = 2;
            pthread_create(&threads[i], NULL, matrix_scalar_multiplication, (void*) &mos[i]);
        } else if(i==2){
            pthread_create(&threads[i], NULL, matrix_transpose, (void*) &mos[i]);
        } else {
            pthread_create(&threads[i], NULL, matrix_multiplication, (void*) &mos[i]);
        }
    }

    for(i=0; i<NTHREADS; i++){
        pthread_join(threads[i], NULL);
    }

    for(i=0; i<3; i++){
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}