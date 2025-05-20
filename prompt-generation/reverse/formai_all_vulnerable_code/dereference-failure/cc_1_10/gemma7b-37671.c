//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: decentralized
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

Appointment* head = NULL;

void addAppointment(char* name, char* date, char* time) {
    Appointment* newApp = malloc(sizeof(Appointment));
    strcpy(newApp->name, name);
    strcpy(newApp->date, date);
    strcpy(newApp->time, time);
    newApp->next = NULL;

    if (head == NULL) {
        head = newApp;
    } else {
        Appointment* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newApp;
    }
}

int findAppointment(char* name) {
    Appointment* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    addAppointment("John Doe", "2023-08-01", "10:00");
    addAppointment("Jane Doe", "2023-08-02", "12:00");
    addAppointment("Peter Pan", "2023-08-03", "14:00");

    if (findAppointment("John Doe")) {
        printf("Appointment found for John Doe.\n");
    } else {
        printf("Appointment not found for John Doe.\n");
    }

    return 0;
}