//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Task {
  void (*func)(void *);
  void *arg;
} Task;

typedef struct TaskQueue {
  Task *tasks;
  int head;
  int tail;
  int size;
} TaskQueue;

TaskQueue *task_queue;

void task_queue_init(int size) {
  task_queue = malloc(sizeof(TaskQueue));
  task_queue->tasks = malloc(sizeof(Task) * size);
  task_queue->head = 0;
  task_queue->tail = 0;
  task_queue->size = size;
}

void task_queue_destroy() {
  free(task_queue->tasks);
  free(task_queue);
}

void task_queue_push(Task *task) {
  if ((task_queue->tail + 1) % task_queue->size == task_queue->head) {
    printf("Task queue is full!\n");
    return;
  }
  task_queue->tasks[task_queue->tail] = *task;
  task_queue->tail = (task_queue->tail + 1) % task_queue->size;
}

Task *task_queue_pop() {
  if (task_queue->head == task_queue->tail) {
    return NULL;
  }
  Task *task = &task_queue->tasks[task_queue->head];
  task_queue->head = (task_queue->head + 1) % task_queue->size;
  return task;
}

void *task_thread(void *arg) {
  while (1) {
    Task *task = task_queue_pop();
    if (task == NULL) {
      break;
    }
    task->func(task->arg);
  }
  return NULL;
}

int main() {
  task_queue_init(10);

  pthread_t threads[4];

  for (int i = 0; i < 4; i++) {
    pthread_create(&threads[i], NULL, task_thread, NULL);
  }

  for (int i = 0; i < 100; i++) {
    Task task;
    task.func = printf;
    task.arg = "Hello from task %d!\n";
    task_queue_push(&task);
  }

  for (int i = 0; i < 4; i++) {
    pthread_join(threads[i], NULL);
  }

  task_queue_destroy();

  return 0;
}