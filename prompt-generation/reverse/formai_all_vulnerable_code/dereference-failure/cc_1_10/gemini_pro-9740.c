//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Appointment struct
typedef struct Appointment {
    char *description;
    time_t start_time;
    time_t end_time;
} Appointment;

// Appointment scheduler struct
typedef struct AppointmentScheduler {
    Appointment *appointments;
    int num_appointments;
} AppointmentScheduler;

// Create a new appointment scheduler
AppointmentScheduler *new_appointment_scheduler() {
    AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
    scheduler->appointments = NULL;
    scheduler->num_appointments = 0;
    return scheduler;
}

// Add an appointment to the scheduler
void add_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    scheduler->appointments = realloc(scheduler->appointments, (scheduler->num_appointments + 1) * sizeof(Appointment));
    scheduler->appointments[scheduler->num_appointments++] = *appointment;
}

// Print the appointments in the scheduler
void print_appointments(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("%s\n", scheduler->appointments[i].description);
        printf("%s\n", ctime(&scheduler->appointments[i].start_time));
        printf("%s\n", ctime(&scheduler->appointments[i].end_time));
    }
}

// Free the memory allocated for the scheduler
void free_appointment_scheduler(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        free(scheduler->appointments[i].description);
    }
    free(scheduler->appointments);
    free(scheduler);
}

// Main function
int main() {
    // Create a new appointment scheduler
    AppointmentScheduler *scheduler = new_appointment_scheduler();

    // Add some appointments to the scheduler
    Appointment appointment1 = {
        .description = "Doctor's appointment",
        .start_time = time(NULL) + 3600,
        .end_time = time(NULL) + 4800
    };
    add_appointment(scheduler, &appointment1);

    Appointment appointment2 = {
        .description = "Meeting with boss",
        .start_time = time(NULL) + 86400,
        .end_time = time(NULL) + 93600
    };
    add_appointment(scheduler, &appointment2);

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Free the memory allocated for the scheduler
    free_appointment_scheduler(scheduler);

    return 0;
}