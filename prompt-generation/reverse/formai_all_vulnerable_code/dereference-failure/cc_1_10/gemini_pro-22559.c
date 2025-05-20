//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent an appointment
typedef struct appointment {
    int id;
    char *description;
    int start_time;
    int end_time;
} appointment;

// Array of appointments
appointment appointments[100];

// Index of the next available appointment
int next_index = 0;

// Function to create a new appointment
appointment *create_appointment(int id, char *description, int start_time, int end_time) {
    // Allocate memory for the new appointment
    appointment *new_appointment = malloc(sizeof(appointment));

    // Set the properties of the new appointment
    new_appointment->id = id;
    new_appointment->description = description;
    new_appointment->start_time = start_time;
    new_appointment->end_time = end_time;

    // Return the new appointment
    return new_appointment;
}

// Function to add an appointment to the array
void add_appointment(appointment *new_appointment) {
    // Add the new appointment to the array
    appointments[next_index++] = *new_appointment;
}

// Function to find an appointment by its ID
appointment *find_appointment_by_id(int id) {
    // Iterate over the array of appointments
    for (int i = 0; i < next_index; i++) {
        // Check if the current appointment's ID matches the given ID
        if (appointments[i].id == id) {
            // Return the current appointment
            return &appointments[i];
        }
    }

    // Return NULL if the appointment was not found
    return NULL;
}

// Function to delete an appointment by its ID
void delete_appointment_by_id(int id) {
    // Find the appointment by its ID
    appointment *appointment_to_delete = find_appointment_by_id(id);

    // Check if the appointment was found
    if (appointment_to_delete != NULL) {
        // Shift the remaining appointments down to fill the gap
        for (int i = appointment_to_delete - appointments; i < next_index - 1; i++) {
            appointments[i] = appointments[i + 1];
        }

        // Decrement the next index
        next_index--;
    }
}

// Function to print the array of appointments
void print_appointments() {
    // Iterate over the array of appointments
    for (int i = 0; i < next_index; i++) {
        // Print the details of the current appointment
        printf("Appointment ID: %d\n", appointments[i].id);
        printf("Description: %s\n", appointments[i].description);
        printf("Start time: %d\n", appointments[i].start_time);
        printf("End time: %d\n\n", appointments[i].end_time);
    }
}

// Main function
int main() {
    // Create some appointments
    appointment *appointment1 = create_appointment(1, "Meeting with client", 1000, 1100);
    appointment *appointment2 = create_appointment(2, "Conference call", 1200, 1300);
    appointment *appointment3 = create_appointment(3, "Lunch break", 1300, 1400);

    // Add the appointments to the array
    add_appointment(appointment1);
    add_appointment(appointment2);
    add_appointment(appointment3);

    // Print the array of appointments
    print_appointments();

    // Find an appointment by its ID
    appointment *found_appointment = find_appointment_by_id(2);

    // Check if the appointment was found
    if (found_appointment != NULL) {
        // Print the details of the found appointment
        printf("Found appointment:\n");
        printf("Appointment ID: %d\n", found_appointment->id);
        printf("Description: %s\n", found_appointment->description);
        printf("Start time: %d\n", found_appointment->start_time);
        printf("End time: %d\n\n", found_appointment->end_time);
    } else {
        // Print an error message
        printf("Appointment not found.\n");
    }

    // Delete an appointment by its ID
    delete_appointment_by_id(2);

    // Print the array of appointments
    print_appointments();

    return 0;
}