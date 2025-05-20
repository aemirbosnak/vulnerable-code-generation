//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments that can be scheduled
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct Appointment {
    char *name;
    char *description;
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

// Define the structure of the appointment scheduler
typedef struct AppointmentScheduler {
    Appointment *appointments[MAX_APPOINTMENTS];
    int numAppointments;
} AppointmentScheduler;

// Create a new appointment scheduler
AppointmentScheduler *createAppointmentScheduler() {
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
        Appointment *appointment = scheduler->appointments[i];
        printf("%s on %d/%d/%d at %d:%d\n", appointment->name, appointment->day, appointment->month, appointment->year, appointment->hour, appointment->minute);
    }
}

// Free the memory used by the scheduler
void freeAppointmentScheduler(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->numAppointments; i++) {
        Appointment *appointment = scheduler->appointments[i];
        free(appointment->name);
        free(appointment->description);
        free(appointment);
    }
    free(scheduler);
}

// Main function
int main() {
    // Create a new appointment scheduler
    AppointmentScheduler *scheduler = createAppointmentScheduler();

    // Add some appointments to the scheduler
    Appointment *appointment1 = malloc(sizeof(Appointment));
    appointment1->name = "Doctor's appointment";
    appointment1->description = "Annual checkup";
    appointment1->day = 15;
    appointment1->month = 3;
    appointment1->year = 2023;
    appointment1->hour = 10;
    appointment1->minute = 0;
    addAppointment(scheduler, appointment1);

    Appointment *appointment2 = malloc(sizeof(Appointment));
    appointment2->name = "Dentist appointment";
    appointment2->description = "Cleaning and checkup";
    appointment2->day = 1;
    appointment2->month = 4;
    appointment2->year = 2023;
    appointment2->hour = 11;
    appointment2->minute = 30;
    addAppointment(scheduler, appointment2);

    // Print the appointments in the scheduler
    printAppointments(scheduler);

    // Free the memory used by the scheduler
    freeAppointmentScheduler(scheduler);

    return 0;
}