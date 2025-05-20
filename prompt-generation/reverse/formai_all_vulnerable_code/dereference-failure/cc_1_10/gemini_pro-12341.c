//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

// Structure to represent a task
typedef struct task {
    char *name;             // Name of the task
    int priority;          // Priority of the task (higher value means higher priority)
    int arrival_time;      // Arrival time of the task in milliseconds
    int execution_time;    // Execution time of the task in milliseconds
    int remaining_time;    // Remaining execution time of the task in milliseconds
    int start_time;        // Start time of the task in milliseconds
    int finish_time;       // Finish time of the task in milliseconds
    struct task *next;     // Pointer to the next task in the queue
} task;

// Function to create a new task
task *create_task(char *name, int priority, int arrival_time, int execution_time) {
    task *new_task = (task *)malloc(sizeof(task));
    new_task->name = name;
    new_task->priority = priority;
    new_task->arrival_time = arrival_time;
    new_task->execution_time = execution_time;
    new_task->remaining_time = execution_time;
    new_task->start_time = 0;
    new_task->finish_time = 0;
    new_task->next = NULL;
    return new_task;
}

// Function to insert a new task into the queue in ascending order of arrival time
void insert_task(task **head, task *new_task) {
    task *current = *head;
    task *previous = NULL;

    // If the queue is empty or the new task has the highest priority, insert at the beginning
    if (*head == NULL || new_task->arrival_time < (*head)->arrival_time) {
        new_task->next = *head;
        *head = new_task;
        return;
    }

    // Otherwise, find the correct position to insert the new task
    while (current != NULL && new_task->arrival_time >= current->arrival_time) {
        previous = current;
        current = current->next;
    }

    // Insert the new task after the previous task
    new_task->next = current;
    previous->next = new_task;
}

// Function to print the queue of tasks
void print_queue(task *head) {
    task *current = head;
    while (current != NULL) {
        printf("Task: %s, Priority: %d, Arrival Time: %d, Execution Time: %d\n", current->name, current->priority, current->arrival_time, current->execution_time);
        current = current->next;
    }
}

// Function to schedule the tasks using the Round-Robin scheduling algorithm
void schedule_tasks(task *head, int quantum) {
    task *current = head;
    int time = 0;

    // While there are still tasks to be executed
    while (current != NULL) {

        // If the current task has remaining time, execute it for one quantum
        if (current->remaining_time > 0) {
            if (current->remaining_time <= quantum) {
                // If the remaining time is less than or equal to the quantum, execute the remaining time
                time += current->remaining_time;
                current->remaining_time = 0;
                current->finish_time = time;
            } else {
                // If the remaining time is greater than the quantum, execute for one quantum
                time += quantum;
                current->remaining_time -= quantum;
            }
        }

        // Move to the next task in the queue
        current = current->next;

        // If we have reached the end of the queue, go back to the beginning
        if (current == NULL) {
            current = head;
        }
    }
}

// Function to print the schedule of tasks
void print_schedule(task *head) {
    task *current = head;
    printf("Task Schedule:\n");
    while (current != NULL) {
        printf("Task: %s, Start Time: %d, Finish Time: %d\n", current->name, current->start_time, current->finish_time);
        current = current->next;
    }
}

// Main function
int main() {
    // Create a queue of tasks
    task *head = NULL;
    insert_task(&head, create_task("Task 1", 1, 0, 10));
    insert_task(&head, create_task("Task 2", 2, 5, 5));
    insert_task(&head, create_task("Task 3", 3, 10, 15));
    insert_task(&head, create_task("Task 4", 4, 15, 10));

    // Print the queue of tasks
    printf("Task Queue:\n");
    print_queue(head);

    // Schedule the tasks using the Round-Robin scheduling algorithm with a quantum of 5
    schedule_tasks(head, 5);

    // Print the schedule of tasks
    print_schedule(head);

    return 0;
}