//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_BAGS 100
#define NUM_CHECKERS 2
#define NUM_SCREENERS 3
#define NUM_LOADERS 4

typedef struct {
  int id;
  int weight;
  int size;
  char *contents;
} bag;

typedef struct {
  bag *bag;
  int checked;
  int screened;
  int loaded;
} status;

bag *bags[NUM_BAGS];
status statuses[NUM_BAGS];
sem_t checker_sem;
sem_t screener_sem;
sem_t loader_sem;
pthread_t checker_threads[NUM_CHECKERS];
pthread_t screener_threads[NUM_SCREENERS];
pthread_t loader_threads[NUM_LOADERS];

void *checker(void *arg) {
  while (1) {
    sem_wait(&checker_sem);
    int id = rand() % NUM_BAGS;
    if (statuses[id].checked == 0) {
      statuses[id].checked = 1;
      printf("Checker %d checked bag %d\n", (int)arg, id);
    }
    sem_post(&screener_sem);
  }
}

void *screener(void *arg) {
  while (1) {
    sem_wait(&screener_sem);
    int id = rand() % NUM_BAGS;
    if (statuses[id].screened == 0) {
      statuses[id].screened = 1;
      printf("Screener %d screened bag %d\n", (int)arg, id);
    }
    sem_post(&loader_sem);
  }
}

void *loader(void *arg) {
  while (1) {
    sem_wait(&loader_sem);
    int id = rand() % NUM_BAGS;
    if (statuses[id].loaded == 0) {
      statuses[id].loaded = 1;
      printf("Loader %d loaded bag %d\n", (int)arg, id);
    }
  }
}

int main() {
  srand(time(NULL));
  sem_init(&checker_sem, 0, NUM_BAGS);
  sem_init(&screener_sem, 0, 0);
  sem_init(&loader_sem, 0, 0);
  for (int i = 0; i < NUM_BAGS; i++) {
    bags[i] = malloc(sizeof(bag));
    bags[i]->id = i;
    bags[i]->weight = rand() % 50;
    bags[i]->size = rand() % 100;
    bags[i]->contents = malloc(rand() % 100);
    statuses[i].checked = 0;
    statuses[i].screened = 0;
    statuses[i].loaded = 0;
  }
  for (int i = 0; i < NUM_CHECKERS; i++) {
    pthread_create(&checker_threads[i], NULL, checker, (void *)i);
  }
  for (int i = 0; i < NUM_SCREENERS; i++) {
    pthread_create(&screener_threads[i], NULL, screener, (void *)i);
  }
  for (int i = 0; i < NUM_LOADERS; i++) {
    pthread_create(&loader_threads[i], NULL, loader, (void *)i);
  }
  while (1) {
    for (int i = 0; i < NUM_BAGS; i++) {
      if (statuses[i].checked && statuses[i].screened && statuses[i].loaded) {
        printf("Bag %d checked, screened, and loaded successfully\n", i);
      }
    }
  }
  return 0;
}