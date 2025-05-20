//FormAI DATASET v1.0 Category: Interprocess communication ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#define SHMSZ 27
#define PI 3.14159265

int main()
{
  char c;
  int shmid, i;
  pid_t pid;
  key_t key;
  char *shm, *s;

  key = 6523;

  if((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
      perror("shmget");
      exit(1);
  }

  if((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
      perror("shmat");
      exit(1);
  }

  s = shm;

  *s = '0';

  pid = fork();

  if(pid == 0) {
      for(i = 0; i < 1000; i++) {
          *s = cos(i * (PI / 180)) + 48; // Write to shared memory
          printf("Child Process: %.3lf degrees = %c\n", i * (PI / 180), *s);
          s++;
          sleep(1);
      }
      printf("Child Process Completed!\n");
  }
  else if(pid > 0) {
      wait(NULL);
      printf("Parent Process:");
      for(i = 0; i < 1000; i++) {
          printf("%c", *s);
          s++;
      }
      putchar('\n');
      printf("Parent Process Completed!\n");
      if(shmdt(shm) == -1) {
          perror("shmdt");
          exit(1);
      }
      if(shmctl(shmid, IPC_RMID, NULL) == -1) {
          perror("shmctl");
      }
  }
  else {
      perror("fork");
      exit(1);
  }

  return 0;
}