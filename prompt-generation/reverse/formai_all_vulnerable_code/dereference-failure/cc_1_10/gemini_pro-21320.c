//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// This is a minimal implementation of a threading library. It provides only the basics:
// thread creation, termination, and synchronization.

// A thread is represented by a struct that contains a pointer to the thread's function,
// a pointer to the thread's argument, and a flag that indicates whether the thread is
// running.
struct thread {
  void *(*start_routine)(void *);
  void *arg;
  int running;
};

// A mutex is represented by a struct that contains a flag that indicates whether the
// mutex is locked.
struct mutex {
  int locked;
};

// A condition variable is represented by a struct that contains a queue of threads that
// are waiting on the condition variable.
struct condition_variable {
  struct thread *queue;
};

// Create a new thread.
struct thread *thread_create(void *(*start_routine)(void *), void *arg) {
  struct thread *thread = malloc(sizeof(struct thread));
  thread->start_routine = start_routine;
  thread->arg = arg;
  thread->running = 1;
  return thread;
}

// Terminate a thread.
void thread_join(struct thread *thread) {
  while (thread->running) {
    // Yield the CPU to other threads.
    sched_yield();
  }
  free(thread);
}

// Create a new mutex.
struct mutex *mutex_create() {
  struct mutex *mutex = malloc(sizeof(struct mutex));
  mutex->locked = 0;
  return mutex;
}

// Lock a mutex.
void mutex_lock(struct mutex *mutex) {
  while (mutex->locked) {
    // Yield the CPU to other threads.
    sched_yield();
  }
  mutex->locked = 1;
}

// Unlock a mutex.
void mutex_unlock(struct mutex *mutex) {
  mutex->locked = 0;
}

// Create a new condition variable.
struct condition_variable *condition_variable_create() {
  struct condition_variable *condition_variable = malloc(sizeof(struct condition_variable));
  condition_variable->queue = NULL;
  return condition_variable;
}

// Wait on a condition variable.
void condition_variable_wait(struct condition_variable *condition_variable, struct mutex *mutex) {
  // Add the current thread to the queue of threads waiting on the condition variable.
  condition_variable->queue = thread_create(NULL, NULL);

  // Unlock the mutex and yield the CPU to other threads.
  mutex_unlock(mutex);
  sched_yield();

  // The thread has been woken up, so remove it from the queue.
  condition_variable->queue = NULL;
}

// Signal a condition variable.
void condition_variable_signal(struct condition_variable *condition_variable) {
  // Wake up the first thread in the queue of threads waiting on the condition variable.
  if (condition_variable->queue != NULL) {
    thread_join(condition_variable->queue);
  }
}

// Broadcast a condition variable.
void condition_variable_broadcast(struct condition_variable *condition_variable) {
  // Wake up all of the threads in the queue of threads waiting on the condition variable.
  while (condition_variable->queue != NULL) {
    thread_join(condition_variable->queue);
  }
}

// A simple test program.
int main() {
  // Create a mutex.
  struct mutex *mutex = mutex_create();

  // Create a condition variable.
  struct condition_variable *condition_variable = condition_variable_create();

  // Create a thread that waits on the condition variable.
  struct thread *thread = thread_create(NULL, NULL);

  // Lock the mutex.
  mutex_lock(mutex);

  // Signal the condition variable.
  condition_variable_signal(condition_variable);

  // Unlock the mutex.
  mutex_unlock(mutex);

  // Join the thread.
  thread_join(thread);

  return 0;
}