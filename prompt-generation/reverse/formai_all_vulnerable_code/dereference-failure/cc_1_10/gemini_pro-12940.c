//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of appointments that can be scheduled
#define MAX_APPOINTMENTS 10

// Define the structure of an appointment
typedef struct appointment {
    char name[50];
    char description[100];
    time_t start_time;
    time_t end_time;
} appointment_t;

// Define the structure of the appointment scheduler
typedef struct appointment_scheduler {
    appointment_t appointments[MAX_APPOINTMENTS];
    int num_appointments;
} appointment_scheduler_t;

// Create a new appointment scheduler
appointment_scheduler_t* create_appointment_scheduler() {
    appointment_scheduler_t* scheduler = malloc(sizeof(appointment_scheduler_t));
    scheduler->num_appointments = 0;
    return scheduler;
}

// Destroy an appointment scheduler
void destroy_appointment_scheduler(appointment_scheduler_t* scheduler) {
    free(scheduler);
}

// Add an appointment to the scheduler
int add_appointment(appointment_scheduler_t* scheduler, appointment_t* appointment) {
    if (scheduler->num_appointments >= MAX_APPOINTMENTS) {
        return -1; // Error: The scheduler is full
    }

    scheduler->appointments[scheduler->num_appointments++] = *appointment;
    return 0; // Success
}

// Remove an appointment from the scheduler
int remove_appointment(appointment_scheduler_t* scheduler, int index) {
    if (index < 0 || index >= scheduler->num_appointments) {
        return -1; // Error: The index is out of range
    }

    // Shift the remaining appointments down one position
    for (int i = index + 1; i < scheduler->num_appointments; i++) {
        scheduler->appointments[i - 1] = scheduler->appointments[i];
    }

    scheduler->num_appointments--;
    return 0; // Success
}

// Print the appointments in the scheduler
void print_appointments(appointment_scheduler_t* scheduler) {
    printf("Appointments:\n");
    for (int i = 0; i < scheduler->num_appointments; i++) {
        appointment_t* appointment = &scheduler->appointments[i];
        printf("%s (%s) - %s - %s\n", 
            appointment->name, 
            appointment->description, 
            ctime(&appointment->start_time), 
            ctime(&appointment->end_time));
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
    appointment_scheduler_t* scheduler = create_appointment_scheduler();

    // Add some appointments to the scheduler
    appointment_t appointment1 = {
        .name = "John Doe",
        .description = "Meeting with the boss",
        .start_time = get_current_time() + 3600, // 1 hour from now
        .end_time = get_current_time() + 7200  // 2 hours from now
    };

    appointment_t appointment2 = {
        .name = "Jane Doe",
        .description = "Doctor's appointment",
        .start_time = get_current_time() + 10800, // 3 hours from now
        .end_time = get_current_time() + 14400  // 4 hours from now
    };

    add_appointment(scheduler, &appointment1);
    add_appointment(scheduler, &appointment2);

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Remove an appointment from the scheduler
    remove_appointment(scheduler, 0);

    // Print the appointments in the scheduler again
    print_appointments(scheduler);

    // Destroy the appointment scheduler
    destroy_appointment_scheduler(scheduler);

    return 0;
}