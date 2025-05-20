//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Define the size of the shared memory segment
#define SHM_SIZE 1024

// Define the key for the shared memory segment
#define SHM_KEY 1234

// Define the message to be sent
#define MESSAGE "Hello from the parent process!"

int main() {
  // Create a shared memory segment
  int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
  if (shm_id == -1) {
    perror("shmget");
    exit(1);
  }

  // Attach the shared memory segment to the parent process
  void *shm_ptr = shmat(shm_id, NULL, 0);
  if (shm_ptr == (void *)-1) {
    perror("shmat");
    exit(1);
  }

  // Create a child process
  pid_t child_pid = fork();
  if (child_pid == -1) {
    perror("fork");
    exit(1);
  }

  // Parent process
  if (child_pid > 0) {
    // Copy the message to the shared memory segment
    memcpy(shm_ptr, MESSAGE, strlen(MESSAGE) + 1);

    // Wait for the child process to finish
    wait(NULL);

    // Detach the shared memory segment from the parent process
    shmdt(shm_ptr);

    // Destroy the shared memory segment
    shmctl(shm_id, IPC_RMID, NULL);
  }
  // Child process
  else {
    // Attach the shared memory segment to the child process
    void *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
      perror("shmat");
      exit(1);
    }

    // Read the message from the shared memory segment
    char *message = shm_ptr;

    // Print the message
    printf("Received message from the parent process: %s\n", message);

    // Detach the shared memory segment from the child process
    shmdt(shm_ptr);
  }

  return 0;
}