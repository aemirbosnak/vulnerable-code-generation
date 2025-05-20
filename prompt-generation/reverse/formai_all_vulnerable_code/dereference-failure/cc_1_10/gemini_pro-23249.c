//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
  int shmid;
  char *shm_addr;
  pid_t pid;

  // Create shared memory segment
  shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
  if (shmid == -1) {
    perror("shmget");
    exit(EXIT_FAILURE);
  }

  // Attach shared memory segment to process's address space
  shm_addr = shmat(shmid, NULL, 0);
  if (shm_addr == (void *)-1) {
    perror("shmat");
    exit(EXIT_FAILURE);
  }

  // Create child process
  pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid == 0) { // Child process
    // Write data to shared memory segment
    strcpy(shm_addr, "Hello from child");

    // Wait for parent process to finish
    while (*shm_addr != '\0') {
      sleep(1);
    }

    // Detach shared memory segment from process's address space
    if (shmdt(shm_addr) == -1) {
      perror("shmdt");
      exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
  } else { // Parent process
    // Wait for child process to finish
    wait(NULL);

    // Read data from shared memory segment
    printf("Data received from child: %s\n", shm_addr);

    // Detach shared memory segment from process's address space
    if (shmdt(shm_addr) == -1) {
      perror("shmdt");
      exit(EXIT_FAILURE);
    }

    // Destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
      perror("shmctl");
      exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
  }

  return 0;
}