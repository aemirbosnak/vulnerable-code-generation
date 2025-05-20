//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

// Define the number of signals and their states
#define NUM_SIGNALS 3
#define RED 0
#define YELLOW 1
#define GREEN 2

// Define the shared memory key and semaphore key
#define SHM_KEY 1234
#define SEM_KEY 5678

// Define the semaphore operations
#define SEM_LOCK -1
#define SEM_UNLOCK 1

// Create a structure to represent the traffic light state
typedef struct {
  int state[NUM_SIGNALS];
  int current_signal;
} traffic_light_state;

int main() {
  // Create the shared memory segment
  int shm_id = shmget(SHM_KEY, sizeof(traffic_light_state), IPC_CREAT | 0666);
  if (shm_id == -1) {
    perror("shmget");
    exit(1);
  }

  // Attach the shared memory segment to the process
  traffic_light_state *state = (traffic_light_state *)shmat(shm_id, NULL, 0);
  if (state == (void *)-1) {
    perror("shmat");
    exit(1);
  }

  // Create the semaphore set
  int sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);
  if (sem_id == -1) {
    perror("semget");
    exit(1);
  }

  // Initialize the semaphore to 1 (unlocked)
  semctl(sem_id, 0, SETVAL, 1);

  // Initialize the traffic light state
  state->current_signal = GREEN;
  state->state[RED] = 0;
  state->state[YELLOW] = 0;
  state->state[GREEN] = 1;

  // Loop forever, changing the traffic light state
  while (1) {
    // Lock the semaphore
    semop(sem_id, &(struct sembuf){SEM_LOCK, 0, 0}, 1);

    // Change the current signal
    state->current_signal = (state->current_signal + 1) % NUM_SIGNALS;

    // Update the traffic light state
    for (int i = 0; i < NUM_SIGNALS; i++) {
      state->state[i] = (i == state->current_signal) ? 1 : 0;
    }

    // Unlock the semaphore
    semop(sem_id, &(struct sembuf){SEM_UNLOCK, 0, 0}, 1);

    // Sleep for 1 second
    sleep(1);
  }

  // Detach the shared memory segment from the process
  shmdt(state);

  // Remove the shared memory segment
  shmctl(shm_id, IPC_RMID, NULL);

  // Remove the semaphore set
  semctl(sem_id, 0, IPC_RMID);

  return 0;
}