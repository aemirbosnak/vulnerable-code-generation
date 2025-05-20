//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10
#define MAX_Appointments_PER_DAY 5

typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
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

void addAppointment(Appointment* head, char* name, char* date, char* time) {
    Appointment* newAppointment = createAppointment(name, date, time);
    if (head == NULL) {
        head = newAppointment;
    } else {
        head->next = newAppointment;
    }
    head = newAppointment;
}

int getAvailableAppointments(Appointment* head, char* date) {
    int availableAppointments = 0;
    Appointment* currentAppointment = head;
    while (currentAppointment) {
        if (strcmp(currentAppointment->date, date) == 0) {
            availableAppointments++;
        }
        currentAppointment = currentAppointment->next;
    }
    return availableAppointments;
}

int main() {
    Appointment* head = NULL;
    addAppointment(head, "John Doe", "2023-08-01", "10:00");
    addAppointment(head, "Jane Doe", "2023-08-01", "12:00");
    addAppointment(head, "Peter Pan", "2023-08-02", "09:00");
    addAppointment(head, "Mary Poppins", "2023-08-02", "11:00");

    int availableAppointments = getAvailableAppointments(head, "2023-08-01");
    printf("Available appointments for 2023-08-01: %d\n", availableAppointments);

    availableAppointments = getAvailableAppointments(head, "2023-08-02");
    printf("Available appointments for 2023-08-02: %d\n", availableAppointments);

    return 0;
}