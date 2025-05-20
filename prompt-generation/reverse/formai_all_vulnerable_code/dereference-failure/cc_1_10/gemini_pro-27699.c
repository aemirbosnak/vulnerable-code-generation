//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Appointment structure
typedef struct Appointment {
    int id;
    char *description;
    time_t start_time;
    time_t end_time;
} Appointment;

// Appointment scheduler structure
typedef struct AppointmentScheduler {
    Appointment **appointments;
    int num_appointments;
    int max_appointments;
} AppointmentScheduler;

// Create a new appointment scheduler
AppointmentScheduler *create_appointment_scheduler(int max_appointments) {
    AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
    scheduler->appointments = malloc(sizeof(Appointment *) * max_appointments);
    scheduler->num_appointments = 0;
    scheduler->max_appointments = max_appointments;
    return scheduler;
}

// Destroy an appointment scheduler
void destroy_appointment_scheduler(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        free(scheduler->appointments[i]);
    }
    free(scheduler->appointments);
    free(scheduler);
}

// Add an appointment to the scheduler
int add_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    if (scheduler->num_appointments >= scheduler->max_appointments) {
        return -1;  // Error: scheduler is full
    }
    scheduler->appointments[scheduler->num_appointments++] = appointment;
    return 0;  // Success
}

// Remove an appointment from the scheduler
int remove_appointment(AppointmentScheduler *scheduler, int appointment_id) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (scheduler->appointments[i]->id == appointment_id) {
            // Found the appointment, remove it
            free(scheduler->appointments[i]);
            scheduler->num_appointments--;
            // Shift the remaining appointments down
            for (int j = i; j < scheduler->num_appointments; j++) {
                scheduler->appointments[j] = scheduler->appointments[j + 1];
            }
            return 0;  // Success
        }
    }
    return -1;  // Error: appointment not found
}

// Print the appointments in the scheduler
void print_appointments(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("Appointment %d:\n", scheduler->appointments[i]->id);
        printf("  Description: %s\n", scheduler->appointments[i]->description);
        printf("  Start time: %s", ctime(&scheduler->appointments[i]->start_time));
        printf("  End time: %s", ctime(&scheduler->appointments[i]->end_time));
    }
}

// Main function
int main() {
    // Create an appointment scheduler with a maximum of 10 appointments
    AppointmentScheduler *scheduler = create_appointment_scheduler(10);

    // Create some appointments
    Appointment *appointment1 = malloc(sizeof(Appointment));
    appointment1->id = 1;
    appointment1->description = "Doctor's appointment";
    appointment1->start_time = time(NULL) + 60 * 60;  // 1 hour from now
    appointment1->end_time = appointment1->start_time + 60 * 60;  // 1 hour later

    Appointment *appointment2 = malloc(sizeof(Appointment));
    appointment2->id = 2;
    appointment2->description = "Meeting with boss";
    appointment2->start_time = time(NULL) + 2 * 60 * 60;  // 2 hours from now
    appointment2->end_time = appointment2->start_time + 60 * 60;  // 1 hour later

    // Add the appointments to the scheduler
    add_appointment(scheduler, appointment1);
    add_appointment(scheduler, appointment2);

    // Print the appointments
    print_appointments(scheduler);

    // Remove an appointment
    remove_appointment(scheduler, 1);

    // Print the appointments again
    print_appointments(scheduler);

    // Destroy the appointment scheduler
    destroy_appointment_scheduler(scheduler);

    return 0;
}