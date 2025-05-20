//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

void createAppointment(Appointment* head) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));

    printf("Enter your name: ");
    scanf("%s", newAppointment->name);

    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%s", newAppointment->date);

    printf("Enter the time (hh:mm): ");
    scanf("%s", newAppointment->time);

    newAppointment->next = NULL;

    if (head == NULL) {
        head = newAppointment;
    } else {
        head->next = newAppointment;
    }
}

void printAppointments(Appointment* head) {
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

    char choice;

    do {
        printf("Enter 'c' to create an appointment, 'p' to print appointments, or 'q' to quit: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'c':
                createAppointment(head);
                break;
            case 'p':
                printAppointments(head);
                break;
            case 'q':
                exit(0);
                break;
            default:
                printf("Invalid input.\n");
        }
    } while (choice != 'q');

    return 0;
}