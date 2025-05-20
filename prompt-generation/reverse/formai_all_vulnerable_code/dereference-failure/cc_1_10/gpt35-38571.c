//FormAI DATASET v1.0 Category: Task Scheduler ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

// Define a task structure
typedef struct task {
    char* name;
    int priority;
    int delay_time;
    bool active;
} Task;

// Define a node structure for linked list
typedef struct node {
    Task* t;
    struct node* next;
} Node;

// Function to add a task to the list
void add_task(Node** head, Task* t) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->t = t;
    new_node->next = NULL;
    
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to delete a task from the list
void delete_task(Node** head, Task* t) {
    Node* current = *head;
    Node* previous = NULL;
    while (current != NULL) {
        if (current->t == t) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->t->name);
            free(current->t);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Function to print all active tasks in the list
void print_tasks(Node* head) {
    Node* current = head;
    while (current != NULL) {
        if (current->t->active) {
            printf("Task: %s, Priority: %d, Delay Time: %d\n", current->t->name, current->t->priority, current->t->delay_time);
        }
        current = current->next;
    }
}

// Function to execute a task
void execute_task(Task* t) {
    printf("Executing task: %s\n", t->name);
    sleep(t->delay_time); // simulate some delay time
    printf("Task %s completed!\n", t->name);
}

// Function to execute tasks in the list
void execute_tasks(Node* head) {
    Node* current = head;
    while (current != NULL) {
        if (current->t->active) {
            execute_task(current->t);
        }
        current->t->active = false;
        current = current->next;
    }
}

int main() {
    // Initialize the list with some tasks
    Node* head = NULL;
    
    Task* task1 = (Task*) malloc(sizeof(Task));
    task1->name = strdup("Task 1");
    task1->priority = 1;
    task1->delay_time = 3;
    task1->active = true;
    add_task(&head, task1);
    
    Task* task2 = (Task*) malloc(sizeof(Task));
    task2->name = strdup("Task 2");
    task2->priority = 2;
    task2->delay_time = 1;
    task2->active = true;
    add_task(&head, task2);
    
    Task* task3 = (Task*) malloc(sizeof(Task));
    task3->name = strdup("Task 3");
    task3->priority = 3;
    task3->delay_time = 2;
    task3->active = true;
    add_task(&head, task3);
    
    // Print all active tasks
    printf("Active Tasks:\n");
    print_tasks(head);
    
    // Execute tasks and mark them inactive
    execute_tasks(head);
    
    // Print all active tasks
    printf("Active Tasks:\n");
    print_tasks(head);
    
    // Add a new task and execute tasks again
    Task* task4 = (Task*) malloc(sizeof(Task));
    task4->name = strdup("Task 4");
    task4->priority = 1;
    task4->delay_time = 2;
    task4->active = true;
    add_task(&head, task4);
    
    printf("Active Tasks:\n");
    print_tasks(head);
    
    execute_tasks(head);
    
    printf("Active Tasks:\n");
    print_tasks(head);
    
    // Clean up memory
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete_task(&head, temp->t);
    }
    
    return 0;
}