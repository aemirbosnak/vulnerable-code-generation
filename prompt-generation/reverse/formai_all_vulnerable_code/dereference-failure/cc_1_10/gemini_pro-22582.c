//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Task structure
typedef struct task {
    int id;             // Task ID
    int arrival_time;   // Task arrival time
    int burst_time;     // Task burst time
    int priority;       // Task priority
    int remaining_time; // Remaining time to complete the task
} task;

// Task queue
typedef struct queue {
    task *tasks;      // Array of tasks
    int count;        // Number of tasks in the queue
    int head;         // Index of the first task in the queue
    int tail;         // Index of the last task in the queue
} queue;

// Function to initialize the task queue
queue *init_queue() {
    queue *q = malloc(sizeof(queue));
    q->tasks = malloc(sizeof(task) * 100);
    q->count = 0;
    q->head = 0;
    q->tail = 0;
    return q;
}

// Function to insert a task into the task queue
void enqueue(queue *q, task t) {
    q->tasks[q->tail] = t;
    q->tail = (q->tail + 1) % 100;
    q->count++;
}

// Function to remove a task from the task queue
task dequeue(queue *q) {
    task t = q->tasks[q->head];
    q->head = (q->head + 1) % 100;
    q->count--;
    return t;
}

// Function to compare two tasks based on their priority
int compare_tasks(const void *a, const void *b) {
    task *task1 = (task *)a;
    task *task2 = (task *)b;
    return task1->priority - task2->priority;
}

// Function to schedule tasks using the Shortest Remaining Time First algorithm
void srtf(queue *q) {
    // Sort tasks based on their arrival time
    qsort(q->tasks, q->count, sizeof(task), compare_tasks);

    // Initialize the current time
    int current_time = 0;

    // While there are tasks in the queue
    while (q->count > 0) {
        // Get the task with the shortest remaining time
        task t = dequeue(q);

        // Update the current time
        current_time += t.burst_time;

        // Print the task information
        printf("Task %d completed at time %d\n", t.id, current_time);
    }
}

// Main function
int main() {
    // Initialize the task queue
    queue *q = init_queue();

    // Create and enqueue tasks
    for (int i = 0; i < 10; i++) {
        task t;
        t.id = i + 1;
        t.arrival_time = rand() % 10;
        t.burst_time = rand() % 10;
        t.priority = rand() % 10;
        t.remaining_time = t.burst_time;
        enqueue(q, t);
    }

    // Print sorted by arrival time queue
    queue temp = *q;
    q = init_queue();
    int i = 0;
    while (temp.count > 0)
    {
        task t = dequeue(&temp);
        if (t.arrival_time == i)
        {
            enqueue(q, t);
        }
        else
        {
            enqueue(&temp, t);
        }
        i++;
    }
    q = &temp;
    
    // Sort tasks based on their priority
    qsort(q->tasks, q->count, sizeof(task), compare_tasks);

    // Print sorted by priority queue
    printf("Sorted tasks based on priority:\n");
    for (int i = 0; i < q->count; i++) {
        printf("Task %d, Arrival time: %d, Burst time: %d, Priority: %d\n", q->tasks[i].id, q->tasks[i].arrival_time, q->tasks[i].burst_time, q->tasks[i].priority);
    }

    // Schedule tasks using the Shortest Remaining Time First algorithm
    srtf(q);

    return 0;
}