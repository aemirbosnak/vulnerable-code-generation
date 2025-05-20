//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: complex
#include <stdio.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct Task {
    char name[20];
    int priority;
    time_t scheduled_time;
    struct Task* next;
} Task;

Task* createTask(char* name, int priority, time_t scheduled_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->scheduled_time = scheduled_time;
    newTask->next = NULL;
    return newTask;
}

void addTask(Task** head, char* name, int priority, time_t scheduled_time) {
    Task* newTask = createTask(name, priority, scheduled_time);
    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    while (head) {
        if (head->scheduled_time <= now) {
            printf("%s has started.\n", head->name);
            head = head->next;
        } else {
            break;
        }
    }
}

int main() {
    Task* head = NULL;
    addTask(&head, "Task 1", 1, time(NULL) + 60);
    addTask(&head, "Task 2", 2, time(NULL) + 30);
    addTask(&head, "Task 3", 3, time(NULL) + 90);

    scheduleTasks(head);

    return 0;
}