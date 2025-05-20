//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[10];
    char time[10];
    struct Appointment* next;
} Appointment;

void createAppointment(Appointment** head) {
    *head = (Appointment*)malloc(sizeof(Appointment));
    (*head)->next = NULL;
    (*head)->name[0] = '\0';
    (*head)->date[0] = '\0';
    (*head)->time[0] = '\0';
}

void addAppointment(Appointment** head, char* name, char* date, char* time) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    newAppointment->next = NULL;
    newAppointment->name[0] = '\0';
    newAppointment->date[0] = '\0';
    newAppointment->time[0] = '\0';

    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);

    if (*head == NULL) {
        *head = newAppointment;
    } else {
        (*head)->next = newAppointment;
        *head = newAppointment;
    }
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
    createAppointment(&head);
    addAppointment(&head, "John Doe", "2023-08-01", "10:00");
    addAppointment(&head, "Jane Doe", "2023-08-02", "12:00");
    addAppointment(&head, "Peter Pan", "2023-08-03", "09:00");
    displayAppointments(head);

    return 0;
}