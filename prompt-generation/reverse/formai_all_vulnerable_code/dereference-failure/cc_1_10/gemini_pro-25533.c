//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Appointment {
    char *name;
    char *date;
    char *time;
    struct Appointment *next;
};

struct Appointment *head = NULL;

void add_appointment(char *name, char *date, char *time) {
    struct Appointment *new_appointment = malloc(sizeof(struct Appointment));
    new_appointment->name = strdup(name);
    new_appointment->date = strdup(date);
    new_appointment->time = strdup(time);
    new_appointment->next = NULL;

    if (head == NULL) {
        head = new_appointment;
    } else {
        struct Appointment *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_appointment;
    }
}

void print_appointments() {
    struct Appointment *current = head;
    while (current != NULL) {
        printf("%s %s %s\n", current->name, current->date, current->time);
        current = current->next;
    }
}

void delete_appointment(char *name) {
    struct Appointment *current = head;
    struct Appointment *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->name);
            free(current->date);
            free(current->time);
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    add_appointment("John", "2023-03-08", "10:00");
    add_appointment("Mary", "2023-03-15", "11:00");
    add_appointment("Bob", "2023-03-22", "12:00");

    print_appointments();

    delete_appointment("John");

    printf("\n");

    print_appointments();

    return 0;
}