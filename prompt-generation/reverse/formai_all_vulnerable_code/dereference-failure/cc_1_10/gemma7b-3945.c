//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    int hour;
    int minute;
    struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, int hour, int minute) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    newAppointment->hour = hour;
    newAppointment->minute = minute;
    newAppointment->next = NULL;
    return newAppointment;
}

void addAppointment(Appointment* head, char* name, int hour, int minute) {
    Appointment* newAppointment = createAppointment(name, hour, minute);
    if (head == NULL) {
        head = newAppointment;
    } else {
        head->next = newAppointment;
    }
}

int findAppointment(Appointment* head, char* name) {
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
    addAppointment(head, "John Doe", 10, 30);
    addAppointment(head, "Jane Doe", 12, 00);
    addAppointment(head, "Peter Pan", 14, 00);

    if (findAppointment(head, "John Doe")) {
        printf("John Doe's appointment is found.\n");
    }

    return 0;
}