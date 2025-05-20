//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the maximum number of appointments that can be scheduled
#define MAX_APPOINTMENTS 10

// Define the structure of an appointment
typedef struct appointment {
    char name[50];
    time_t start_time;
    time_t end_time;
} appointment_t;

// Define the structure of the appointment scheduler
typedef struct appointment_scheduler {
    appointment_t appointments[MAX_APPOINTMENTS];
    int num_appointments;
} appointment_scheduler_t;

// Create a new appointment scheduler
appointment_scheduler_t *create_appointment_scheduler() {
    appointment_scheduler_t *scheduler = malloc(sizeof(appointment_scheduler_t));
    if (scheduler == NULL) {
        return NULL;
    }

    scheduler->num_appointments = 0;

    return scheduler;
}

// Destroy an appointment scheduler
void destroy_appointment_scheduler(appointment_scheduler_t *scheduler) {
    free(scheduler);
}

// Add an appointment to the scheduler
bool add_appointment(appointment_scheduler_t *scheduler, appointment_t *appointment) {
    if (scheduler->num_appointments >= MAX_APPOINTMENTS) {
        return false;
    }

    scheduler->appointments[scheduler->num_appointments] = *appointment;
    scheduler->num_appointments++;

    return true;
}

// Remove an appointment from the scheduler
bool remove_appointment(appointment_scheduler_t *scheduler, appointment_t *appointment) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (&scheduler->appointments[i] == appointment) {
            for (int j = i + 1; j < scheduler->num_appointments; j++) {
                scheduler->appointments[j - 1] = scheduler->appointments[j];
            }
            scheduler->num_appointments--;
            return true;
        }
    }

    return false;
}

// Print the appointments in the scheduler
void print_appointments(appointment_scheduler_t *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("%s: %s - %s\n", scheduler->appointments[i].name, ctime(&scheduler->appointments[i].start_time), ctime(&scheduler->appointments[i].end_time));
    }
}

// Get the current time
time_t get_current_time() {
    time_t current_time;
    time(&current_time);
    return current_time;
}

// Main function
int main() {
    // Create an appointment scheduler
    appointment_scheduler_t *scheduler = create_appointment_scheduler();

    // Add some appointments to the scheduler
    appointment_t appointment1 = {"John Doe", get_current_time() + 3600, get_current_time() + 7200};
    add_appointment(scheduler, &appointment1);

    appointment_t appointment2 = {"Jane Doe", get_current_time() + 7200, get_current_time() + 10800};
    add_appointment(scheduler, &appointment2);

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Remove an appointment from the scheduler
    remove_appointment(scheduler, &appointment1);

    // Print the appointments in the scheduler again
    print_appointments(scheduler);

    // Destroy the appointment scheduler
    destroy_appointment_scheduler(scheduler);

    return 0;
}