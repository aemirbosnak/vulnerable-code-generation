//FormAI DATASET v1.0 Category: Task Scheduler ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct task {
    int id;
    int time;
    bool completed;
} Task;

typedef struct task_node {
    Task *task;
    struct task_node *next;
} TaskNode;

TaskNode *head = NULL;

void addTask(int id, int time) {
    Task *task = (Task*) malloc(sizeof(Task));
    task->id = id;
    task->time = time;
    task->completed = false;
    
    TaskNode *node = (TaskNode*) malloc(sizeof(TaskNode));
    node->task = task;
    node->next = NULL;
    
    if (head == NULL) {
        head = node;
    } else {
        TaskNode *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
    printf("Task added successfully!\n");
}

void scheduleTasks() {
    int total_time = 0;
    TaskNode *current = head;
    while (current != NULL) {
        if (current->task->completed == false) {
            total_time += current->task->time;
        }
        current = current->next;
    }
    
    printf("\nTotal time required for all tasks: %d\n", total_time);
}

void completeTask(int id) {
    TaskNode *current = head;
    while (current != NULL) {
        if (current->task->id == id) {
            current->task->completed = true;
            printf("Task %d marked as complete!\n", id);
            return;
        }
        current = current->next;
    }
    printf("Task %d not found!\n", id);
}

int main() {
    int choice, id, time;
    do {
        printf("\nSelect an option:\n");
        printf("1. Add a task\n");
        printf("2. Schedule tasks\n");
        printf("3. Complete a task\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter task id: ");
                scanf("%d", &id);
                printf("Enter task time: ");
                scanf("%d", &time);
                addTask(id, time);
                break;
            case 2:
                scheduleTasks();
                break;
            case 3:
                printf("\nEnter task id to complete: ");
                scanf("%d", &id);
                completeTask(id);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        
    } while (choice != 4);
    
    return 0;
}