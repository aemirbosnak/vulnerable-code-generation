//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: Cyberpunk
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  char *name;
  int *age;
  pthread_t thread;
  pthread_mutex_t *lock;
} cyberpunk_thread;

void *cyberpunk_thread_run(void *arg) {
  cyberpunk_thread *thread = (cyberpunk_thread *)arg;
  pthread_mutex_lock(thread->lock);
  printf("Cyberpunk %s (age %d) says: 'I'm in the future!'\n", thread->name, *thread->age);
  sleep(1);
  pthread_mutex_unlock(thread->lock);
  return NULL;
}

int main() {
  // Initialize random number generator
  srand(time(NULL));

  // Create an array of cyberpunk threads
  int num_threads = 5;
  cyberpunk_thread threads[num_threads];

  // Create a shared mutex lock
  pthread_mutex_t lock;
  pthread_mutex_init(&lock, NULL);

  // Initialize each thread
  for (int i = 0; i < num_threads; i++) {
    threads[i].name = malloc(100);
    snprintf(threads[i].name, 100, "Cyberpunk %d", i + 1);
    threads[i].age = malloc(sizeof(int));
    *threads[i].age = rand() % 100;
    threads[i].lock = &lock;
    pthread_create(&threads[i].thread, NULL, cyberpunk_thread_run, &threads[i]);
  }

  // Join all threads
  for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i].thread, NULL);
  }

  // Destroy the mutex lock
  pthread_mutex_destroy(&lock);

  // Free allocated memory
  for (int i = 0; i < num_threads; i++) {
    free(threads[i].name);
    free(threads[i].age);
  }

  return 0;
}