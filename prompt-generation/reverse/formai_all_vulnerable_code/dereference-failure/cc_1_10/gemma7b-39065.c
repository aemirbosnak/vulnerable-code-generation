//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[10];
    char time[10];
    struct Appointment* next;
} Appointment;

void scheduleAppointment(Appointment* head) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    printf("Enter your name: ");
    scanf("%s", newAppointment->name);
    printf("Enter the date of your appointment: ");
    scanf("%s", newAppointment->date);
    printf("Enter the time of your appointment: ");
    scanf("%s", newAppointment->time);

    newAppointment->next = head;
    head = newAppointment;
}

void displayAppointments(Appointment* head) {
    printf("Your appointments:\n");
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Date: %s\n", head->date);
        printf("Time: %s\n", head->time);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Appointment* head = NULL;
    int choice;

    printf("Welcome to the Galactic Appointment Scheduler!\n");

    while (1) {
        printf("Enter 1 to schedule an appointment, 2 to display your appointments, or 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scheduleAppointment(head);
                break;
            case 2:
                displayAppointments(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}