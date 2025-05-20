//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: calm
#include <stdio.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 5

typedef struct Task {
  char name[20];
  int priority;
  time_t start_time;
  time_t end_time;
  struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, int priority, time_t start, time_t end) {
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->start_time = start;
  newTask->end_time = end;
  newTask->next = NULL;

  if (head == NULL) {
    head = newTask;
  } else {
    Task* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newTask;
  }
}

void scheduleTasks() {
  time_t now = time(NULL);

  Task* current = head;
  while (current) {
    if (now >= current->start_time && now < current->end_time) {
      printf("Task: %s, Priority: %d\n", current->name, current->priority);
    }
    current = current->next;
  }
}

int main() {
  addTask("Wake up", 1, 7 * 60 * 60, 8 * 60 * 60);
  addTask("Breakfast", 2, 8 * 60 * 60, 9 * 60 * 60);
  addTask("Work", 3, 9 * 60 * 60, 17 * 60 * 60);
  addTask("Lunch", 2, 13 * 60 * 60, 14 * 60 * 60);
  addTask("Study", 1, 15 * 60 * 60, 16 * 60 * 60);
  addTask("Dinner", 2, 17 * 60 * 60, 18 * 60 * 60);
  addTask("Relax", 3, 18 * 60 * 60, 19 * 60 * 60);
  addTask("Bedtime", 1, 19 * 60 * 60, 20 * 60 * 60);

  scheduleTasks();

  return 0;
}