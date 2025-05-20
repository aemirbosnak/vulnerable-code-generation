//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define DISK_COUNT 10
#define TOWERS 3
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef struct {
    int top;
    char name[3];
} tower;

tower towers[TOWERS] = { {0, "A"}, {0, "B"}, {0, "C"} };

pthread_mutex_t mutex[TOWERS];

void move_disk(int from, int to) {
    if (from > 0 && towers[from - 1].top > 0 && towers[to].top > 0 &&
        towers[from - 1].top < towers[to].top &&
        towers[from - 1].top < DISK_COUNT && towers[to].top < DISK_COUNT) {
        printf("Moving disk %d from %s to %s\n", towers[from - 1].top, towers[from - 1].name, towers[to].name);
        pthread_mutex_lock(&mutex[from - 1]);
        towers[from - 1].top--;
        pthread_mutex_unlock(&mutex[from - 1]);
        pthread_mutex_lock(&mutex[to]);
        towers[to].top++;
        usleep(100000); // Sleep for a short time to simulate disk movement
        pthread_mutex_unlock(&mutex[to]);
    } else {
        printf("Invalid move, please try again.\n");
    }
}

void hanoi(int n, int from, int to, int aux) {
    if (n > 0) {
        hanoi(n - 1, from, aux, to);
        move_disk(from, to);
        hanoi(n - 1, aux, to, from);
    }
}

int main(int argc, char *argv[]) {
    int i;
    for (i = 0; i < TOWERS; i++) {
        pthread_mutex_init(&mutex[i], NULL);
        towers[i].top = -1;
        strcpy(towers[i].name, argv[i + 1]);
    }

    srand(time(NULL));

    hanoi(DISK_COUNT, 0, 2, 1);

    for (i = 0; i < TOWERS; i++) {
        pthread_mutex_destroy(&mutex[i]);
    }

    return 0;
}