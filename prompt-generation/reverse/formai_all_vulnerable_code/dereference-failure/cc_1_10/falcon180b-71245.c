//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_ENEMIES 10

void *enemy_attack(void *arg);

struct enemy {
    int id;
    int health;
    int attack;
};

struct enemy enemies[NUM_ENEMIES];

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < NUM_ENEMIES; i++) {
        enemies[i].id = i + 1;
        enemies[i].health = rand() % 100 + 1;
        enemies[i].attack = rand() % 50 + 1;
    }

    pthread_t threads[NUM_THREADS];
    int thread_id;
    for (thread_id = 0; thread_id < NUM_THREADS; thread_id++) {
        pthread_create(&threads[thread_id], NULL, enemy_attack, (void *)thread_id);
    }

    for (thread_id = 0; thread_id < NUM_THREADS; thread_id++) {
        pthread_join(threads[thread_id], NULL);
    }

    return 0;
}

void *enemy_attack(void *arg) {
    int thread_id = *((int *)arg);
    int i;
    for (i = 0; i < NUM_ENEMIES; i++) {
        if (enemies[i].id == thread_id) {
            printf("Enemy %d attacks with %d damage!\n", thread_id, enemies[i].attack);
            break;
        }
    }

    pthread_exit(NULL);
}