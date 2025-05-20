//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_PLAYERS 2
#define NUM_BAGS 5
#define MAX_QUEUE_SIZE 10

typedef struct {
    int bag_id;
    int player_id;
} Bag;

typedef struct {
    pthread_mutex_t lock;
    int queue[NUM_BAGS];
    int head;
    int tail;
} Queue;

Queue queue[NUM_PLAYERS];

void* process_bags(void* args);

int main() {
    pthread_t threads[NUM_PLAYERS];
    int i;
    for (i = 0; i < NUM_PLAYERS; i++) {
        pthread_create(&threads[i], NULL, process_bags, (void*)i);
    }
    for (i = 0; i < NUM_PLAYERS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}

void* process_bags(void* args) {
    int player_id = *(int*)args;
    Bag bags[NUM_BAGS];
    int i;
    for (i = 0; i < NUM_BAGS; i++) {
        bags[i].bag_id = rand() % NUM_BAGS;
        bags[i].player_id = player_id;
    }
    for (i = 0; i < NUM_BAGS; i++) {
        queue[player_id].queue[i] = bags[i].bag_id;
        queue[player_id].head = i;
    }
    pthread_mutex_lock(&queue[player_id].lock);
    int num_bags = queue[player_id].head;
    for (i = 0; i < num_bags; i++) {
        printf("Bag %d is ready to be picked up by Player %d\n",
               queue[player_id].queue[i], player_id);
        sleep(1);
    }
    pthread_mutex_unlock(&queue[player_id].lock);
    return NULL;
}