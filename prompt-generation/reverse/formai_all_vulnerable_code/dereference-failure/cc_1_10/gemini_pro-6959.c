//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
  // Create a shared memory segment
  int shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
  if (shm_id == -1) {
    perror("shmget");
    return 1;
  }

  // Attach the shared memory segment to the current process
  int *shm_ptr = (int *)shmat(shm_id, NULL, 0);
  if (shm_ptr == (int *)-1) {
    perror("shmat");
    return 1;
  }

  // Write a value to the shared memory segment
  *shm_ptr = 42;

  // Create a pipe
  int pipe_fd[2];
  if (pipe(pipe_fd) == -1) {
    perror("pipe");
    return 1;
  }

  // Fork a child process
  pid_t child_pid = fork();
  if (child_pid == -1) {
    perror("fork");
    return 1;
  }

  // In the child process, read the value from the shared memory segment and write it to the pipe
  if (child_pid == 0) {
    close(pipe_fd[1]);
    int value;
    while (read(pipe_fd[0], &value, sizeof(int)) > 0) {
      printf("Child: %d\n", value);
    }
    close(pipe_fd[0]);
    exit(0);
  }

  // In the parent process, write the value from the shared memory segment to the pipe
  else {
    close(pipe_fd[0]);
    while (*shm_ptr != 0) {
      int value = *shm_ptr;
      write(pipe_fd[1], &value, sizeof(int));
    }
    close(pipe_fd[1]);
    wait(NULL);
  }

  // Detach the shared memory segment from the current process
  if (shmdt(shm_ptr) == -1) {
    perror("shmdt");
    return 1;
  }

  // Destroy the shared memory segment
  if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
    perror("shmctl");
    return 1;
  }

  return 0;
}