//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
    char *description;
    int day;
    int month;
    int year;
    int hour;
    int minute;
    struct Appointment *next;
} Appointment;

Appointment *createAppointment(char *description, int day, int month, int year, int hour, int minute) {
    Appointment *newAppointment = (Appointment *)malloc(sizeof(Appointment));
    newAppointment->description = strdup(description);
    newAppointment->day = day;
    newAppointment->month = month;
    newAppointment->year = year;
    newAppointment->hour = hour;
    newAppointment->minute = minute;
    newAppointment->next = NULL;
    return newAppointment;
}

void addAppointment(Appointment **head, Appointment *newAppointment) {
    if (*head == NULL) {
        *head = newAppointment;
    } else {
        Appointment *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newAppointment;
    }
}

void printAppointments(Appointment *head) {
    Appointment *current = head;
    while (current != NULL) {
        printf("%s %d/%d/%d %d:%d\n", current->description, current->day, current->month, current->year, current->hour, current->minute);
        current = current->next;
    }
}

int main() {
    Appointment *head = NULL;

    Appointment *newAppointment1 = createAppointment("Doctor's appointment", 15, 3, 2023, 10, 30);
    addAppointment(&head, newAppointment1);

    Appointment *newAppointment2 = createAppointment("Dentist appointment", 18, 3, 2023, 14, 0);
    addAppointment(&head, newAppointment2);

    Appointment *newAppointment3 = createAppointment("Haircut appointment", 20, 3, 2023, 16, 30);
    addAppointment(&head, newAppointment3);

    printAppointments(head);

    return 0;
}