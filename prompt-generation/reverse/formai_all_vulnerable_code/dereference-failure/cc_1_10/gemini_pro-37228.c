//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments that can be scheduled.
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment.
typedef struct appointment {
    char name[50];
    char date[20];
    char time[20];
    char description[100];
} appointment_t;

// Define the structure of the appointment scheduler.
typedef struct appointment_scheduler {
    appointment_t appointments[MAX_APPOINTMENTS];
    int num_appointments;
} appointment_scheduler_t;

// Create a new appointment scheduler.
appointment_scheduler_t *create_appointment_scheduler() {
    appointment_scheduler_t *scheduler = malloc(sizeof(appointment_scheduler_t));
    scheduler->num_appointments = 0;
    return scheduler;
}

// Destroy an appointment scheduler.
void destroy_appointment_scheduler(appointment_scheduler_t *scheduler) {
    free(scheduler);
}

// Add an appointment to the scheduler.
void add_appointment(appointment_scheduler_t *scheduler, appointment_t *appointment) {
    scheduler->appointments[scheduler->num_appointments] = *appointment;
    scheduler->num_appointments++;
}

// Remove an appointment from the scheduler.
void remove_appointment(appointment_scheduler_t *scheduler, int index) {
    for (int i = index; i < scheduler->num_appointments - 1; i++) {
        scheduler->appointments[i] = scheduler->appointments[i + 1];
    }
    scheduler->num_appointments--;
}

// Print the appointments in the scheduler.
void print_appointments(appointment_scheduler_t *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("%s, %s, %s, %s\n",
            scheduler->appointments[i].name,
            scheduler->appointments[i].date,
            scheduler->appointments[i].time,
            scheduler->appointments[i].description);
    }
}

// Get an appointment from the scheduler by index.
appointment_t *get_appointment(appointment_scheduler_t *scheduler, int index) {
    return &scheduler->appointments[index];
}

// Get the number of appointments in the scheduler.
int get_num_appointments(appointment_scheduler_t *scheduler) {
    return scheduler->num_appointments;
}

// Main function.
int main() {
    // Create an appointment scheduler.
    appointment_scheduler_t *scheduler = create_appointment_scheduler();

    // Add some appointments to the scheduler.
    appointment_t appointment1 = {"John Doe", "2023-03-08", "10:00 AM", "Meeting with client"};
    add_appointment(scheduler, &appointment1);

    appointment_t appointment2 = {"Jane Doe", "2023-03-15", "2:00 PM", "Meeting with team"};
    add_appointment(scheduler, &appointment2);

    // Print the appointments in the scheduler.
    print_appointments(scheduler);

    // Remove an appointment from the scheduler.
    remove_appointment(scheduler, 1);

    // Print the appointments in the scheduler again.
    print_appointments(scheduler);

    // Destroy the appointment scheduler.
    destroy_appointment_scheduler(scheduler);

    return 0;
}