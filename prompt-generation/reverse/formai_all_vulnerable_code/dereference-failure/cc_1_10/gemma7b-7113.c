//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: modular
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

void addAppointment(Appointment* head) {
    Appointment* newApp = malloc(sizeof(Appointment));
    newApp->next = NULL;

    printf("Enter your name: ");
    scanf("%s", newApp->name);

    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%s", newApp->date);

    printf("Enter the time (hh:mm): ");
    scanf("%s", newApp->time);

    if (head == NULL) {
        head = newApp;
    } else {
        newApp->next = head;
        head = newApp;
    }
}

void displayAppointments(Appointment* head) {
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

    while (1) {
        printf("Enter 'a' to add an appointment, 'd' to display appointments, or 'q' to quit: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'a':
                addAppointment(head);
                break;
            case 'd':
                displayAppointments(head);
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}