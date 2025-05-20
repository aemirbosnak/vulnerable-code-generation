//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

Appointment* insertAppointment(Appointment* head, char* name, char* date, char* time) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    newAppointment->next = NULL;

    if (head == NULL) {
        head = newAppointment;
    } else {
        head->next = newAppointment;
    }

    return head;
}

void printAppointments(Appointment* head) {
    Appointment* currentAppointment = head;
    while (currentAppointment) {
        printf("Name: %s\n", currentAppointment->name);
        printf("Date: %s\n", currentAppointment->date);
        printf("Time: %s\n", currentAppointment->time);
        printf("\n");
        currentAppointment = currentAppointment->next;
    }
}

int main() {
    Appointment* head = NULL;

    insertAppointment(head, "John Doe", "2023-04-01", "10:00");
    insertAppointment(head, "Jane Doe", "2023-04-02", "12:00");
    insertAppointment(head, "Bill Smith", "2023-04-03", "14:00");

    printAppointments(head);

    return 0;
}