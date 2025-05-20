//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 50

typedef struct Appointment {
    int id;
    char description[MAX_APPOINTMENT_LENGTH];
    struct Appointment *next;
} Appointment;

Appointment *head = NULL;

void createAppointment(int id, char *description) {
    Appointment *newAppointment = (Appointment *) malloc(sizeof(Appointment));
    newAppointment->id = id;
    strcpy(newAppointment->description, description);
    newAppointment->next = head;
    head = newAppointment;
}

void printAppointments() {
    Appointment *current = head;
    int i = 0;
    printf("\nAppointments:\n");
    while (current != NULL) {
        printf("%d. %s\n", current->id, current->description);
        current = current->next;
        i++;
    }
}

int main() {
    int choice, id, i;
    char description[MAX_APPOINTMENT_LENGTH];

    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Create new appointment\n");
        printf("2. Print all appointments\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter appointment ID: ");
                scanf("%d", &id);
                printf("Enter appointment description: ");
                scanf("%s", description);
                createAppointment(id, description);
                break;
            case 2:
                printAppointments();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    while (head != NULL) {
        Appointment *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}