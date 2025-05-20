//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Appointment structure
typedef struct Appointment {
    char *name;
    char *date;
    char *time;
    struct Appointment *next;
} Appointment;

// Linked list of appointments
Appointment *head = NULL;

// Function to create a new appointment
Appointment *create_appointment(char *name, char *date, char *time) {
    Appointment *new_appointment = malloc(sizeof(Appointment));
    new_appointment->name = strdup(name);
    new_appointment->date = strdup(date);
    new_appointment->time = strdup(time);
    new_appointment->next = NULL;
    return new_appointment;
}

// Function to add an appointment to the linked list
void add_appointment(Appointment *appointment) {
    if (head == NULL) {
        head = appointment;
    } else {
        Appointment *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = appointment;
    }
}

// Function to print the linked list of appointments
void print_appointments() {
    Appointment *current = head;
    while (current != NULL) {
        printf("%s %s %s\n", current->name, current->date, current->time);
        current = current->next;
    }
}

// Function to free the memory allocated for the linked list of appointments
void free_appointments() {
    Appointment *current = head;
    while (current != NULL) {
        Appointment *next = current->next;
        free(current->name);
        free(current->date);
        free(current->time);
        free(current);
        current = next;
    }
    head = NULL;
}

// Main function
int main() {
    // Create some sample appointments
    Appointment *appointment1 = create_appointment("John Doe", "2023-03-08", "10:00 AM");
    Appointment *appointment2 = create_appointment("Jane Smith", "2023-03-10", "11:00 AM");
    Appointment *appointment3 = create_appointment("Bill Jones", "2023-03-12", "12:00 PM");

    // Add the appointments to the linked list
    add_appointment(appointment1);
    add_appointment(appointment2);
    add_appointment(appointment3);

    // Print the linked list of appointments
    print_appointments();

    // Free the memory allocated for the linked list of appointments
    free_appointments();

    return 0;
}