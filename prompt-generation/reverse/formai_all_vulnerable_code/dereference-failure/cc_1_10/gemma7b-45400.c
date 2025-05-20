//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE 10

typedef struct Task {
    char name[20];
    int priority;
    int time_slot;
    struct Task* next;
} Task;

Task* insert_task(Task* head, char* name, int priority, int time_slot) {
    Task* new_task = (Task*)malloc(sizeof(Task));
    strcpy(new_task->name, name);
    new_task->priority = priority;
    new_task->time_slot = time_slot;
    new_task->next = NULL;

    if (head == NULL) {
        head = new_task;
    } else {
        Task* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = new_task;
    }

    return head;
}

void print_schedule(Task* head) {
    printf("**Task Scheduler:**\n");
    printf("-----------------------\n");
    Task* current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Priority: %d\n", current->priority);
        printf("Time Slot: %d\n", current->time_slot);
        printf("\n");
        current = current->next;
    }
}

int main() {
    Task* head = NULL;

    // Insert tasks
    insert_task(head, "Homework", 3, 10);
    insert_task(head, "Project", 2, 12);
    insert_task(head, "Meeting", 1, 14);
    insert_task(head, "Lunch", 4, 16);

    // Print schedule
    print_schedule(head);

    return 0;
}