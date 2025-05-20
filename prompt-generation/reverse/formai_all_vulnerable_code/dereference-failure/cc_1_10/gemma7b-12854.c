//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
};

void addAppointment(struct Appointment** head) {
    struct Appointment* newAppointment = (struct Appointment*)malloc(sizeof(struct Appointment));

    printf("Enter your name: ");
    scanf("%s", newAppointment->name);

    printf("Enter the date of your appointment: ");
    scanf("%s", newAppointment->date);

    printf("Enter the time of your appointment: ");
    scanf("%s", newAppointment->time);

    newAppointment->next = NULL;

    if (*head == NULL) {
        *head = newAppointment;
    } else {
        (*head)->next = newAppointment;
    }
}

void printAppointments(struct Appointment* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Date: %s\n", head->date);
        printf("Time: %s\n", head->time);
        printf("\n");
        head = head->next;
    }
}

int main() {
    struct Appointment* head = NULL;

    printf("Welcome to the C Appointment Scheduler!\n");

    while (1) {
        printf("Enter 1 to add an appointment, 2 to print appointments, or 3 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(&head);
                break;
            case 2:
                printAppointments(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}