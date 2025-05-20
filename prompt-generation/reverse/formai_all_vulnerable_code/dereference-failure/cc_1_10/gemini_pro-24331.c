//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Appointment structure
typedef struct Appointment {
    char *name;
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
        free(scheduler->appointments[i]->name);
        free(scheduler->appointments[i]->description);
        free(scheduler->appointments[i]);
    }
    free(scheduler->appointments);
    free(scheduler);
}

// Add an appointment to the scheduler
void add_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    if (scheduler->num_appointments >= scheduler->max_appointments) {
        printf("Error: Appointment scheduler is full.\n");
        return;
    }
    scheduler->appointments[scheduler->num_appointments++] = appointment;
}

// Remove an appointment from the scheduler
void remove_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (scheduler->appointments[i] == appointment) {
            scheduler->appointments[i] = scheduler->appointments[--scheduler->num_appointments];
            return;
        }
    }
    printf("Error: Appointment not found.\n");
}

// Find an appointment in the scheduler
Appointment *find_appointment(AppointmentScheduler *scheduler, time_t start_time, time_t end_time) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (scheduler->appointments[i]->start_time == start_time && scheduler->appointments[i]->end_time == end_time) {
            return scheduler->appointments[i];
        }
    }
    return NULL;
}

// Print the appointments in the scheduler
void print_appointments(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("%s (%s): %s - %s\n",
            scheduler->appointments[i]->name,
            scheduler->appointments[i]->description,
            ctime(&scheduler->appointments[i]->start_time),
            ctime(&scheduler->appointments[i]->end_time)
        );
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
    AppointmentScheduler *scheduler = create_appointment_scheduler(10);

    // Add some appointments to the scheduler
    Appointment *appointment1 = malloc(sizeof(Appointment));
    appointment1->name = strdup("Appointment 1");
    appointment1->description = strdup("This is the first appointment.");
    appointment1->start_time = get_current_time() + 3600; // 1 hour from now
    appointment1->end_time = appointment1->start_time + 3600; // 1 hour later
    add_appointment(scheduler, appointment1);

    Appointment *appointment2 = malloc(sizeof(Appointment));
    appointment2->name = strdup("Appointment 2");
    appointment2->description = strdup("This is the second appointment.");
    appointment2->start_time = get_current_time() + 7200; // 2 hours from now
    appointment2->end_time = appointment2->start_time + 3600; // 1 hour later
    add_appointment(scheduler, appointment2);

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Find an appointment in the scheduler
    Appointment *appointment = find_appointment(scheduler, appointment2->start_time, appointment2->end_time);
    if (appointment) {
        printf("Found appointment: %s\n", appointment->name);
    } else {
        printf("Error: Appointment not found.\n");
    }

    // Remove an appointment from the scheduler
    remove_appointment(scheduler, appointment1);

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Destroy the appointment scheduler
    destroy_appointment_scheduler(scheduler);

    return 0;
}