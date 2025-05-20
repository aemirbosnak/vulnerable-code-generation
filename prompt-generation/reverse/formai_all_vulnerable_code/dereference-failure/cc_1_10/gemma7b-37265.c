//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

Task* insertTask(Task* head, char* name, int priority) {
    Task* newNode = malloc(sizeof(Task));
    strcpy(newNode->name, name);
    newNode->priority = priority;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Task* current = head;
        Task* previous = NULL;
        while (current) {
            if (newNode->priority < current->priority) {
                previous = current;
                current = current->next;
            } else {
                break;
            }
        }

        if (previous) {
            previous->next = newNode;
        } else {
            head = newNode;
        }
    }

    return head;
}

void printSchedule(Task* head) {
    printf("Schedule:\n");
    for (Task* current = head; current; current = current->next) {
        printf("  %-20s (priority: %d)\n", current->name, current->priority);
    }
}

int main() {
    Task* head = NULL;

    insertTask(head, "Do homework", 3);
    insertTask(head, "Eat dinner", 2);
    insertTask(head, "Go to school", 1);
    insertTask(head, "Watch TV", 4);

    printSchedule(head);

    sleep(5);

    insertTask(head, "Clean room", 5);

    printSchedule(head);

    return 0;
}