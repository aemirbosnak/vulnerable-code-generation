//GEMINI-pro DATASET v1.0 Category: System administration ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/msg.h>

int main() {
  // Create a shared memory segment
  int shm_id = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
  if (shm_id == -1) {
    perror("shmget");
    return EXIT_FAILURE;
  }

  // Attach the shared memory segment to the current process
  void *shm_addr = shmat(shm_id, NULL, 0);
  if (shm_addr == (void *)-1) {
    perror("shmat");
    return EXIT_FAILURE;
  }

  // Create a child process
  pid_t child_pid = fork();
  if (child_pid == -1) {
    perror("fork");
    return EXIT_FAILURE;
  }

  if (child_pid == 0) {
    // Child process
    printf("Child process writing to shared memory\n");

    // Write to the shared memory segment
    strcpy(shm_addr, "Hello from the child process!");

    // Detach the shared memory segment from the child process
    shmdt(shm_addr);

    // Exit the child process
    exit(EXIT_SUCCESS);
  } else {
    // Parent process
    wait(NULL);
    printf("Parent process reading from shared memory\n");

    // Read from the shared memory segment
    printf("%s\n", shm_addr);

    // Detach the shared memory segment from the parent process
    shmdt(shm_addr);

    // Remove the shared memory segment
    shmctl(shm_id, IPC_RMID, NULL);
  }

  return EXIT_SUCCESS;
}