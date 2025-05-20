//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Hotel data
typedef struct hotel {
    int num_rooms;
    int num_guests;
    int* rooms;
    pthread_mutex_t lock;
} hotel_t;

// Guest data
typedef struct guest {
    int id;
    int room_num;
    hotel_t* hotel;
} guest_t;

// Function to initialize the hotel
void hotel_init(hotel_t* hotel, int num_rooms) {
    hotel->num_rooms = num_rooms;
    hotel->num_guests = 0;
    hotel->rooms = malloc(sizeof(int) * num_rooms);
    for (int i = 0; i < num_rooms; i++) {
        hotel->rooms[i] = 0;
    }
    pthread_mutex_init(&hotel->lock, NULL);
}

// Function to check in a guest
void guest_check_in(guest_t* guest) {
    pthread_mutex_lock(&guest->hotel->lock);
    for (int i = 0; i < guest->hotel->num_rooms; i++) {
        if (guest->hotel->rooms[i] == 0) {
            guest->room_num = i + 1;
            guest->hotel->rooms[i] = 1;
            guest->hotel->num_guests++;
            break;
        }
    }
    pthread_mutex_unlock(&guest->hotel->lock);
}

// Function to check out a guest
void guest_check_out(guest_t* guest) {
    pthread_mutex_lock(&guest->hotel->lock);
    guest->hotel->rooms[guest->room_num - 1] = 0;
    guest->hotel->num_guests--;
    pthread_mutex_unlock(&guest->hotel->lock);
}

// Function to run the hotel
void* hotel_run(void* arg) {
    hotel_t* hotel = (hotel_t*)arg;
    while (1) {
        // Check for guests waiting to check in
        pthread_mutex_lock(&hotel->lock);
        if (hotel->num_guests < hotel->num_rooms) {
            guest_t* guest = malloc(sizeof(guest_t));
            guest->id = rand() % 1000;
            guest->hotel = hotel;
            guest_check_in(guest);
            printf("Guest %d checked in to room %d.\n", guest->id, guest->room_num);
        }
        pthread_mutex_unlock(&hotel->lock);
        
        // Check for guests waiting to check out
        pthread_mutex_lock(&hotel->lock);
        if (hotel->num_guests > 0) {
            int guest_id = rand() % hotel->num_guests;
            guest_t* guest = malloc(sizeof(guest_t));
            guest->id = guest_id;
            guest->hotel = hotel;
            guest_check_out(guest);
            printf("Guest %d checked out of room %d.\n", guest->id, guest->room_num);
        }
        pthread_mutex_unlock(&hotel->lock);
        
        // Sleep for a while
        sleep(1);
    }
    return NULL;
}

int main() {
    // Initialize the hotel
    hotel_t hotel;
    hotel_init(&hotel, 10);
    
    // Create a thread to run the hotel
    pthread_t tid;
    pthread_create(&tid, NULL, hotel_run, &hotel);
    
    // Join the thread
    pthread_join(tid, NULL);
    
    return 0;
}