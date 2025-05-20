//FormAI DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Struct for task
typedef struct Task {
    int id; // Task id
    char *name; // Task name
    void (*function)(); // Task function
    int run_time; // Task run time
    struct Task *next; // Pointer to next task
} Task;

// Function to create new task
Task *create_task(int id, char *name, void (*function)(), int run_time) {
    Task *new_task = (Task*) malloc(sizeof(Task));
    new_task->id = id;
    new_task->name = name;
    new_task->function = function;
    new_task->run_time = run_time;
    new_task->next = NULL;
    return new_task;
}

// Function to add task to scheduler
Task *add_task(Task *head, Task *new_task) {
    // If head is null (no tasks in scheduler) set new task to head
    if (head == NULL) {
        return new_task;
    }
    // If new task has less runtime than head, add it to beginning of list
    if (new_task->run_time < head->run_time) {
        new_task->next = head;
        return new_task;
    }
    Task *current_task = head;
    // Traverse list to find proper place for task based on runtime
    while (current_task->next != NULL && current_task->next->run_time <= new_task->run_time) {
        current_task = current_task->next;
    }
    new_task->next = current_task->next;
    current_task->next = new_task;
    return head;
}

// Function to remove task by id from scheduler
Task *remove_task(Task *head, int id) {
    Task *current_task = head;
    Task *prev_task = NULL;
    // Traverse list to find task with matching id
    while (current_task != NULL && current_task->id != id) {
        prev_task = current_task;
        current_task = current_task->next;
    }
    // Task with matching id not found
    if (current_task == NULL) {
        return head;
    }
    // If task to remove is the head, set next task as head
    if (prev_task == NULL) {
        head = current_task->next;
    } else {
        prev_task->next = current_task->next;
    }
    free(current_task);
    return head;
}

// Function to run tasks in scheduler
void run_tasks(Task *head) {
    Task *current_task = head;
    int time_counter = 0;
    // Traverse list and run tasks based on runtime
    while (current_task != NULL) {
        printf("[%d] RUNNING TASK '%s'\n", time_counter, current_task->name);
        current_task->function();
        time_counter += current_task->run_time;
        current_task = current_task->next;
    }
}

// Example task function
void task_function() {
    printf("This is a task function.\n");
}

int main() {
    // Create tasks
    Task *task1 = create_task(1, "Task 1", task_function, 2);
    Task *task2 = create_task(2, "Task 2", task_function, 1);
    Task *task3 = create_task(3, "Task 3", task_function, 3);
    Task *task4 = create_task(4, "Task 4", task_function, 5);
    // Add tasks to scheduler
    Task *scheduler = NULL;
    scheduler = add_task(scheduler, task1);
    scheduler = add_task(scheduler, task2);
    scheduler = add_task(scheduler, task3);
    scheduler = add_task(scheduler, task4);
    // Run scheduler
    run_tasks(scheduler);
    // Remove task from scheduler
    printf("\nREMOVING TASK 2\n");
    scheduler = remove_task(scheduler, 2);
    // Run scheduler again
    run_tasks(scheduler);
    return 0;
}