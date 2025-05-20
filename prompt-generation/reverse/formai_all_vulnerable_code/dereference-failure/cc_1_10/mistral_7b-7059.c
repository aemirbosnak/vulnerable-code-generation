//MISTRAL-7B DATASET v1.0 Category: Task Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 100

typedef struct Task {
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    time_t deadline;
    struct Task *next;
} Task;

Task *head = NULL;

void add_task(char *name, char *description, time_t deadline) {
    Task *new_task = (Task *) malloc(sizeof(Task));
    strcpy(new_task->name, name);
    strcpy(new_task->description, description);
    new_task->deadline = deadline;
    new_task->next = head;
    head = new_task;
}

int check_deadline() {
    Task *current = head;
    time_t current_time = time(NULL);

    while (current != NULL && current->deadline <= current_time) {
        printf("\nTask %s with deadline %s (%ld seconds ago) has been executed.\n", current->name, ctime(&current->deadline), (long int) (current_time - current->deadline));
        Task *temp = current;
        current = current->next;
        free(temp);
    }

    return current == NULL;
}

int main() {
    int choice;
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    time_t deadline;

    while (1) {
        printf("\nTask Scheduler\n1. Add task\n2. Execute tasks\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf("%s", name);
                printf("Enter task description: ");
                scanf("%s", description);
                printf("Enter deadline (in seconds): ");
                scanf("%ld", &deadline);
                add_task(name, description, deadline);
                break;
            case 2:
                if (check_deadline()) {
                    printf("No tasks with deadlines passed.\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}