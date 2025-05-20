//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: paranoid
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

Appointment* CreateAppointment(char* name, char* date, char* time) {
    Appointment* newAppointment = malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    newAppointment->next = NULL;
    return newAppointment;
}

int ValidateAppointment(Appointment* appointment) {
    if (strlen(appointment->name) < 1) {
        return 0;
    }
    if (strlen(appointment->date) < 1) {
        return 0;
    }
    if (strlen(appointment->time) < 1) {
        return 0;
    }
    return 1;
}

void PrintAppointments(Appointment* head) {
    while (head) {
        printf("%s, %s, %s\n", head->name, head->date, head->time);
        head = head->next;
    }
}

int main() {
    Appointment* head = NULL;

    // Paranoia mode:
    for (int i = 0; i < MAX_Appointments; i++) {
        char name[50], date[50], time[50];
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter date: ");
        scanf("%s", date);
        printf("Enter time: ");
        scanf("%s", time);

        Appointment* newAppointment = CreateAppointment(name, date, time);
        if (ValidateAppointment(newAppointment)) {
            if (head) {
                newAppointment->next = head;
            }
            head = newAppointment;
        } else {
            printf("Invalid appointment details.\n");
        }
    }

    PrintAppointments(head);

    return 0;
}