//FormAI DATASET v1.0 Category: Interprocess communication ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main(void) {
  char *parent_msg = "Hello, this is the parent!";
  char *child_msg = "Hey there, this is the child!";

  key_t key = 1234;
  int shmid;
  char *shm, *s;

  // Creating the shared memory segment
  if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
    perror("shmget");
    exit(1);
  }

  // Attaching the segment to our data space
  if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
    perror("shmat");
    exit(1);
  }

  // Writing to the shared memory segment
  strncpy(shm, parent_msg, SHM_SIZE);

  // Forking the process to create a child
  pid_t pid = fork();

  if (pid == -1) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {  // child process
    s = shm;

    while (*s != '\0') {
      putchar(*s);
      s++;
    }

    putchar('\n');

    // Writing to the shared memory segment from the child process
    strncpy(shm, child_msg, SHM_SIZE);

    exit(0);
  } else {  // parent process
    wait(NULL);

    putchar('\n');

    s = shm;

    while (*s != '\0') {
      putchar(*s);
      s++;
    }

    putchar('\n');

    // Detaching the shared memory segment
    if (shmdt(shm) == -1) {
      perror("shmdt");
      exit(1);
    }

    // Removing the shared memory segment
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
      perror("shmctl");
      exit(1);
    }
  }

  return 0;
}