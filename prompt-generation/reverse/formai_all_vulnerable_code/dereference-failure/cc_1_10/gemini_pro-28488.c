//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appointment structure
typedef struct Appointment {
    char *name;
    char *time;
    struct Appointment *next;
} Appointment;

// Linked list of appointments
Appointment *appointments = NULL;

// Create a new appointment
Appointment *create_appointment(char *name, char *time) {
    Appointment *new_appointment = malloc(sizeof(Appointment));
    new_appointment->name = strdup(name);
    new_appointment->time = strdup(time);
    new_appointment->next = NULL;
    return new_appointment;
}

// Add an appointment to the linked list
void add_appointment(Appointment *appointment) {
    if (appointments == NULL) {
        appointments = appointment;
    } else {
        Appointment *current = appointments;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = appointment;
    }
}

// Print the linked list of appointments
void print_appointments() {
    Appointment *current = appointments;
    while (current != NULL) {
        printf("%s %s\n", current->name, current->time);
        current = current->next;
    }
}

// Free the linked list of appointments
void free_appointments() {
    Appointment *current = appointments;
    while (current != NULL) {
        Appointment *next = current->next;
        free(current->name);
        free(current->time);
        free(current);
        current = next;
    }
}

// Main function
int main() {
    // Create some appointments
    Appointment *appointment1 = create_appointment("John Doe", "10:00 AM");
    Appointment *appointment2 = create_appointment("Jane Doe", "11:00 AM");
    Appointment *appointment3 = create_appointment("Bill Smith", "12:00 PM");

    // Add the appointments to the linked list
    add_appointment(appointment1);
    add_appointment(appointment2);
    add_appointment(appointment3);

    // Print the linked list of appointments
    print_appointments();

    // Free the linked list of appointments
    free_appointments();

    return 0;
}