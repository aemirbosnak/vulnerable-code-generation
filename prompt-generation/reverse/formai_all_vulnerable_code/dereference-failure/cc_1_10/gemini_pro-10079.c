//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

// Declare the semaphore union
union semun {
  int val;
  struct semid_ds *buf;
  unsigned short *array;
  struct seminfo *__buf;
};

// Declare the shared memory structure
struct shared_memory {
  int counter;
  char message[100];
};

// Initialize the semaphore
int init_semaphore(int semid, int value) {
  union semun arg;
  arg.val = value;
  return semctl(semid, 0, SETVAL, arg);
}

// Lock the semaphore
int lock_semaphore(int semid) {
  struct sembuf op;
  op.sem_num = 0;
  op.sem_op = -1;
  op.sem_flg = 0;
  return semop(semid, &op, 1);
}

// Unlock the semaphore
int unlock_semaphore(int semid) {
  struct sembuf op;
  op.sem_num = 0;
  op.sem_op = 1;
  op.sem_flg = 0;
  return semop(semid, &op, 1);
}

// Initialize the shared memory
int init_shared_memory(int shmid, struct shared_memory *shared_mem) {
  shared_mem->counter = 0;
  strcpy(shared_mem->message, "Hello, IPC!");
  return 0;
}

// Get the shared memory
struct shared_memory *get_shared_memory(int shmid) {
  return (struct shared_memory *)shmat(shmid, NULL, 0);
}

// Release the shared memory
int release_shared_memory(struct shared_memory *shared_mem) {
  return shmdt(shared_mem);
}

// Destroy the semaphore
int destroy_semaphore(int semid) {
  return semctl(semid, 0, IPC_RMID);
}

// Destroy the shared memory
int destroy_shared_memory(int shmid) {
  return shmctl(shmid, IPC_RMID, NULL);
}

int main() {
  // Create the semaphore
  int semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
  if (semid < 0) {
    perror("semget");
    exit(EXIT_FAILURE);
  }

  // Initialize the semaphore
  if (init_semaphore(semid, 1) < 0) {
    perror("init_semaphore");
    exit(EXIT_FAILURE);
  }

  // Create the shared memory
  int shmid = shmget(IPC_PRIVATE, sizeof(struct shared_memory), IPC_CREAT | 0666);
  if (shmid < 0) {
    perror("shmget");
    exit(EXIT_FAILURE);
  }

  // Initialize the shared memory
  struct shared_memory *shared_mem = get_shared_memory(shmid);
  if (shared_mem == NULL) {
    perror("get_shared_memory");
    exit(EXIT_FAILURE);
  }

  if (init_shared_memory(shmid, shared_mem) < 0) {
    perror("init_shared_memory");
    exit(EXIT_FAILURE);
  }

  // Fork a child process
  pid_t child_pid = fork();
  if (child_pid < 0) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (child_pid == 0) {
    // Child process
    while (1) {
      // Lock the semaphore
      if (lock_semaphore(semid) < 0) {
        perror("lock_semaphore");
        exit(EXIT_FAILURE);
      }

      // Increment the counter
      shared_mem->counter++;

      // Unlock the semaphore
      if (unlock_semaphore(semid) < 0) {
        perror("unlock_semaphore");
        exit(EXIT_FAILURE);
      }

      // Sleep for 1 second
      sleep(1);
    }
  } else {
    // Parent process
    while (1) {
      // Lock the semaphore
      if (lock_semaphore(semid) < 0) {
        perror("lock_semaphore");
        exit(EXIT_FAILURE);
      }

      // Print the counter and message
      printf("Counter: %d\n", shared_mem->counter);
      printf("Message: %s\n", shared_mem->message);

      // Unlock the semaphore
      if (unlock_semaphore(semid) < 0) {
        perror("unlock_semaphore");
        exit(EXIT_FAILURE);
      }

      // Sleep for 1 second
      sleep(1);
    }
  }

  // Wait for the child process to terminate
  wait(NULL);

  // Destroy the semaphore
  if (destroy_semaphore(semid) < 0) {
    perror("destroy_semaphore");
    exit(EXIT_FAILURE);
  }

  // Destroy the shared memory
  if (release_shared_memory(shared_mem) < 0) {
    perror("release_shared_memory");
    exit(EXIT_FAILURE);
  }

  if (destroy_shared_memory(shmid) < 0) {
    perror("destroy_shared_memory");
    exit(EXIT_FAILURE);
  }

  return 0;
}