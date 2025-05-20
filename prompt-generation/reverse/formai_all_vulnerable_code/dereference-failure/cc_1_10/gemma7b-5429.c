//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    char time[50];
    char date[50];
    struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, char* time, char* date) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->time, time);
    strcpy(newAppointment->date, date);
    newAppointment->next = NULL;
    return newAppointment;
}

void addAppointment(Appointment* head, char* name, char* time, char* date) {
    Appointment* newAppointment = createAppointment(name, time, date);
    if (head == NULL) {
        head = newAppointment;
    } else {
        newAppointment->next = head;
        head = newAppointment;
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
    addAppointment(head, "John Smith", "10:00 AM", "January 1st");
    addAppointment(head, "Mary Jones", "1:00 PM", "January 2nd");
    addAppointment(head, "Sherlock Holmes", "4:00 PM", "January 3rd");

    if (findAppointment(head, "John Smith")) {
        printf("John Smith has an appointment on January 1st at 10:00 AM.\n");
    }

    return 0;
}