//FormAI DATASET v1.0 Category: Interprocess communication ; Style: relaxed
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <errno.h>

#define SHMSIZE 27

int main() {
  pid_t pid;
  char *shm, *s;
  key_t key = 5678;
  int shmid, status;

  /* create a shared memory segment */
  if ((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0) {
    perror("shmget");
    exit(1);
  }

  /* attach the shared memory segment to our data space */
  if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
    perror("shmat");
    exit(1);
  }

  /* write some data to the shared memory segment */
  s = shm;
  for (char c = 'a'; c <= 'z'; c++) {
    *s++ = c;
  }
  *s = '\0';

  /* fork a child process */
  if ((pid = fork()) < 0) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {  /* child process */
    /* modify the shared memory segment */
    s = shm;
    for (char c = 'a'; c <= 'z'; c++) {
      *s++ = toupper(c);
    }

    /* exit the child process */
    exit(0);
  } else {  /* parent process */
    /* wait for the child process to exit */
    waitpid(pid, &status, 0);

    /* print the contents of the shared memory segment */
    printf("%s\n", shm);

    /* detach the shared memory segment from our data space */
    if (shmdt(shm) == -1) {
      perror("shmdt");
      exit(1);
    }

    /* delete the shared memory segment */
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
      perror("shmctl");
      exit(1);
    }
  }

  return 0;
}