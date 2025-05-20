//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Task {
    char name[50];
    int duration; // Duration in seconds
    struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, int duration) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->duration = duration;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        Task* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTask;
    }

    printf("Task '%s' added with duration %d seconds!\n", name, duration);
}

void viewTasks() {
    if (head == NULL) {
        printf("No tasks scheduled! Add some tasks to get started!\n");
        return;
    }

    Task* temp = head;
    printf("\nScheduled Tasks:\n");
    while (temp != NULL) {
        printf("Task: '%s' - Duration: %d seconds\n", temp->name, temp->duration);
        temp = temp->next;
    }
}

void executeTasks() {
    if (head == NULL) {
        printf("No tasks to execute! Add tasks first!\n");
        return;
    }

    printf("\nExecuting tasks!\n");
    Task* temp = head;
    while (temp != NULL) {
        printf("Starting task '%s'...\n", temp->name);
        sleep(temp->duration);
        printf("Task '%s' completed!\n", temp->name);

        Task* toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }

    head = NULL; // All tasks executed, so reset the head
    printf("All tasks completed!\n");
}

void freeTasks() {
    while (head != NULL) {
        Task* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice, duration;
    char name[50];

    do {
        printf("\n=== Welcome to the Task Scheduler ===\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Execute Tasks\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf("%s", name);
                printf("Enter task duration (in seconds): ");
                scanf("%d", &duration);
                addTask(name, duration);
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                executeTasks();
                break;

            case 4:
                printf("Exiting the Task Scheduler. Bye!\n");
                break;

            default:
                printf("Invalid option! Please choose 1, 2, 3, or 4.\n");
        }
    } while (choice != 4);

    freeTasks(); // Clean up any remaining tasks before exiting
    return 0;
}