//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// Define the maximum number of guests
#define MAX_GUESTS 10

// Define the hotel's rooms
struct room {
  int room_number;
  int is_occupied;
};

// Define the hotel's guests
struct guest {
  int guest_id;
  int room_number;
  int is_checked_in;
};

// Define the hotel's threads
struct thread_args {
  int thread_id;
  struct hotel *hotel;
};

// Define the hotel's semaphores
sem_t check_in_semaphore;
sem_t check_out_semaphore;

// Define the hotel's mutexes
pthread_mutex_t room_mutex;

// Define the hotel's structure
struct hotel {
  struct room rooms[MAX_GUESTS];
  struct guest guests[MAX_GUESTS];
};

// Initialize the hotel
void hotel_init(struct hotel *hotel) {
  for (int i = 0; i < MAX_GUESTS; i++) {
    hotel->rooms[i].room_number = i;
    hotel->rooms[i].is_occupied = 0;
    hotel->guests[i].guest_id = -1;
    hotel->guests[i].room_number = -1;
    hotel->guests[i].is_checked_in = 0;
  }
}

// Check in a guest
void guest_check_in(struct hotel *hotel, struct guest *guest) {
  sem_wait(&check_in_semaphore);
  pthread_mutex_lock(&room_mutex);

  // Find an available room
  for (int i = 0; i < MAX_GUESTS; i++) {
    if (hotel->rooms[i].is_occupied == 0) {
      hotel->rooms[i].is_occupied = 1;
      guest->room_number = hotel->rooms[i].room_number;
      guest->is_checked_in = 1;
      break;
    }
  }

  pthread_mutex_unlock(&room_mutex);
  sem_post(&check_in_semaphore);
}

// Check out a guest
void guest_check_out(struct hotel *hotel, struct guest *guest) {
  sem_wait(&check_out_semaphore);
  pthread_mutex_lock(&room_mutex);

  // Find the guest's room
  for (int i = 0; i < MAX_GUESTS; i++) {
    if (hotel->guests[i].guest_id == guest->guest_id) {
      hotel->rooms[i].is_occupied = 0;
      guest->room_number = -1;
      guest->is_checked_in = 0;
      break;
    }
  }

  pthread_mutex_unlock(&room_mutex);
  sem_post(&check_out_semaphore);
}

// Thread function
void *thread_main(void *args) {
  struct thread_args *thread_args = (struct thread_args *)args;

  // Get the hotel
  struct hotel *hotel = thread_args->hotel;

  // Create a guest
  struct guest guest;
  guest.guest_id = thread_args->thread_id;

  // Check in the guest
  guest_check_in(hotel, &guest);

  // Sleep for a random amount of time
  sleep(rand() % 10);

  // Check out the guest
  guest_check_out(hotel, &guest);

  // Exit the thread
  pthread_exit(NULL);
}

// Main function
int main(int argc, char *argv[]) {
  // Initialize the hotel
  struct hotel hotel;
  hotel_init(&hotel);

  // Initialize the semaphores
  sem_init(&check_in_semaphore, 0, 1);
  sem_init(&check_out_semaphore, 0, 1);

  // Initialize the mutexes
  pthread_mutex_init(&room_mutex, NULL);

  // Create the threads
  pthread_t threads[MAX_GUESTS];
  for (int i = 0; i < MAX_GUESTS; i++) {
    struct thread_args *thread_args = malloc(sizeof(struct thread_args));
    thread_args->thread_id = i;
    thread_args->hotel = &hotel;
    pthread_create(&threads[i], NULL, thread_main, (void *)thread_args);
  }

  // Join the threads
  for (int i = 0; i < MAX_GUESTS; i++) {
    pthread_join(threads[i], NULL);
  }

  // Destroy the semaphores
  sem_destroy(&check_in_semaphore);
  sem_destroy(&check_out_semaphore);

  // Destroy the mutexes
  pthread_mutex_destroy(&room_mutex);

  return 0;
}