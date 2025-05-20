//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, char* date, char* time) {
    Appointment* newAppointment = (Appointment*) malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    newAppointment->next = NULL;
    return newAppointment;
}

void displayAppointments(Appointment* head) {
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

    // Create a few appointments
    Appointment* newAppointment1 = createAppointment("John Doe", "2023-04-01", "10:00");
    Appointment* newAppointment2 = createAppointment("Jane Doe", "2023-04-02", "12:00");
    Appointment* newAppointment3 = createAppointment("Bill Smith", "2023-04-03", "14:00");

    // Add the appointments to the head of the list
    head = newAppointment1;
    newAppointment2->next = head;
    newAppointment3->next = newAppointment2;

    // Display the appointments
    displayAppointments(head);

    return 0;
}