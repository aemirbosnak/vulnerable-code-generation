//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PLAYERS 4
#define MEMORY_SIZE 1024
#define MAX_OBJ 100

struct player {
    char name[50];
    int score;
    void* memory;
};

struct object {
    char value;
    struct object* next;
};

int main() {
    // Create shared memory for players
    key_t key = IPC_PRIVATE;
    int shm_id = shmget(key, MEMORY_SIZE, IPC_CREAT | 0644);
    if (shm_id == -1) {
        perror("shmget() failed");
        return 1;
    }

    // Create players
    struct player players[PLAYERS];
    for (int i = 0; i < PLAYERS; i++) {
        players[i].name[0] = 'P';
        players[i].score = 0;
        players[i].memory = mmap(NULL, MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_id, i * MEMORY_SIZE);
        if (players[i].memory == MAP_FAILED) {
            perror("mmap() failed");
            return 1;
        }
    }

    // Create objects
    struct object* objects = NULL;
    for (int i = 0; i < MAX_OBJ; i++) {
        objects = realloc(objects, sizeof(struct object) * (i + 1));
        objects[i].value = 'A' + (i % 26);
        objects[i].next = NULL;
    }

    // Start game loop
    while (1) {
        // Update players' scores
        for (int i = 0; i < PLAYERS; i++) {
            players[i].score += objects[i % MAX_OBJ].value;
        }

        // Print scores
        for (int i = 0; i < PLAYERS; i++) {
            printf("Player %c has score %d\n", players[i].name, players[i].score);
        }

        // Add new objects
        for (int i = 0; i < PLAYERS; i++) {
            struct object* new_object = malloc(sizeof(struct object));
            new_object->value = 'A' + (i % 26);
            new_object->next = objects;
            objects = new_object;
        }

        // Sleep for a bit
        sleep(1);
    }

    // Clean up
    for (int i = 0; i < PLAYERS; i++) {
        munmap(players[i].memory, MEMORY_SIZE);
    }
    free(objects);
    shmctl(shm_id, IPC_RMID, 0);

    return 0;
}