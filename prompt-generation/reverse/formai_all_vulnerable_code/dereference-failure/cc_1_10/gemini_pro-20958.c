//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct {
    char *name;
    char *time;
    char *date;
} Appointment;

// Define the structure of the appointment scheduler
typedef struct {
    Appointment *appointments[MAX_APPOINTMENTS];
    int numAppointments;
} AppointmentScheduler;

// Create a new appointment scheduler
AppointmentScheduler *newAppointmentScheduler() {
    AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
    scheduler->numAppointments = 0;
    return scheduler;
}

// Add an appointment to the scheduler
void addAppointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    scheduler->appointments[scheduler->numAppointments] = appointment;
    scheduler->numAppointments++;
}

// Print the appointments in the scheduler
void printAppointments(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->numAppointments; i++) {
        printf("%s: %s on %s\n", scheduler->appointments[i]->name, scheduler->appointments[i]->time, scheduler->appointments[i]->date);
    }
}

// Free the memory used by the scheduler
void freeAppointmentScheduler(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->numAppointments; i++) {
        free(scheduler->appointments[i]->name);
        free(scheduler->appointments[i]->time);
        free(scheduler->appointments[i]->date);
        free(scheduler->appointments[i]);
    }
    free(scheduler);
}

// Main function
int main() {
    // Create a new appointment scheduler
    AppointmentScheduler *scheduler = newAppointmentScheduler();

    // Add some appointments to the scheduler
    Appointment *appointment1 = malloc(sizeof(Appointment));
    appointment1->name = "John Doe";
    appointment1->time = "10:00 AM";
    appointment1->date = "2023-03-08";
    addAppointment(scheduler, appointment1);

    Appointment *appointment2 = malloc(sizeof(Appointment));
    appointment2->name = "Jane Doe";
    appointment2->time = "11:00 AM";
    appointment2->date = "2023-03-08";
    addAppointment(scheduler, appointment2);

    // Print the appointments in the scheduler
    printAppointments(scheduler);

    // Free the memory used by the scheduler
    freeAppointmentScheduler(scheduler);

    return 0;
}