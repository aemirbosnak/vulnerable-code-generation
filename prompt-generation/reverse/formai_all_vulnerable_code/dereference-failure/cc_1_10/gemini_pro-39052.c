//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 10

// Define the appointment structure
typedef struct {
    char name[50];
    char time[10];
    char date[10];
} Appointment;

// Define the appointment scheduler structure
typedef struct {
    Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments;
} AppointmentScheduler;

// Create a new appointment scheduler
AppointmentScheduler* createAppointmentScheduler() {
    AppointmentScheduler* scheduler = malloc(sizeof(AppointmentScheduler));
    scheduler->numAppointments = 0;
    return scheduler;
}

// Add an appointment to the scheduler
void addAppointment(AppointmentScheduler* scheduler, Appointment appointment) {
    if (scheduler->numAppointments < MAX_APPOINTMENTS) {
        scheduler->appointments[scheduler->numAppointments] = appointment;
        scheduler->numAppointments++;
    } else {
        printf("Error: The appointment scheduler is full.\n");
    }
}

// Print the appointments in the scheduler
void printAppointments(AppointmentScheduler* scheduler) {
    for (int i = 0; i < scheduler->numAppointments; i++) {
        printf("%s %s %s\n", scheduler->appointments[i].name, scheduler->appointments[i].time, scheduler->appointments[i].date);
    }
}

// Get an appointment from the scheduler
Appointment getAppointment(AppointmentScheduler* scheduler, char* name) {
    for (int i = 0; i < scheduler->numAppointments; i++) {
        if (strcmp(scheduler->appointments[i].name, name) == 0) {
            return scheduler->appointments[i];
        }
    }
    Appointment emptyAppointment;
    strcpy(emptyAppointment.name, "");
    strcpy(emptyAppointment.time, "");
    strcpy(emptyAppointment.date, "");
    return emptyAppointment;
}

// Delete an appointment from the scheduler
void deleteAppointment(AppointmentScheduler* scheduler, char* name) {
    for (int i = 0; i < scheduler->numAppointments; i++) {
        if (strcmp(scheduler->appointments[i].name, name) == 0) {
            scheduler->appointments[i] = scheduler->appointments[scheduler->numAppointments - 1];
            scheduler->numAppointments--;
            break;
        }
    }
}

// Main function
int main() {
    // Create a new appointment scheduler
    AppointmentScheduler* scheduler = createAppointmentScheduler();

    // Add some appointments to the scheduler
    Appointment appointment1 = {"John Doe", "10:00 AM", "01/01/2023"};
    addAppointment(scheduler, appointment1);
    Appointment appointment2 = {"Jane Doe", "11:00 AM", "01/02/2023"};
    addAppointment(scheduler, appointment2);
    Appointment appointment3 = {"John Smith", "12:00 PM", "01/03/2023"};
    addAppointment(scheduler, appointment3);

    // Print the appointments in the scheduler
    printf("Appointments:\n");
    printAppointments(scheduler);

    // Get an appointment from the scheduler
    Appointment appointment = getAppointment(scheduler, "Jane Doe");

    // Print the appointment
    printf("Appointment for Jane Doe:\n");
    printf("%s %s %s\n", appointment.name, appointment.time, appointment.date);

    // Delete the appointment from the scheduler
    deleteAppointment(scheduler, "Jane Doe");

    // Print the appointments in the scheduler
    printf("Appointments after deleting Jane Doe's appointment:\n");
    printAppointments(scheduler);

    return 0;
}