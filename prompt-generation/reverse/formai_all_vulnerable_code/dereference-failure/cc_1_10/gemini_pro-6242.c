//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
typedef struct node {
    char *name;
    char *phone;
    int time;
    struct node *next;
} node_t;

// Appointment scheduler structure
typedef struct scheduler {
    node_t *head;
    node_t *tail;
} scheduler_t;

// Function to create a new node
node_t *create_node(char *name, char *phone, int time) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->name = strdup(name);
    new_node->phone = strdup(phone);
    new_node->time = time;
    new_node->next = NULL;

    return new_node;
}

// Function to create a new appointment scheduler
scheduler_t *create_scheduler() {
    scheduler_t *scheduler = (scheduler_t *)malloc(sizeof(scheduler_t));
    scheduler->head = NULL;
    scheduler->tail = NULL;

    return scheduler;
}

// Function to add a new appointment to the scheduler
void add_appointment(scheduler_t *scheduler, char *name, char *phone, int time) {
    node_t *new_node = create_node(name, phone, time);

    if (scheduler->head == NULL) {
        scheduler->head = new_node;
        scheduler->tail = new_node;
    } else {
        scheduler->tail->next = new_node;
        scheduler->tail = new_node;
    }
}

// Function to remove an appointment from the scheduler
void remove_appointment(scheduler_t *scheduler, char *name) {
    node_t *current = scheduler->head;
    node_t *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                scheduler->head = current->next;
            } else {
                previous->next = current->next;
            }

            free(current->name);
            free(current->phone);
            free(current);

            if (scheduler->head == NULL) {
                scheduler->tail = NULL;
            }

            return;
        }

        previous = current;
        current = current->next;
    }
}

// Function to print the appointments in the scheduler
void print_scheduler(scheduler_t *scheduler) {
    node_t *current = scheduler->head;

    while (current != NULL) {
        printf("%s %s %d\n", current->name, current->phone, current->time);
        current = current->next;
    }
}

// Function to free the memory allocated for the scheduler
void free_scheduler(scheduler_t *scheduler) {
    node_t *current = scheduler->head;

    while (current != NULL) {
        node_t *next = current->next;
        free(current->name);
        free(current->phone);
        free(current);
        current = next;
    }

    free(scheduler);
}

// Main function
int main() {
    // Create a new appointment scheduler
    scheduler_t *scheduler = create_scheduler();

    // Add some appointments to the scheduler
    add_appointment(scheduler, "John Doe", "555-1212", 10);
    add_appointment(scheduler, "Jane Doe", "555-1213", 11);
    add_appointment(scheduler, "Jack Doe", "555-1214", 12);

    // Print the appointments in the scheduler
    print_scheduler(scheduler);

    // Remove an appointment from the scheduler
    remove_appointment(scheduler, "Jane Doe");

    // Print the appointments in the scheduler
    print_scheduler(scheduler);

    // Free the memory allocated for the scheduler
    free_scheduler(scheduler);

    return 0;
}