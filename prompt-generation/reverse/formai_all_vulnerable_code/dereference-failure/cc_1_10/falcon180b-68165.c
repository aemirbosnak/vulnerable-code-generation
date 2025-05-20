//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
  int fd;
  int shmid;
  char *shm;
  pid_t pid;

  // Create shared memory segment
  shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }

  // Attach shared memory segment
  shm = shmat(shmid, NULL, 0);
  if (shm == (void *)-1) {
    perror("shmat");
    exit(1);
  }

  // Initialize shared memory
  memset(shm, 0, SIZE);

  // Fork child process
  pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {
    // Child process writes to shared memory
    for (int i = 0; i < SIZE; i++) {
      sprintf(shm + i, "Child wrote: %d\n", i);
    }
  } else {
    // Parent process reads from shared memory
    sleep(1);
    for (int i = 0; i < SIZE; i++) {
      printf("Parent read: %s", shm + i);
    }
  }

  // Detach shared memory segment
  if (shmdt(shm) == -1) {
    perror("shmdt");
    exit(1);
  }

  // Delete shared memory segment
  if (shmctl(shmid, IPC_RMID, NULL) == -1) {
    perror("shmctl");
    exit(1);
  }

  return 0;
}