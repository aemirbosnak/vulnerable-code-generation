//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_Appointments 10

struct Appointment {
    char name[50];
    char time[50];
    struct Appointment* next;
};

void add_appointment(struct Appointment** head) {
    struct Appointment* new_appointment = (struct Appointment*)malloc(sizeof(struct Appointment));
    new_appointment->next = NULL;

    printf("Enter your name: ");
    scanf("%s", new_appointment->name);

    printf("Enter the time of your appointment: ");
    scanf("%s", new_appointment->time);

    if (*head == NULL) {
        *head = new_appointment;
    } else {
        (*head)->next = new_appointment;
    }
}

void print_appointments(struct Appointment* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Time: %s\n", head->time);
        printf("\n");
        head = head->next;
    }
}

int main() {
    struct Appointment* head = NULL;

    // Add appointments
    add_appointment(&head);
    add_appointment(&head);
    add_appointment(&head);

    // Print appointments
    print_appointments(head);

    return 0;
}