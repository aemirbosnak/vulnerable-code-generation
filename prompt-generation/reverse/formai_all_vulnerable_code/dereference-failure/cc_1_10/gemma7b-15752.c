//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, char* date, char* time) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    newAppointment->next = NULL;
    return newAppointment;
}

void displayAppointments(Appointment* appointments) {
    while (appointments) {
        printf("Name: %s\n", appointments->name);
        printf("Date: %s\n", appointments->date);
        printf("Time: %s\n", appointments->time);
        printf("\n");
        appointments = appointments->next;
    }
}

int main() {
    Appointment* appointments = NULL;
    char* name;
    char* date;
    char* time;

    printf("Enter the name of the appointment:");
    scanf("%s", name);

    printf("Enter the date of the appointment:");
    scanf("%s", date);

    printf("Enter the time of the appointment:");
    scanf("%s", time);

    appointments = createAppointment(name, date, time);

    displayAppointments(appointments);

    return 0;
}