//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define struct for appointments
typedef struct {
    char name[50];
    char date[15];
    char time[10];
} Appointment;

// Define function for scheduling appointments
void scheduleAppointment(Appointment **appointments, int numAppointments) {
    char name[50], date[15], time[10];
    // Ask for user input for appointment details
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter the appointment date (MM/DD/YYYY): ");
    scanf("%s", date);
    printf("Enter the appointment time (HH:MM AM/PM): ");
    scanf("%s", time);
    // Add appointment to array of appointments
    Appointment *newAppointment = malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    appointments[numAppointments] = newAppointment;
    // Increment number of appointments
    numAppointments++;
    // Confirm appointment details to user
    printf("\nAppointment scheduled for:\nName: %s\nDate: %s\nTime: %s\n", name, date, time);
    // Display updated list of appointments
    printf("\nCurrent Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("Appointment %d:\nName: %s\nDate: %s\nTime: %s\n", i+1, appointments[i]->name, appointments[i]->date, appointments[i]->time);
    }
}

int main() {
    // Initialize array of pointers to Appointment structs
    Appointment *appointments[50];
    int numAppointments = 0;
    // Initialize variable for user input for menu selection
    int choice;
    do {
        // Display menu options for user
        printf("\nAppointment Scheduler Menu:\n");
        printf("1. Schedule an Appointment\n");
        printf("2. View All Appointments\n");
        printf("3. Exit\n");
        // Ask for user input for menu selection
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Call function to schedule appointment
                scheduleAppointment(appointments, numAppointments);
                break;
            case 2:
                // Display all existing appointments
                printf("\nExisting Appointments:\n");
                for (int i = 0; i < numAppointments; i++) {
                    printf("Appointment %d:\nName: %s\nDate: %s\nTime: %s\n", i+1, appointments[i]->name, appointments[i]->date, appointments[i]->time);
                }
                break;
            default:
                // Exit program
                printf("\nExiting Appointment Scheduler. Goodbye!\n");
                break;
        }
    } while (choice != 3);
    // Free memory allocated for Appointment structs
    for (int i = 0; i < numAppointments; i++) {
        free(appointments[i]);
    }
    return 0;
}