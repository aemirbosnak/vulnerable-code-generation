//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    int day;
    int month;
    int year;
    struct Appointment* next;
} Appointment;

Appointment* head = NULL;

void insertAppointment(char* name, int day, int month, int year) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    newAppointment->day = day;
    newAppointment->month = month;
    newAppointment->year = year;
    newAppointment->next = NULL;

    if (head == NULL) {
        head = newAppointment;
    } else {
        Appointment* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newAppointment;
    }
}

int searchAppointment(char* name) {
    Appointment* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    insertAppointment("John Doe", 10, 1, 2023);
    insertAppointment("Jane Doe", 15, 2, 2023);
    insertAppointment("Mike Smith", 20, 3, 2023);

    if (searchAppointment("John Doe")) {
        printf("John Doe's appointment is on January 10, 2023.\n");
    }

    return 0;
}