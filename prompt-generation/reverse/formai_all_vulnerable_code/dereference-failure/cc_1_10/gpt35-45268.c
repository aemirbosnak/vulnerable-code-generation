//FormAI DATASET v1.0 Category: Interprocess communication ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main() {
  int shmid;
  char *shm, *s;
  key_t key = 1234;

  // create shared memory segment
  if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
    perror("shmget");
    exit(1);
  }

  // attach to shared memory
  if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
    perror("shmat");
    exit(1);
  }

  // write data to shared memory
  printf("Enter a message: ");
  fgets(shm, SHM_SIZE, stdin);

  // start child process
  pid_t pid = fork();

  if (pid < 0) {
    perror("fork");
    exit(1);
  } 

  if (pid == 0) { // child process

    // read data from shared memory
    printf("Child process reads: %s", shm);

    // modify shared memory
    s = shm;
    s += strlen(shm);

    *s = '!';

    printf("Child process writes: %s\n", shm);

    // detach from shared memory
    if (shmdt(shm) == -1) {
      perror("shmdt");
      exit(1);
    }

    exit(0);
  } 

  else { // parent process
    wait(NULL);

    // read modified shared memory
    printf("Parent process reads: %s\n", shm);

    // detach from shared memory
    if (shmdt(shm) == -1) {
      perror("shmdt");
      exit(1);
    }

    // delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
      perror("shmctl");
      exit(1);
    }

    exit(0);
  }

  return 0;
}