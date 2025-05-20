//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
  // Create a shared memory segment.
  int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | IPC_EXCL | 0666);
  if (shm_id == -1) {
    perror("shmget");
    return 1;
  }

  // Attach the shared memory segment to the current process.
  void *shm_addr = shmat(shm_id, NULL, 0);
  if (shm_addr == (void *)-1) {
    perror("shmat");
    return 1;
  }

  // Create a child process.
  pid_t child_pid = fork();
  if (child_pid == -1) {
    perror("fork");
    return 1;
  }

  // Parent process writes to shared memory.
  if (child_pid > 0) {
    // Write a message to shared memory.
    strcpy(shm_addr, "Hello from parent!");

    // Wait for the child process to finish.
    wait(NULL);

    // Detach the shared memory segment from the current process.
    if (shmdt(shm_addr) == -1) {
      perror("shmdt");
      return 1;
    }

    // Delete the shared memory segment.
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
      perror("shmctl");
      return 1;
    }
  }
  // Child process reads from shared memory.
  else {
    // Read the message from shared memory.
    printf("Hello from child: %s\n", shm_addr);

    // Detach the shared memory segment from the current process.
    if (shmdt(shm_addr) == -1) {
      perror("shmdt");
      return 1;
    }
  }

  return 0;
}