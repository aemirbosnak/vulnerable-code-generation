//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the number of appointments
#define NUM_APPOINTMENTS 10

// Define the appointment structure
typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    struct Appointment* next;
} Appointment;

// Function to insert an appointment
void insertAppointment(Appointment** head, char* name, char* date, char* time) {
    // Allocate memory for the new appointment
    Appointment* newAppt = (Appointment*)malloc(sizeof(Appointment));

    // Copy the appointment data
    strcpy(newAppt->name, name);
    strcpy(newAppt->date, date);
    strcpy(newAppt->time, time);

    // Insert the new appointment into the list
    if (*head == NULL) {
        *head = newAppt;
    } else {
        (*head)->next = newAppt;
    }
}

// Function to print all appointments
void printAppointments(Appointment* head) {
    // Traverse the list of appointments
    while (head) {
        // Print the appointment data
        printf("%s, %s, %s\n", head->name, head->date, head->time);
        head = head->next;
    }
}

int main() {
    // Create a linked list of appointments
    Appointment* head = NULL;

    // Insert some appointments
    insertAppointment(&head, "John Doe", "2023-01-01", "10:00");
    insertAppointment(&head, "Jane Doe", "2023-01-02", "12:00");
    insertAppointment(&head, "Peter Pan", "2023-01-03", "14:00");

    // Print all appointments
    printAppointments(head);

    return 0;
}