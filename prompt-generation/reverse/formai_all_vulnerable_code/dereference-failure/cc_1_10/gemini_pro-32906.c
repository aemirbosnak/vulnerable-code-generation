//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appointment struct
typedef struct Appointment {
    char *name;
    char *time;
    struct Appointment *next;
} Appointment;

// Appointment list
Appointment *head = NULL;

// Create a new appointment
Appointment *create_appointment(char *name, char *time) {
    Appointment *new_appt = malloc(sizeof(Appointment));
    new_appt->name = strdup(name);
    new_appt->time = strdup(time);
    new_appt->next = NULL;
    return new_appt;
}

// Add an appointment to the list
void add_appointment(Appointment *appt) {
    if (head == NULL) {
        head = appt;
    } else {
        Appointment *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = appt;
    }
}

// Print the list of appointments
void print_appointments() {
    Appointment *current = head;
    while (current != NULL) {
        printf("%s %s\n", current->name, current->time);
        current = current->next;
    }
}

// Free the memory for an appointment
void free_appointment(Appointment *appt) {
    free(appt->name);
    free(appt->time);
    free(appt);
}

// Free the memory for the list of appointments
void free_appointments() {
    Appointment *current = head;
    while (current != NULL) {
        Appointment *next = current->next;
        free_appointment(current);
        current = next;
    }
}

// Get the number of appointments
int get_num_appointments() {
    int count = 0;
    Appointment *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Get an appointment by name
Appointment *get_appointment_by_name(char *name) {
    Appointment *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Delete an appointment by name
void delete_appointment_by_name(char *name) {
    if (head == NULL) {
        return;
    }

    Appointment *current = head;
    Appointment *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free_appointment(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Main function
int main() {
    // Create some appointments
    Appointment *appt1 = create_appointment("John Doe", "10:00 AM");
    Appointment *appt2 = create_appointment("Jane Doe", "11:00 AM");
    Appointment *appt3 = create_appointment("Bob Smith", "12:00 PM");

    // Add the appointments to the list
    add_appointment(appt1);
    add_appointment(appt2);
    add_appointment(appt3);

    // Print the list of appointments
    printf("Appointments:\n");
    print_appointments();

    // Get the number of appointments
    int num_appts = get_num_appointments();
    printf("Number of appointments: %d\n", num_appts);

    // Get an appointment by name
    Appointment *appt = get_appointment_by_name("John Doe");
    if (appt != NULL) {
        printf("Appointment for John Doe: %s\n", appt->time);
    } else {
        printf("No appointment for John Doe found.\n");
    }

    // Delete an appointment by name
    delete_appointment_by_name("Jane Doe");

    // Print the list of appointments again
    printf("Appointments after deleting Jane Doe:\n");
    print_appointments();

    // Free the memory for the list of appointments
    free_appointments();

    return 0;
}