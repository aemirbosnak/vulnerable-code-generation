//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
  // Create a shared memory segment
  int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0600);
  if (shm_id == -1) {
    perror("shmget");
    exit(1);
  }

  // Attach the shared memory segment to the current process
  void *shm_ptr = shmat(shm_id, NULL, 0);
  if (shm_ptr == (void *)-1) {
    perror("shmat");
    exit(1);
  }

  // Write a message to the shared memory segment
  strcpy(shm_ptr, "Hello from parent process");

  // Create a child process
  pid_t child_pid = fork();
  if (child_pid == -1) {
    perror("fork");
    exit(1);
  }

  // Wait for the child process to finish
  int status;
  waitpid(child_pid, &status, 0);

  // Read the message from the shared memory segment
  printf("Message from child process: %s\n", shm_ptr);

  // Detach the shared memory segment from the current process
  shmdt(shm_ptr);

  // Remove the shared memory segment
  shmctl(shm_id, IPC_RMID, NULL);

  return 0;
}