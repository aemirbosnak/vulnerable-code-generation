//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

void *producer_thread(void *arg);
void *consumer_thread(void *arg);

int shmid;
char *buffer;

int main() {
  pthread_t producer, consumer;

  // Creating a shared memory segment
  shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }

  // Attaching the shared memory segment to the process
  buffer = (char *)shmat(shmid, NULL, 0);
  if (buffer == (char *)-1) {
    perror("shmat");
    exit(1);
  }

  // Initialize buffer to be empty
  *buffer = '\0';

  // Create threads for producer and consumer
  pthread_create(&producer, NULL, producer_thread, NULL);
  pthread_create(&consumer, NULL, consumer_thread, NULL);

  // Wait for threads to finish
  pthread_join(producer, NULL);
  pthread_join(consumer, NULL);

  // Detach and remove the shared memory segment
  shmdt(buffer);
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}

void *producer_thread(void *arg) {
  char message[SHM_SIZE];

  while (1) {
    // Read input from user
    fgets(message, SHM_SIZE, stdin);

    // Write message to shared memory buffer
    sprintf(buffer, "%s", message);
    printf("Producer wrote %s\n", message);
  }
}

void *consumer_thread(void *arg) {
  char message[SHM_SIZE];

  while (1) {
    // Read message from shared memory buffer
    sprintf(message, "%s", buffer);
    printf("Consumer read %s\n", message);

    // Clear the buffer after reading the message
    *buffer = '\0';
  }
}