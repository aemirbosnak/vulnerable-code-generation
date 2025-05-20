//FormAI DATASET v1.0 Category: Task Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// define a task struct
typedef struct Task {
  int id;
  int interval;
  int nextRunTime;
  void (*taskFunc)(void);
} Task;

// define a task queue struct that links each task
typedef struct TaskQueueNode {
  Task *task;
  struct TaskQueueNode *next;
} TaskQueueNode;

// declare the function that will be called by the scheduler
void taskFunc1(void) {
  printf("Task 1 executed!\n");
}

void taskFunc2(void) {
  printf("Task 2 executed!\n");
}

// initialize the queue
TaskQueueNode *queueHead = NULL;

// function to add task to queue
void addTask(Task *task) {
  TaskQueueNode *newNode = (TaskQueueNode*) malloc(sizeof(TaskQueueNode));
  newNode->task = task;
  newNode->next = NULL;

  if (queueHead == NULL) {
    queueHead = newNode;
  } else {
    TaskQueueNode *currNode = queueHead;
    TaskQueueNode *prevNode = NULL;

    // find the right position to add to
    while (currNode != NULL && currNode->task->nextRunTime < task->nextRunTime) {
      prevNode = currNode;
      currNode = currNode->next;
    }

    // add the new node
    if (prevNode == NULL) {
      newNode->next = queueHead;
      queueHead = newNode;
    } else {
      prevNode->next = newNode;
      newNode->next = currNode;
    }
  }
}

// function to remove task from queue
void removeTask(Task *task) {
  TaskQueueNode *currNode = queueHead;
  TaskQueueNode *prevNode = NULL;

  while (currNode != NULL) {
    if (currNode->task == task) {
      if (prevNode == NULL) {
        queueHead = currNode->next;
      } else {
        prevNode->next = currNode->next;
      }
      free(currNode);
      break;
    }
    prevNode = currNode;
    currNode = currNode->next;
  }
}

// function to run the scheduler and execute tasks at the right intervals
void runScheduler(void) {
  int currentTime = 0;
  TaskQueueNode *currNode;
  Task *currTask;

  while (1) {
    // loop through the task queue
    currNode = queueHead;
    while (currNode != NULL) {
      currTask = currNode->task;

      // check if it's time to run the task
      if (currTask->nextRunTime <= currentTime) {
        // execute task function
        currTask->taskFunc();

        // update next run time for the task
        currTask->nextRunTime += currTask->interval;

        // move task to the right position in the task queue
        removeTask(currTask);
        addTask(currTask);
      }

      currNode = currNode->next;
    }

    currentTime++;
  }
}

int main(void) {
  // create tasks with different intervals
  Task task1 = {1, 3, 3, &taskFunc1};
  Task task2 = {2, 5, 5, &taskFunc2};

  // add tasks to queue
  addTask(&task1);
  addTask(&task2);

  // run the scheduler
  runScheduler();

  return 0;
}