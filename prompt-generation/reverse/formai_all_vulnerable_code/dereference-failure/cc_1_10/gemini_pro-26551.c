//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appointment structure
typedef struct Appointment {
    char *name;
    char *date;
    char *time;
    char *description;
} Appointment;

// Create a new appointment
Appointment *create_appointment(char *name, char *date, char *time, char *description) {
    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->name = strdup(name);
    appointment->date = strdup(date);
    appointment->time = strdup(time);
    appointment->description = strdup(description);
    return appointment;
}

// Print an appointment
void print_appointment(Appointment *appointment) {
    printf("%s\n", appointment->name);
    printf("%s\n", appointment->date);
    printf("%s\n", appointment->time);
    printf("%s\n", appointment->description);
}

// Free an appointment
void free_appointment(Appointment *appointment) {
    free(appointment->name);
    free(appointment->date);
    free(appointment->time);
    free(appointment->description);
    free(appointment);
}

// Main function
int main() {
    // Create a new appointment
    Appointment *appointment = create_appointment("John Doe", "2023-03-08", "10:00 AM", "Meeting with Dr. Smith");

    // Print the appointment
    print_appointment(appointment);

    // Free the appointment
    free_appointment(appointment);

    return 0;
}