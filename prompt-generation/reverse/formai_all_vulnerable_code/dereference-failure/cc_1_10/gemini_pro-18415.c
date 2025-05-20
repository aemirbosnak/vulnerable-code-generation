//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appointment structure
typedef struct Appointment {
    char *name;
    char *description;
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

// Appointment scheduler structure
typedef struct AppointmentScheduler {
    Appointment **appointments;  // Array of appointments
    int num_appointments;      // Number of appointments
} AppointmentScheduler;

// Create a new appointment scheduler
AppointmentScheduler *create_appointment_scheduler() {
    AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
    scheduler->appointments = NULL;
    scheduler->num_appointments = 0;
    return scheduler;
}

// Add an appointment to the scheduler
void add_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    // Reallocate the array of appointments if necessary
    if (scheduler->num_appointments == 0) {
        // Double the size of the array
        scheduler->appointments = realloc(scheduler->appointments, 2 * sizeof(Appointment *));
    } else if (scheduler->num_appointments % 2 == 0) {
        // Increase the size of the array by 1
        scheduler->appointments = realloc(scheduler->appointments, (scheduler->num_appointments + 1) * sizeof(Appointment *));
    }

    // Add the appointment to the array
    scheduler->appointments[scheduler->num_appointments++] = appointment;
}

// Remove an appointment from the scheduler
void remove_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    // Find the index of the appointment
    int index = -1;
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (scheduler->appointments[i] == appointment) {
            index = i;
            break;
        }
    }

    // If the appointment was found, remove it from the array
    if (index >= 0) {
        // Shift the remaining appointments left
        for (int i = index + 1; i < scheduler->num_appointments; i++) {
            scheduler->appointments[i - 1] = scheduler->appointments[i];
        }

        // Decrement the number of appointments
        scheduler->num_appointments--;

        // Reallocate the array of appointments if necessary
        if (scheduler->num_appointments % 2 == 0) {
            scheduler->appointments = realloc(scheduler->appointments, (scheduler->num_appointments) * sizeof(Appointment *));
        }
    }
}

// Print the appointments in the scheduler
void print_appointments(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        Appointment *appointment = scheduler->appointments[i];
        printf("Appointment %d:\n", i + 1);
        printf("  Name: %s\n", appointment->name);
        printf("  Description: %s\n", appointment->description);
        printf("  Date: %d/%d/%d\n", appointment->day, appointment->month, appointment->year);
        printf("  Time: %d:%d\n", appointment->hour, appointment->minute);
    }
}

// Free the memory allocated for the scheduler
void free_appointment_scheduler(AppointmentScheduler *scheduler) {
    // Free the appointments
    for (int i = 0; i < scheduler->num_appointments; i++) {
        free(scheduler->appointments[i]);
    }

    // Free the array of appointments
    free(scheduler->appointments);

    // Free the scheduler
    free(scheduler);
}

// Main function
int main() {
    // Create a new appointment scheduler
    AppointmentScheduler *scheduler = create_appointment_scheduler();

    // Add some appointments to the scheduler
    Appointment *appointment1 = malloc(sizeof(Appointment));
    appointment1->name = "Doctor's appointment";
    appointment1->description = "Annual checkup";
    appointment1->day = 15;
    appointment1->month = 3;
    appointment1->year = 2023;
    appointment1->hour = 10;
    appointment1->minute = 0;
    add_appointment(scheduler, appointment1);

    Appointment *appointment2 = malloc(sizeof(Appointment));
    appointment2->name = "Meeting with boss";
    appointment2->description = "Discuss project plans";
    appointment2->day = 20;
    appointment2->month = 3;
    appointment2->year = 2023;
    appointment2->hour = 14;
    appointment2->minute = 0;
    add_appointment(scheduler, appointment2);

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Remove an appointment from the scheduler
    remove_appointment(scheduler, appointment2);

    // Print the appointments in the scheduler again
    print_appointments(scheduler);

    // Free the memory allocated for the scheduler
    free_appointment_scheduler(scheduler);

    return 0;
}