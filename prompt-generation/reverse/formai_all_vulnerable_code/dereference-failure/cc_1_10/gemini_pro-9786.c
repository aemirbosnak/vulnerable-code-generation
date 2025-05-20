//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store appointment details
typedef struct Appointment {
    char *description;
    time_t start_time;
    time_t end_time;
} Appointment;

// Function to create a new appointment
Appointment *create_appointment(char *description, time_t start_time, time_t end_time) {
    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->description = strdup(description);
    appointment->start_time = start_time;
    appointment->end_time = end_time;
    return appointment;
}

// Function to destroy an appointment
void destroy_appointment(Appointment *appointment) {
    free(appointment->description);
    free(appointment);
}

// Function to print an appointment
void print_appointment(Appointment *appointment) {
    printf("Appointment: %s\n", appointment->description);
    printf("Start time: %s\n", ctime(&appointment->start_time));
    printf("End time: %s\n", ctime(&appointment->end_time));
}

// Function to compare two appointments by start time
int compare_appointments(const void *a, const void *b) {
    Appointment *appointment1 = (Appointment *)a;
    Appointment *appointment2 = (Appointment *)b;
    return appointment1->start_time - appointment2->start_time;
}

// Main function
int main() {
    // Create an array of appointments
    Appointment *appointments[] = {
        create_appointment("Meeting with client", time(NULL), time(NULL) + 3600),
        create_appointment("Doctor's appointment", time(NULL) + 3600, time(NULL) + 7200),
        create_appointment("Dinner with friends", time(NULL) + 7200, time(NULL) + 10800),
    };

    // Sort the appointments by start time
    qsort(appointments, sizeof(appointments) / sizeof(Appointment *), sizeof(Appointment *), compare_appointments);

    // Print the appointments
    for (size_t i = 0; i < sizeof(appointments) / sizeof(Appointment *); i++) {
        print_appointment(appointments[i]);
    }

    // Destroy the appointments
    for (size_t i = 0; i < sizeof(appointments) / sizeof(Appointment *); i++) {
        destroy_appointment(appointments[i]);
    }

    return 0;
}