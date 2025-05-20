//FormAI DATASET v1.0 Category: Interprocess communication ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {

  char* message = "Hello, world!";
  char buffer[SHM_SIZE];
  int shmid;
  key_t key;
  pid_t pid;
  void* shmptr;

  // Generate a unique key for the shared memory segment
  key = ftok(".", 'a');

  // Create the shared memory segment
  shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
  if (shmid < 0) {
    perror("shmget");
    exit(1);
  }

  // Attach to the shared memory segment
  shmptr = shmat(shmid, NULL, 0);
  if (shmptr == (void*) -1) {
    perror("shmat");
    exit(1);
  }

  // Write the message to the shared memory segment
  strcpy((char*)shmptr, message);

  // Fork a new process
  pid = fork();

  if (pid < 0) {
    perror("fork");
    exit(1);
  }

  if (pid == 0) {
    // Child process reads from the shared memory segment
    sleep(1);
    printf("Child process reads: %s\n", (char*)shmptr);

    // Detach from the shared memory segment
    if (shmdt(shmptr) < 0) {
      perror("shmdt");
      exit(1);
    }

    // Exit the child process
    exit(0);
  } else {
    // Parent process waits for the child to finish
    wait(NULL);

    // Read from the shared memory segment into a buffer
    strncpy(buffer, (char*)shmptr, SHM_SIZE);

    // Detach from the shared memory segment
    if (shmdt(shmptr) < 0) {
      perror("shmdt");
      exit(1);
    }

    // Delete the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    // Print the message
    printf("Parent process reads: %s\n", buffer);
  }

  return 0;
}