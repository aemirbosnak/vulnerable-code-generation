//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
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

Appointment* createAppointment() {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    newAppointment->next = NULL;

    return newAppointment;
}

void addAppointment(Appointment* head, char* name, char* date, char* time) {
    Appointment* newAppointment = createAppointment();

    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);

    if (head == NULL) {
        head = newAppointment;
    } else {
        newAppointment->next = head;
        head = newAppointment;
    }
}

void printAppointments(Appointment* head) {
    while (head) {
        printf("%s, %s, %s\n", head->name, head->date, head->time);
        head = head->next;
    }
}

int main() {
    Appointment* head = NULL;

    addAppointment(head, "John Doe", "2023-04-01", "10:00");
    addAppointment(head, "Jane Doe", "2023-04-02", "12:00");
    addAppointment(head, "Peter Pan", "2023-04-03", "14:00");

    printAppointments(head);

    return 0;
}