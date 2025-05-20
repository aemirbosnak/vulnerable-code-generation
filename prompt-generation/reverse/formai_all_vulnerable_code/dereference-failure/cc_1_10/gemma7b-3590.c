//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: authentic
#include <stdio.h>
#include <time.h>

#define NUM_TASKS 5

typedef struct Task {
    char name[20];
    int priority;
    int estimated_time;
    struct Task* next;
} Task;

void addTask(Task** head, char* name, int priority, int estimated_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->estimated_time = estimated_time;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    int i = 0;

    printf("Scheduled tasks for today:\n");

    while (head) {
        int estimated_time = head->estimated_time;
        int remaining_time = estimated_time - now;

        if (remaining_time > 0) {
            printf("%s (estimated completion: %d minutes)\n", head->name, remaining_time);
        } else {
            printf("%s has already been completed.\n", head->name);
        }

        head = head->next;
    }
}

int main() {
    Task* head = NULL;

    addTask(&head, "Wash dishes", 3, 20);
    addTask(&head, "Do laundry", 2, 15);
    addTask(&head, "Clean the kitchen", 4, 30);
    addTask(&head, "Water the plants", 1, 10);
    addTask(&head, "Mop the floor", 3, 25);

    scheduleTasks(head);

    return 0;
}