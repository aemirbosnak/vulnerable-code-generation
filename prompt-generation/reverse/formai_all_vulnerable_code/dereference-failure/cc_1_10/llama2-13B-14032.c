//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_NUMBER 100

// Structure to hold the task information
typedef struct {
    int num;   // Number to calculate the factorial of
    int result; // Result of the calculation
} task_t;

// Function to create a new task
void *create_task(int num) {
    task_t *task = malloc(sizeof(task_t));
    task->num = num;
    return task;
}

// Function to execute a task
void *execute_task(void *task) {
    task_t *t = task;
    int result = factorial(t->num);
    t->result = result;
    return NULL;
}

// Function to calculate the factorial of a number
int factorial(int num) {
    int result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

int main() {
    // Create a list of tasks
    task_t *tasks[MAX_NUMBER];
    for (int i = 0; i < MAX_NUMBER; i++) {
        tasks[i] = create_task(i);
    }

    // Start the tasks
    for (int i = 0; i < MAX_NUMBER; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            execute_task(tasks[i]);
            exit(0);
        }
    }

    // Wait for the tasks to complete
    for (int i = 0; i < MAX_NUMBER; i++) {
        wait(NULL);
    }

    // Print the results
    for (int i = 0; i < MAX_NUMBER; i++) {
        printf("%d! = %d\n", tasks[i]->num, tasks[i]->result);
    }

    return 0;
}