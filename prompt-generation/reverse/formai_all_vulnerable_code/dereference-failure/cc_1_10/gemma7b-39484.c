//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_Appointments 10

struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
};

void addAppointment(struct Appointment** head) {
    struct Appointment* newApp = (struct Appointment*)malloc(sizeof(struct Appointment));
    printf("Enter your name: ");
    scanf("%s", newApp->name);
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%s", newApp->date);
    printf("Enter the time (hh:mm): ");
    scanf("%s", newApp->time);
    newApp->next = NULL;

    if (*head == NULL) {
        *head = newApp;
    } else {
        (*head)->next = newApp;
    }
}

void displayAppointments(struct Appointment* head) {
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

    while (1) {
        int choice;
        printf("1. Add Appointment\n");
        printf("2. Display Appointments\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAppointment(&head);
                break;
            case 2:
                displayAppointments(head);
                break;
            default:
                exit(1);
        }
    }

    return 0;
}