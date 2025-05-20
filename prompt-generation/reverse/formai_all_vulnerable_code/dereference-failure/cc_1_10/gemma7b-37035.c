//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    struct Appointment* next;
};

struct Appointment* insertAppointment(struct Appointment* head, char* name, char* date, char* time) {
    struct Appointment* newApp = (struct Appointment*)malloc(sizeof(struct Appointment));
    strcpy(newApp->name, name);
    strcpy(newApp->date, date);
    strcpy(newApp->time, time);
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

    return head;
}

struct Appointment* findAppointment(struct Appointment* head, char* name) {
    struct Appointment* temp = head;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

int main() {
    struct Appointment* head = NULL;

    insertAppointment(head, "John Doe", "2023-04-01", "10:00");
    insertAppointment(head, "Jane Doe", "2023-04-02", "12:00");
    insertAppointment(head, "Bill Smith", "2023-04-03", "14:00");

    struct Appointment* foundApp = findAppointment(head, "Jane Doe");

    if (foundApp) {
        printf("Name: %s\n", foundApp->name);
        printf("Date: %s\n", foundApp->date);
        printf("Time: %s\n", foundApp->time);
    } else {
        printf("Appointment not found.\n");
    }

    return 0;
}