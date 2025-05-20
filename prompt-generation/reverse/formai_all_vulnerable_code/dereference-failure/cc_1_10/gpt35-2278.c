//FormAI DATASET v1.0 Category: Interprocess communication ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
  int shmid;
  key_t key;
  char *shm, *s;

  // generate unique key for shared memory
  if ((key = ftok("ipc_example.c", 'R')) == -1) {
    perror("ftok");
    exit(1);
  }

  // create shared memory segment with specified key
  if ((shmid = shmget(key, SHM_SIZE, 0666|IPC_CREAT)) == -1) {
    perror("shmget");
    exit(1);
  }

  // attach shared memory segment to this process's address space
  if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
    perror("shmat");
    exit(1);
  }

  // write message to shared memory
  s = shm;
  for (char c = 'a'; c <= 'z'; c++) {
    *s++ = c;
  }
  *s = '\0';

  // wait for message to be read
  while (*shm != '*')
    sleep(1);

  // detach shared memory segment
  if (shmdt(shm) == -1) {
    perror("shmdt");
    exit(1);
  }

  // delete shared memory segment
  if (shmctl(shmid, IPC_RMID, NULL) == -1) {
    perror("shmctl");
    exit(1);
  }

  return 0;
}