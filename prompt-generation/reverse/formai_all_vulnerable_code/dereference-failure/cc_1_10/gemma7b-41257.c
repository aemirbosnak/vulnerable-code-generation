//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SCHEDULER_MAX 10

typedef struct Task
{
  char name[20];
  int priority;
  int executionTime;
  struct Task* next;
} Task;

Task* createTask(char* name, int priority, int executionTime)
{
  Task* newTask = (Task*)malloc(sizeof(Task));
  strcpy(newTask->name, name);
  newTask->priority = priority;
  newTask->executionTime = executionTime;
  newTask->next = NULL;
  return newTask;
}

void addTask(Task** head, Task* newTask)
{
  if (*head == NULL)
  {
    *head = newTask;
  }
  else
  {
    (*head)->next = newTask;
  }
}

void scheduleTasks(Task* head)
{
  time_t currentTime = time(NULL);
  time_t nextExecutionTime = currentTime + 1;
  while (head)
  {
    if (head->executionTime <= nextExecutionTime)
    {
      printf("Executing task: %s\n", head->name);
      sleep(head->executionTime);
      nextExecutionTime = currentTime + head->executionTime;
    }
    head = head->next;
  }
}

int main()
{
  Task* head = NULL;
  addTask(&head, createTask("Task 1", 1, 5));
  addTask(&head, createTask("Task 2", 2, 3));
  addTask(&head, createTask("Task 3", 1, 2));

  scheduleTasks(head);

  return 0;
}