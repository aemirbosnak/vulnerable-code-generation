//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
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

Appointment* createAppointment(char* name, char* date, char* time) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
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
        newAppointment->next = head;
        head = newAppointment;
    }
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
    addAppointment(head, "John Doe", "2023-08-08", "10:00");
    addAppointment(head, "Jane Doe", "2023-08-09", "12:00");
    addAppointment(head, "Peter Pan", "2023-08-10", "09:00");

    printAppointments(head);

    return 0;
}