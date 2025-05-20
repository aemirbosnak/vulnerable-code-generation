//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
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

void createAppointment(Appointment* head) {
    head = (Appointment*)malloc(sizeof(Appointment));
    head->next = NULL;
    return;
}

void addAppointment(Appointment* head, char* name, char* date, char* time) {
    Appointment* newAppt = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppt->name, name);
    strcpy(newAppt->date, date);
    strcpy(newAppt->time, time);
    newAppt->next = NULL;

    if (head == NULL) {
        head = newAppt;
    } else {
        head->next = newAppt;
    }
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
    createAppointment(head);

    addAppointment(head, "John Doe", "2023-06-01", "10:00");
    addAppointment(head, "Jane Doe", "2023-06-02", "12:00");
    addAppointment(head, "Peter Pan", "2023-06-03", "14:00");

    printAppointments(head);

    return 0;
}