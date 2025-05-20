//FormAI DATASET v1.0 Category: Interprocess communication ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_KEY 0x12345
#define BUF_SIZE 1024

int main() {

  int shmid;
  char *data;
  int wstatus;

  // Create shared memory segment
  shmid = shmget(SHM_KEY, BUF_SIZE, IPC_CREAT | 0666);
  if (shmid == -1) {
    perror("shmget");
    exit(EXIT_FAILURE);
  }

  // Attach shared memory segment
  data = shmat(shmid, NULL, 0);
  if (data == (char *)(-1)) {
    perror("shmat");
    exit(EXIT_FAILURE);
  }

  // Fork child process
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid == 0) { // Child process

    printf("Child process is waiting for data...\n");

    while (strncmp(data, "END", 3) != 0) {
      sleep(1);
    }

    printf("Child process received data: %s\n", data);

    // Detach shared memory segment
    if (shmdt(data) == -1) {
      perror("shmdt");
      _exit(EXIT_FAILURE);
    }

    // Exit child process
    _exit(EXIT_SUCCESS);

  } else { // Parent process

    printf("Parent process is writing data...\n");

    // Write data to shared memory segment
    strcpy(data, "Hello, child process! How are you today?");

    // Wait for child process to terminate
    if (waitpid(pid, &wstatus, 0) == -1) {
      perror("waitpid");
      exit(EXIT_FAILURE);
    }

    printf("Parent process has received exit status of %d\n", wstatus);

    // Detach shared memory segment
    if (shmdt(data) == -1) {
      perror("shmdt");
      exit(EXIT_FAILURE);
    }

    // Delete shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
      perror("shmctl");
      exit(EXIT_FAILURE);
    }

    printf("Parent process has deleted shared memory segment\n");

    // Exit parent process
    exit(EXIT_SUCCESS);

  }

}