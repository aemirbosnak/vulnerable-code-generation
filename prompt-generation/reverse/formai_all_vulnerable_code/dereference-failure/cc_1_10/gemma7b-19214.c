//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define the Sherlock Holmes Appointment Scheduler structure
typedef struct Appointment {
    char name[50];
    char date[10];
    char time[10];
    struct Appointment* next;
} Appointment;

// Function to insert an appointment into the scheduler
void insertAppointment(Appointment** head, char* name, char* date, char* time) {
    // Allocate memory for the new appointment
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));

    // Copy the appointment details into the new appointment structure
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);

    // If the head of the scheduler is null, make it the new appointment
    if (*head == NULL) {
        *head = newAppointment;
    } else {
        // Traverse the scheduler until the last appointment is reached
        Appointment* currentAppointment = *head;
        while (currentAppointment->next != NULL) {
            currentAppointment = currentAppointment->next;
        }

        // Insert the new appointment at the end of the scheduler
        currentAppointment->next = newAppointment;
    }
}

// Function to print the appointments in the scheduler
void printAppointments(Appointment* head) {
    // Traverse the scheduler and print each appointment
    Appointment* currentAppointment = head;
    while (currentAppointment) {
        printf("Name: %s, Date: %s, Time: %s\n", currentAppointment->name, currentAppointment->date, currentAppointment->time);
        currentAppointment = currentAppointment->next;
    }
}

int main() {
    // Create a new Sherlock Holmes Appointment Scheduler
    Appointment* head = NULL;

    // Insert some appointments
    insertAppointment(&head, "Mr. A", "2023-03-01", "10:00");
    insertAppointment(&head, "Mrs. B", "2023-03-02", "12:00");
    insertAppointment(&head, "Mr. C", "2023-03-03", "14:00");

    // Print the appointments
    printAppointments(head);

    return 0;
}