//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure for an appointment
typedef struct appointment {
    char *name;
    char *description;
    time_t start_time;
    time_t end_time;
} appointment_t;

// Create a new appointment
appointment_t *create_appointment(char *name, char *description, time_t start_time, time_t end_time) {
    appointment_t *new_appointment = malloc(sizeof(appointment_t));
    if (new_appointment == NULL) {
        // Error allocating memory for the new appointment
        return NULL;
    }

    // Set the fields of the new appointment
    new_appointment->name = strdup(name);
    new_appointment->description = strdup(description);
    new_appointment->start_time = start_time;
    new_appointment->end_time = end_time;

    return new_appointment;
}

// Free the memory allocated for an appointment
void free_appointment(appointment_t *appointment) {
    free(appointment->name);
    free(appointment->description);
    free(appointment);
}

// Print the details of an appointment
void print_appointment(appointment_t *appointment) {
    // Convert the start and end times to human-readable format
    char *start_time_str = ctime(&appointment->start_time);
    char *end_time_str = ctime(&appointment->end_time);

    // Print the appointment details
    printf("Appointment:\n");
    printf("Name: %s\n", appointment->name);
    printf("Description: %s\n", appointment->description);
    printf("Start time: %s\n", start_time_str);
    printf("End time: %s\n", end_time_str);
}

// Compare two appointments by their start time
int compare_appointments(const void *a, const void *b) {
    appointment_t *appointment1 = (appointment_t *)a;
    appointment_t *appointment2 = (appointment_t *)b;

    if (appointment1->start_time < appointment2->start_time) {
        return -1;
    } else if (appointment1->start_time > appointment2->start_time) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    // Create an array of appointments
    appointment_t *appointments[] = {
        create_appointment("Doctor's appointment", "Annual checkup", time(NULL), time(NULL) + 3600),
        create_appointment("Meeting with boss", "Discuss project progress", time(NULL) + 3600, time(NULL) + 7200),
        create_appointment("Lunch with friend", "Catch up over lunch", time(NULL) + 7200, time(NULL) + 10800),
        create_appointment("Movie night", "Watch a movie with friends", time(NULL) + 10800, time(NULL) + 14400),
        create_appointment("Gym workout", "Get some exercise", time(NULL) + 14400, time(NULL) + 18000),
    };

    // Sort the appointments by their start time
    qsort(appointments, sizeof(appointments) / sizeof(appointment_t *), sizeof(appointment_t *), compare_appointments);

    // Print the sorted appointments
    for (int i = 0; i < sizeof(appointments) / sizeof(appointment_t *); i++) {
        print_appointment(appointments[i]);
        printf("\n");
    }

    // Free the memory allocated for the appointments
    for (int i = 0; i < sizeof(appointments) / sizeof(appointment_t *); i++) {
        free_appointment(appointments[i]);
    }

    return 0;
}