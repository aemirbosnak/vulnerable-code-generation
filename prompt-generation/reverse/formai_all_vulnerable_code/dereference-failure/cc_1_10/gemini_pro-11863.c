//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appointment struct
typedef struct appointment {
    char *name;
    char *description;
    int start_time;
    int end_time;
    struct appointment *next;
} appointment_t;

// Schedule struct
typedef struct schedule {
    appointment_t *head;
    appointment_t *tail;
    int num_appointments;
} schedule_t;

// Function to create a new appointment
appointment_t *create_appointment(char *name, char *description, int start_time, int end_time) {
    appointment_t *new_appointment = malloc(sizeof(appointment_t));
    new_appointment->name = strdup(name);
    new_appointment->description = strdup(description);
    new_appointment->start_time = start_time;
    new_appointment->end_time = end_time;
    new_appointment->next = NULL;
    return new_appointment;
}

// Function to add an appointment to a schedule
void add_appointment(schedule_t *schedule, appointment_t *appointment) {
    if (schedule->head == NULL) {
        schedule->head = appointment;
        schedule->tail = appointment;
    } else {
        schedule->tail->next = appointment;
        schedule->tail = appointment;
    }
    schedule->num_appointments++;
}

// Function to print a schedule
void print_schedule(schedule_t *schedule) {
    appointment_t *current_appointment = schedule->head;
    while (current_appointment != NULL) {
        printf("%s: %s (%d-%d)\n", current_appointment->name, current_appointment->description, current_appointment->start_time, current_appointment->end_time);
        current_appointment = current_appointment->next;
    }
}

// Function to free the memory allocated for an appointment
void free_appointment(appointment_t *appointment) {
    free(appointment->name);
    free(appointment->description);
    free(appointment);
}

// Function to free the memory allocated for a schedule
void free_schedule(schedule_t *schedule) {
    appointment_t *current_appointment = schedule->head;
    while (current_appointment != NULL) {
        appointment_t *next_appointment = current_appointment->next;
        free_appointment(current_appointment);
        current_appointment = next_appointment;
    }
    free(schedule);
}

// Main function
int main() {
    // Create a new schedule
    schedule_t *schedule = malloc(sizeof(schedule_t));
    schedule->head = NULL;
    schedule->tail = NULL;
    schedule->num_appointments = 0;

    // Add some appointments to the schedule
    add_appointment(schedule, create_appointment("John Doe", "Meeting", 9, 10));
    add_appointment(schedule, create_appointment("Jane Smith", "Interview", 10, 11));
    add_appointment(schedule, create_appointment("Bob Jones", "Phone call", 11, 12));

    // Print the schedule
    print_schedule(schedule);

    // Free the memory allocated for the schedule
    free_schedule(schedule);

    return 0;
}