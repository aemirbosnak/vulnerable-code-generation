//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    char *name;
    char *date;
    char *time;
    char *location;
    char *description;
    struct appointment *next;
} appointment;

appointment *head = NULL;  // Head of the linked list of appointments

// Function to create a new appointment
appointment *create_appointment(char *name, char *date, char *time, char *location, char *description) {
    appointment *new_appointment = malloc(sizeof(appointment));
    new_appointment->name = strdup(name);
    new_appointment->date = strdup(date);
    new_appointment->time = strdup(time);
    new_appointment->location = strdup(location);
    new_appointment->description = strdup(description);
    new_appointment->next = NULL;
    return new_appointment;
}

// Function to add an appointment to the linked list
void add_appointment(appointment *new_appointment) {
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

// Function to print the linked list of appointments
void print_appointments() {
    appointment *current = head;
    while (current != NULL) {
        printf("Appointment with %s on %s at %s in %s (%s)\n", current->name, current->date, current->time, current->location, current->description);
        current = current->next;
    }
}

// Function to free the memory allocated for the linked list of appointments
void free_appointments() {
    appointment *current = head;
    while (current != NULL) {
        appointment *next = current->next;
        free(current->name);
        free(current->date);
        free(current->time);
        free(current->location);
        free(current->description);
        free(current);
        current = next;
    }
}

int main() {
    // Create some appointments
    appointment *appointment1 = create_appointment("John Smith", "2023-02-14", "7:00 PM", "The Eiffel Tower", "Valentine's Day dinner");
    appointment *appointment2 = create_appointment("Jane Doe", "2023-03-08", "8:00 PM", "The Louvre", "Anniversary dinner");
    appointment *appointment3 = create_appointment("Michael Jones", "2023-04-12", "9:00 PM", "The Arc de Triomphe", "Birthday dinner");

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