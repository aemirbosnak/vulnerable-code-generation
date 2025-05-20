//FormAI DATASET v1.0 Category: Interprocess communication ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

int main() {
  int pid;
  int shmid;
  char *shm;
  
  // Create shared memory segment
  if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
    perror("shmget");
    exit(1);
  }
  
  // Attach to shared memory segment
  if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
    perror("shmat");
    exit(1);
  }
  
  // Fork a child process
  if ((pid = fork()) < 0) {
    perror("fork");
    exit(1);
  }
  
  // Child process writes to shared memory
  if (pid == 0) {
    char *msg = "Hello from the child process!";
    strncpy(shm, msg, SHM_SIZE);
    exit(0);
  }
  
  // Parent process waits for child to finish
  waitpid(pid, NULL, 0);
  
  // Parent process reads from shared memory
  printf("Message from child process: %s\n", shm);
  
  // Detach from shared memory segment
  if (shmdt(shm) < 0) {
    perror("shmdt");
    exit(1);
  }
  
  // Remove shared memory segment
  if (shmctl(shmid, IPC_RMID, NULL) < 0) {
    perror("shmctl");
    exit(1);
  }
  
  return 0;
}