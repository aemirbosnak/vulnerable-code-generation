//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Structure to store the state of each room
typedef struct {
    char name[32];  // Name of the room
    int num_visitors;  // Number of visitors currently in the room
    pthread_mutex_t lock;  // Mutex to protect the room's state
} room;

// Array of rooms
room rooms[] = {
    { "Foyer", 0, PTHREAD_MUTEX_INITIALIZER },
    { "Living Room", 0, PTHREAD_MUTEX_INITIALIZER },
    { "Dining Room", 0, PTHREAD_MUTEX_INITIALIZER },
    { "Kitchen", 0, PTHREAD_MUTEX_INITIALIZER },
    { "Master Bedroom", 0, PTHREAD_MUTEX_INITIALIZER },
    { "Guest Bedroom", 0, PTHREAD_MUTEX_INITIALIZER },
    { "Bathroom", 0, PTHREAD_MUTEX_INITIALIZER },
};

// Number of rooms
const int num_rooms = sizeof(rooms) / sizeof(rooms[0]);

// Function to simulate a visitor entering a room
void *visitor_enter(void *arg) {
    // Get the room number
    int room_num = *(int *)arg;
    free(arg);

    // Acquire the lock for the room
    pthread_mutex_lock(&rooms[room_num].lock);

    // Increment the number of visitors in the room
    rooms[room_num].num_visitors++;

    // Print a message to indicate that the visitor has entered the room
    printf("Visitor entered %s. (%d visitors now present)\n", rooms[room_num].name, rooms[room_num].num_visitors);

    // Release the lock for the room
    pthread_mutex_unlock(&rooms[room_num].lock);

    // Sleep for a random amount of time to simulate the visitor exploring the room
    sleep(rand() % 5 + 1);

    // Acquire the lock for the room again
    pthread_mutex_lock(&rooms[room_num].lock);

    // Decrement the number of visitors in the room
    rooms[room_num].num_visitors--;

    // Print a message to indicate that the visitor has left the room
    printf("Visitor left %s. (%d visitors now present)\n", rooms[room_num].name, rooms[room_num].num_visitors);

    // Release the lock for the room
    pthread_mutex_unlock(&rooms[room_num].lock);

    return NULL;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a thread for each visitor
    pthread_t threads[num_rooms * 10];
    for (int i = 0; i < num_rooms * 10; i++) {
        // Get a random room number
        int *room_num = malloc(sizeof(int));
        *room_num = rand() % num_rooms;

        // Create a thread to simulate the visitor entering the room
        pthread_create(&threads[i], NULL, visitor_enter, room_num);
    }

    // Join all the threads
    for (int i = 0; i < num_rooms * 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}