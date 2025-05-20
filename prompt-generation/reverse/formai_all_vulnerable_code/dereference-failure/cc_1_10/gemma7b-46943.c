//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    int day;
    int month;
    int year;
    struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, int day, int month, int year) {
    Appointment* newAppt = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppt->name, name);
    newAppt->day = day;
    newAppt->month = month;
    newAppt->year = year;
    newAppt->next = NULL;
    return newAppt;
}

void addAppointment(Appointment* head, char* name, int day, int month, int year) {
    Appointment* newAppt = createAppointment(name, day, month, year);
    if (head == NULL) {
        head = newAppt;
    } else {
        head->next = newAppt;
    }
}

int findAppointment(Appointment* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            return 1;
        } else {
            head = head->next;
        }
    }
    return 0;
}

int main() {
    Appointment* head = NULL;
    addAppointment(head, "John Doe", 10, 1, 2023);
    addAppointment(head, "Jane Doe", 12, 2, 2023);
    addAppointment(head, "Bill Smith", 14, 3, 2023);

    if (findAppointment(head, "John Doe")) {
        printf("John Doe's appointment is found.\n");
    }

    return 0;
}