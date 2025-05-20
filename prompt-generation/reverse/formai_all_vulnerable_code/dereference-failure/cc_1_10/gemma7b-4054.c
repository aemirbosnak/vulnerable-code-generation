//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

Task* head = NULL;

void addTask(char* name, time_t start, time_t end) {
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->start_time = start;
    newTask->end_time = end;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        Task* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newTask;
    }
}

void printTasks() {
    Task* current = head;
    printf("Tasks:\n");
    while (current) {
        printf("%s, Start: %d, End: %d\n", current->name, current->start_time, current->end_time);
        current = current->next;
    }
}

int main() {
    addTask("Hack the Mainframe", 10, 12);
    addTask("Infiltrate the Server", 12, 14);
    addTask("Destroy the World", 14, 16);

    printTasks();

    return 0;
}