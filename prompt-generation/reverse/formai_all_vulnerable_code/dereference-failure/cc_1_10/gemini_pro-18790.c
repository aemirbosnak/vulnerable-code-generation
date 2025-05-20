//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    char *description;
    int day;
    int month;
    int year;
    int start_time;
    int end_time;
} appointment;

typedef struct list_node {
    appointment *appointment;
    struct list_node *next;
} list_node;

list_node *head = NULL;

void add_appointment(appointment *appt) {
    list_node *new_node = malloc(sizeof(list_node));
    new_node->appointment = appt;
    new_node->next = head;
    head = new_node;
}

void print_appointments() {
    list_node *current = head;
    while (current != NULL) {
        printf("%s %d/%d/%d %d:%d-%d:%d\n",
               current->appointment->description,
               current->appointment->day,
               current->appointment->month,
               current->appointment->year,
               current->appointment->start_time,
               current->appointment->end_time);
        current = current->next;
    }
}

int main() {
    appointment *appt1 = malloc(sizeof(appointment));
    appt1->description = "Meeting with John";
    appt1->day = 1;
    appt1->month = 2;
    appt1->year = 2023;
    appt1->start_time = 900;
    appt1->end_time = 1000;

    add_appointment(appt1);

    appointment *appt2 = malloc(sizeof(appointment));
    appt2->description = "Doctor's appointment";
    appt2->day = 5;
    appt2->month = 2;
    appt2->year = 2023;
    appt2->start_time = 1100;
    appt2->end_time = 1200;

    add_appointment(appt2);

    print_appointments();

    return 0;
}