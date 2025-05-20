//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX 10

int A[MAX][MAX],B[MAX][MAX],C[MAX][MAX],M,N,P,Q;
int sum=0;

void *runner(void *param);

int main(int argc, char **argv)
{
    printf("Enter the number of rows and columns for first matrix: ");
    scanf("%d %d",&M,&N);

    printf("Enter the elements of first matrix:\n");
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }

    printf("Enter the number of rows and columns for second matrix: ");
    scanf("%d %d",&P,&Q);

    if(N!=P)
    {
        printf("Error! Incompatible dimensions for matrix multiplication.\n");
        exit(0);
    }

    printf("Enter the elements of second matrix:\n");
    for(int i=0;i<P;i++)
    {
        for(int j=0;j<Q;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }

    int max_threads = Q;
    pthread_t workers[max_threads];
    int rows_per_thread = N / max_threads;
    int remainder = N % max_threads;

    for(int i=0;i<max_threads;i++)
    {
        int start_row = i*rows_per_thread;
        int end_row = (i == max_threads - 1)? N : start_row + rows_per_thread - 1;

        pthread_create(&workers[i], NULL, runner, (void*)&start_row);
    }

    for(int i=0;i<max_threads;i++)
    {
        pthread_join(workers[i], NULL);
    }

    printf("Resultant Matrix:\n");
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<Q;j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void *runner(void *param)
{
    int start_row = *(int*)param;
    int end_row = start_row + (N/Q) - 1;

    for(int i=start_row;i<=end_row;i++)
    {
        for(int j=0;j<Q;j++)
        {
            for(int k=0;k<P;k++)
            {
                sum += A[i][k]*B[k][j];
            }
            C[i][j] = sum;
            sum = 0;
        }
    }

    return NULL;
}