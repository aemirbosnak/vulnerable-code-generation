//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure to represent an appointment
typedef struct Appointment {
    char *name;
    char *reason;
    int day;
    int month;
    int year;
    int hour;
    int minute;
} Appointment;

// Function to create a new appointment
Appointment *createAppointment(char *name, char *reason, int day, int month, int year, int hour, int minute) {
    Appointment *newAppointment = malloc(sizeof(Appointment));
    newAppointment->name = strdup(name);
    newAppointment->reason = strdup(reason);
    newAppointment->day = day;
    newAppointment->month = month;
    newAppointment->year = year;
    newAppointment->hour = hour;
    newAppointment->minute = minute;
    return newAppointment;
}

// Function to print an appointment
void printAppointment(Appointment *appointment) {
    printf("Name: %s\n", appointment->name);
    printf("Reason: %s\n", appointment->reason);
    printf("Date: %d/%d/%d\n", appointment->day, appointment->month, appointment->year);
    printf("Time: %d:%d\n\n", appointment->hour, appointment->minute);
}

// Function to compare two appointments by time
int compareAppointments(const void *a, const void *b) {
    Appointment *appt1 = (Appointment *)a;
    Appointment *appt2 = (Appointment *)b;

    if (appt1->year != appt2->year) {
        return appt1->year - appt2->year;
    } else if (appt1->month != appt2->month) {
        return appt1->month - appt2->month;
    } else if (appt1->day != appt2->day) {
        return appt1->day - appt2->day;
    } else if (appt1->hour != appt2->hour) {
        return appt1->hour - appt2->hour;
    } else {
        return appt1->minute - appt2->minute;
    }
}

// Function to find the next available appointment time
int findNextAvailableTime(Appointment *appointments, int numAppointments, int day, int month, int year, int hour, int minute) {
    // Sort the appointments by time
    qsort(appointments, numAppointments, sizeof(Appointment), compareAppointments);

    // Find the first appointment that is on or after the specified time
    int i;
    for (i = 0; i < numAppointments; i++) {
        if (appointments[i].year > year ||
            (appointments[i].year == year && appointments[i].month > month) ||
            (appointments[i].year == year && appointments[i].month == month && appointments[i].day > day) ||
            (appointments[i].year == year && appointments[i].month == month && appointments[i].day == day && appointments[i].hour > hour) ||
            (appointments[i].year == year && appointments[i].month == month && appointments[i].day == day && appointments[i].hour == hour && appointments[i].minute > minute)) {
            return i;
        }
    }

    // If no appointment is found, return -1
    return -1;
}

// Function to add a new appointment to the array of appointments
void addAppointment(Appointment **appointments, int *numAppointments, Appointment *newAppointment) {
    // Reallocate the array of appointments to make room for the new appointment
    *appointments = realloc(*appointments, (*numAppointments + 1) * sizeof(Appointment));

    // Add the new appointment to the array
    (*appointments)[*numAppointments] = *newAppointment;

    // Increment the number of appointments
    (*numAppointments)++;
}

// Function to remove an appointment from the array of appointments
void removeAppointment(Appointment **appointments, int *numAppointments, int index) {
    // Shift the appointments after the removed appointment to the left
    for (int i = index; i < *numAppointments - 1; i++) {
        (*appointments)[i] = (*appointments)[i + 1];
    }

    // Decrement the number of appointments
    (*numAppointments)--;

    // Reallocate the array of appointments to remove the extra space
    *appointments = realloc(*appointments, *numAppointments * sizeof(Appointment));
}

// Function to print the array of appointments
void printAppointments(Appointment *appointments, int numAppointments) {
    for (int i = 0; i < numAppointments; i++) {
        printAppointment(&appointments[i]);
    }
}

// Function to free the memory allocated for the array of appointments
void freeAppointments(Appointment *appointments, int numAppointments) {
    for (int i = 0; i < numAppointments; i++) {
        free(appointments[i].name);
        free(appointments[i].reason);
    }
    free(appointments);
}

// Main function
int main() {
    // Create an array of appointments
    Appointment *appointments = NULL;
    int numAppointments = 0;

    // Add some appointments to the array
    addAppointment(&appointments, &numAppointments, createAppointment("John Doe", "Doctor's appointment", 1, 2, 2023, 10, 0));
    addAppointment(&appointments, &numAppointments, createAppointment("Jane Doe", "Dentist appointment", 5, 3, 2023, 11, 30));
    addAppointment(&appointments, &numAppointments, createAppointment("Bill Smith", "Haircut", 10, 4, 2023, 13, 0));
    addAppointment(&appointments, &numAppointments, createAppointment("Susan Jones", "Massage", 15, 5, 2023, 14, 30));

    // Print the array of appointments
    printf("Appointments:\n");
    printAppointments(appointments, numAppointments);

    // Find the next available appointment time on March 1, 2023 at 1:00 PM
    int nextAvailableIndex = findNextAvailableTime(appointments, numAppointments, 1, 3, 2023, 13, 0);

    // If an appointment is found, print it
    if (nextAvailableIndex != -1) {
        printf("\nNext available appointment:\n");
        printAppointment(&appointments[nextAvailableIndex]);
    } else {
        printf("\nNo appointments available on that date and time.\n");
    }

    // Remove the first appointment from the array
    removeAppointment(&appointments, &numAppointments, 0);

    // Print the array of appointments
    printf("\nAppointments after removing the first appointment:\n");
    printAppointments(appointments, numAppointments);

    // Free the memory allocated for the array of appointments
    freeAppointments(appointments, numAppointments);

    return 0;
}