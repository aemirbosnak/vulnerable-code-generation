//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appointment structure
typedef struct Appointment {
    int id;
    char *name;
    char *date;
    char *time;
    char *location;
    char *description;
} Appointment;

// Appointment scheduler structure
typedef struct AppointmentScheduler {
    int num_appointments;
    Appointment *appointments;
} AppointmentScheduler;

// Create a new appointment
Appointment *create_appointment(int id, char *name, char *date, char *time, char *location, char *description) {
    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->id = id;
    appointment->name = strdup(name);
    appointment->date = strdup(date);
    appointment->time = strdup(time);
    appointment->location = strdup(location);
    appointment->description = strdup(description);
    return appointment;
}

// Add an appointment to the scheduler
void add_appointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    scheduler->appointments = realloc(scheduler->appointments, sizeof(Appointment) * (scheduler->num_appointments + 1));
    scheduler->appointments[scheduler->num_appointments++] = *appointment;
}

// Print the appointments in the scheduler
void print_appointments(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        printf("Appointment %d:\n", scheduler->appointments[i].id);
        printf("Name: %s\n", scheduler->appointments[i].name);
        printf("Date: %s\n", scheduler->appointments[i].date);
        printf("Time: %s\n", scheduler->appointments[i].time);
        printf("Location: %s\n", scheduler->appointments[i].location);
        printf("Description: %s\n", scheduler->appointments[i].description);
        printf("\n");
    }
}

// Free the memory allocated for the scheduler
void free_scheduler(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->num_appointments; i++) {
        free(scheduler->appointments[i].name);
        free(scheduler->appointments[i].date);
        free(scheduler->appointments[i].time);
        free(scheduler->appointments[i].location);
        free(scheduler->appointments[i].description);
    }
    free(scheduler->appointments);
    free(scheduler);
}

// Main function
int main() {
    // Create a new appointment scheduler
    AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
    scheduler->num_appointments = 0;
    scheduler->appointments = NULL;

    // Add some appointments to the scheduler
    add_appointment(scheduler, create_appointment(1, "John Doe", "2023-03-08", "10:00 AM", "123 Main Street", "Meeting about the project"));
    add_appointment(scheduler, create_appointment(2, "Jane Smith", "2023-03-15", "2:00 PM", "456 Elm Street", "Job interview"));
    add_appointment(scheduler, create_appointment(3, "Bob Jones", "2023-03-22", "11:00 AM", "789 Oak Street", "Coffee meeting"));

    // Print the appointments in the scheduler
    print_appointments(scheduler);

    // Free the memory allocated for the scheduler
    free_scheduler(scheduler);

    return 0;
}