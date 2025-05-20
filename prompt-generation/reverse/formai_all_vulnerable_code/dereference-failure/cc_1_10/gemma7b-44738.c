//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void displayAppointments(Appointment* head) {
    while (head) {
        printf("%s, %s, %s\n", head->name, head->date, head->time);
        head = head->next;
    }
}

int main() {
    Appointment* head = NULL;
    char name[50], date[50], time[50];

    // Create and add appointments
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter date: ");
    scanf("%s", date);
    printf("Enter time: ");
    scanf("%s", time);
    head = createAppointment(name, date, time);

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter date: ");
    scanf("%s", date);
    printf("Enter time: ");
    scanf("%s", time);
    createAppointment(name, date, time);

    // Display appointments
    displayAppointments(head);

    return 0;
}