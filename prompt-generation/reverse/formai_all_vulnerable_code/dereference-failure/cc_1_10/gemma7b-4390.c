//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
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

Appointment* createAppointment() {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    newAppointment->next = NULL;
    return newAppointment;
}

int insertAppointment(Appointment* head, char* name, char* date, char* time) {
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

    return 0;
}

void printAppointments(Appointment* head) {
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
    insertAppointment(head, "John Doe", "2023-08-01", "10:00");
    insertAppointment(head, "Jane Doe", "2023-08-02", "12:00");
    insertAppointment(head, "Peter Pan", "2023-08-03", "09:00");

    printAppointments(head);

    return 0;
}