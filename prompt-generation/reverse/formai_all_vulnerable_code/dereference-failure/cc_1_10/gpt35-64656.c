//FormAI DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>

#define SHM_SIZE 256

int main() {
  int shmid;
  key_t key;
  char *shm;
  pid_t pid;

  key = ftok("unique_key", 'R');
  shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);

  if (shmid < 0) {
    perror("shmget");
    exit(1);
  }

  shm = shmat(shmid, NULL, 0);

  if (shm == (char *)-1) {
    perror("shmat");
    exit(1);
  }

  printf("Enter a message: ");
  fgets(shm, SHM_SIZE, stdin);

  pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {
    printf("Child process reading from shared memory...\n");
    sleep(1);
    printf("Child process read: %s", shm);
    exit(0);
  } else {
    printf("Parent process writing to shared memory...\n");
    wait(NULL);
    printf("Parent process exited!\n");
  }

  shmdt(shm);
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}