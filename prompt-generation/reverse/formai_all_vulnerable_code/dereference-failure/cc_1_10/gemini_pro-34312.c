//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store an appointment
typedef struct appointment {
    char *name;
    char *description;
    time_t start_time;
    time_t end_time;
} appointment_t;

// Function to create a new appointment
appointment_t *create_appointment(char *name, char *description, time_t start_time, time_t end_time) {
    appointment_t *new_appointment = malloc(sizeof(appointment_t));
    new_appointment->name = name;
    new_appointment->description = description;
    new_appointment->start_time = start_time;
    new_appointment->end_time = end_time;
    return new_appointment;
}

// Function to print an appointment
void print_appointment(appointment_t *appointment) {
    printf("Appointment:\n");
    printf("Name: %s\n", appointment->name);
    printf("Description: %s\n", appointment->description);
    printf("Start time: %s\n", ctime(&appointment->start_time));
    printf("End time: %s\n", ctime(&appointment->end_time));
}

// Function to compare two appointments
int compare_appointments(appointment_t *a, appointment_t *b) {
    return a->start_time - b->start_time;
}

// Function to sort an array of appointments
void sort_appointments(appointment_t **appointments, int num_appointments) {
    qsort(appointments, num_appointments, sizeof(appointment_t *), compare_appointments);
}

// Function to find a free time slot in an array of appointments
time_t find_free_time_slot(appointment_t **appointments, int num_appointments, time_t start_time, time_t end_time) {
    for (int i = 0; i < num_appointments; i++) {
        if (appointments[i]->start_time > end_time) {
            return start_time;
        } else if (appointments[i]->end_time < start_time) {
            start_time = appointments[i]->end_time;
        } else {
            return -1;
        }
    }
    return start_time;
}

// Function to schedule an appointment
int schedule_appointment(appointment_t **appointments, int num_appointments, appointment_t *new_appointment) {
    // Sort the appointments by start time
    sort_appointments(appointments, num_appointments);

    // Find a free time slot for the new appointment
    time_t free_time_slot = find_free_time_slot(appointments, num_appointments, new_appointment->start_time, new_appointment->end_time);

    // If there is a free time slot, add the new appointment to the array
    if (free_time_slot != -1) {
        appointments[num_appointments] = new_appointment;
        num_appointments++;
        return 0;
    } else {
        return -1;
    }
}

// Function to print a list of appointments
void print_appointments(appointment_t **appointments, int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
        printf("\n");
    }
}

// Main function
int main() {
    // Create an array of appointments
    appointment_t *appointments[10];
    int num_appointments = 0;

    // Schedule some appointments
    appointment_t *appointment1 = create_appointment("Appointment 1", "This is the first appointment.", time(NULL) + 3600, time(NULL) + 7200);
    schedule_appointment(appointments, num_appointments, appointment1);

    appointment_t *appointment2 = create_appointment("Appointment 2", "This is the second appointment.", time(NULL) + 7200, time(NULL) + 10800);
    schedule_appointment(appointments, num_appointments, appointment2);

    appointment_t *appointment3 = create_appointment("Appointment 3", "This is the third appointment.", time(NULL) + 10800, time(NULL) + 14400);
    schedule_appointment(appointments, num_appointments, appointment3);

    // Print the list of appointments
    print_appointments(appointments, num_appointments);

    return 0;
}