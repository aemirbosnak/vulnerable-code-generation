//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: Linus Torvalds
// Linus Torvalds-style C Task Scheduler Example
// Remember, kids: real programmers don't use comments.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Task structure
typedef struct task {
    void (*func)(void *);
    void *arg;
    struct task *next;
} task_t;

// Task queue
task_t *head = NULL;

// Add a task to the queue
void schedule(void (*func)(void *), void *arg) {
    task_t *new = malloc(sizeof(task_t));
    new->func = func;
    new->arg = arg;
    new->next = NULL;

    if (head == NULL) {
        head = new;
    } else {
        task_t *cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new;
    }
}

// Run the next task in the queue
void run_next_task() {
    if (head == NULL) {
        return;
    }

    task_t *cur = head;
    head = cur->next;
    cur->func(cur->arg);
    free(cur);
}

// Task 1: Print "Hello, world!"
void task1(void *arg) {
    printf("Hello, world!\n");
}

// Task 2: Sleep for 1 second and then print "I'm awake!"
void task2(void *arg) {
    sleep(1);
    printf("I'm awake!\n");
}

// Main function
int main() {
    // Schedule tasks
    schedule(task1, NULL);
    schedule(task2, NULL);

    // Run tasks until the queue is empty
    while (head != NULL) {
        run_next_task();
    }

    return 0;
}