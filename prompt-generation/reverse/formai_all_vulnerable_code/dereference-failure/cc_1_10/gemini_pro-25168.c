//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Define the shared memory segment size
#define SHM_SIZE 1024

// Define the shared memory segment key
#define SHM_KEY 1234

int main() {
  // Create the shared memory segment
  int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
  if (shm_id == -1) {
    perror("shmget");
    exit(1);
  }

  // Attach the shared memory segment to the current process
  void *shm_ptr = shmat(shm_id, NULL, 0);
  if (shm_ptr == (void *)-1) {
    perror("shmat");
    exit(1);
  }

  // Write data to the shared memory segment
  char *message = "Hello from the parent process!";
  memcpy(shm_ptr, message, strlen(message) + 1);

  // Detach the shared memory segment from the current process
  if (shmdt(shm_ptr) == -1) {
    perror("shmdt");
    exit(1);
  }

  // Fork a child process
  pid_t child_pid = fork();
  if (child_pid == -1) {
    perror("fork");
    exit(1);
  }

  // In the child process, read data from the shared memory segment
  if (child_pid == 0) {
    // Attach the shared memory segment to the child process
    shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
      perror("shmat");
      exit(1);
    }

    // Read data from the shared memory segment
    char *message = shm_ptr;
    printf("Message from the parent process: %s\n", message);

    // Detach the shared memory segment from the child process
    if (shmdt(shm_ptr) == -1) {
      perror("shmdt");
      exit(1);
    }

    exit(0);
  }

  // In the parent process, wait for the child process to finish
  int status;
  wait(&status);

  // Remove the shared memory segment
  if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
    perror("shmctl");
    exit(1);
  }

  return 0;
}