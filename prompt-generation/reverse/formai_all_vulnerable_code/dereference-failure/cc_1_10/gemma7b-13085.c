//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    struct Appointment* next;
} Appointment;

void insertAppointment(Appointment* head, Appointment* newApp) {
    if (head == NULL) {
        head = newApp;
    } else {
        newApp->next = head;
        head = newApp;
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

    // Insert some appointments
    insertAppointment(head, malloc(sizeof(Appointment)));
    strcpy(head->name, "John Doe");
    strcpy(head->date, "2023-04-01");
    strcpy(head->time, "10:00");

    insertAppointment(head, malloc(sizeof(Appointment)));
    strcpy(head->name, "Jane Doe");
    strcpy(head->date, "2023-04-02");
    strcpy(head->time, "12:00");

    insertAppointment(head, malloc(sizeof(Appointment)));
    strcpy(head->name, "Peter Pan");
    strcpy(head->date, "2023-04-03");
    strcpy(head->time, "09:00");

    // Search for an appointment
    if (findAppointment(head, "John Doe")) {
        printf("John Doe's appointment is on %s at %s.\n", head->date, head->time);
    }

    // Print all appointments
    Appointment* current = head;
    while (current) {
        printf("Name: %s, Date: %s, Time: %s\n", current->name, current->date, current->time);
        current = current->next;
    }

    return 0;
}