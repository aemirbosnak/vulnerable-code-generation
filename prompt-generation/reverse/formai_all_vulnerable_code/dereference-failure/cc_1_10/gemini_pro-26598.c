//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Our own little thread library!

typedef struct thread_t {
  void *(*start_routine)(void *);
  void *arg;
  pthread_t tid;
} thread_t;

static void *thread_wrapper(void *arg) {
  thread_t *thread = (thread_t *)arg;
  return thread->start_routine(thread->arg);
}

int thread_create(thread_t *thread, void *(*start_routine)(void *), void *arg) {
  thread->start_routine = start_routine;
  thread->arg = arg;
  return pthread_create(&thread->tid, NULL, thread_wrapper, thread);
}

int thread_join(thread_t *thread, void **retval) {
  return pthread_join(thread->tid, retval);
}

// Our main program: a simple multi-threaded hello world!

static void *hello_world(void *arg) {
  char *name = (char *)arg;
  printf("Hello, world! From thread %s\n", name);
  return NULL;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <num_threads>\n", argv[0]);
    return 1;
  }

  int num_threads = atoi(argv[1]);
  thread_t threads[num_threads];

  for (int i = 0; i < num_threads; i++) {
    char name[16];
    snprintf(name, sizeof(name), "thread%d", i);
    thread_create(&threads[i], hello_world, name);
  }

  for (int i = 0; i < num_threads; i++) {
    thread_join(&threads[i], NULL);
  }

  return 0;
}