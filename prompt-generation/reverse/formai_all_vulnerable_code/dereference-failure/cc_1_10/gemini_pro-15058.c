//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_DISKS 10
#define NUM_TOWERS 3

int towers[NUM_TOWERS][NUM_DISKS];
int top[NUM_TOWERS];

pthread_mutex_t tower_mutexes[NUM_TOWERS];

void move_disk(int from, int to) {
  pthread_mutex_lock(&tower_mutexes[from]);
  pthread_mutex_lock(&tower_mutexes[to]);

  int disk = towers[from][top[from]--];
  towers[to][++top[to]] = disk;

  pthread_mutex_unlock(&tower_mutexes[to]);
  pthread_mutex_unlock(&tower_mutexes[from]);
}

void* tower_of_hanoi(void* arg) {
  int* disks = (int*)arg;

  for (int i = disks[0]; i > 0; i--) {
    move_disk(disks[1], disks[2]);
  }

  return NULL;
}

int main() {
  for (int i = 0; i < NUM_TOWERS; i++) {
    top[i] = -1;
  }

  for (int i = 0; i < NUM_DISKS; i++) {
    towers[0][i] = NUM_DISKS - i;
  }

  pthread_t threads[NUM_TOWERS];

  for (int i = 0; i < NUM_TOWERS; i++) {
    pthread_mutex_init(&tower_mutexes[i], NULL);
  }

  for (int i = 1; i < NUM_TOWERS; i++) {
    int* disks = malloc(sizeof(int) * 3);
    disks[0] = NUM_DISKS - i;
    disks[1] = 0;
    disks[2] = i;

    pthread_create(&threads[i], NULL, tower_of_hanoi, (void*)disks);
  }

  for (int i = 1; i < NUM_TOWERS; i++) {
    pthread_join(threads[i], NULL);
  }

  for (int i = 0; i < NUM_TOWERS; i++) {
    pthread_mutex_destroy(&tower_mutexes[i]);
  }

  return 0;
}