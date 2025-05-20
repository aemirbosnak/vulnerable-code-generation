//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, char* date, char* time) {
    Appointment* newAppt = malloc(sizeof(Appointment));
    strcpy(newAppt->name, name);
    strcpy(newAppt->date, date);
    strcpy(newAppt->time, time);
    newAppt->next = NULL;
    return newAppt;
}

void displayAppointments(Appointment* appt) {
    while (appt) {
        printf("%s - %s - %s\n", appt->name, appt->date, appt->time);
        appt = appt->next;
    }
}

int main() {
    time_t t = time(NULL);
    srand(t);

    Appointment* head = NULL;

    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        char* name = "John Doe"; // Replace with actual name
        char* date = "2023-08-01"; // Replace with actual date
        char* time = "10:00 AM"; // Replace with actual time

        Appointment* newAppt = createAppointment(name, date, time);
        if (head == NULL) {
            head = newAppt;
        } else {
            newAppt->next = head;
            head = newAppt;
        }
    }

    displayAppointments(head);

    return 0;
}