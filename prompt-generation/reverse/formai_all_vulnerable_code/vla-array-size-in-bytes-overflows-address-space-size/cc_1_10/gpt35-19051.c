//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int numDisks;
int movesCount = 0;

pthread_mutex_t mutex;
pthread_cond_t cond;

struct Tower {
    int top;
    int* disks;
};

struct Tower source, dest, aux;

void printTower(char rodName, struct Tower tower) {
    printf("Rod %c: ", rodName);

    for (int i = 0; i < tower.top; i++) {
        printf("%d ", tower.disks[i]);
    }

    printf("\n");
}

void pushDisk(struct Tower* tower, int disk) {
    tower->disks[tower->top++] = disk;
}

int popDisk(struct Tower* tower) {
    return tower->disks[--tower->top];
}

void moveDisk(struct Tower* source, struct Tower* dest) {
    int disk = popDisk(source);
    pushDisk(dest, disk);
    movesCount++;
    printf("Move %d: Move disk %d from source to destination\n", movesCount, disk);
    printTower('A', source[0]);
    printTower('B', dest[0]);
    printf("\n");
}

void* towerOfHanoi(void* arg) {
    int disk = *(int*)arg;

    while (1) {
        pthread_mutex_lock(&mutex);

        while (source.top <= 0) {
            if (movesCount == (1 << numDisks) - 1) {
                pthread_mutex_unlock(&mutex);
                return NULL;
            }

            pthread_cond_wait(&cond, &mutex);
        }

        moveDisk(&source, &dest);
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    printf("Enter number of disks: ");
    scanf("%d", &numDisks);

    source.top = dest.top = aux.top = 0;
    source.disks = (int*)malloc(sizeof(int) * numDisks);
    dest.disks = (int*)malloc(sizeof(int) * numDisks);
    aux.disks = (int*)malloc(sizeof(int) * numDisks);

    for (int i = numDisks; i >= 1; i--) {
        pushDisk(&source, i);
    }

    pthread_t tid[numDisks];

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    for (int i = 0; i < numDisks; i++) {
        pthread_create(&tid[i], NULL, towerOfHanoi, &source.disks[i]);
    }

    for (int i = 0; i < numDisks; i++) {
        pthread_join(tid[i], NULL);
    }

    printf("Total moves: %d\n", movesCount);

    free(source.disks);
    free(dest.disks);
    free(aux.disks);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}