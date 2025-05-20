//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Task structure
struct task {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
    struct task *next;
};

// Queue structure
struct queue {
    struct task *front;
    struct task *rear;
};

// Function to create a new task
struct task *create_task(int id, int arrival_time, int burst_time, int priority) {
    struct task *new_task = malloc(sizeof(struct task));
    new_task->id = id;
    new_task->arrival_time = arrival_time;
    new_task->burst_time = burst_time;
    new_task->remaining_time = burst_time;
    new_task->priority = priority;
    new_task->next = NULL;
    return new_task;
}

// Function to enqueue a task
void enqueue(struct queue *q, struct task *t) {
    if (q->front == NULL) {
        q->front = q->rear = t;
    } else {
        q->rear->next = t;
        q->rear = t;
    }
}

// Function to dequeue a task
struct task *dequeue(struct queue *q) {
    if (q->front == NULL) {
        return NULL;
    } else {
        struct task *t = q->front;
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        return t;
    }
}

// Function to sort the tasks by arrival time and then by priority
void sort_tasks(struct task **tasks, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tasks[j]->arrival_time > tasks[j + 1]->arrival_time) {
                struct task *temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            } else if (tasks[j]->arrival_time == tasks[j + 1]->arrival_time) {
                if (tasks[j]->priority < tasks[j + 1]->priority) {
                    struct task *temp = tasks[j];
                    tasks[j] = tasks[j + 1];
                    tasks[j + 1] = temp;
                }
            }
        }
    }
}

// Function to schedule the tasks using the Shortest Job First (SJF) algorithm
void schedule_tasks_sjf(struct task **tasks, int n) {
    int time = 0;
    struct queue ready_queue;
    ready_queue.front = ready_queue.rear = NULL;

    while (n > 0) {
        // Enqueue all tasks that have arrived at current time
        for (int i = 0; i < n; i++) {
            if (tasks[i]->arrival_time <= time) {
                enqueue(&ready_queue, tasks[i]);
                tasks[i] = NULL;
                n--;
            }
        }

        // Sort the ready queue by burst time
        struct task *sorted_queue = NULL;
        while (ready_queue.front != NULL) {
            struct task *t = dequeue(&ready_queue);
            if (sorted_queue == NULL) {
                sorted_queue = t;
            } else {
                struct task *temp = sorted_queue;
                while (temp->next != NULL && temp->next->burst_time < t->burst_time) {
                    temp = temp->next;
                }
                if (temp->next == NULL) {
                    temp->next = t;
                } else {
                    t->next = temp->next;
                    temp->next = t;
                }
            }
        }
        ready_queue.front = ready_queue.rear = sorted_queue;

        // Execute the task at the front of the ready queue
        struct task *t = dequeue(&ready_queue);
        printf("Task %d is executing at time %d\n", t->id, time);
        t->remaining_time--;
        time++;

        // If the task is completed, remove it from the list of tasks
        if (t->remaining_time == 0) {
            n--;
        } else {
            enqueue(&ready_queue, t);
        }
    }
}

// Function to schedule the tasks using the Round Robin (RR) algorithm
void schedule_tasks_rr(struct task **tasks, int n) {
    int time = 0;
    struct queue ready_queue;
    ready_queue.front = ready_queue.rear = NULL;

    while (n > 0) {
        // Enqueue all tasks that have arrived at current time
        for (int i = 0; i < n; i++) {
            if (tasks[i]->arrival_time <= time) {
                enqueue(&ready_queue, tasks[i]);
                tasks[i] = NULL;
                n--;
            }
        }

        // Execute the tasks in the ready queue using round robin
        struct task *t = dequeue(&ready_queue);
        printf("Task %d is executing at time %d\n", t->id, time);
        t->remaining_time--;
        time++;

        // If the task is completed, remove it from the list of tasks
        if (t->remaining_time == 0) {
            n--;
        } else {
            enqueue(&ready_queue, t);
        }
    }
}

// Main function
int main() {
    // Create an array of tasks
    struct task *tasks[] = {
        create_task(1, 0, 10, 1),
        create_task(2, 2, 7, 2),
        create_task(3, 4, 15, 3),
        create_task(4, 6, 5, 4),
        create_task(5, 8, 12, 5),
    };

    // Sort the tasks by arrival time and then by priority
    sort_tasks(tasks, 5);

    // Schedule the tasks using the Shortest Job First (SJF) algorithm
    printf("SJF Scheduling:\n");
    schedule_tasks_sjf(tasks, 5);

    // Create an array of tasks again for round robin scheduling
    struct task *tasks2[] = {
        create_task(1, 0, 10, 1),
        create_task(2, 2, 7, 2),
        create_task(3, 4, 15, 3),
        create_task(4, 6, 5, 4),
        create_task(5, 8, 12, 5),
    };

    // Schedule the tasks using the Round Robin (RR) algorithm
    printf("\nRR Scheduling:\n");
    schedule_tasks_rr(tasks2, 5);

    return 0;
}