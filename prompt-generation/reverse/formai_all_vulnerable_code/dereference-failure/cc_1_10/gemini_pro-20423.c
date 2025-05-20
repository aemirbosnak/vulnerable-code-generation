//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments that can be scheduled
#define MAX_APPOINTMENTS 100

// Define the structure of an appointment
typedef struct Appointment {
    char *name;
    char *description;
    int start_time;
    int end_time;
} Appointment;

// Create an array of appointments
Appointment appointments[MAX_APPOINTMENTS];

// Initialize the number of appointments to 0
int num_appointments = 0;

// Function to add an appointment to the schedule
void add_appointment(char *name, char *description, int start_time, int end_time) {
    // Check if the array of appointments is full
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: The array of appointments is full.\n");
        return;
    }

    // Allocate memory for the new appointment
    appointments[num_appointments].name = malloc(strlen(name) + 1);
    appointments[num_appointments].description = malloc(strlen(description) + 1);

    // Copy the appointment details into the array
    strcpy(appointments[num_appointments].name, name);
    strcpy(appointments[num_appointments].description, description);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;

    // Increment the number of appointments
    num_appointments++;
}

// Function to print the schedule of appointments
void print_schedule() {
    // Loop through the array of appointments
    for (int i = 0; i < num_appointments; i++) {
        // Print the appointment details
        printf("%s: %s (%d-%d)\n", appointments[i].name, appointments[i].description, appointments[i].start_time, appointments[i].end_time);
    }
}

// Main function
int main() {
    // Add some appointments to the schedule
    add_appointment("John Doe", "Meeting with client", 9, 10);
    add_appointment("Jane Doe", "Doctor's appointment", 10, 11);
    add_appointment("John Smith", "Lunch with friend", 12, 1);
    add_appointment("Jane Smith", "Shopping", 1, 2);

    // Print the schedule of appointments
    print_schedule();

    return 0;
}