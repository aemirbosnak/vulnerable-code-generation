//FormAI DATASET v1.0 Category: Interprocess communication ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024 //Size of shared memory segment

int main(int argc, char **argv) {
  key_t key;
  int shmid;
  char *shm, *s;

  //Generate the shared memory key
  if ((key = ftok("shared_memory_program",'R')) == -1) {
    perror("ftok");
    exit(1);
  }

  //Create the shared memory segment
  if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
    perror("shmget");
    exit(1);
  }

  //Make the shared memory segment accessible to the program
  shm = shmat(shmid, NULL, 0);
  if (shm == (char *) -1) {
    perror("shmat");
    exit(1);
  }

  //Write to the shared memory segment
  s = shm;
  char message[] = "Hello, World!";
  strcpy(s, message);

  //Create the child process
  pid_t pid = fork();

  //Error handling for fork()
  if (pid == -1) {
    perror("fork");
    exit(1);
  }

  //Child process
  if (pid == 0) {
    printf("Child process reading from shared memory: %s\n", shm);
    exit(0);
  }

  //Parent process
  else {
    //Wait for the child process to finish
    wait(NULL);

    //Detach from the shared memory segment and remove it
    if (shmdt(shm) == -1) {
      perror("shmdt");
      exit(1);
    }
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
      perror("shmctl");
      exit(1);
    }

    printf("Parent process finished.\n");
    exit(0);
  }
}