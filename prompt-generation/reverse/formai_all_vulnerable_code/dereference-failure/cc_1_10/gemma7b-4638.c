//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

Appointment* insertAppointment(Appointment* head, char* name, char* date, char* time) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    newAppointment->name[0] = '\0';
    newAppointment->date[0] = '\0';
    newAppointment->time[0] = '\0';
    newAppointment->next = NULL;

    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);

    if (head == NULL) {
        head = newAppointment;
    } else {
        head->next = newAppointment;
    }

    return head;
}

void printAppointments(Appointment* head) {
    Appointment* current = head;
    while (current) {
        printf("Name: %s, Date: %s, Time: %s\n", current->name, current->date, current->time);
        current = current->next;
    }
}

int main() {
    Appointment* head = NULL;

    insertAppointment(head, "John Doe", "2023-08-01", "10:00");
    insertAppointment(head, "Jane Doe", "2023-08-02", "12:00");
    insertAppointment(head, "Bill Smith", "2023-08-03", "14:00");

    printAppointments(head);

    return 0;
}