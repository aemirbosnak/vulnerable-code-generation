//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
// Hey, Linus, check out this appointment scheduler I whipped up!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Datatypes, macros, and structs.
typedef struct Appointment {
    int id;
    char *title;
    char *description;
    int start_time;
    int end_time;
} Appointment;

#define MAX_APPOINTMENTS 100
#define LINE_LENGTH 100

// Function prototypes.
Appointment *create_appointment(char *title, char *description, int start_time, int end_time);
void schedule_appointment(Appointment *appointment);
void print_appointment(Appointment *appointment);
void delete_appointment(Appointment *appointment);
void print_appointments();

// Global variables.
Appointment *appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

// Main function.
int main() {
    // Create some appointments.
    Appointment *appt1 = create_appointment("Meeting with Bob", "Discuss quarterly sales figures", 1000, 1100);
    Appointment *appt2 = create_appointment("Lunch with Mary", "Catch up and discuss new project", 1200, 1300);
    Appointment *appt3 = create_appointment("Doctor's appointment", "Annual checkup", 1400, 1500);

    // Schedule the appointments.
    schedule_appointment(appt1);
    schedule_appointment(appt2);
    schedule_appointment(appt3);

    // Print the appointments.
    print_appointments();

    // Delete an appointment.
    delete_appointment(appt2);

    // Print the appointments again.
    print_appointments();

    return 0;
}

// Function definitions.
Appointment *create_appointment(char *title, char *description, int start_time, int end_time) {
    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->id = num_appointments++;
    appointment->title = strdup(title);
    appointment->description = strdup(description);
    appointment->start_time = start_time;
    appointment->end_time = end_time;
    return appointment;
}

void schedule_appointment(Appointment *appointment) {
    appointments[num_appointments++] = appointment;
}

void print_appointment(Appointment *appointment) {
    printf("Appointment ID: %d\n", appointment->id);
    printf("Title: %s\n", appointment->title);
    printf("Description: %s\n", appointment->description);
    printf("Start time: %d\n", appointment->start_time);
    printf("End time: %d\n", appointment->end_time);
    printf("\n");
}

void delete_appointment(Appointment *appointment) {
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i] == appointment) {
            for (int j = i + 1; j < num_appointments; j++) {
                appointments[j - 1] = appointments[j];
            }
            num_appointments--;
            free(appointment->title);
            free(appointment->description);
            free(appointment);
            break;
        }
    }
}

void print_appointments() {
    printf("Here are the scheduled appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }
    printf("\n");
}