//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
    char *name;
    char *time;
    char *date;
    struct Appointment *next;
} Appointment;

Appointment *head = NULL;

void addAppointment(char *name, char *time, char *date) {
    Appointment *newAppointment = malloc(sizeof(Appointment));
    newAppointment->name = strdup(name);
    newAppointment->time = strdup(time);
    newAppointment->date = strdup(date);
    newAppointment->next = NULL;

    if (head == NULL) {
        head = newAppointment;
    } else {
        Appointment *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newAppointment;
    }
}

void printAppointments() {
    Appointment *current = head;
    while (current != NULL) {
        printf("%s %s %s\n", current->name, current->time, current->date);
        current = current->next;
    }
}

void deleteAppointment(char *name) {
    Appointment *current = head;
    Appointment *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->name);
            free(current->time);
            free(current->date);
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    addAppointment("John Doe", "10:00 AM", "2023-03-08");
    addAppointment("Jane Doe", "11:00 AM", "2023-03-08");
    addAppointment("Bob Smith", "12:00 PM", "2023-03-08");

    printAppointments();

    deleteAppointment("John Doe");

    printAppointments();

    return 0;
}