//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store an appointment
typedef struct appointment {
    char *name;
    char *description;
    int start_time;
    int end_time;
} appointment;

// Function to create a new appointment
appointment *create_appointment(char *name, char *description, int start_time, int end_time) {
    appointment *new_appointment = malloc(sizeof(appointment));
    new_appointment->name = strdup(name);
    new_appointment->description = strdup(description);
    new_appointment->start_time = start_time;
    new_appointment->end_time = end_time;
    return new_appointment;
}

// Function to print an appointment
void print_appointment(appointment *appointment) {
    printf("%s - %s (%d - %d)\n", appointment->name, appointment->description, appointment->start_time, appointment->end_time);
}

// Function to compare two appointments by start time
int compare_appointments(const void *a, const void *b) {
    const appointment *appointment1 = (const appointment *)a;
    const appointment *appointment2 = (const appointment *)b;
    return appointment1->start_time - appointment2->start_time;
}

// Function to schedule an appointment
int schedule_appointment(appointment **appointments, int num_appointments, appointment *new_appointment) {
    // Check if the new appointment overlaps with any existing appointments
    for (int i = 0; i < num_appointments; i++) {
        if (new_appointment->start_time < appointments[i]->end_time && new_appointment->end_time > appointments[i]->start_time) {
            return 0; // Overlap found
        }
    }

    // No overlap found, so add the new appointment to the array
    appointments = realloc(appointments, (num_appointments + 1) * sizeof(appointment *));
    appointments[num_appointments] = new_appointment;
    num_appointments++;

    // Sort the appointments by start time
    qsort(appointments, num_appointments, sizeof(appointment *), compare_appointments);

    return 1; // Appointment scheduled successfully
}

// Function to print all appointments
void print_all_appointments(appointment **appointments, int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }
}

// Function to free the memory allocated for an appointment
void free_appointment(appointment *appointment) {
    free(appointment->name);
    free(appointment->description);
    free(appointment);
}

// Function to free the memory allocated for all appointments
void free_all_appointments(appointment **appointments, int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        free_appointment(appointments[i]);
    }
    free(appointments);
}

// Main function
int main() {
    // Create an array of appointments
    appointment **appointments = NULL;
    int num_appointments = 0;

    // Schedule some appointments
    schedule_appointment(appointments, num_appointments, create_appointment("John Doe", "Meeting", 1000, 1100));
    schedule_appointment(appointments, num_appointments, create_appointment("Jane Doe", "Lunch", 1200, 1300));
    schedule_appointment(appointments, num_appointments, create_appointment("John Smith", "Interview", 1400, 1500));

    // Print all appointments
    print_all_appointments(appointments, num_appointments);

    // Free the memory allocated for the appointments
    free_all_appointments(appointments, num_appointments);

    return 0;
}