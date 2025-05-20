//FormAI DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/*****************************************************************
* NAME:             task_queue
*
* DESCRIPTION:      Struct that defines a task queue.
*
* MEMBERS:
*   - task:         Pointer to the task function to be executed.
*   - delay:        The amount of time in seconds to wait before
*                   executing the task.
*   - next:         Pointer to the next task in the queue.
*
******************************************************************/
typedef struct task_queue {
    void (*task)(void);
    int delay;
    struct task_queue *next;
} task_queue;

// Define the task queue head
task_queue *queue_head = NULL;

/*****************************************************************
* NAME:             add_task
*
* DESCRIPTION:      Add a new task to the task queue.
*
* PARAMETERS:
*   - task:         Pointer to the task function to be executed.
*   - delay:        The amount of time in seconds to wait before
*                   executing the task.
*
******************************************************************/
void add_task(void (*task)(void), int delay) {
    // Allocate memory for the new task
    task_queue *new_task = (task_queue *) malloc(sizeof(task_queue));
    new_task->task = task;
    new_task->delay = delay;
    new_task->next = NULL;

    // If the task queue is empty, set as the head
    if (queue_head == NULL) {
        queue_head = new_task;
        return;
    }

    // Add the new task to the end of the queue
    task_queue *current_task = queue_head;
    while (current_task->next != NULL) {
        current_task = current_task->next;
    }
    current_task->next = new_task;
}

/*****************************************************************
* NAME:             execute_task
*
* DESCRIPTION:      Execute the task at the head of the task queue.
*
******************************************************************/
void execute_task() {
    // If the task queue is empty, do nothing
    if (queue_head == NULL) {
        return;
    }

    // Execute the task at the head of the queue
    task_queue *current_task = queue_head;
    current_task->task();

    // Remove the executed task from the queue
    queue_head = current_task->next;
    free(current_task);
}

/*****************************************************************
* NAME:             print_hello
*
* DESCRIPTION:      Print "Hello, world!" to the console.
*
******************************************************************/
void print_hello() {
    printf("Hello, world!\n");
}

/*****************************************************************
* NAME:             print_time
*
* DESCRIPTION:      Print the current time to the console.
*
******************************************************************/
void print_time() {
    time_t current_time = time(NULL);
    printf("%s", ctime(&current_time));
}

/*****************************************************************
* NAME:             main
*
* DESCRIPTION:      The main program loop that executes the task
*                   queue.
*
******************************************************************/
int main() {
    // Add some sample tasks to the queue
    add_task(print_hello, 2);
    add_task(print_time, 5);

    // Continuously execute tasks from the queue
    while (1) {
        // Wait for the delay time of the first task
        sleep(queue_head->delay);

        // Execute the first task in the queue
        execute_task();
    }

    return 0;
}