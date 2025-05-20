//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 20

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

void insertAppointment(Appointment* head, char* name, char* date, char* time) {
    Appointment* newAppt = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppt->name, name);
    strcpy(newAppt->date, date);
    strcpy(newAppt->time, time);
    newAppt->next = NULL;

    if (head == NULL) {
        head = newAppt;
    } else {
        newAppt->next = head;
        head = newAppt;
    }
}

int searchAppointments(Appointment* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main() {
    Appointment* head = NULL;

    insertAppointment(head, "John Doe", "2023-06-01", "10:00");
    insertAppointment(head, "Jane Doe", "2023-06-02", "12:00");
    insertAppointment(head, "Peter Pan", "2023-06-03", "14:00");

    if (searchAppointments(head, "John Doe") == 1) {
        printf("John Doe's appointment is on 2023-06-01 at 10:00\n");
    }

    return 0;
}