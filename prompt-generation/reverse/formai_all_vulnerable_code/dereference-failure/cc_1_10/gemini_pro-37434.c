//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Shared memory segment size
#define SHM_SIZE 1024

// Shared memory segment key
#define SHM_KEY 1234

// Maximum number of fortunes
#define MAX_FORTUNES 10

// Fortune messages
char *fortunes[] = {
  "You will have a great day!",
  "You will meet someone special.",
  "You will get a promotion.",
  "You will win the lottery.",
  "You will find your true love.",
  "You will be happy and successful.",
  "You will have a long and healthy life.",
  "You will make a difference in the world.",
  "You will achieve your dreams.",
  "You are loved."
};

int main() {
  // Create a shared memory segment
  int shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
  if (shmid == -1) {
    perror("shmget");
    return 1;
  }

  // Attach the shared memory segment to the current process
  void *shmptr = shmat(shmid, NULL, 0);
  if (shmptr == (void *)-1) {
    perror("shmat");
    return 1;
  }

  // Get a random fortune
  srand(time(NULL));
  int fortune_index = rand() % MAX_FORTUNES;
  char *fortune = fortunes[fortune_index];

  // Copy the fortune to the shared memory segment
  strcpy(shmptr, fortune);

  // Detach the shared memory segment from the current process
  shmdt(shmptr);

  return 0;
}