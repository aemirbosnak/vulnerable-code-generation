//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: light-weight
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // Create a shared memory segment
  int shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
  if (shm_id == -1) {
    perror("shmget");
    return 1;
  }

  // Attach the shared memory segment to our process
  int *shared_memory = (int *)shmat(shm_id, NULL, 0);
  if (shared_memory == (int *)-1) {
    perror("shmat");
    return 1;
  }

  // Initialize the shared memory with a message
  *shared_memory = 0;

  // Fork a child process
  pid_t child_pid = fork();
  if (child_pid == -1) {
    perror("fork");
    return 1;
  }

  // Parent process
  if (child_pid > 0) {
    while (*shared_memory == 0) {
      sleep(1);
    }

    printf("Parent received message: %d\n", *shared_memory);

    // Detach the shared memory segment from our process
    if (shmdt(shared_memory) == -1) {
      perror("shmdt");
      return 1;
    }

    // Destroy the shared memory segment
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
      perror("shmctl");
      return 1;
    }
  }

  // Child process
  else {
    sleep(1);

    // Increment the shared memory value
    *shared_memory++;

    printf("Child sent message: %d\n", *shared_memory);

    // Detach the shared memory segment from our process
    if (shmdt(shared_memory) == -1) {
      perror("shmdt");
      return 1;
    }
  }

  return 0;
}