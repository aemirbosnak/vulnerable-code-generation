//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appointment struct
typedef struct Appointment {
    char *name;
    char *time;
    char *reason;
    struct Appointment *next;
} Appointment;

// Appointment scheduler struct
typedef struct AppointmentScheduler {
    Appointment *head;
    Appointment *tail;
    int size;
} AppointmentScheduler;

// Create a new appointment scheduler
AppointmentScheduler *new_appointment_scheduler() {
    AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
    scheduler->head = NULL;
    scheduler->tail = NULL;
    scheduler->size = 0;
    return scheduler;
}

// Add a new appointment to the scheduler
void add_appointment(AppointmentScheduler *scheduler, char *name, char *time, char *reason) {
    Appointment *new_appointment = malloc(sizeof(Appointment));
    new_appointment->name = strdup(name);
    new_appointment->time = strdup(time);
    new_appointment->reason = strdup(reason);
    new_appointment->next = NULL;

    if (scheduler->size == 0) {
        scheduler->head = new_appointment;
        scheduler->tail = new_appointment;
    } else {
        scheduler->tail->next = new_appointment;
        scheduler->tail = new_appointment;
    }

    scheduler->size++;
}

// Remove an appointment from the scheduler
void remove_appointment(AppointmentScheduler *scheduler, char *name) {
    Appointment *current = scheduler->head;
    Appointment *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                scheduler->head = current->next;
            } else {
                previous->next = current->next;
            }

            if (current == scheduler->tail) {
                scheduler->tail = previous;
            }

            free(current->name);
            free(current->time);
            free(current->reason);
            free(current);

            scheduler->size--;
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Appointment not found.\n");
}

// Print the appointments in the scheduler
void print_appointments(AppointmentScheduler *scheduler) {
    Appointment *current = scheduler->head;

    while (current != NULL) {
        printf("%s %s %s\n", current->name, current->time, current->reason);
        current = current->next;
    }
}

// Free the memory used by the scheduler
void free_appointment_scheduler(AppointmentScheduler *scheduler) {
    Appointment *current = scheduler->head;

    while (current != NULL) {
        Appointment *next = current->next;
        free(current->name);
        free(current->time);
        free(current->reason);
        free(current);
        current = next;
    }

    free(scheduler);
}

// Main function
int main() {
    // Create a new appointment scheduler
    AppointmentScheduler *scheduler = new_appointment_scheduler();

    // Add some appointments to the scheduler
    add_appointment(scheduler, "John Doe", "10:00 AM", "Meeting");
    add_appointment(scheduler, "Jane Smith", "11:00 AM", "Interview");
    add_appointment(scheduler, "Bob Jones", "12:00 PM", "Lunch");

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Remove an appointment from the scheduler
    remove_appointment(scheduler, "Bob Jones");

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Free the memory used by the scheduler
    free_appointment_scheduler(scheduler);

    return 0;
}