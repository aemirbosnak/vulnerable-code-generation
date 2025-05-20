//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    char *name;
    char *description;
    int start_time;
    int end_time;
    struct appointment *next;
} appointment;

appointment *head = NULL;

void add_appointment(char *name, char *description, int start_time, int end_time) {
    appointment *new_appointment = malloc(sizeof(appointment));
    new_appointment->name = strdup(name);
    new_appointment->description = strdup(description);
    new_appointment->start_time = start_time;
    new_appointment->end_time = end_time;
    new_appointment->next = NULL;

    if (head == NULL) {
        head = new_appointment;
    } else {
        appointment *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_appointment;
    }
}

void print_appointments() {
    appointment *current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Description: %s\n", current->description);
        printf("Start time: %d\n", current->start_time);
        printf("End time: %d\n", current->end_time);
        printf("\n");
        current = current->next;
    }
}

int main() {
    add_appointment("John Smith", "Meeting with client", 9, 10);
    add_appointment("Jane Doe", "Doctor's appointment", 10, 11);
    add_appointment("Bill Jones", "Lunch with friend", 12, 1);
    add_appointment("Mary Johnson", "Movie with boyfriend", 7, 9);

    print_appointments();

    return 0;
}