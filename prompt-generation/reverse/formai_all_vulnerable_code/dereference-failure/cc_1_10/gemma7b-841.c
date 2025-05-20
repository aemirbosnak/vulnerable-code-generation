//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10

struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
};

void create_appointment(struct Appointment** head) {
    *head = (struct Appointment*)malloc(sizeof(struct Appointment));
    (*head)->next = NULL;
    (*head)->name[0] = '\0';
    (*head)->date[0] = '\0';
    (*head)->time[0] = '\0';
}

void add_appointment(struct Appointment** head, char* name, char* date, char* time) {
    struct Appointment* new_appointment = (struct Appointment*)malloc(sizeof(struct Appointment));
    new_appointment->next = NULL;
    new_appointment->name[0] = '\0';
    new_appointment->date[0] = '\0';
    new_appointment->time[0] = '\0';

    strcpy(new_appointment->name, name);
    strcpy(new_appointment->date, date);
    strcpy(new_appointment->time, time);

    if (*head == NULL) {
        *head = new_appointment;
    } else {
        (*head)->next = new_appointment;
    }
}

void print_appointments(struct Appointment* head) {
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
    add_appointment(&head, "John Doe", "2023-04-08", "10:00");
    add_appointment(&head, "Jane Doe", "2023-04-09", "12:00");
    add_appointment(&head, "Peter Pan", "2023-04-10", "14:00");

    print_appointments(head);

    return 0;
}