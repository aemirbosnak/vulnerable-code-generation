//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[10];
    char time[10];
    struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, char* date, char* time) {
    Appointment* newApp = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newApp->name, name);
    strcpy(newApp->date, date);
    strcpy(newApp->time, time);
    newApp->next = NULL;
    return newApp;
}

void addAppointment(Appointment* head, char* name, char* date, char* time) {
    Appointment* newApp = createAppointment(name, date, time);
    if (head == NULL) {
        head = newApp;
    } else {
        head->next = newApp;
    }
    head = newApp;
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

    // Simulate some appointments
    addAppointment(head, "John Doe", "2023-08-01", "10:00");
    addAppointment(head, "Jane Doe", "2023-08-02", "12:00");
    addAppointment(head, "Peter Pan", "2023-08-03", "14:00");

    // Print all appointments
    printAppointments(head);

    return 0;
}