//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 5
#define NUM_ROWS 5
#define NUM_COLS 5

int threadsRunning = 0;
int *bingoBoard;
int *numbers;

void* bingoThread(void* arg) {
    int threadId = (int)arg;
    int i, j;
    int *num = &numbers[threadId * (NUM_ROWS * NUM_COLS)];
    pthread_t *threads = (pthread_t *)arg;
    pthread_t *threadPool = (pthread_t *)arg;

    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            printf("%d ", *num);
            num++;
        }
        printf("\n");
    }

    printf("Thread %d: Bingo!\n", threadId);

    pthread_exit(NULL);
}

void fillBoard() {
    int i, j;
    int num;

    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            num = rand() % 75;
            bingoBoard[i * NUM_COLS + j] = num;
            if (num == 1 || num == 2 || num == 3 || num == 4 || num == 5) {
                printf("%d ", num);
            }
        }
        printf("\n");
    }
}

int main() {
    pthread_t *threadPool;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    pthread_t *threads = (pthread_t *)malloc(MAX_THREADS * sizeof(pthread_t));

    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        int j = (i * (NUM_ROWS * NUM_COLS)) % 75;
        int num = 75 - j;
        bingoBoard = (int *)malloc(NUM_ROWS * NUM_COLS * sizeof(int));
        numbers = (int *)malloc((NUM_ROWS * NUM_COLS) * sizeof(int));
        threads[i] = pthread_create(&threadPool[i], &attr, bingoThread, (void *)&i);
    }

    fillBoard();
    printf("Bingo!\n");

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}