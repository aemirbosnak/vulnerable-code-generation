//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

struct Appointment {
    char name[50];
    char time[50];
    char date[50];
    struct Appointment* next;
};

struct Appointment* head = NULL;

void insertAppointment(char* name, char* time, char* date) {
    struct Appointment* newApp = malloc(sizeof(struct Appointment));
    strcpy(newApp->name, name);
    strcpy(newApp->time, time);
    strcpy(newApp->date, date);
    newApp->next = NULL;

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

void printAppointments() {
    struct Appointment* temp = head;
    while (temp) {
        printf("%s, %s, %s\n", temp->name, temp->time, temp->date);
        temp = temp->next;
    }
}

int main() {
    insertAppointment("John Doe", "10:00", "2023-03-01");
    insertAppointment("Jane Doe", "12:00", "2023-03-02");
    insertAppointment("Mike Smith", "14:00", "2023-03-03");

    printAppointments();

    return 0;
}