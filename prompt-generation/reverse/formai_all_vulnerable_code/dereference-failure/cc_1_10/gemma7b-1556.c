//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 10

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

void scheduleAppointment(Appointment* head) {
    printf("Enter your name: ");
    char name[50];
    scanf("%s", name);

    printf("Enter the date of your appointment: ");
    char date[20];
    scanf("%s", date);

    printf("Enter the time of your appointment: ");
    char time[20];
    scanf("%s", time);

    Appointment* newAppointment = createAppointment(name, date, time);
    if (head == NULL) {
        head = newAppointment;
    } else {
        head->next = newAppointment;
    }

    printf("Your appointment has been scheduled.\n");
}

void listAppointments(Appointment* head) {
    printf("List of appointments:\n");
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Date: %s\n", head->date);
        printf("Time: %s\n", head->time);
        printf("\n");
        head = head->next;
    }
}

int main() {
    time_t t;
    srand(time(&t));

    Appointment* head = NULL;
    int numAppointments = 0;

    while (numAppointments < MAX_APPOINTMENTS) {
        scheduleAppointment(head);
        numAppointments++;
    }

    listAppointments(head);

    return 0;
}