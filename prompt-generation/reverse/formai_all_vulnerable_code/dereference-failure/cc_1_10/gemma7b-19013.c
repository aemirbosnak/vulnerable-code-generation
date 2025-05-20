//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    struct Appointment* next;
} Appointment;

void createAppointment(Appointment** head) {
    *head = malloc(sizeof(Appointment));
    (*head)->next = NULL;
    (*head)->name[0] = '\0';
    (*head)->date[0] = '\0';
    (*head)->time[0] = '\0';
}

void addAppointment(Appointment** head, char* name, char* date, char* time) {
    Appointment* newAppointment = malloc(sizeof(Appointment));
    newAppointment->next = NULL;
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);

    if (*head == NULL) {
        *head = newAppointment;
    } else {
        (*head)->next = newAppointment;
        *head = newAppointment;
    }
}

void printAppointments(Appointment* head) {
    while (head) {
        printf("%s, %s, %s\n", head->name, head->date, head->time);
        head = head->next;
    }
}

int main() {
    Appointment* head = NULL;

    createAppointment(&head);
    addAppointment(&head, "John Doe", "2023-08-08", "10:00");
    addAppointment(&head, "Jane Doe", "2023-08-09", "12:00");
    addAppointment(&head, "Peter Pan", "2023-08-10", "14:00");

    printAppointments(head);

    return 0;
}