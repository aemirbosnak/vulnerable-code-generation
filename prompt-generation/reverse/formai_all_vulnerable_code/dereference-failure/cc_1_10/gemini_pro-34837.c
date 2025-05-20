//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
  // Create a shared memory segment
  int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
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

  // Create a child process
  pid_t child_pid = fork();
  if (child_pid == -1) {
    perror("fork");
    exit(1);
  }

  // Parent process writes to the shared memory segment
  if (child_pid != 0) {
    strcpy(shm_ptr, "Hello from parent");
    printf("Parent wrote to shared memory: %s\n", shm_ptr);
  }
  // Child process reads from the shared memory segment
  else {
    sleep(1); // Give the parent process time to write to the shared memory segment
    printf("Child read from shared memory: %s\n", shm_ptr);
  }

  // Wait for the child process to finish
  if (child_pid != 0) {
    int status;
    waitpid(child_pid, &status, 0);
  }

  // Detach the shared memory segment from the current process
  shmdt(shm_ptr);

  // Destroy the shared memory segment
  shmctl(shm_id, IPC_RMID, NULL);

  return 0;
}