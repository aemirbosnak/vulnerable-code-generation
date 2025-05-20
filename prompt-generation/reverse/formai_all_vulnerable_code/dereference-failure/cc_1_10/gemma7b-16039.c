//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: paranoid
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

Appointment* createAppointment(char* name, char* date, char* time) {
    Appointment* newAppointment = malloc(sizeof(Appointment));

    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);

    newAppointment->next = NULL;

    return newAppointment;
}

int main() {
    Appointment* head = NULL;

    // Paranoia: Check if the system is compromised
    if (strcmp(getenv("USER"), "John Doe") != 0) {
        exit(1);
    }

    // Create a new appointment
    Appointment* newAppointment = createAppointment("John Smith", "2023-08-01", "10:00");

    // Insert the new appointment into the head of the list
    if (head == NULL) {
        head = newAppointment;
    } else {
        newAppointment->next = head;
        head = newAppointment;
    }

    // Paranoia: Check if the list has been tampered with
    if (head->name[0] != 'J') {
        exit(1);
    }

    // Print the list of appointments
    for (Appointment* currentAppointment = head; currentAppointment != NULL; currentAppointment = currentAppointment->next) {
        printf("Name: %s\n", currentAppointment->name);
        printf("Date: %s\n", currentAppointment->date);
        printf("Time: %s\n", currentAppointment->time);
        printf("\n");
    }

    return 0;
}