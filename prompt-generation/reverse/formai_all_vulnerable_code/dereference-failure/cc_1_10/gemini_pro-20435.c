//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // Create a shared memory segment
  key_t key = ftok("shared_memory_key", 0);
  int shm_id = shmget(key, sizeof(int), IPC_CREAT | IPC_EXCL | 0644);
  if (shm_id == -1) {
    perror("shmget");
    return EXIT_FAILURE;
  }

  // Attach the shared memory segment to the current process
  int *shared_memory = shmat(shm_id, NULL, 0);
  if (shared_memory == (void *)-1) {
    perror("shmat");
    return EXIT_FAILURE;
  }

  // Initialize the shared memory
  *shared_memory = 0;

  // Fork a child process
  pid_t child_pid = fork();
  if (child_pid == -1) {
    perror("fork");
    return EXIT_FAILURE;
  }

  // In the child process, increment the shared memory value
  if (child_pid == 0) {
    *shared_memory++;
    printf("Child process: Incremented the shared memory value to %d\n",
           *shared_memory);
    exit(EXIT_SUCCESS);
  }

  // In the parent process, wait for the child process to finish and print the
  // shared memory value
  else {
    waitpid(child_pid, NULL, 0);
    printf("Parent process: The shared memory value is %d\n", *shared_memory);
  }

  // Detach the shared memory segment from the current process
  shmdt(shared_memory);

  // Destroy the shared memory segment
  shmctl(shm_id, IPC_RMID, NULL);

  return EXIT_SUCCESS;
}