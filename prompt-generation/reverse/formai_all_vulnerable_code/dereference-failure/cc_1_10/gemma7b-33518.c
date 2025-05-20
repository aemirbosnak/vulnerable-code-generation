//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char email[50];
    char phone[20];
    char date[20];
    char time[20];
    struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, char* email, char* phone, char* date, char* time) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->email, email);
    strcpy(newAppointment->phone, phone);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    newAppointment->next = NULL;
    return newAppointment;
}

void printAppointments(Appointment* appointments) {
    while (appointments) {
        printf("Name: %s\n", appointments->name);
        printf("Email: %s\n", appointments->email);
        printf("Phone: %s\n", appointments->phone);
        printf("Date: %s\n", appointments->date);
        printf("Time: %s\n", appointments->time);
        printf("\n");
        appointments = appointments->next;
    }
}

int main() {
    Appointment* head = NULL;

    // Create a few appointments
    head = createAppointment("John Doe", "john.doe@example.com", "123-456-7890", "2023-04-01", "10:00");
    head = createAppointment("Jane Doe", "jane.doe@example.com", "456-789-0123", "2023-04-02", "12:00");
    head = createAppointment("Bob Smith", "bob.smith@example.com", "555-123-4567", "2023-04-03", "02:00");

    // Print the appointments
    printAppointments(head);

    return 0;
}