//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

#define ROOM_COUNT 5
#define GHOST_COUNT 3

pthread_t ghosts[GHOST_COUNT];
pthread_mutex_t room_mutex[ROOM_COUNT];
bool is_running = true;

void* haunt_room(void *arg) {
    int room_num = *(int*)arg;
    while(is_running) {
        sleep(1);
        printf("Ghost %ld is haunting room %d\n", pthread_self(), room_num);
        pthread_mutex_lock(&room_mutex[room_num]);
        printf("Ghost %ld has entered room %d\n", pthread_self(), room_num);
        sleep(3);
        printf("Ghost %ld is leaving room %d\n", pthread_self(), room_num);
        pthread_mutex_unlock(&room_mutex[room_num]);
    }
    return NULL;
}

int main() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("----------------------------------------\n");
    
    for(int i=0; i<ROOM_COUNT; i++) {
        pthread_mutex_init(&room_mutex[i], NULL);
    }
    
    for(int i=0; i<GHOST_COUNT; i++) {
        int *room_num = malloc(sizeof(int));
        *room_num = i % ROOM_COUNT;
        pthread_create(&ghosts[i], NULL, &haunt_room, room_num);
    }
    
    printf("Press any key to stop the simulation...\n");
    getchar();
    
    is_running = false;
    
    for(int i=0; i<GHOST_COUNT; i++) {
        pthread_join(ghosts[i], NULL);
    }
    
    for(int i=0; i<ROOM_COUNT; i++) {
        pthread_mutex_destroy(&room_mutex[i]);
    }
    
    printf("\nSimulation complete. Thank you for participating!\n");
    return 0;
}