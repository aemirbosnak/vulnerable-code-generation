//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Resource to be shared by threads
int ammo = 100;

// Mutex to protect shared resource
pthread_mutex_t ammo_lock;

// Thread function to simulate scavengers
void* scavenge(void* arg) {
  int scavenger_id = *(int*)arg;

  while (1) {
    // Acquire lock to access shared resource
    pthread_mutex_lock(&ammo_lock);

    // Check if there is enough ammo to scavenge
    if (ammo > 0) {
      // Scavenge ammo
      int scavenged_ammo = rand() % 10;
      ammo -= scavenged_ammo;

      // Print scavenger's status
      printf("Scavenger %d scavenged %d ammo. Total ammo: %d\n", scavenger_id, scavenged_ammo, ammo);
    }

    // Release lock to allow other threads to access the resource
    pthread_mutex_unlock(&ammo_lock);

    // Sleep for a random time to simulate scavenging duration
    sleep(rand() % 5);
  }

  return NULL;
}

int main() {
  // Initialize the mutex
  pthread_mutex_init(&ammo_lock, NULL);

  // Create an array of thread IDs
  pthread_t scavengers[4];

  // Start four scavenger threads
  for (int i = 0; i < 4; i++) {
    int* id = malloc(sizeof(int));
    *id = i;
    pthread_create(&scavengers[i], NULL, scavenge, (void*)id);
  }

  // Join the threads to wait for them to complete
  for (int i = 0; i < 4; i++) {
    pthread_join(scavengers[i], NULL);
  }

  // Destroy the mutex
  pthread_mutex_destroy(&ammo_lock);

  return 0;
}