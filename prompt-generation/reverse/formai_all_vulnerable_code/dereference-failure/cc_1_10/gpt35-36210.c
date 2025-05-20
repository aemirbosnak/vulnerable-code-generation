//FormAI DATASET v1.0 Category: Task Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Task {
    int id;
    int priority;
    int time;
    struct Task* next_task;
} Task;

Task* create_task(int id, int priority, int time) {
    Task* task = (Task*) malloc(sizeof(Task));
    task->id = id;
    task->priority = priority;
    task->time = time;
    task->next_task = NULL;
    return task;
}

Task* add_task(Task* head, int id, int priority, int time) {
    Task* task = create_task(id, priority, time);
    if (head == NULL) {
        return task;
    }
    if (task->priority > head->priority) {
        task->next_task = head;
        return task;
    }
    Task* current_task = head;
    while (current_task->next_task != NULL && task->priority <= current_task->next_task->priority) {
        current_task = current_task->next_task;
    }
    task->next_task = current_task->next_task;
    current_task->next_task = task;
    return head;
}

Task* remove_task(Task* head, Task* task) {
    if (head == task) {
        head = head->next_task;
    } else {
        Task* current_task = head;
        while (current_task->next_task != task) {
            current_task = current_task->next_task;
        }
        current_task->next_task = task->next_task;
    }
    free(task);
    return head;
}

void run_task(Task* head) {
    if (head == NULL) {
        return;
    }
    printf("Running task %d for %d seconds\n", head->id, head->time);
    head->time--;
    if (head->time == 0) {
        head = remove_task(head, head);
    }
    run_task(head);
}

int main() {
    Task* task_queue = NULL;
    // Add tasks to the queue
    task_queue = add_task(task_queue, 1, 5, 3);
    task_queue = add_task(task_queue, 2, 3, 2);
    task_queue = add_task(task_queue, 3, 4, 4);
    task_queue = add_task(task_queue, 4, 2, 1);
    task_queue = add_task(task_queue, 5, 1, 5);
    // Run the tasks in priority order
    run_task(task_queue);
    return 0;
}