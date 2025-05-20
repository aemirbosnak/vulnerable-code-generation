//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_MSG_LEN 1024
#define SHM_KEY 0xdeadbeef

int main() {
  // Create a shared memory segment
  int shmid = shmget(SHM_KEY, 4096, IPC_CREAT | 0644);
  if (shmid < 0) {
    perror("shmget() failed");
    return 1;
  }

  // Attach to the shared memory segment
  void *shm = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
  if (shm == MAP_FAILED) {
    perror("mmap() failed");
    return 1;
  }

  // Write a message to the shared memory
  char message[] = "Hello, world!";
  strcpy(shm, message);

  // Fork a new process
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork() failed");
    return 1;
  }

  // In the parent process, wait for the child process to finish
  if (pid > 0) {
    printf("Parent waiting for child...\n");
    wait(NULL);
    printf("Parent done waiting\n");
  }

  // In the child process, read the message from shared memory
  printf("Child reading message...\n");
  char *msg = shm;
  printf("Message: %s\n", msg);

  // Write a response to the shared memory
  char response[] = "Hello, world back!";
  strcpy(shm, response);

  // Exit the child process
  exit(0);

  // In the parent process, print the response
  printf("Parent printing response...\n");
  char *msg2 = shm;
  printf("Response: %s\n", msg2);

  return 0;
}