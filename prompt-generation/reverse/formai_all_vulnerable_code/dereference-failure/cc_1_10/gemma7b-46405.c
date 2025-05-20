//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the appointment structure
typedef struct Appointment {
    char name[50];
    char date[10];
    char time[10];
    struct Appointment* next;
} Appointment;

// Function to insert an appointment
void insertAppointment(Appointment** head, char* name, char* date, char* time) {
    Appointment* newApp = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newApp->name, name);
    strcpy(newApp->date, date);
    strcpy(newApp->time, time);
    newApp->next = NULL;

    if (*head == NULL) {
        *head = newApp;
    } else {
        (*head)->next = newApp;
    }
}

// Function to print all appointments
void printAppointments(Appointment* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Date: %s\n", head->date);
        printf("Time: %s\n", head->time);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Appointment* head = NULL;

    // Insert some appointments
    insertAppointment(&head, "John Doe", "2023-08-01", "10:00");
    insertAppointment(&head, "Jane Doe", "2023-08-02", "12:00");
    insertAppointment(&head, "Peter Pan", "2023-08-03", "14:00");

    // Print all appointments
    printAppointments(head);

    return 0;
}