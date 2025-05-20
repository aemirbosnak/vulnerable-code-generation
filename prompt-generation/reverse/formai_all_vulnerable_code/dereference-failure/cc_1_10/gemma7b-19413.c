//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10
#define MAX_Appointments_PER_DAY 5

typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    struct Appointment* next;
} Appointment;

void addAppointment(Appointment* head, char* name, char* date, char* time) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
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

void printAppointments(Appointment* head) {
    Appointment* temp = head;
    while (temp) {
        printf("%s, %s, %s\n", temp->name, temp->date, temp->time);
        temp = temp->next;
    }
}

int main() {
    Appointment* head = NULL;

    addAppointment(head, "John Doe", "2023-08-01", "10:00");
    addAppointment(head, "Jane Doe", "2023-08-02", "12:00");
    addAppointment(head, "Peter Pan", "2023-08-03", "14:00");

    printAppointments(head);

    return 0;
}