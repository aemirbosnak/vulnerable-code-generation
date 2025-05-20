//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct {
    char name[50];
    char description[100];
    time_t start_time;
    time_t end_time;
} appointment;

// Define the structure of the appointment scheduler
typedef struct {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments;
} appointment_scheduler;

// Create a new appointment scheduler
appointment_scheduler* create_appointment_scheduler() {
    appointment_scheduler* scheduler = malloc(sizeof(appointment_scheduler));
    scheduler->num_appointments = 0;
    return scheduler;
}

// Add an appointment to the scheduler
void add_appointment(appointment_scheduler* scheduler, appointment* new_appointment) {
    if (scheduler->num_appointments < MAX_APPOINTMENTS) {
        scheduler->appointments[scheduler->num_appointments] = *new_appointment;
        scheduler->num_appointments++;
    } else {
        printf("Error: The appointment scheduler is full.\n");
    }
}

// Remove an appointment from the scheduler
void remove_appointment(appointment_scheduler* scheduler, int index) {
    if (index >= 0 && index < scheduler->num_appointments) {
        for (int i = index; i < scheduler->num_appointments - 1; i++) {
            scheduler->appointments[i] = scheduler->appointments[i + 1];
        }
        scheduler->num_appointments--;
    } else {
        printf("Error: The appointment index is invalid.\n");
    }
}

// Print the appointments in the scheduler
void print_appointments(appointment_scheduler* scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        appointment* appointment = &scheduler->appointments[i];
        printf("-----------------------------------------------------------\n");
        printf("Name: %s\n", appointment->name);
        printf("Description: %s\n", appointment->description);
        printf("Start time: %s", ctime(&appointment->start_time));
        printf("End time: %s", ctime(&appointment->end_time));
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
    // Initialize the random number generator
    srand(time(NULL));

    // Create a new appointment scheduler
    appointment_scheduler* scheduler = create_appointment_scheduler();

    // Add some random appointments to the scheduler
    for (int i = 0; i < 10; i++) {
        appointment* new_appointment = malloc(sizeof(appointment));
        strcpy(new_appointment->name, "Random Appointment");
        strcpy(new_appointment->description, "This is a randomly generated appointment.");
        new_appointment->start_time = get_current_time() + (rand() % 3600 * 24);
        new_appointment->end_time = new_appointment->start_time + (rand() % 3600);
        add_appointment(scheduler, new_appointment);
    }

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Remove an appointment from the scheduler
    remove_appointment(scheduler, 5);

    // Print the appointments in the scheduler again
    print_appointments(scheduler);

    // Free the memory allocated for the scheduler
    free(scheduler);

    return 0;
}