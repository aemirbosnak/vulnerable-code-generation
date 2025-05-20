//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to schedule an appointment
void schedule_appointment(char* name, int start_time, int end_time, char* note) {
    // Check if the appointment time is valid
    if (start_time < 0 || end_time < 0 || start_time >= end_time) {
        printf("Invalid appointment time.\n");
        return;
    }

    // Schedule the appointment
    printf("Appointment scheduled for %s from %d:%02d to %d:%02d with note: %s.\n", name, start_time / 100, start_time % 100, end_time / 100, end_time % 100, note);
}

// Function to cancel an appointment
void cancel_appointment(char* name, int start_time, int end_time, char* note) {
    // Check if the appointment exists
    if (start_time < 0 || end_time < 0 || start_time >= end_time) {
        printf("Appointment does not exist.\n");
        return;
    }

    // Cancel the appointment
    printf("Appointment canceled for %s from %d:%02d to %d:%02d with note: %s.\n", name, start_time / 100, start_time % 100, end_time / 100, end_time % 100, note);
}

// Function to view appointments
void view_appointments() {
    printf("Appointments:\n");

    // Loop through all appointments and display them
    char* name[3];
    int start_time[3];
    int end_time[3];
    char* note[3];

    for (int i = 0; i < 3; i++) {
        name[i] = (char*) malloc(100 * sizeof(char));
        start_time[i] = (int) malloc(100 * sizeof(int));
        end_time[i] = (int) malloc(100 * sizeof(int));
        note[i] = (char*) malloc(100 * sizeof(char));
    }

    name[0] = (char*) malloc(100 * sizeof(char));
    start_time[0] = (int) malloc(100 * sizeof(int));
    end_time[0] = (int) malloc(100 * sizeof(int));
    note[0] = (char*) malloc(100 * sizeof(char));
    name[1] = (char*) malloc(100 * sizeof(char));
    start_time[1] = (int) malloc(100 * sizeof(int));
    end_time[1] = (int) malloc(100 * sizeof(int));
    note[1] = (char*) malloc(100 * sizeof(char));
    name[2] = (char*) malloc(100 * sizeof(char));
    start_time[2] = (int) malloc(100 * sizeof(int));
    end_time[2] = (int) malloc(100 * sizeof(int));
    note[2] = (char*) malloc(100 * sizeof(char));

    schedule_appointment(name[0], start_time[0], end_time[0], note[0]);
    schedule_appointment(name[1], start_time[1], end_time[1], note[1]);
    schedule_appointment(name[2], start_time[2], end_time[2], note[2]);

    // Display the appointments
    printf("Appointment 1: %s from %d:%02d to %d:%02d with note: %s\n", name[0], start_time[0] / 100, start_time[0] % 100, end_time[0] / 100, end_time[0] % 100, note[0]);
    printf("Appointment 2: %s from %d:%02d to %d:%02d with note: %s\n", name[1], start_time[1] / 100, start_time[1] % 100, end_time[1] / 100, end_time[1] % 100, note[1]);
    printf("Appointment 3: %s from %d:%02d to %d:%02d with note: %s\n", name[2], start_time[2] / 100, start_time[2] % 100, end_time[2] / 100, end_time[2] % 100, note[2]);

    // Free allocated memory
    free(name[0]);
    free(start_time[0]);
    free(end_time[0]);
    free(note[0]);
    free(name[1]);
    free(start_time[1]);
    free(end_time[1]);
    free(note[1]);
    free(name[2]);
    free(start_time[2]);
    free(end_time[2]);
    free(note[2]);
}

// Function to main program
int main() {
    // Create an appointment
    char* name = (char*) malloc(100 * sizeof(char));
    int start_time = 1500;
    int end_time = 1600;
    char* note = (char*) malloc(100 * sizeof(char));
    schedule_appointment(name, start_time, end_time, note);

    // Cancel the appointment
    cancel_appointment(name, start_time, end_time, note);

    // View appointments
    view_appointments();

    return 0;
}