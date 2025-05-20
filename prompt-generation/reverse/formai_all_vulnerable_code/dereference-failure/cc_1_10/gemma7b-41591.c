//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10
#define MAX_NAME_LENGTH 20

typedef struct Appointment {
    char name[MAX_NAME_LENGTH];
    char time[MAX_NAME_LENGTH];
    struct Appointment* next;
} Appointment;

void createAppointment(Appointment** head) {
    *head = (Appointment*)malloc(sizeof(Appointment));
    (*head)->next = NULL;
    return;
}

void addAppointment(Appointment* head, char* name, char* time) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->time, time);
    newAppointment->next = NULL;

    if (head == NULL) {
        head = newAppointment;
    } else {
        head->next = newAppointment;
    }
    head = newAppointment;
}

void displayAppointments(Appointment* head) {
    while (head) {
        printf("%s - %s\n", head->name, head->time);
        head = head->next;
    }
}

int main() {
    Appointment* head = NULL;

    // Multiplayer code
    char name[MAX_NAME_LENGTH];
    char time[MAX_NAME_LENGTH];

    // Create a new appointment
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter the time of your appointment: ");
    scanf("%s", time);
    addAppointment(head, name, time);

    // Display all appointments
    displayAppointments(head);

    return 0;
}