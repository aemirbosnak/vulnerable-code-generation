//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the appointment structure
typedef struct appointment {
    int id;
    char *description;
    time_t start_time;
    time_t end_time;
    struct appointment *next;
} appointment;

// Define the appointment scheduler structure
typedef struct appointment_scheduler {
    appointment *head;
    appointment *tail;
} appointment_scheduler;

// Create a new appointment
appointment *create_appointment(int id, char *description, time_t start_time, time_t end_time) {
    appointment *new_appointment = malloc(sizeof(appointment));
    new_appointment->id = id;
    new_appointment->description = description;
    new_appointment->start_time = start_time;
    new_appointment->end_time = end_time;
    new_appointment->next = NULL;
    return new_appointment;
}

// Add an appointment to the scheduler
void add_appointment(appointment_scheduler *scheduler, appointment *new_appointment) {
    if (scheduler->head == NULL) {
        scheduler->head = new_appointment;
        scheduler->tail = new_appointment;
    } else {
        scheduler->tail->next = new_appointment;
        scheduler->tail = new_appointment;
    }
}

// Remove an appointment from the scheduler
void remove_appointment(appointment_scheduler *scheduler, int id) {
    appointment *current_appointment = scheduler->head;
    appointment *previous_appointment = NULL;

    while (current_appointment != NULL) {
        if (current_appointment->id == id) {
            if (previous_appointment == NULL) {
                scheduler->head = current_appointment->next;
            } else {
                previous_appointment->next = current_appointment->next;
            }

            if (current_appointment == scheduler->tail) {
                scheduler->tail = previous_appointment;
            }

            free(current_appointment);
            break;
        }

        previous_appointment = current_appointment;
        current_appointment = current_appointment->next;
    }
}

// Print the appointments in the scheduler
void print_appointments(appointment_scheduler *scheduler) {
    appointment *current_appointment = scheduler->head;

    while (current_appointment != NULL) {
        printf("Appointment ID: %d\n", current_appointment->id);
        printf("Description: %s\n", current_appointment->description);
        printf("Start time: %s\n", ctime(&current_appointment->start_time));
        printf("End time: %s\n", ctime(&current_appointment->end_time));
        printf("\n");

        current_appointment = current_appointment->next;
    }
}

// Free the memory allocated for the appointments
void free_appointments(appointment_scheduler *scheduler) {
    appointment *current_appointment = scheduler->head;

    while (current_appointment != NULL) {
        appointment *next_appointment = current_appointment->next;
        free(current_appointment);
        current_appointment = next_appointment;
    }

    scheduler->head = NULL;
    scheduler->tail = NULL;
}

// Main function
int main() {
    // Create a new appointment scheduler
    appointment_scheduler *scheduler = malloc(sizeof(appointment_scheduler));
    scheduler->head = NULL;
    scheduler->tail = NULL;

    // Create some appointments
    appointment *appointment1 = create_appointment(1, "Meeting with client", time(NULL), time(NULL) + 3600);
    appointment *appointment2 = create_appointment(2, "Conference call", time(NULL) + 3600, time(NULL) + 7200);
    appointment *appointment3 = create_appointment(3, "Lunch with team", time(NULL) + 7200, time(NULL) + 10800);

    // Add the appointments to the scheduler
    add_appointment(scheduler, appointment1);
    add_appointment(scheduler, appointment2);
    add_appointment(scheduler, appointment3);

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Remove an appointment from the scheduler
    remove_appointment(scheduler, 2);

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Free the memory allocated for the appointments
    free_appointments(scheduler);
    free(scheduler);

    return 0;
}