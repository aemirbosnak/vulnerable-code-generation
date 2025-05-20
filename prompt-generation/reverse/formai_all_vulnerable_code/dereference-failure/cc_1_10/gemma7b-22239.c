//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

void insertAppointment(Appointment** head, char* name, char* date, char* time) {
    Appointment* newApp = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newApp->name, name);
    strcpy(newApp->date, date);
    strcpy(newApp->time, time);
    newApp->next = NULL;

    if (*head == NULL) {
        *head = newApp;
    } else {
        (*head)->next = newApp;
    }
}

int searchAppointment(Appointment* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main() {
    Appointment* head = NULL;

    insertAppointment(&head, "John Doe", "2023-08-01", "10:00");
    insertAppointment(&head, "Jane Doe", "2023-08-02", "12:00");
    insertAppointment(&head, "Peter Pan", "2023-08-03", "14:00");

    if (searchAppointment(head, "John Doe")) {
        printf("John Doe's appointment is on %s at %s", head->date, head->time);
    } else {
        printf("John Doe's appointment not found");
    }

    return 0;
}