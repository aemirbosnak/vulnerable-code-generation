//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum number of appointments that can be scheduled.
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment.
typedef struct Appointment {
    char *description;
    time_t start_time;
    time_t end_time;
} Appointment;

// Define the structure of the appointment scheduler.
typedef struct AppointmentScheduler {
    Appointment *appointments[MAX_APPOINTMENTS];
    int num_appointments;
} AppointmentScheduler;

// Create a new appointment scheduler.
AppointmentScheduler *create_appointment_scheduler() {
    AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
    scheduler->num_appointments = 0;
    return scheduler;
}

// Destroy an appointment scheduler.
void destroy_appointment_scheduler(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        free(scheduler->appointments[i]->description);
        free(scheduler->appointments[i]);
    }
    free(scheduler);
}

// Add an appointment to the scheduler.
void add_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    if (scheduler->num_appointments == MAX_APPOINTMENTS) {
        fprintf(stderr, "Error: cannot add more appointments to the scheduler.\n");
        return;
    }

    scheduler->appointments[scheduler->num_appointments++] = appointment;
}

// Remove an appointment from the scheduler.
void remove_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (scheduler->appointments[i] == appointment) {
            for (int j = i + 1; j < scheduler->num_appointments; j++) {
                scheduler->appointments[j - 1] = scheduler->appointments[j];
            }
            scheduler->num_appointments--;
            return;
        }
    }

    fprintf(stderr, "Error: appointment not found.\n");
}

// Print the appointments in the scheduler.
void print_appointments(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("%s\n", scheduler->appointments[i]->description);
    }
}

// Main function.
int main() {
    // Create an appointment scheduler.
    AppointmentScheduler *scheduler = create_appointment_scheduler();

    // Add some appointments to the scheduler.
    Appointment *appointment1 = malloc(sizeof(Appointment));
    appointment1->description = "Meet with client";
    appointment1->start_time = time(NULL) + 60 * 60;
    appointment1->end_time = time(NULL) + 60 * 60 * 2;
    add_appointment(scheduler, appointment1);

    Appointment *appointment2 = malloc(sizeof(Appointment));
    appointment2->description = "Go to doctor";
    appointment2->start_time = time(NULL) + 60 * 60 * 3;
    appointment2->end_time = time(NULL) + 60 * 60 * 4;
    add_appointment(scheduler, appointment2);

    // Print the appointments in the scheduler.
    print_appointments(scheduler);

    // Remove an appointment from the scheduler.
    remove_appointment(scheduler, appointment1);

    // Print the appointments in the scheduler.
    print_appointments(scheduler);

    // Destroy the appointment scheduler.
    destroy_appointment_scheduler(scheduler);

    return 0;
}