//FormAI DATASET v1.0 Category: Interprocess communication ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1000 // The size of the shared memory segment

int main() {
  int shmid;
  char *shm, *s;

  // Create the shared memory segment with key 5678
  if ((shmid = shmget(5678, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
    perror("shmget");
    exit(1);
  }

  // Attach the shared memory segment to the current process' address space
  if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
    perror("shmat");
    exit(1);
  }

  // Write a message to the shared memory segment
  sprintf(shm, "Hello, world!");

  // Find the end of the message in the shared memory segment
  s = shm + strlen("Hello, world!");

  // Add some additional messages to the shared memory segment
  for (char c = 'a'; c <= 'z'; c++) {
    *s++ = c;
  }

  // Terminate the message with a null character
  *s = '\0';

  // Wait for 5 seconds to allow the message to be read by other processes
  sleep(5);

  // Display the message
  printf("Message from shared memory: %s\n", shm);

  // Detach the shared memory segment from the current process' address space
  if (shmdt(shm) == -1) {
    perror("shmdt");
    exit(1);
  }

  // Delete the shared memory segment
  if (shmctl(shmid, IPC_RMID, 0) == -1) {
    perror("shmctl");
    exit(1);
  }

  return 0;
}