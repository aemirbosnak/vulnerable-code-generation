//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define NUM_TASKS 5
#define TASK_DELAY 1000

typedef struct Task {
  char name[20];
  void (*function)(void);
  struct Task* next;
} Task;

void task_A(void) {
  printf("Task A is running...\n");
  sleep(TASK_DELAY);
}

void task_B(void) {
  printf("Task B is running...\n");
  sleep(TASK_DELAY);
}

void task_C(void) {
  printf("Task C is running...\n");
  sleep(TASK_DELAY);
}

void task_D(void) {
  printf("Task D is running...\n");
  sleep(TASK_DELAY);
}

void task_E(void) {
  printf("Task E is running...\n");
  sleep(TASK_DELAY);
}

int main() {
  Task* head = NULL;
  for (int i = 0; i < NUM_TASKS; i++) {
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, "Task ");
    newTask->function = (void (*)(void))"task_"
      [i] + 'A';
    newTask->next = head;
    head = newTask;
  }

  struct timeval start, end;
  gettimeofday(&start, NULL);

  while (head) {
    head->function();
    head = head->next;
  }

  gettimeofday(&end, NULL);

  printf("Total time elapsed: %ld milliseconds\n", end.tv_sec - start.tv_sec * 1000 + end.tv_usec - start.tv_usec * 1000);

  return 0;
}