//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASK_COUNT 10

typedef struct task_node {
    char task_name[20];
    int task_priority;
    struct task_node* next;
} task_node;

void add_task(task_node** head, char* task_name, int task_priority) {
    task_node* new_node = (task_node*)malloc(sizeof(task_node));
    strcpy(new_node->task_name, task_name);
    new_node->task_priority = task_priority;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
}

void print_tasks(task_node* head) {
    while (head) {
        printf("%s (priority: %d)\n", head->task_name, head->task_priority);
        head = head->next;
    }
}

void schedule_tasks(task_node* head) {
    time_t now = time(NULL);
    for (task_node* current = head; current; current = current->next) {
        // Calculate task completion time
        time_t completion_time = now + current->task_priority * 60;

        // If task completion time has arrived, execute the task
        if (completion_time <= now) {
            printf("Executing task: %s\n", current->task_name);
            // Simulate task execution
            sleep(2);
        }
    }
}

int main() {
    task_node* head = NULL;

    // Add some tasks
    add_task(&head, "Do homework", 3);
    add_task(&head, "Go to the park", 2);
    add_task(&head, "Buy groceries", 1);

    // Schedule tasks
    schedule_tasks(head);

    // Print remaining tasks
    print_tasks(head);

    return 0;
}