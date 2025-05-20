//FormAI DATASET v1.0 Category: Interprocess communication ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main (int argc, char *argv[]) {
  int shmid;
  char* shmaddr;
  char* data;
  int ret;

  // Create a shared memory segment
  shmid = shmget((key_t)1234, SHM_SIZE, 0666|IPC_CREAT);
  if (shmid == -1) {
    perror("shmget failed");
    return 1;
  }

  // Attach the shared memory segment to the process address space
  shmaddr = shmat(shmid, (void *)0, 0);
  if (shmaddr == (char*)-1) {
    perror("shmat failed");
    return 1;
  }

  // Read data from shared memory
  data = shmaddr;
  printf("Data read from shared memory: %s\n", data);

  // Detach shared memory segment
  ret = shmdt(shmaddr);
  if (ret == -1) {
    perror("shmdt failed");
    return 1;
  }

  // Modify data and write to shared memory
  strcpy(data, "Hello, World!");
  printf("Data written to shared memory: %s\n", data);

  // Attach the shared memory segment to the process address space again
  shmaddr = shmat(shmid, (void *)0, 0);
  if (shmaddr == (char*)-1) {
    perror("shmat failed");
    return 1;
  }

  // Read data from shared memory again
  data = shmaddr;
  printf("Data read from shared memory after modification: %s\n", data);

  // Detach shared memory segment
  ret = shmdt(shmaddr);
  if (ret == -1) {
    perror("shmdt failed");
    return 1;
  }

  // Delete shared memory segment
  ret = shmctl(shmid, IPC_RMID, 0);
  if (ret == -1) {
    perror("shmctl failed");
    return 1;
  }

  return 0;
}