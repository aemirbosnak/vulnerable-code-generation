//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char time[50];
    struct Appointment* next;
} Appointment;

Appointment* head = NULL;

void scheduleAppointment(char* name, char* time) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->time, time);
    newAppointment->next = NULL;

    if (head == NULL) {
        head = newAppointment;
    } else {
        Appointment* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newAppointment;
    }
}

int checkAppointment(char* name) {
    Appointment* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    scheduleAppointment("John Doe", "10:00");
    scheduleAppointment("Jane Doe", "12:00");
    scheduleAppointment("Jack Doe", "14:00");
    scheduleAppointment("Jill Doe", "16:00");

    if (checkAppointment("Jane Doe")) {
        printf("Jane Doe's appointment is scheduled for 12:00\n");
    }

    if (checkAppointment("John Doe")) {
        printf("John Doe's appointment is scheduled for 10:00\n");
    }

    return 0;
}