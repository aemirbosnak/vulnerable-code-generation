//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store appointment details
typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    char reason[100];
} Appointment;

// Function to create a new appointment
Appointment* createAppointment(char *name, char *date, char *time, char *reason) {
    Appointment *newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    strcpy(newAppointment->reason, reason);
    return newAppointment;
}

// Function to print appointment details
void printAppointment(Appointment *app) {
    printf("Name: %s\n", app->name);
    printf("Date: %s\n", app->date);
    printf("Time: %s\n", app->time);
    printf("Reason: %s\n", app->reason);
}

// Function to compare two appointments by date and time
int compareAppointments(Appointment *a, Appointment *b) {
    int dateComparison = strcmp(a->date, b->date);
    if (dateComparison == 0) {
        return strcmp(a->time, b->time);
    } else {
        return dateComparison;
    }
}

// Function to sort an array of appointments by date and time
void sortAppointments(Appointment **apps, int n) {
    for (int i = 1; i < n; i++) {
        Appointment *key = apps[i];
        int j = i - 1;
        while (j >= 0 && compareAppointments(key, apps[j]) < 0) {
            apps[j + 1] = apps[j];
            j--;
        }
        apps[j + 1] = key;
    }
}

// Function to find the first available time slot
int findAvailableSlot(Appointment **apps, int n, char *date, char *time) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(apps[i]->date, date) == 0 && strcmp(apps[i]->time, time) == 0) {
            index = i;
            break;
        }
    }
    return index;
}

// Function to schedule an appointment
int scheduleAppointment(Appointment **apps, int *n, char *name, char *date, char *time, char *reason) {
    int slotIndex = findAvailableSlot(apps, *n, date, time);
    if (slotIndex != -1) {
        // Slot is available, update the appointment details
        strcpy(apps[slotIndex]->name, name);
        strcpy(apps[slotIndex]->date, date);
        strcpy(apps[slotIndex]->time, time);
        strcpy(apps[slotIndex]->reason, reason);
        printf("Appointment scheduled successfully!\n");
        return 1;
    } else {
        // Slot is not available, add a new appointment to the end of the array
        Appointment *newAppointment = createAppointment(name, date, time, reason);
        apps[*n] = newAppointment;
        (*n)++;
        sortAppointments(apps, *n);
        printf("Appointment scheduled successfully!\n");
        return 1;
    }
}

// Function to cancel an appointment
int cancelAppointment(Appointment **apps, int *n, char *name, char *date, char *time) {
    int slotIndex = findAvailableSlot(apps, *n, date, time);
    if (slotIndex != -1) {
        // Slot is available, delete the appointment
        free(apps[slotIndex]);
        for (int i = slotIndex; i < *n - 1; i++) {
            apps[i] = apps[i + 1];
        }
        (*n)--;
        printf("Appointment cancelled successfully!\n");
        return 1;
    } else {
        // Slot is not available, appointment cannot be cancelled
        printf("Appointment not found!\n");
        return 0;
    }
}

// Function to display all appointments
void displayAppointments(Appointment **apps, int n) {
    printf("Appointments:\n");
    for (int i = 0; i < n; i++) {
        printAppointment(apps[i]);
        printf("\n");
    }
}

int main() {
    // Initialize the array of appointments
    Appointment *apps[100];
    int n = 0;

    // Schedule some appointments
    scheduleAppointment(apps, &n, "John Doe", "2023-03-08", "10:00 AM", "Meeting");
    scheduleAppointment(apps, &n, "Jane Smith", "2023-03-10", "11:00 AM", "Interview");
    scheduleAppointment(apps, &n, "Bob Smith", "2023-03-12", "1:00 PM", "Consultation");

    // Display the appointments
    displayAppointments(apps, n);

    // Cancel an appointment
    cancelAppointment(apps, &n, "John Doe", "2023-03-08", "10:00 AM");

    // Display the appointments after cancellation
    displayAppointments(apps, n);

    return 0;
}