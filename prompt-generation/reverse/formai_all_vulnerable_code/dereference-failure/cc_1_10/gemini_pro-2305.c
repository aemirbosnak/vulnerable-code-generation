//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Hotel room structure
typedef struct room {
    int room_number;
    int is_occupied;
    pthread_mutex_t lock;
} room;

// Hotel data structure
typedef struct hotel {
    int num_rooms;
    room *rooms;
    pthread_mutex_t lock;
} hotel;

// Thread function to handle guest check-in
void *check_in(void *arg) {
    hotel *h = (hotel *)arg;

    // Acquire the hotel lock
    pthread_mutex_lock(&h->lock);

    // Find an unoccupied room
    int i;
    for (i = 0; i < h->num_rooms; i++) {
        if (h->rooms[i].is_occupied == 0) {
            break;
        }
    }

    // If no unoccupied room is found, return an error
    if (i == h->num_rooms) {
        printf("No unoccupied rooms available.\n");
        pthread_mutex_unlock(&h->lock);
        return NULL;
    }

    // Mark the room as occupied
    h->rooms[i].is_occupied = 1;

    // Release the hotel lock
    pthread_mutex_unlock(&h->lock);

    // Acquire the room lock
    pthread_mutex_lock(&h->rooms[i].lock);

    // Print the check-in message
    printf("Guest checked in to room %d.\n", h->rooms[i].room_number);

    // Release the room lock
    pthread_mutex_unlock(&h->rooms[i].lock);

    return NULL;
}

// Thread function to handle guest check-out
void *check_out(void *arg) {
    hotel *h = (hotel *)arg;

    // Acquire the hotel lock
    pthread_mutex_lock(&h->lock);

    // Find the guest's room
    int room_number;
    printf("Enter the room number of the guest checking out: ");
    scanf("%d", &room_number);

    // If the room number is invalid, return an error
    if (room_number < 0 || room_number >= h->num_rooms) {
        printf("Invalid room number.\n");
        pthread_mutex_unlock(&h->lock);
        return NULL;
    }

    // Acquire the room lock
    pthread_mutex_lock(&h->rooms[room_number].lock);

    // Mark the room as unoccupied
    h->rooms[room_number].is_occupied = 0;

    // Release the room lock
    pthread_mutex_unlock(&h->rooms[room_number].lock);

    // Release the hotel lock
    pthread_mutex_unlock(&h->lock);

    // Print the check-out message
    printf("Guest checked out of room %d.\n", room_number);

    return NULL;
}

// Main function
int main() {
    // Create the hotel
    hotel h;
    h.num_rooms = 10;
    h.rooms = malloc(sizeof(room) * h.num_rooms);
    for (int i = 0; i < h.num_rooms; i++) {
        h.rooms[i].room_number = i + 1;
        h.rooms[i].is_occupied = 0;
        pthread_mutex_init(&h.rooms[i].lock, NULL);
    }
    pthread_mutex_init(&h.lock, NULL);

    // Create the threads
    pthread_t check_in_thread, check_out_thread;
    pthread_create(&check_in_thread, NULL, check_in, &h);
    pthread_create(&check_out_thread, NULL, check_out, &h);

    // Join the threads
    pthread_join(check_in_thread, NULL);
    pthread_join(check_out_thread, NULL);

    // Destroy the hotel
    for (int i = 0; i < h.num_rooms; i++) {
        pthread_mutex_destroy(&h.rooms[i].lock);
    }
    pthread_mutex_destroy(&h.lock);
    free(h.rooms);

    return 0;
}