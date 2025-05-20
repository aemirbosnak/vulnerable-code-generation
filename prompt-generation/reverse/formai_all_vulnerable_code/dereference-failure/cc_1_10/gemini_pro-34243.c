//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Appointment struct
typedef struct Appointment {
    int id;
    char *description;
    time_t start_time;
    time_t end_time;
} Appointment;

// Appointment scheduler struct
typedef struct AppointmentScheduler {
    int num_appointments;
    Appointment *appointments;
} AppointmentScheduler;

// Create a new appointment scheduler
AppointmentScheduler *create_appointment_scheduler() {
    AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
    scheduler->num_appointments = 0;
    scheduler->appointments = NULL;
    return scheduler;
}

// Destroy an appointment scheduler
void destroy_appointment_scheduler(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        free(scheduler->appointments[i].description);
    }
    free(scheduler->appointments);
    free(scheduler);
}

// Add an appointment to the scheduler
void add_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    scheduler->appointments = realloc(scheduler->appointments, (scheduler->num_appointments + 1) * sizeof(Appointment));
    scheduler->appointments[scheduler->num_appointments] = *appointment;
    scheduler->num_appointments++;
}

// Remove an appointment from the scheduler
void remove_appointment(AppointmentScheduler *scheduler, int id) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        if (scheduler->appointments[i].id == id) {
            for (int j = i + 1; j < scheduler->num_appointments; j++) {
                scheduler->appointments[j - 1] = scheduler->appointments[j];
            }
            scheduler->num_appointments--;
            break;
        }
    }
}

// Print the appointments in the scheduler
void print_appointments(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("Appointment %d: %s\n", scheduler->appointments[i].id, scheduler->appointments[i].description);
        printf("Start time: %s\n", ctime(&scheduler->appointments[i].start_time));
        printf("End time: %s\n", ctime(&scheduler->appointments[i].end_time));
        printf("\n");
    }
}

// Main function
int main() {
    // Create an appointment scheduler
    AppointmentScheduler *scheduler = create_appointment_scheduler();

    // Add some appointments to the scheduler
    Appointment appointment1 = {1, "Dentist appointment", time(NULL), time(NULL) + 3600};
    Appointment appointment2 = {2, "Doctor's appointment", time(NULL) + 86400, time(NULL) + 90000};
    Appointment appointment3 = {3, "Haircut", time(NULL) + 172800, time(NULL) + 180000};
    add_appointment(scheduler, &appointment1);
    add_appointment(scheduler, &appointment2);
    add_appointment(scheduler, &appointment3);

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Remove an appointment from the scheduler
    remove_appointment(scheduler, 2);

    // Print the appointments in the scheduler again
    print_appointments(scheduler);

    // Destroy the appointment scheduler
    destroy_appointment_scheduler(scheduler);

    return 0;
}