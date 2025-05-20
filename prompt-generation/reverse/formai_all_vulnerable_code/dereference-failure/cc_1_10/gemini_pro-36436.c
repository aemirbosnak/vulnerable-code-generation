//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appointment struct
typedef struct Appointment {
    char* title;
    char* description;
    int start_time;
    int end_time;
} Appointment;

// Appointment scheduler struct
typedef struct AppointmentScheduler {
    Appointment* appointments;
    int num_appointments;
    int max_appointments;
} AppointmentScheduler;

// Create a new appointment scheduler
AppointmentScheduler* create_appointment_scheduler() {
    AppointmentScheduler* scheduler = malloc(sizeof(AppointmentScheduler));
    scheduler->appointments = NULL;
    scheduler->num_appointments = 0;
    scheduler->max_appointments = 0;
    return scheduler;
}

// Destroy an appointment scheduler
void destroy_appointment_scheduler(AppointmentScheduler* scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        free(scheduler->appointments[i].title);
        free(scheduler->appointments[i].description);
    }
    free(scheduler->appointments);
    free(scheduler);
}

// Add an appointment to the scheduler
void add_appointment(AppointmentScheduler* scheduler, Appointment appointment) {
    // Check if the scheduler is full
    if (scheduler->num_appointments == scheduler->max_appointments) {
        // Double the size of the scheduler
        scheduler->max_appointments *= 2;
        scheduler->appointments = realloc(scheduler->appointments, scheduler->max_appointments * sizeof(Appointment));
    }

    // Add the appointment to the scheduler
    scheduler->appointments[scheduler->num_appointments] = appointment;
    scheduler->num_appointments++;
}

// Remove an appointment from the scheduler
void remove_appointment(AppointmentScheduler* scheduler, int index) {
    // Check if the index is valid
    if (index < 0 || index >= scheduler->num_appointments) {
        return;
    }

    // Shift the appointments after the index
    for (int i = index; i < scheduler->num_appointments - 1; i++) {
        scheduler->appointments[i] = scheduler->appointments[i + 1];
    }

    // Decrement the number of appointments
    scheduler->num_appointments--;
}

// Print all appointments
void print_appointments(AppointmentScheduler* scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("Appointment %d:\n", i + 1);
        printf("Title: %s\n", scheduler->appointments[i].title);
        printf("Description: %s\n", scheduler->appointments[i].description);
        printf("Start time: %d\n", scheduler->appointments[i].start_time);
        printf("End time: %d\n", scheduler->appointments[i].end_time);
        printf("\n");
    }
}

// Main function
int main() {
    // Create an appointment scheduler
    AppointmentScheduler* scheduler = create_appointment_scheduler();

    // Add some appointments to the scheduler
    Appointment appointment1 = {"Meeting with John", "Discuss project plans", 9, 10};
    add_appointment(scheduler, appointment1);

    Appointment appointment2 = {"Lunch with Mary", "Catch up and discuss work", 12, 1};
    add_appointment(scheduler, appointment2);

    Appointment appointment3 = {"Call with Sam", "Discuss project status", 2, 3};
    add_appointment(scheduler, appointment3);

    // Print all appointments
    print_appointments(scheduler);

    // Remove an appointment from the scheduler
    remove_appointment(scheduler, 1);

    // Print all appointments again
    print_appointments(scheduler);

    // Destroy the appointment scheduler
    destroy_appointment_scheduler(scheduler);

    return 0;
}