//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct {
  int time; // in seconds
  void (*task)(void*);
  void* arg;
} task_t;

typedef struct {
  int size;
  int capacity;
  task_t* tasks;
} task_queue_t;

task_queue_t* task_queue_create(int capacity) {
  task_queue_t* queue = malloc(sizeof(task_queue_t));
  queue->size = 0;
  queue->capacity = capacity;
  queue->tasks = malloc(sizeof(task_t) * capacity);
  return queue;
}

void task_queue_destroy(task_queue_t* queue) {
  free(queue->tasks);
  free(queue);
}

int task_queue_push(task_queue_t* queue, task_t task) {
  if (queue->size == queue->capacity) {
    return -1;
  }
  queue->tasks[queue->size++] = task;
  return 0;
}

task_t task_queue_pop(task_queue_t* queue) {
  if (queue->size == 0) {
    return (task_t){0, NULL, NULL};
  }
  return queue->tasks[--queue->size];
}

int task_queue_is_empty(task_queue_t* queue) {
  return queue->size == 0;
}

void task_scheduler_run(task_queue_t* queue) {
  while (!task_queue_is_empty(queue)) {
    task_t task = task_queue_pop(queue);
    sleep(task.time);
    task.task(task.arg);
  }
}

void task1(void* arg) {
  printf("Task 1: The moon is a green cheese.\n");
}

void task2(void* arg) {
  printf("Task 2: The sky is falling, the sky is falling!\n");
}

void task3(void* arg) {
  printf("Task 3: I'm melting, I'm melting!\n");
}

int main() {
  srand(time(NULL));

  task_queue_t* queue = task_queue_create(10);

  for (int i = 0; i < 10; i++) {
    task_t task = {
      .time = rand() % 10 + 1,
      .task = (i % 3 == 0) ? task1 : ((i % 3 == 1) ? task2 : task3),
      .arg = NULL
    };
    task_queue_push(queue, task);
  }

  task_scheduler_run(queue);

  task_queue_destroy(queue);

  return 0;
}