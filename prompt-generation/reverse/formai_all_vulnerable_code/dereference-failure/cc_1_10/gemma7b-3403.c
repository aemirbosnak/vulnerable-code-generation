//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

struct Appointment {
    char name[50];
    char date[10];
    char time[10];
    struct Appointment* next;
};

void createAppointment(struct Appointment** head) {
    *head = malloc(sizeof(struct Appointment));
    (*head)->next = NULL;
    (*head)->name[0] = '\0';
    (*head)->date[0] = '\0';
    (*head)->time[0] = '\0';
}

void addAppointment(struct Appointment* head, char* name, char* date, char* time) {
    struct Appointment* newApp = malloc(sizeof(struct Appointment));
    newApp->next = NULL;
    strcpy(newApp->name, name);
    strcpy(newApp->date, date);
    strcpy(newApp->time, time);

    if (head == NULL) {
        head = newApp;
    } else {
        struct Appointment* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newApp;
    }
}

void printAppointments(struct Appointment* head) {
    struct Appointment* temp = head;
    while (temp) {
        printf("Name: %s\n", temp->name);
        printf("Date: %s\n", temp->date);
        printf("Time: %s\n", temp->time);
        printf("\n");
        temp = temp->next;
    }
}

int main() {
    struct Appointment* head = NULL;

    // Create and add appointments
    addAppointment(head, "John Doe", "2023-01-01", "10:00");
    addAppointment(head, "Jane Doe", "2023-01-02", "12:00");
    addAppointment(head, "Peter Pan", "2023-01-03", "14:00");

    // Print all appointments
    printAppointments(head);

    return 0;
}