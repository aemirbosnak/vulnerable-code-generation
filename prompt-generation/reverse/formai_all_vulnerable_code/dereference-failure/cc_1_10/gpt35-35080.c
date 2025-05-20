//FormAI DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Task {
    int id;
    int priority;
    int arrival_time;
    int burst_time;
    int remaining_time;
    bool is_finished;
} Task;

typedef struct Node {
    Task task;
    struct Node* next;
} Node;

Node* head = NULL;

void add_task(Task new_task) {
    Node* new_node = malloc(sizeof(Node));
    new_node->task = new_task;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void delete_task(int id) {
    if (head == NULL) {
        printf("No tasks to delete.\n");
    } else {
        Node* current = head;
        Node* previous = NULL;

        while ((current != NULL) && (current->task.id != id)) {
            previous = current;
            current = current->next;
        }

        if (current == NULL) {
            printf("Task not found.\n");
        } else {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
        }
    }
}

void display_tasks() {
    if (head == NULL) {
        printf("No tasks to display.\n");
    } else {
        printf("ID\tPriority\tArrival Time\tBurst Time\tRemaining Time\tStatus\n");
        Node* current = head;
        while (current != NULL) {
            char* status = current->task.is_finished ? "Finished" : "Incomplete";
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%s\n", current->task.id, current->task.priority, current->task.arrival_time, current->task.burst_time, current->task.remaining_time, status);
            current = current->next;
        }
    }
}

void execute_task(Task* task) {
    task->remaining_time = task->remaining_time - 1;
    if (task->remaining_time == 0) {
        task->is_finished = true;
    }
}

void execute_next_task() {
    if (head == NULL) {
        printf("No tasks to execute.\n");
    } else {
        Node* current = head;
        Node* selected = NULL;

        while (current != NULL) {
            if ((selected == NULL) || (current->task.priority > selected->task.priority)) {
                selected = current;
            }
            current = current->next;
        }

        execute_task(&selected->task);
        printf("Executing Task ID %d\n", selected->task.id);
        if (selected->task.is_finished) {
            printf("Task ID %d is finished.\n", selected->task.id);
            delete_task(selected->task.id);
        }
    }
}

int main() {
    Task task1 = {1, 3, 0, 3, 3, false};
    Task task2 = {2, 5, 1, 2, 2, false};
    Task task3 = {3, 1, 2, 4, 4, false};
    Task task4 = {4, 2, 5, 1, 1, false};

    add_task(task1);
    add_task(task2);
    add_task(task3);
    add_task(task4);

    printf("Initial Task List:\n");
    display_tasks();

    while (head != NULL) {
        execute_next_task();
    }

    printf("All tasks have been executed.\n");
    return 0;
}