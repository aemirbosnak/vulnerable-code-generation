//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: cheerful
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[50];
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

void insertTask(Task** head, char* name, time_t start_time, time_t end_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->start_time = start_time;
    newTask->end_time = end_time;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void printTasks(Task* head) {
    while (head) {
        printf("%s, Start: %ld, End: %ld\n", head->name, head->start_time, head->end_time);
        head = head->next;
    }
}

int main() {
    Task* head = NULL;

    insertTask(&head, "Wake up", 7 * 60 * 60, 8 * 60 * 60);
    insertTask(&head, "Breakfast", 8 * 60 * 60, 9 * 60 * 60);
    insertTask(&head, "Work", 9 * 60 * 60, 17 * 60 * 60);
    insertTask(&head, "Lunch", 12 * 60 * 60, 13 * 60 * 60);
    insertTask(&head, "Nap", 13 * 60 * 60, 14 * 60 * 60);
    insertTask(&head, "Work", 14 * 60 * 60, 17 * 60 * 60);
    insertTask(&head, "Dinner", 18 * 60 * 60, 19 * 60 * 60);
    insertTask(&head, "Relax", 19 * 60 * 60, 20 * 60 * 60);

    printTasks(head);

    return 0;
}