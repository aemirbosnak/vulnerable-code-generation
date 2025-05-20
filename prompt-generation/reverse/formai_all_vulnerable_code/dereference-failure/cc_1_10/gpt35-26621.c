//FormAI DATASET v1.0 Category: Interprocess communication ; Style: detailed
/* This is a program demonstrating interprocess communication between two processes using shared memory and semaphores */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

// Define the key values for shared memory and semaphore
#define SHM_KEY 0x1234
#define SEM_KEY 0x5678

// Define the size of shared memory and the number of semaphores
#define SHM_SIZE 1024
#define NUM_SEMS 2

// Define the indexes for the semaphores
#define SEM_MUTEX 0
#define SEM_FULL 1

// Define the structure for the shared memory
typedef struct {
  char buf[SHM_SIZE];
} SharedMem;

int main()
{
  // Create shared memory
  int shmid = shmget(SHM_KEY, sizeof(SharedMem), IPC_CREAT | 0666);
  if (shmid == -1) {
    perror("Error creating shared memory");
    exit(1);
  }

  // Attach shared memory
  SharedMem *shm = (SharedMem*)shmat(shmid, NULL, 0);
  if (shm == (void*)-1) {
    perror("Error attaching shared memory");
    exit(1);
  }

  // Create semaphores
  int semid = semget(SEM_KEY, NUM_SEMS, IPC_CREAT | 0666);
  if (semid == -1) {
    perror("Error creating semaphores");
    exit(1);
  }

  // Initialize semaphores
  semctl(semid, SEM_MUTEX, SETVAL, 1);
  semctl(semid, SEM_FULL, SETVAL, 0);

  // Fork a new process
  pid_t pid = fork();

  if (pid == -1) {
    perror("Error forking process");
    exit(1);
  }
  else if (pid == 0) {
    // Child process

    // Wait for semaphore
    struct sembuf sb = {SEM_FULL, -1, 0};
    semop(semid, &sb, 1);

    // Print message received from parent
    printf("Child process received message: %s\n", shm->buf);

    // Release semaphore
    sb.sem_num = SEM_MUTEX;
    sb.sem_op = 1;
    semop(semid, &sb, 1);

    // Detach shared memory
    shmdt(shm);
  }
  else {
    // Parent process

    // Wait for semaphore
    struct sembuf sb = {SEM_MUTEX, -1, 0};
    semop(semid, &sb, 1);

    // Write message to shared memory
    printf("Enter a message: ");
    fgets(shm->buf, SHM_SIZE, stdin);

    // Release semaphore
    sb.sem_num = SEM_FULL;
    sb.sem_op = 1;
    semop(semid, &sb, 1);

    // Detach shared memory
    shmdt(shm);

    // Wait for child process to finish
    wait(NULL);

    // Destroy shared memory and semaphore
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);
  }

  return 0;
}