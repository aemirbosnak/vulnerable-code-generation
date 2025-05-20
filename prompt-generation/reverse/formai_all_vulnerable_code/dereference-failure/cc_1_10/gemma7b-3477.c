//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Appointments 10
#define MAX_TIME_SLOTS 24

typedef struct Appointment {
    char name[50];
    char timeSlot[2];
    struct Appointment* next;
} Appointment;

void createAppointment(Appointment** head) {
    *head = (Appointment*)malloc(sizeof(Appointment));
    (*head)->next = NULL;
    (*head)->name[0] = '\0';
    (*head)->timeSlot[0] = '\0';
}

void addAppointment(Appointment* head, char* name, char* timeSlot) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    newAppointment->next = NULL;
    newAppointment->name[0] = '\0';
    newAppointment->timeSlot[0] = '\0';

    strcpy(newAppointment->name, name);
    strcpy(newAppointment->timeSlot, timeSlot);

    if (head == NULL) {
        head = newAppointment;
    } else {
        head->next = newAppointment;
    }
}

void printAppointments(Appointment* head) {
    while (head) {
        printf("%s - %s\n", head->name, head->timeSlot);
        head = head->next;
    }
}

int main() {
    Appointment* head = NULL;

    createAppointment(&head);
    addAppointment(head, "John Doe", "10:00");
    addAppointment(head, "Jane Doe", "12:00");
    addAppointment(head, "Bill Smith", "14:00");

    printAppointments(head);

    return 0;
}