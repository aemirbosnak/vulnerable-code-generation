//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_APPOINTMENTS 100
#define APPOINTMENT_SIZE sizeof(struct appointment)

struct appointment {
  char name[32];
  char date[20];
  char time[20];
};

struct appointment_list {
  struct appointment appointments[MAX_APPOINTMENTS];
  int count;
};

struct appointment_list *list;

pthread_mutex_t mutex;
sem_t semaphore;

void *thread_proc(void *arg) {
  while (1) {
    sem_wait(&semaphore);
    pthread_mutex_lock(&mutex);

    // Check if the list is full
    if (list->count == MAX_APPOINTMENTS) {
      printf("Error: The appointment list is full.\n");
    } else {
      // Get the appointment details from the user
      struct appointment appointment;
      printf("Enter your name: ");
      scanf("%s", appointment.name);
      printf("Enter the date of your appointment (YYYY-MM-DD): ");
      scanf("%s", appointment.date);
      printf("Enter the time of your appointment (HH:MM): ");
      scanf("%s", appointment.time);

      // Add the appointment to the list
      list->appointments[list->count] = appointment;
      list->count++;

      printf("Your appointment has been scheduled.\n");
    }

    pthread_mutex_unlock(&mutex);
    sem_post(&semaphore);
  }

  return NULL;
}

int main() {
  // Create the shared memory segment
  int shmid = shmget(IPC_PRIVATE, APPOINTMENT_SIZE, IPC_CREAT | IPC_EXCL | 0600);
  if (shmid == -1) {
    perror("shmget");
    return 1;
  }

  // Attach the shared memory segment to the address space of the process
  list = (struct appointment_list *)shmat(shmid, NULL, 0);
  if (list == (void *)-1) {
    perror("shmat");
    return 1;
  }

  // Initialize the appointment list
  list->count = 0;

  // Initialize the mutex and semaphore
  pthread_mutex_init(&mutex, NULL);
  sem_init(&semaphore, 0, 1);

  // Create the thread
  pthread_t thread;
  pthread_create(&thread, NULL, thread_proc, NULL);

  // Join the thread
  pthread_join(thread, NULL);

  // Destroy the mutex and semaphore
  pthread_mutex_destroy(&mutex);
  sem_destroy(&semaphore);

  // Detach the shared memory segment from the address space of the process
  shmdt(list);

  // Destroy the shared memory segment
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}