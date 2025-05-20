//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 10

// Define the structure of an appointment
typedef struct Appointment {
    char name[50];
    char date[10];
    char time[10];
    struct Appointment* next;
} Appointment;

// Function to insert an appointment
void insertAppointment(Appointment** head, char* name, char* date, char* time) {
    // Allocate memory for the new appointment
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));

    // Copy the name, date, and time of the new appointment
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);

    // Set the next pointer of the new appointment to NULL
    newAppointment->next = NULL;

    // If the head of the list is NULL, make the new appointment the head of the list
    if (*head == NULL) {
        *head = newAppointment;
    } else {
        // Traverse the list until the last appointment is reached
        Appointment* lastAppointment = *head;
        while (lastAppointment->next != NULL) {
            lastAppointment = lastAppointment->next;
        }

        // Insert the new appointment at the end of the list
        lastAppointment->next = newAppointment;
    }
}

// Function to print the appointments
void printAppointments(Appointment* head) {
    // Traverse the list of appointments
    while (head) {
        // Print the name, date, and time of each appointment
        printf("Name: %s\n", head->name);
        printf("Date: %s\n", head->date);
        printf("Time: %s\n", head->time);
        printf("\n");
        head = head->next;
    }
}

int main() {
    // Create a linked list of appointments
    Appointment* head = NULL;

    // Insert some appointments
    insertAppointment(&head, "John Doe", "2023-01-01", "10:00");
    insertAppointment(&head, "Jane Doe", "2023-01-02", "12:00");
    insertAppointment(&head, "Bob Smith", "2023-01-03", "14:00");

    // Print the appointments
    printAppointments(head);

    return 0;
}