//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

// Sherlock is a detective, so we'll use a semaphore to
// control access to the shared memory segment.
int main() {
  // First, we need to create a shared memory segment.
  int shmid = shmget(IPC_PRIVATE, 1000, IPC_CREAT | 0600);
  if (shmid == -1) {
    perror("shmget");
    return 1;
  }

  // Now, we need to attach the shared memory segment to our
  // process.
  char *shmptr = shmat(shmid, NULL, 0);
  if (shmptr == (char *)-1) {
    perror("shmat");
    return 1;
  }

  // We'll use a semaphore to control access to the shared
  // memory segment.
  int semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0600);
  if (semid == -1) {
    perror("semget");
    return 1;
  }

  // Initialize the semaphore to 1.
  semctl(semid, 0, SETVAL, 1);

  // Now, we're ready to start investigating.
  while (1) {
    // First, we need to wait for the semaphore to be available.
    struct sembuf op;
    op.sem_num = 0;
    op.sem_op = -1;
    op.sem_flg = 0;
    semop(semid, &op, 1);

    // Now, we have exclusive access to the shared memory segment.
    // Let's see if there's a new case to investigate.
    if (strcmp(shmptr, "No cases today, Watson") == 0) {
      // No new cases. Let's wait a bit.
      sleep(1);
    } else {
      // We have a new case! Let's investigate.
      printf("New case: %s\n", shmptr);
      // ...

      // We're done investigating. Let's mark the case as closed.
      strcpy(shmptr, "No cases today, Watson");
    }

    // Now, we're done with the shared memory segment.
    // Let's release the semaphore so that other processes can
    // access it.
    op.sem_op = 1;
    semop(semid, &op, 1);
  }

  // We're all done. Let's clean up.
  shmdt(shmptr);
  shmctl(shmid, IPC_RMID, NULL);
  semctl(semid, 0, IPC_RMID, NULL);

  return 0;
}