//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_Appointments 10
#define MAX_NAME_LENGTH 20

typedef struct Appointment {
    char name[MAX_NAME_LENGTH];
    char date[MAX_NAME_LENGTH];
    char time[MAX_NAME_LENGTH];
    struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, char* date, char* time) {
    Appointment* newAppointment = malloc(sizeof(Appointment));

    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    newAppointment->next = NULL;

    return newAppointment;
}

void addAppointment(Appointment* head, char* name, char* date, char* time) {
    Appointment* newAppointment = createAppointment(name, date, time);

    if (head == NULL) {
        head = newAppointment;
    } else {
        head->next = newAppointment;
    }
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

    addAppointment(head, "John Doe", "2023-01-01", "10:00");
    addAppointment(head, "Jane Doe", "2023-01-02", "12:00");
    addAppointment(head, "Peter Pan", "2023-01-03", "14:00");

    printAppointments(head);

    return 0;
}