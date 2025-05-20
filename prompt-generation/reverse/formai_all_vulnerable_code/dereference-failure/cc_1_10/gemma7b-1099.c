//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    int hour;
    int minute;
    struct Appointment* next;
} Appointment;

void createAppointment(Appointment** head) {
    *head = malloc(sizeof(Appointment));
    (*head)->name[0] = '\0';
    (*head)->hour = 0;
    (*head)->minute = 0;
    (*head)->next = NULL;
}

void addAppointment(Appointment* head, char* name, int hour, int minute) {
    Appointment* newAppointment = malloc(sizeof(Appointment));
    newAppointment->name[0] = '\0';
    newAppointment->hour = hour;
    newAppointment->minute = minute;
    newAppointment->next = NULL;

    if (head == NULL) {
        createAppointment(&head);
    }

    if (strcmp(newAppointment->name, head->name) == 0) {
        printf("Error: Appointment already exists.\n");
        return;
    }

    if (head->next == NULL) {
        head->next = newAppointment;
    } else {
        addAppointment(head->next, name, hour, minute);
    }
}

void listAppointments(Appointment* head) {
    while (head) {
        printf("%s (%d:%d) ", head->name, head->hour, head->minute);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Appointment* head = NULL;

    addAppointment(&head, "John Doe", 10, 30);
    addAppointment(&head, "Jane Doe", 11, 00);
    addAppointment(&head, "Peter Pan", 12, 00);
    addAppointment(&head, "Mary Poppins", 13, 00);

    listAppointments(head);

    return 0;
}