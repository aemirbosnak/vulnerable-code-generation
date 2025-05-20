//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
  int id;
  int floor;
  int destination;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
} elevator;

typedef struct {
  int num_elevators;
  elevator *elevators;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
} building;

void elevator_up(building *b, elevator *e) {
  pthread_mutex_lock(&e->mutex);
  while (e->floor < e->destination) {
    e->floor++;
    printf("Elevator %d is now on floor %d\n", e->id, e->floor);
    pthread_cond_wait(&e->cond, &e->mutex);
  }
  pthread_mutex_unlock(&e->mutex);
}

void elevator_down(building *b, elevator *e) {
  pthread_mutex_lock(&e->mutex);
  while (e->floor > e->destination) {
    e->floor--;
    printf("Elevator %d is now on floor %d\n", e->id, e->floor);
    pthread_cond_wait(&e->cond, &e->mutex);
  }
  pthread_mutex_unlock(&e->mutex);
}

void elevator_thread(void *arg) {
  building *b = (building *)arg;
  elevator *e = &b->elevators[0];

  while (1) {
    pthread_mutex_lock(&e->mutex);
    while (e->floor == e->destination) {
      pthread_cond_wait(&e->cond, &e->mutex);
    }
    if (e->floor < e->destination) {
      elevator_up(b, e);
    } else {
      elevator_down(b, e);
    }
    pthread_mutex_unlock(&e->mutex);
  }
}

void passenger_thread(void *arg) {
  building *b = (building *)arg;

  int floor = rand() % b->num_elevators;
  int destination = rand() % b->num_elevators;

  pthread_mutex_lock(&b->mutex);
  while (b->elevators[floor].floor != floor) {
    pthread_cond_wait(&b->cond, &b->mutex);
  }
  b->elevators[floor].destination = destination;
  pthread_cond_signal(&b->elevators[floor].cond);
  pthread_mutex_unlock(&b->mutex);
}

int main(int argc, char **argv) {
  int num_elevators = 10;
  int num_passengers = 100;

  building b;
  b.num_elevators = num_elevators;
  b.elevators = malloc(sizeof(elevator) * num_elevators);
  for (int i = 0; i < num_elevators; i++) {
    b.elevators[i].id = i;
    b.elevators[i].floor = 0;
    b.elevators[i].destination = 0;
    pthread_mutex_init(&b.elevators[i].mutex, NULL);
    pthread_cond_init(&b.elevators[i].cond, NULL);
  }
  pthread_mutex_init(&b.mutex, NULL);
  pthread_cond_init(&b.cond, NULL);

  pthread_t elevator_threads[num_elevators];
  for (int i = 0; i < num_elevators; i++) {
    pthread_create(&elevator_threads[i], NULL, elevator_thread, &b);
  }

  pthread_t passenger_threads[num_passengers];
  for (int i = 0; i < num_passengers; i++) {
    pthread_create(&passenger_threads[i], NULL, passenger_thread, &b);
  }

  for (int i = 0; i < num_elevators; i++) {
    pthread_join(elevator_threads[i], NULL);
  }

  for (int i = 0; i < num_passengers; i++) {
    pthread_join(passenger_threads[i], NULL);
  }

  for (int i = 0; i < num_elevators; i++) {
    pthread_mutex_destroy(&b.elevators[i].mutex);
    pthread_cond_destroy(&b.elevators[i].cond);
  }
  pthread_mutex_destroy(&b.mutex);
  pthread_cond_destroy(&b.cond);
  free(b.elevators);

  return 0;
}