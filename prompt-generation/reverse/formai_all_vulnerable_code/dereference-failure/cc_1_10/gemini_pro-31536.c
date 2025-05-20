//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct appointment {
    char *name;
    char *description;
    int start_time;
    int end_time;
} appointment;

// Define the structure of the appointment scheduler
typedef struct appointment_scheduler {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments;
} appointment_scheduler;

// Create a new appointment scheduler
appointment_scheduler *create_appointment_scheduler() {
    appointment_scheduler *scheduler = malloc(sizeof(appointment_scheduler));
    scheduler->num_appointments = 0;
    return scheduler;
}

// Add an appointment to the scheduler
void add_appointment(appointment_scheduler *scheduler, appointment *appointment) {
    if (scheduler->num_appointments < MAX_APPOINTMENTS) {
        scheduler->appointments[scheduler->num_appointments++] = *appointment;
    } else {
        printf("Error: The appointment scheduler is full.\n");
    }
}

// Print the appointments in the scheduler
void print_appointments(appointment_scheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("%s (%d-%d): %s\n",
            scheduler->appointments[i].name,
            scheduler->appointments[i].start_time,
            scheduler->appointments[i].end_time,
            scheduler->appointments[i].description);
    }
}

// Free the memory used by the scheduler
void free_appointment_scheduler(appointment_scheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        free(scheduler->appointments[i].name);
        free(scheduler->appointments[i].description);
    }
    free(scheduler);
}

// Main function
int main() {
    // Create a new appointment scheduler
    appointment_scheduler *scheduler = create_appointment_scheduler();

    // Add some appointments to the scheduler
    appointment appointment1 = {
        .name = "Doctor's appointment",
        .description = "Annual checkup",
        .start_time = 1000,
        .end_time = 1100
    };
    add_appointment(scheduler, &appointment1);

    appointment appointment2 = {
        .name = "Meeting with boss",
        .description = "Discuss project progress",
        .start_time = 1300,
        .end_time = 1400
    };
    add_appointment(scheduler, &appointment2);

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Free the memory used by the scheduler
    free_appointment_scheduler(scheduler);

    return 0;
}