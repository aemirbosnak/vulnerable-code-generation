//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct task {
    int id;
    int arrival_time;
    int execution_time;
    int remaining_time;
    int priority;
} task;

typedef struct node {
    task data;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

void enqueue(task new_task) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = new_task;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

task dequeue() {
    if (head == NULL) {
        printf("Error: Queue is empty!\n");
        exit(1);
    }

    task dequeued_task = head->data;
    node *temp = head;
    head = head->next;
    free(temp);

    if (head == NULL) {
        tail = NULL;
    }

    return dequeued_task;
}

void print_queue() {
    node *current = head;

    while (current != NULL) {
        printf("Task ID: %d, Arrival Time: %d, Execution Time: %d, Remaining Time: %d, Priority: %d\n",
            current->data.id, current->data.arrival_time, current->data.execution_time, current->data.remaining_time, current->data.priority);
        current = current->next;
    }
}

int main() {
    // Initialize the task scheduler
    int num_tasks = 10;
    int time_quantum = 10;
    int current_time = 0;

    // Create a queue of tasks
    srand(time(NULL));
    for (int i = 0; i < num_tasks; i++) {
        task new_task;
        new_task.id = i + 1;
        new_task.arrival_time = rand() % 100;
        new_task.execution_time = rand() % 100;
        new_task.remaining_time = new_task.execution_time;
        new_task.priority = rand() % 10;
        enqueue(new_task);
    }

    // Run the task scheduler
    while (head != NULL) {
        // Get the next task from the queue
        task current_task = dequeue();

        // Check if the task has arrived yet
        if (current_task.arrival_time > current_time) {
            // If the task has not arrived yet, put it back in the queue and move on to the next task
            enqueue(current_task);
            continue;
        }

        // Execute the task for the time quantum
        if (current_task.remaining_time > time_quantum) {
            current_task.remaining_time -= time_quantum;
            enqueue(current_task);
        } else {
            // If the task has finished executing, print a message
            printf("Task %d completed at time %d\n", current_task.id, current_time);
        }

        // Increment the current time
        current_time++;
    }

    return 0;
}