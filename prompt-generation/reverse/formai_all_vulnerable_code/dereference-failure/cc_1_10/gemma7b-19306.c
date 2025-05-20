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

int main() {
    time_t t;
    srand(time(&t));

    Appointment* head = NULL;

    // Simulate some random appointments
    for (int i = 0; i < MAX_Appointments; i++) {
        addAppointment(head, "John Doe", "2023-08-01", "10:00");
        addAppointment(head, "Jane Doe", "2023-08-02", "12:00");
        addAppointment(head, "Bill Smith", "2023-08-03", "14:00");
    }

    // Print the appointments
    for (Appointment* current = head; current; current = current->next) {
        printf("Name: %s, Date: %s, Time: %s\n", current->name, current->date, current->time);
    }

    return 0;
}