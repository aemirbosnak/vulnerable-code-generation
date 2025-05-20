//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
    int id;
    char description[50];
    struct Appointment *next;
    struct Appointment *prev;
    int start_time;
    int end_time;
} Appointment;

Appointment *head = NULL;
Appointment *tail = NULL;

void addAppointment(int id, char *description, int start_time, int end_time) {
    Appointment *newAppointment = (Appointment *)malloc(sizeof(Appointment));

    strcpy(newAppointment->description, description);
    newAppointment->id = id;
    newAppointment->start_time = start_time;
    newAppointment->end_time = end_time;
    newAppointment->next = NULL;
    newAppointment->prev = NULL;

    if (head == NULL) {
        head = newAppointment;
        tail = newAppointment;
    } else {
        tail->next = newAppointment;
        newAppointment->prev = tail;
        tail = newAppointment;
    }
}

void deleteAppointment(int id) {
    Appointment *current = head;
    Appointment *previous = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = previous;
            } else {
                tail = previous;
            }

            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void viewAppointments() {
    Appointment *current = head;

    printf("ID\tDescription\tStart Time\tEnd Time\n");

    while (current != NULL) {
        printf("%d\t%s\t%d\t%d\n", current->id, current->description, current->start_time, current->end_time);
        current = current->next;
    }
}

int main() {
    addAppointment(1, "Doctor's Appointment", 10, 12);
    addAppointment(2, "Meeting with team", 14, 16);
    addAppointment(3, "Lunch break", 12, 14);

    viewAppointments();

    deleteAppointment(2);

    viewAppointments();

    return 0;
}