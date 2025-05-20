//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

// Struct to represent a task
typedef struct Task {
    int id;
    char name[50];
    time_t execution_time;
    struct Task* next;
} Task;

// Head of the task linked list
Task* head = NULL;
int task_count = 0;

// Function to create a new task
Task* create_task(const char* name, int delay) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    new_task->id = task_count++;
    strncpy(new_task->name, name, sizeof(new_task->name) - 1);
    new_task->execution_time = time(NULL) + delay;
    new_task->next = NULL;
    return new_task;
}

// Function to add a task to the scheduler
void add_task(const char* name, int delay) {
    Task* new_task = create_task(name, delay);
    if (head == NULL) {
        head = new_task;
    } else {
        Task* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_task;
    }
    printf("Task '%s' added with ID %d scheduled to run in %d seconds.\n", name, new_task->id, delay);
}

// Function to execute a task
void execute_task(Task* task) {
    printf("Executing task: '%s' (ID: %d)\n", task->name, task->id);
    // Simulating task execution with sleep
    sleep(1);
    printf("Task '%s' completed.\n", task->name);
}

// Function to run the scheduler
void run_scheduler() {
    while (head != NULL) {
        time_t now = time(NULL);
        Task* temp = head;
        Task* prev = NULL;

        while (temp != NULL) {
            if (temp->execution_time <= now) {
                execute_task(temp);
                // Remove the task from the list
                if (prev == NULL) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                Task* to_free = temp;
                temp = temp->next;
                free(to_free);
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        sleep(1); // Sleep to prevent busy waiting
    }
}

// Function to handle signal for cleanup
void signal_handler(int sig) {
    if (sig == SIGINT) {
        printf("\nScheduler terminated by user.\n");
        while (head != NULL) {
            Task* temp = head;
            head = head->next;
            free(temp);
        }
        exit(0);
    }
}

// Function to print the current tasks
void print_tasks() {
    Task* temp = head;
    if (temp == NULL) {
        printf("No scheduled tasks.\n");
        return;
    }
    
    printf("Scheduled Tasks:\n");
    while (temp != NULL) {
        printf("ID: %d, Name: '%s', Execute At: %s", temp->id, temp->name, ctime(&(temp->execution_time)));
        temp = temp->next;
    }
}

int main() {
    signal(SIGINT, signal_handler); // Handle termination signal
    add_task("Task1", 3);
    add_task("Task2", 5);
    add_task("Task3", 1);
    
    print_tasks(); // Print current tasks
    printf("Starting the task scheduler...\n");
    
    run_scheduler(); // Run the task scheduler

    return 0;
}