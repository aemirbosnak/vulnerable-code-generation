//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

Appointment* head = NULL;

void scheduleAppointment(char* name, char* date, char* time) {
    Appointment* newAppt = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppt->name, name);
    strcpy(newAppt->date, date);
    strcpy(newAppt->time, time);
    newAppt->next = NULL;

    if (head == NULL) {
        head = newAppt;
    } else {
        Appointment* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newAppt;
    }
}

void printAppointments() {
    Appointment* temp = head;
    while (temp) {
        printf("%s, %s, %s\n", temp->name, temp->date, temp->time);
        temp = temp->next;
    }
}

int main() {
    scheduleAppointment("John Doe", "2023-08-01", "10:00");
    scheduleAppointment("Jane Doe", "2023-08-02", "12:00");
    scheduleAppointment("Peter Pan", "2023-08-03", "14:00");

    printAppointments();

    return 0;
}