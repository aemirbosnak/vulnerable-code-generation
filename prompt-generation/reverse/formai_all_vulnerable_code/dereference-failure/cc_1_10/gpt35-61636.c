//FormAI DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
  int pid;
  int shmid;
  char *shm_ptr;
  char *message = "Hello, World!";

  if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
    perror("Error: Failed to create shared memory segment.");
    exit(1);
  }

  if ((pid = fork()) == -1) {
    perror("Error: Failed to create child process.");
    exit(1);
  }

  if (pid == 0) {
    /* Child process */
    if ((shm_ptr = shmat(shmid, NULL, 0)) == (char *) -1) {
      perror("Error: Failed to attach to shared memory segment.");
      exit(1);
    }

    /* Send message to parent process */
    strncpy(shm_ptr, message, SHM_SIZE);

    /* Detach from shared memory segment */
    if (shmdt(shm_ptr) == -1) {
      perror("Error: Failed to detach from shared memory segment.");
      exit(1);
    }

    exit(0);
  }
  else {
    /* Parent process */
    sleep(1); /* Ensure that child process has attached to shared memory segment */

    if ((shm_ptr = shmat(shmid, NULL, 0)) == (char *) -1) {
      perror("Error: Failed to attach to shared memory segment.");
      exit(1);
    }

    /* Receive message from child process */
    printf("Received message: %s\n", shm_ptr);

    /* Detach from shared memory segment */
    if (shmdt(shm_ptr) == -1) {
      perror("Error: Failed to detach from shared memory segment.");
      exit(1);
    }

    /* Remove shared memory segment */
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
      perror("Error: Failed to remove shared memory segment.");
      exit(1);
    }

    exit(0);
  }

  return 0;
}