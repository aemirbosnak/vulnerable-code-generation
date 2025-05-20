//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    char *name;
    char *date;
    char *time;
    struct appointment *next;
} appointment;

appointment *head = NULL;

void add_appointment(char *name, char *date, char *time) {
    appointment *new_appointment = (appointment *)malloc(sizeof(appointment));
    new_appointment->name = (char *)malloc(strlen(name) + 1);
    strcpy(new_appointment->name, name);
    new_appointment->date = (char *)malloc(strlen(date) + 1);
    strcpy(new_appointment->date, date);
    new_appointment->time = (char *)malloc(strlen(time) + 1);
    strcpy(new_appointment->time, time);
    new_appointment->next = NULL;

    if (head == NULL) {
        head = new_appointment;
    } else {
        appointment *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_appointment;
    }
}

void print_appointments() {
    appointment *current = head;
    while (current != NULL) {
        printf("%s %s %s\n", current->name, current->date, current->time);
        current = current->next;
    }
}

int main() {
    add_appointment("John Doe", "2023-03-08", "10:00 AM");
    add_appointment("Jane Doe", "2023-03-09", "11:00 AM");
    add_appointment("Bill Smith", "2023-03-10", "12:00 PM");

    print_appointments();

    return 0;
}