//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    char name[20];
    char date[20];
    char time[20];
    struct Appointment* next;
};

struct Appointment* head = NULL;

void addAppointment(char* name, char* date, char* time) {
    struct Appointment* newAppt = (struct Appointment*)malloc(sizeof(struct Appointment));
    strcpy(newAppt->name, name);
    strcpy(newAppt->date, date);
    strcpy(newAppt->time, time);
    newAppt->next = NULL;

    if (head == NULL) {
        head = newAppt;
    } else {
        struct Appointment* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newAppt;
    }
}

void printAppointments() {
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
    addAppointment("John Doe", "2023-08-01", "10:00");
    addAppointment("Jane Doe", "2023-08-02", "12:00");
    addAppointment("Peter Pan", "2023-08-03", "09:00");

    printAppointments();

    return 0;
}