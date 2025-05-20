//FormAI DATASET v1.0 Category: Task Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

typedef struct Task {
    int task_id;
    int priority;
    int execution_time;
} Task;

typedef struct TaskList {
    Task task;
    struct TaskList* next;
} TaskList;

void add_task(TaskList** head, Task task) {
    TaskList* new_task_list = (TaskList*) malloc(sizeof(TaskList));
    new_task_list->task = task;
    new_task_list->next = NULL;

    if (*head == NULL) {
        *head = new_task_list;
        return;
    }

    TaskList* current = *head;

    while (current->next != NULL) current = current->next;

    current->next = new_task_list;
}

Task get_highest_priority_task(TaskList** head) {
    TaskList* current = *head;
    Task highest_priority_task = current->task;

    while (current != NULL) {
        if (current->task.priority > highest_priority_task.priority)
        highest_priority_task = current->task;

        current = current->next;
    }

    return highest_priority_task;
}

void remove_task(TaskList** head, Task task) {
    TaskList* current = *head;

    if (current == NULL) return;

    if (current->task.task_id == task.task_id) {
        *head = current->next;
        free(current);
        return;
    }

    TaskList* previous = NULL;

    while (current != NULL && current->task.task_id != task.task_id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) return;

    previous->next = current->next;
    free(current);
}

void print_task_list(TaskList* head) {
    while (head != NULL) {
        printf("Task ID: %d\n", head->task.task_id);
        printf("Priority: %d\n", head->task.priority);
        printf("Execution Time: %d\n", head->task.execution_time);

        head = head->next;
    }
}

int main() {
    TaskList* task_list_head = NULL;

    Task task_1 = {1, 3, 5};
    Task task_2 = {2, 1, 10};
    Task task_3 = {3, 2, 7};

    add_task(&task_list_head, task_1);
    add_task(&task_list_head, task_2);
    add_task(&task_list_head, task_3);

    printf("Task List:\n\n");
    print_task_list(task_list_head);

    printf("\nExecuting Tasks:\n\n");

    while (task_list_head != NULL) {
        Task highest_priority_task = get_highest_priority_task(&task_list_head);

        int task_time_remaining = highest_priority_task.execution_time;
        printf("Task ID: %d (Priority: %d)\n", highest_priority_task.task_id, highest_priority_task.priority);

        while (task_time_remaining > 0) {
        printf("%d seconds remaining...\n", task_time_remaining);
        task_time_remaining--;
        }

        remove_task(&task_list_head, highest_priority_task);

        printf("\n");
    }

    printf("All tasks completed!\n");
}