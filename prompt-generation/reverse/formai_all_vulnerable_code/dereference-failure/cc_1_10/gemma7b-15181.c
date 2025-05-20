//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char name[20];
    int start_hour, start_minute, end_hour, end_minute;
    struct Task* next;
} Task;

void add_task(Task** head) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    printf("Enter task name: ");
    scanf("%s", new_task->name);
    printf("Enter start hour (24-hour format): ");
    scanf("%d", &new_task->start_hour);
    printf("Enter start minute: ");
    scanf("%d", &new_task->start_minute);
    printf("Enter end hour (24-hour format): ");
    scanf("%d", &new_task->end_hour);
    printf("Enter end minute: ");
    scanf("%d", &new_task->end_minute);
    new_task->next = *head;
    *head = new_task;
}

void display_schedule(Task* head) {
    printf("Your schedule:\n");
    while (head) {
        printf("%s (%d:%d - %d:%d)\n", head->name, head->start_hour, head->start_minute, head->end_hour, head->end_minute);
        head = head->next;
    }
}

int main() {
    Task* head = NULL;
    int choice;

    printf("Welcome to the Task Scheduler!\n");

    while (1) {
        printf("1. Add Task\n");
        printf("2. Display Schedule\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task(&head);
                break;
            case 2:
                display_schedule(head);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Press any key to continue...");
        getchar();
    }

    return 0;
}