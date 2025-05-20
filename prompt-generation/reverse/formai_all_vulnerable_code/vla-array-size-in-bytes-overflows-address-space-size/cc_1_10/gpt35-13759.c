//FormAI DATASET v1.0 Category: Task Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Task struct to hold task attributes */
typedef struct {
    int id;
    int priority;
    int duration;
} Task;

/* Function to generate a random task */
Task generate_task(int id) {
    Task t;
    t.id = id;
    t.priority = rand() % 10 + 1;
    t.duration = rand() % 10 + 1;
    return t;
}

/* Function to display task details */
void print_task(Task t) {
    printf("Task ID: %d\nPriority: %d\nDuration: %d\n", t.id, t.priority, t.duration);
}

/* Function to swap tasks */
void swap(Task *a, Task *b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to sort tasks based on priority */
void sort_tasks(Task tasks[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (tasks[j].priority < tasks[j + 1].priority) {
                swap(&tasks[j], &tasks[j + 1]);
            }
        }
    }
}

/* Function to run a task */
void execute_task(Task t) {
    printf("Executing task %d for %d seconds...\n", t.id, t.duration);
    sleep(t.duration);
    printf("Task %d executed successfully.\n", t.id);
}

int main() {
    srand(time(NULL)); // Seed for random number generation

    int n, i;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    Task tasks[n];

    for (i = 0; i < n; i++) {
        tasks[i] = generate_task(i + 1);
    }

    printf("\nUnsorted tasks:\n\n");
    for (i = 0; i < n; i++) {
        print_task(tasks[i]);
        printf("\n");
    }

    printf("\nSorting the tasks based on priority...\n\n");
    sort_tasks(tasks, n);

    printf("\nSorted tasks:\n\n");
    for (i = 0; i < n; i++) {
        print_task(tasks[i]);
        printf("\n");
    }

    printf("\nExecuting the tasks in order of priority...\n\n");
    for (i = 0; i < n; i++) {
        execute_task(tasks[i]);
    }

    printf("\nAll tasks completed successfully.\n");

    return 0;
}