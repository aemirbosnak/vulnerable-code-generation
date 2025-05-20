//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Define the size of the shared memory segment
#define SHM_SIZE 1024

int main() {
  // Create a shared memory segment
  int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | IPC_EXCL | 0666);
  if (shm_id == -1) {
    perror("shmget");
    return 1;
  }

  // Attach the shared memory segment to the address space of the current process
  void *shm_ptr = shmat(shm_id, NULL, 0);
  if (shm_ptr == (void *)-1) {
    perror("shmat");
    return 1;
  }

  // Write some data to the shared memory segment
  char *message = "Hello, world!";
  memcpy(shm_ptr, message, strlen(message) + 1);

  // Fork a child process
  pid_t child_pid = fork();
  if (child_pid == -1) {
    perror("fork");
    return 1;
  }

  if (child_pid == 0) {
    // Child process

    // Read the data from the shared memory segment
    char *message = shm_ptr;
    printf("Child process: %s\n", message);

    // Detach the shared memory segment from the address space of the current process
    if (shmdt(shm_ptr) == -1) {
      perror("shmdt");
      return 1;
    }

    // Exit the child process
    exit(0);
  } else {
    // Parent process

    // Wait for the child process to finish
    int status;
    waitpid(child_pid, &status, 0);

    // Detach the shared memory segment from the address space of the current process
    if (shmdt(shm_ptr) == -1) {
      perror("shmdt");
      return 1;
    }

    // Remove the shared memory segment
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
      perror("shmctl");
      return 1;
    }
  }

  return 0;
}