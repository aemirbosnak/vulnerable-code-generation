//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_ROOMS 5
#define NUM_GHOSTS 3
#define NIGHT_DURATION 5

pthread_mutex_t room_mutexes[NUM_ROOMS];
int room_status[NUM_ROOMS] = {0}; // 0: empty, 1: occupied by ghost

void* ghost_activity(void* arg) {
    int ghost_id = *((int*)arg);
    free(arg);

    while (1) {
        int room_to_scare = rand() % NUM_ROOMS;
        pthread_mutex_lock(&room_mutexes[room_to_scare]);

        if (room_status[room_to_scare] == 0) {
            room_status[room_to_scare] = 1;
            printf("Ghost %d has entered Room %d!\n", ghost_id, room_to_scare);
            sleep(1); // Scaring time
            room_status[room_to_scare] = 0;
            printf("Ghost %d has left Room %d...\n", ghost_id, room_to_scare);
        } else {
            printf("Ghost %d found Room %d occupied!\n", ghost_id, room_to_scare);
        }

        pthread_mutex_unlock(&room_mutexes[room_to_scare]);
        sleep(rand() % 3 + 1); // Wait before next activity
    }
}

void* simulate_night(void* arg) {
    printf("The haunting night has begun!\n");
    sleep(NIGHT_DURATION);
    printf("The night is over; morning is coming!\n");
    exit(0);
}

int main() {
    srand(time(NULL));
    pthread_t ghosts[NUM_GHOSTS];
    pthread_t night_thread;

    // Initialize mutexes for rooms
    for (int i = 0; i < NUM_ROOMS; ++i) {
        pthread_mutex_init(&room_mutexes[i], NULL);
    }

    // Create ghosts
    for (int i = 0; i < NUM_GHOSTS; ++i) {
        int* ghost_id = malloc(sizeof(int));
        *ghost_id = i;
        if (pthread_create(&ghosts[i], NULL, ghost_activity, ghost_id) != 0) {
            perror("Failed to create ghost thread");
            exit(EXIT_FAILURE);
        }
    }

    // Create night simulation thread
    if (pthread_create(&night_thread, NULL, simulate_night, NULL) != 0) {
        perror("Failed to create night thread");
        exit(EXIT_FAILURE);
    }

    // Wait for the night simulation to finish
    pthread_join(night_thread, NULL);

    // Cleanup: join ghost threads
    for (int i = 0; i < NUM_GHOSTS; ++i) {
        pthread_cancel(ghosts[i]);
        pthread_join(ghosts[i], NULL);
    }

    // Destroy mutexes
    for (int i = 0; i < NUM_ROOMS; ++i) {
        pthread_mutex_destroy(&room_mutexes[i]);
    }

    return 0;
}