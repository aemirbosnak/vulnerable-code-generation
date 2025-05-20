//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of appointments that can be scheduled
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct {
    char name[50];
    char description[100];
    time_t start_time;
    time_t end_time;
} appointment_t;

// Define the structure of the appointment scheduler
typedef struct {
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
int add_appointment(appointment_scheduler_t* scheduler, appointment_t appointment) {
    if (scheduler->num_appointments >= MAX_APPOINTMENTS) {
        return -1;  // Error: Too many appointments
    }
    scheduler->appointments[scheduler->num_appointments++] = appointment;
    return 0;
}

// Remove an appointment from the scheduler by index
int remove_appointment(appointment_scheduler_t* scheduler, unsigned int index) {
    if (index >= scheduler->num_appointments) {
        return -1;  // Error: Invalid index
    }
    for (unsigned int i = index; i < scheduler->num_appointments - 1; i++) {
        scheduler->appointments[i] = scheduler->appointments[i + 1];
    }
    scheduler->num_appointments--;
    return 0;
}

// Find an appointment by name
appointment_t* find_appointment(appointment_scheduler_t* scheduler, char* name) {
    for (unsigned int i = 0; i < scheduler->num_appointments; i++) {
        if (strcmp(scheduler->appointments[i].name, name) == 0) {
            return &scheduler->appointments[i];
        }
    }
    return NULL;
}

// Print the appointments in the scheduler
void print_appointments(appointment_scheduler_t* scheduler) {
    printf("Appointments:\n");
    for (unsigned int i = 0; i < scheduler->num_appointments; i++) {
        printf("  %s: %s (%s - %s)\n",
            scheduler->appointments[i].name,
            scheduler->appointments[i].description,
            ctime(&scheduler->appointments[i].start_time),
            ctime(&scheduler->appointments[i].end_time));
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
        .name = "Appointment 1",
        .description = "This is the first appointment.",
        .start_time = get_current_time() + 3600,  // Start in one hour
        .end_time = get_current_time() + 7200,    // End in two hours
    };
    add_appointment(scheduler, appointment1);

    appointment_t appointment2 = {
        .name = "Appointment 2",
        .description = "This is the second appointment.",
        .start_time = get_current_time() + 10800,  // Start in three hours
        .end_time = get_current_time() + 14400,    // End in four hours
    };
    add_appointment(scheduler, appointment2);

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Remove an appointment from the scheduler
    remove_appointment(scheduler, 1);

    // Print the appointments in the scheduler again
    print_appointments(scheduler);

    // Destroy the appointment scheduler
    destroy_appointment_scheduler(scheduler);

    return 0;
}