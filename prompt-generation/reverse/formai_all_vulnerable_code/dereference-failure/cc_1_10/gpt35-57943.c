//FormAI DATASET v1.0 Category: Interprocess communication ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SHM_KEY 8675309   // Shared memory key
#define BUFFER_SIZE 1024  // Maximum buffer size

int main() {
  pid_t pid;      // Process ID
  int shm_id;     // Shared memory ID
  char* shm_addr; // Shared memory address
  char buffer[BUFFER_SIZE]; // Input buffer

  // Allocate shared memory
  shm_id = shmget(SHM_KEY, BUFFER_SIZE, IPC_CREAT | 0666);
  if (shm_id < 0) {
    fprintf(stderr, "Failed to allocate shared memory\n");
    exit(1);
  }

  // Fork a child process
  pid = fork();
  if (pid < 0) {
    fprintf(stderr, "Failed to fork\n");
    exit(1);
  }

  if (pid == 0) { // Child process
    // Attach to shared memory
    shm_addr = shmat(shm_id, NULL, 0);
    if (shm_addr == (char*)-1) {
      fprintf(stderr, "Failed to attach to shared memory\n");
      exit(1);
    }

    // Read from shared memory and print to stdout
    printf("Child process read: %s", shm_addr);

    // Detach from shared memory
    shmdt(shm_addr);
    exit(0);
  } 
  else { // Parent process
    // Attach to shared memory
    shm_addr = shmat(shm_id, NULL, 0);
    if (shm_addr == (char*)-1) {
      fprintf(stderr, "Failed to attach to shared memory\n");
      exit(1);
    }

    // Read from stdin and write to shared memory
    printf("Enter a message to send to the child process: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    strcpy(shm_addr, buffer);

    // Wait for child process to terminate
    wait(NULL);

    // Detach from shared memory
    shmdt(shm_addr);

    // Deallocate shared memory
    shmctl(shm_id, IPC_RMID, NULL);

    printf("Parent process completed successfully!\n");
  }

  return 0;
}