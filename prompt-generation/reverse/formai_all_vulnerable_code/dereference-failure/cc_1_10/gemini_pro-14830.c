//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Define the size of the shared memory segment
#define SHM_SIZE 1024

// Define the key for the shared memory segment
#define SHM_KEY 1234

// Create a shared memory segment
int create_shared_memory() {
  // Create the shared memory segment
  int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
  if (shm_id == -1) {
    perror("shmget");
    exit(1);
  }

  // Return the shared memory segment ID
  return shm_id;
}

// Attach to a shared memory segment
void attach_to_shared_memory(int shm_id) {
  // Attach to the shared memory segment
  void *shm_ptr = shmat(shm_id, NULL, 0);
  if (shm_ptr == (void *)-1) {
    perror("shmat");
    exit(1);
  }

  // Use the shared memory segment
  printf("Attached to shared memory segment: %p\n", shm_ptr);
}

// Detach from a shared memory segment
void detach_from_shared_memory(void *shm_ptr) {
  // Detach from the shared memory segment
  if (shmdt(shm_ptr) == -1) {
    perror("shmdt");
    exit(1);
  }

  // Print a message to indicate that we have detached from the shared memory segment
  printf("Detached from shared memory segment\n");
}

// Delete a shared memory segment
void delete_shared_memory(int shm_id) {
  // Delete the shared memory segment
  if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
    perror("shmctl");
    exit(1);
  }

  // Print a message to indicate that we have deleted the shared memory segment
  printf("Deleted shared memory segment\n");
}

// Main function
int main() {
  // Create a shared memory segment
  int shm_id = create_shared_memory();

  // Attach to the shared memory segment
  attach_to_shared_memory(shm_id);

  // Use the shared memory segment
  char *shm_ptr = shmat(shm_id, NULL, 0);
  strcpy(shm_ptr, "Hello, world!");

  // Detach from the shared memory segment
  detach_from_shared_memory(shm_ptr);

  // Delete the shared memory segment
  delete_shared_memory(shm_id);

  return 0;
}