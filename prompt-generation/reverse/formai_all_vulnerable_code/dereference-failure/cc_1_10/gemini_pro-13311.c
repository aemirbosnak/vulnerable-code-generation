//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define SHARED_MEM_SIZE 1024

int main() {
  // Create a shared memory segment
  int shm_id = shmget(IPC_PRIVATE, SHARED_MEM_SIZE, IPC_CREAT | IPC_EXCL | 0666);
  if (shm_id == -1) {
    perror("shmget");
    exit(EXIT_FAILURE);
  }

  // Attach the shared memory segment to the address space of this process
  void *shm_ptr = shmat(shm_id, NULL, 0);
  if (shm_ptr == MAP_FAILED) {
    perror("shmat");
    exit(EXIT_FAILURE);
  }

  // Create a child process
  pid_t child_pid = fork();
  if (child_pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (child_pid == 0) {
    // Child process writes to the shared memory segment
    char *message = "Hello from the child process!";
    memcpy(shm_ptr, message, strlen(message) + 1);
    printf("Child process wrote message to shared memory: %s\n", message);
  } else {
    // Parent process waits for the child process to finish
    wait(NULL);

    // Parent process reads from the shared memory segment
    char *message = shm_ptr;
    printf("Parent process read message from shared memory: %s\n", message);

    // Detach the shared memory segment from the address space of this process
    if (shmdt(shm_ptr) == -1) {
      perror("shmdt");
      exit(EXIT_FAILURE);
    }

    // Remove the shared memory segment
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
      perror("shmctl");
      exit(EXIT_FAILURE);
    }
  }

  return EXIT_SUCCESS;
}