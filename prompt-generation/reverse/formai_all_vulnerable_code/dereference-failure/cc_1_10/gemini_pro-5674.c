//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    char *name;
    char *reason;
    int day;
    int time;
    struct appointment *next;
} appointment;

appointment *head = NULL;

void add_appointment(char *name, char *reason, int day, int time) {
    appointment *new_appointment = malloc(sizeof(appointment));
    new_appointment->name = strdup(name);
    new_appointment->reason = strdup(reason);
    new_appointment->day = day;
    new_appointment->time = time;
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
        printf("%s - %s - %d - %d\n", current->name, current->reason, current->day, current->time);
        current = current->next;
    }
}

void delete_appointment(char *name) {
    appointment *current = head;
    appointment *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->name);
            free(current->reason);
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    // Add some appointments
    add_appointment("John Doe", "Meeting", 1, 10);
    add_appointment("Jane Smith", "Interview", 2, 11);
    add_appointment("Bob Jones", "Consultation", 3, 12);

    // Print the appointments
    printf("Appointments:\n");
    print_appointments();

    // Delete an appointment
    delete_appointment("Jane Smith");

    // Print the appointments again
    printf("\nAppointments after deletion:\n");
    print_appointments();

    return 0;
}