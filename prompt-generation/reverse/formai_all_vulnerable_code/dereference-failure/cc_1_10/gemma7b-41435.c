//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: visionary
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

Appointment* head = NULL;

void insertAppointment(char* name, char* date, char* time) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    newAppointment->next = NULL;

    if (head == NULL) {
        head = newAppointment;
    } else {
        head->next = newAppointment;
        head = newAppointment;
    }
}

void displayAppointments() {
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
    insertAppointment("John Doe", "2023-08-01", "10:00");
    insertAppointment("Jane Doe", "2023-08-02", "12:00");
    insertAppointment("Peter Pan", "2023-08-03", "14:00");

    displayAppointments();

    return 0;
}