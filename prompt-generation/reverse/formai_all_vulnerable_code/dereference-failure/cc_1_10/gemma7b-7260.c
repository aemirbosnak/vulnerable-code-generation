//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

void createAppointment(Appointment* head) {
    Appointment* newAppt = malloc(sizeof(Appointment));
    head = newAppt;
    printf("Enter your name: ");
    scanf("%s", newAppt->name);
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%s", newAppt->date);
    printf("Enter the time (hh:mm): ");
    scanf("%s", newAppt->time);
    newAppt->next = NULL;
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
    int choice;

    do {
        printf("Welcome to the Retro Appointment Scheduler!\n");
        printf("1. Create New Appointment\n");
        printf("2. Print Appointments\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAppointment(head);
                break;
            case 2:
                printAppointments(head);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}