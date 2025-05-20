//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    char *name;
    char *time;
    char *date;
    struct Appointment *next;
};

struct Appointment *head = NULL;
struct Appointment *tail = NULL;

void add_appointment(char *name, char *time, char *date) {
    struct Appointment *new_appointment = malloc(sizeof(struct Appointment));
    new_appointment->name = malloc(strlen(name) + 1);
    strcpy(new_appointment->name, name);
    new_appointment->time = malloc(strlen(time) + 1);
    strcpy(new_appointment->time, time);
    new_appointment->date = malloc(strlen(date) + 1);
    strcpy(new_appointment->date, date);
    new_appointment->next = NULL;
    if (head == NULL) {
        head = new_appointment;
        tail = new_appointment;
    } else {
        tail->next = new_appointment;
        tail = new_appointment;
    }
}

void print_appointments() {
    struct Appointment *current = head;
    while (current != NULL) {
        printf("%s %s %s\n", current->name, current->time, current->date);
        current = current->next;
    }
}

void delete_appointment(char *name) {
    struct Appointment *current = head;
    struct Appointment *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->name);
            free(current->time);
            free(current->date);
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    add_appointment("John Doe", "10:00 AM", "2023-03-08");
    add_appointment("Jane Doe", "11:00 AM", "2023-03-08");
    add_appointment("Bill Smith", "12:00 PM", "2023-03-08");
    print_appointments();
    delete_appointment("John Doe");
    print_appointments();
    return 0;
}