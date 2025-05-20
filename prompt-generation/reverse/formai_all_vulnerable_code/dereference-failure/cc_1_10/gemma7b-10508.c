//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

void createAppointment(Appointment* head) {
    head = (Appointment*)malloc(sizeof(Appointment));
    head->name[0] = '\0';
    head->date[0] = '\0';
    head->time[0] = '\0';
    head->next = NULL;
}

void addAppointment(Appointment* head) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    newAppointment->name[0] = '\0';
    newAppointment->date[0] = '\0';
    newAppointment->time[0] = '\0';
    newAppointment->next = NULL;

    if (head == NULL) {
        createAppointment(head);
    }

    Appointment* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newAppointment;
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
    addAppointment(head);
    addAppointment(head);
    addAppointment(head);
    displayAppointments(head);

    return 0;
}