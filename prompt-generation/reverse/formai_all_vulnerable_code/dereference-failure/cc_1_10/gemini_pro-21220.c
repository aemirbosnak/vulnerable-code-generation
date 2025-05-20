//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: paranoid
// Appointment Scheduler with Paranoid Mode

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define paranoid suspicion levels
typedef enum { NONE, LOW, MEDIUM, HIGH, XPARANOID } SuspicionLevel;

// Appointment structure
typedef struct Appointment {
    char *name;
    char *description;
    time_t startTime;
    time_t endTime;
    SuspicionLevel suspicionLevel;
} Appointment;

// Appointment scheduler struct
typedef struct AppointmentScheduler {
    Appointment *appointments[100];
    int numAppointments;
    SuspicionLevel paranoidLevel;
} AppointmentScheduler;

// Function to create a new appointment scheduler
AppointmentScheduler *createAppointmentScheduler(SuspicionLevel paranoidLevel) {
    AppointmentScheduler *scheduler = malloc(sizeof(AppointmentScheduler));
    if (scheduler == NULL) {
        return NULL;
    }
    scheduler->numAppointments = 0;
    scheduler->paranoidLevel = paranoidLevel;
    return scheduler;
}

// Function to schedule an appointment
int scheduleAppointment(AppointmentScheduler *scheduler, Appointment *appointment) {
    if (scheduler->numAppointments >= 100) {
        return -1; // Scheduler is full
    }
    scheduler->appointments[scheduler->numAppointments++] = appointment;
    return 0; // Success
}

// Paranoid function
void paranoidCheck(Appointment *appointment) {
    if (appointment->suspicionLevel == XPARANOID) {
        printf("Warning: Appointment '%s' suspected of being a security risk!\n", appointment->name);
    }
}

// Function to print all appointments
void printAppointments(AppointmentScheduler *scheduler) {
    for (int i = 0; i < scheduler->numAppointments; i++) {
        Appointment *appointment = scheduler->appointments[i];
        paranoidCheck(appointment);
        printf("%s: %s\n", appointment->name, appointment->description);
        printf("Start time: %s\n", ctime(&appointment->startTime));
        printf("End time: %s\n", ctime(&appointment->endTime));
        printf("Suspicion level: %d\n", appointment->suspicionLevel);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a paranoid appointment scheduler
    AppointmentScheduler *scheduler = createAppointmentScheduler(HIGH);

    // Schedule some appointments
    Appointment *appointment1 = malloc(sizeof(Appointment));
    appointment1->name = "Meeting with the CIA";
    appointment1->description = "Discuss top-secret plans";
    appointment1->startTime = time(NULL) + 3600; // 1 hour from now
    appointment1->endTime = appointment1->startTime + 3600; // 1 hour long
    appointment1->suspicionLevel = XPARANOID;
    scheduleAppointment(scheduler, appointment1);

    Appointment *appointment2 = malloc(sizeof(Appointment));
    appointment2->name = "Lunch with friends";
    appointment2->description = "Discuss harmless gossip";
    appointment2->startTime = time(NULL) + 7200; // 2 hours from now
    appointment2->endTime = appointment2->startTime + 3600; // 1 hour long
    appointment2->suspicionLevel = NONE;
    scheduleAppointment(scheduler, appointment2);

    // Print all appointments
    printf("Upcoming appointments:\n");
    printAppointments(scheduler);

    // Free allocated memory
    free(appointment1);
    free(appointment2);
    free(scheduler);

    return 0;
}