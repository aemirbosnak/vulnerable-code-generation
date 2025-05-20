//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 10

// Define the appointment structure
typedef struct appointment {
    char *name;
    char *description;
    int day;
    int month;
    int year;
    int hour;
    int minute;
} appointment;

// Define the function to create a new appointment
appointment *create_appointment(char *name, char *description, int day, int month, int year, int hour, int minute) {
    // Allocate memory for the new appointment
    appointment *new_appointment = malloc(sizeof(appointment));

    // Copy the appointment details into the new appointment
    new_appointment->name = strdup(name);
    new_appointment->description = strdup(description);
    new_appointment->day = day;
    new_appointment->month = month;
    new_appointment->year = year;
    new_appointment->hour = hour;
    new_appointment->minute = minute;

    // Return the new appointment
    return new_appointment;
}

// Define the function to print an appointment
void print_appointment(appointment *appointment) {
    // Print the appointment details
    printf("Name: %s\n", appointment->name);
    printf("Description: %s\n", appointment->description);
    printf("Date: %d/%d/%d\n", appointment->day, appointment->month, appointment->year);
    printf("Time: %d:%d\n", appointment->hour, appointment->minute);
    printf("\n");
}

// Define the function to add an appointment to the schedule
void add_appointment(appointment **schedule, int *num_appointments, appointment *new_appointment) {
    // Check if the schedule is full
    if (*num_appointments == MAX_APPOINTMENTS) {
        printf("The schedule is full. Please try again later.\n");
        return;
    }

    // Add the new appointment to the schedule
    schedule[*num_appointments] = new_appointment;
    (*num_appointments)++;
}

// Define the function to remove an appointment from the schedule
void remove_appointment(appointment **schedule, int *num_appointments, int index) {
    // Check if the index is valid
    if (index < 0 || index >= *num_appointments) {
        printf("Invalid index. Please try again.\n");
        return;
    }

    // Remove the appointment from the schedule
    free(schedule[index]);
    for (int i = index; i < *num_appointments - 1; i++) {
        schedule[i] = schedule[i + 1];
    }
    (*num_appointments)--;
}

// Define the function to print the schedule
void print_schedule(appointment **schedule, int num_appointments) {
    // Print the schedule header
    printf("Schedule:\n");

    // Print each appointment in the schedule
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(schedule[i]);
    }
}

// Define the main function
int main() {
    // Create an empty schedule
    appointment *schedule[MAX_APPOINTMENTS];
    int num_appointments = 0;

    // Add some appointments to the schedule
    add_appointment(schedule, &num_appointments, create_appointment("John Doe", "Meeting", 1, 1, 2023, 10, 0));
    add_appointment(schedule, &num_appointments, create_appointment("Jane Doe", "Appointment", 2, 1, 2023, 11, 0));
    add_appointment(schedule, &num_appointments, create_appointment("John Smith", "Interview", 3, 1, 2023, 12, 0));

    // Print the schedule
    print_schedule(schedule, num_appointments);

    // Remove an appointment from the schedule
    remove_appointment(schedule, &num_appointments, 1);

    // Print the schedule again
    print_schedule(schedule, num_appointments);

    // Free the memory allocated for the appointments
    for (int i = 0; i < num_appointments; i++) {
        free(schedule[i]);
    }

    return 0;
}