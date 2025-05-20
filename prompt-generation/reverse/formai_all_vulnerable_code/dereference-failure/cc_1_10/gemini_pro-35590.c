//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: multi-threaded
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

// Haunted house constants
#define NUM_ROOMS      10
#define NUM_THREADS    4

// Room types
#define ROOM_TYPE_NORMAL 0
#define ROOM_TYPE_SPECIAL 1

// Special room events
#define EVENT_GHOST 0
#define EVENT_CREAK 1

// Thread shared data
struct haunted_house {
    pthread_mutex_t lock;
    int num_visitors;  // Number of visitors currently in the house
    int rooms[NUM_ROOMS];  // Array of room types
    int events[NUM_ROOMS];  // Array of special room events
};

// Thread data
struct thread_data {
    struct haunted_house *house;
    int thread_id;
};

// Thread function
void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *)arg;

    // Acquire the house lock
    pthread_mutex_lock(&data->house->lock);

    // Visitor enters the house
    data->house->num_visitors++;

    // Visitor walks through the house
    for (int i = 0; i < NUM_ROOMS; i++) {
        // Check if the room is special
        if (data->house->rooms[i] == ROOM_TYPE_SPECIAL) {
            // Get the special room event
            int event = data->house->events[i];

            // Handle the special room event
            switch (event) {
                case EVENT_GHOST:
                    printf("Thread %d: Ghost!\n", data->thread_id);
                    break;
                case EVENT_CREAK:
                    printf("Thread %d: Creak!\n", data->thread_id);
                    break;
            }
        }
    }

    // Visitor leaves the house
    data->house->num_visitors--;

    // Release the house lock
    pthread_mutex_unlock(&data->house->lock);

    return NULL;
}

int main() {
    // Initialize the haunted house
    struct haunted_house house;
    pthread_mutex_init(&house.lock, NULL);
    house.num_visitors = 0;
    for (int i = 0; i < NUM_ROOMS; i++) {
        house.rooms[i] = ROOM_TYPE_NORMAL;
        house.events[i] = 0;
    }

    // Set up the special rooms
    house.rooms[2] = ROOM_TYPE_SPECIAL;
    house.events[2] = EVENT_GHOST;
    house.rooms[7] = ROOM_TYPE_SPECIAL;
    house.events[7] = EVENT_CREAK;

    // Create the threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        struct thread_data *data = malloc(sizeof(struct thread_data));
        data->house = &house;
        data->thread_id = i;
        pthread_create(&threads[i], NULL, thread_func, data);
    }

    // Wait for the threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&house.lock);

    return 0;
}