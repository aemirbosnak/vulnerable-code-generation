//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an appointment
typedef struct Appointment {
    char *name;
    char *description;
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

// Function to create a new appointment
Appointment *createAppointment(char *name, char *description, int day, int month, int year, int hour, int minute) {
    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->name = strdup(name);
    appointment->description = strdup(description);
    appointment->day = day;
    appointment->month = month;
    appointment->year = year;
    appointment->hour = hour;
    appointment->minute = minute;
    return appointment;
}

// Function to print an appointment
void printAppointment(Appointment *appointment) {
    printf("%s (%s) - %d/%d/%d %d:%d\n", appointment->name, appointment->description, appointment->day, appointment->month, appointment->year, appointment->hour, appointment->minute);
}

// Function to compare two appointments by their time
int compareAppointments(const void *a, const void *b) {
    Appointment *appointment1 = (Appointment *)a;
    Appointment *appointment2 = (Appointment *)b;
    if (appointment1->year != appointment2->year) {
        return appointment1->year - appointment2->year;
    } else if (appointment1->month != appointment2->month) {
        return appointment1->month - appointment2->month;
    } else if (appointment1->day != appointment2->day) {
        return appointment1->day - appointment2->day;
    } else if (appointment1->hour != appointment2->hour) {
        return appointment1->hour - appointment2->hour;
    } else {
        return appointment1->minute - appointment2->minute;
    }
}

// Function to find an appointment by its name
Appointment *findAppointment(Appointment *appointments, int numAppointments, char *name) {
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            return &appointments[i];
        }
    }
    return NULL;
}

// Function to add an appointment to the schedule
void addAppointment(Appointment **appointments, int *numAppointments, Appointment *appointment) {
    *appointments = realloc(*appointments, (*numAppointments + 1) * sizeof(Appointment));
    (*appointments)[*numAppointments] = *appointment;
    (*numAppointments)++;
    qsort(*appointments, *numAppointments, sizeof(Appointment), compareAppointments);
}

// Function to remove an appointment from the schedule
void removeAppointment(Appointment **appointments, int *numAppointments, Appointment *appointment) {
    for (int i = 0; i < *numAppointments; i++) {
        if (&(*appointments)[i] == appointment) {
            for (int j = i + 1; j < *numAppointments; j++) {
                (*appointments)[j - 1] = (*appointments)[j];
            }
            (*numAppointments)--;
            free(appointment);
            break;
        }
    }
}

// Function to print the schedule
void printSchedule(Appointment *appointments, int numAppointments) {
    printf("Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printAppointment(&appointments[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Create an array of appointments
    Appointment *appointments = NULL;
    int numAppointments = 0;

    // Add some appointments to the schedule
    addAppointment(&appointments, &numAppointments, createAppointment("John Doe", "Meeting", 1, 1, 2023, 10, 0));
    addAppointment(&appointments, &numAppointments, createAppointment("Jane Doe", "Lunch", 1, 1, 2023, 12, 0));
    addAppointment(&appointments, &numAppointments, createAppointment("John Smith", "Appointment", 2, 1, 2023, 14, 0));
    addAppointment(&appointments, &numAppointments, createAppointment("Jane Smith", "Meeting", 2, 1, 2023, 16, 0));

    // Print the schedule
    printSchedule(appointments, numAppointments);

    // Find an appointment by its name
    Appointment *appointment = findAppointment(appointments, numAppointments, "John Doe");
    if (appointment != NULL) {
        printf("Found appointment: ");
        printAppointment(appointment);
    } else {
        printf("Appointment not found.\n");
    }

    // Remove an appointment from the schedule
    removeAppointment(&appointments, &numAppointments, appointment);

    // Print the schedule
    printSchedule(appointments, numAppointments);

    // Free the appointments
    for (int i = 0; i < numAppointments; i++) {
        free(appointments[i].name);
        free(appointments[i].description);
    }
    free(appointments);

    return 0;
}