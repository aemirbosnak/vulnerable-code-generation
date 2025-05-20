//FormAI DATASET v1.0 Category: Task Scheduler ; Style: thoughtful
/* 
This program demonstrates a C task scheduler. This scheduler can be used to schedule tasks at specific times. 
It uses a priority queue to keep track of tasks based on their scheduled time.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10 // maximum number of tasks that can be scheduled
#define MAX_NAME_LENGTH 20 // maximum length of task name

// Task struct that will be scheduled
typedef struct task {
    char name[MAX_NAME_LENGTH];
    time_t scheduled_time; // time the task is scheduled to run
} task_t;

typedef struct priority_queue {
    int size; // current number of items in the queue
    int capacity; // max number of items the queue can hold
    task_t *data; // pointer to the array that holds the tasks
} priority_queue_t;

// initialize the priority queue with a given capacity
priority_queue_t* init_priority_queue(int capacity) {
    priority_queue_t *pq = (priority_queue_t*) malloc(sizeof(priority_queue_t));
    pq->size = 0;
    pq->capacity = capacity;
    pq->data = (task_t*) malloc(capacity * sizeof(task_t));
    return pq;
}

// returns 1 if the queue is empty, 0 otherwise
int is_empty(priority_queue_t *pq) {
    return (pq->size == 0);
}

// returns 1 if the queue is full, 0 otherwise
int is_full(priority_queue_t *pq) {
    return (pq->size == pq->capacity);
}

// swap two tasks in the priority queue
void swap(task_t *a, task_t *b) {
    task_t tmp = *a;
    *a = *b;
    *b = tmp;
}

// push a new task into the queue
// uses the scheduled_time to place it in the correct position based on the priority
void push(priority_queue_t *pq, task_t task) {
    if (is_full(pq)) {
        printf("Scheduler is full, unable to schedule new task.\n");
        return;
    }

    pq->data[pq->size] = task;
    int i = pq->size;
    pq->size++;

    // bubble up the task to its correct position
    while (i > 0 && pq->data[i].scheduled_time < pq->data[(i-1)/2].scheduled_time) {
        swap(&(pq->data[i]), &(pq->data[(i-1)/2]));
        i = (i-1) / 2;
    }
}

// pop the top element from the queue
task_t pop(priority_queue_t *pq) {
    if (is_empty(pq)) {
        printf("Scheduler is empty, no tasks to run.\n");
        task_t empty_task = {"", 0};
        return empty_task;
    }

    task_t task = pq->data[0];
    pq->size--;
    pq->data[0] = pq->data[pq->size];

    // bubble down the new root to its correct position
    int i = 0;
    while (2*i+1 < pq->size) {
        int child = 2*i+1;
        if (child + 1 < pq->size && pq->data[child+1].scheduled_time < pq->data[child].scheduled_time) {
            child++;
        }

        if (pq->data[i].scheduled_time > pq->data[child].scheduled_time) {
            swap(&(pq->data[i]), &(pq->data[child]));
            i = child;
        } else {
            break;
        }
    }

    return task;
}

// print the current tasks in the scheduler
void print_tasks(priority_queue_t *pq) {
    if (is_empty(pq)) {
        printf("Scheduler is empty, no tasks to print.\n");
        return;
    }

    for (int i = 0; i < pq->size; i++) {
        printf("%s - scheduled for %s\n", pq->data[i].name, ctime(&(pq->data[i].scheduled_time)));
    }
}

// main function to test the task scheduler
int main() {
    // initialize the priority queue
    priority_queue_t *pq = init_priority_queue(MAX_TASKS);

    // first task to be scheduled
    task_t task1 = {"Task 1", time(NULL) + 30};
    push(pq, task1);

    // second task to be scheduled
    task_t task2 = {"Task 2", time(NULL) + 60};
    push(pq, task2);

    // print the current tasks in the scheduler
    printf("Current tasks in the scheduler:\n");
    print_tasks(pq);

    // pop the next task and run it
    task_t next_task = pop(pq);
    printf("Running task: %s - scheduled for %s\n", next_task.name, ctime(&(next_task.scheduled_time)));

    // print the current tasks in the scheduler
    printf("Current tasks in the scheduler:\n");
    print_tasks(pq);

    return 0;
}