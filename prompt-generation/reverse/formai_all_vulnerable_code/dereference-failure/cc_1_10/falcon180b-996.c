//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct appointment {
    char *name;
    char *date;
    char *time;
    struct appointment *next;
};

void add_appointment(struct appointment **head, char *name, char *date, char *time) {
    struct appointment *new_appointment = (struct appointment *)malloc(sizeof(struct appointment));
    new_appointment->name = name;
    new_appointment->date = date;
    new_appointment->time = time;
    new_appointment->next = NULL;

    if (*head == NULL) {
        *head = new_appointment;
    } else {
        struct appointment *current_appointment = *head;
        while (current_appointment->next!= NULL) {
            current_appointment = current_appointment->next;
        }
        current_appointment->next = new_appointment;
    }
}

void delete_appointment(struct appointment **head, char *name) {
    struct appointment *current_appointment = *head;
    struct appointment *previous_appointment = NULL;

    while (current_appointment!= NULL) {
        if (strcmp(current_appointment->name, name) == 0) {
            if (previous_appointment == NULL) {
                *head = current_appointment->next;
            } else {
                previous_appointment->next = current_appointment->next;
            }
            free(current_appointment->name);
            free(current_appointment->date);
            free(current_appointment->time);
            free(current_appointment);
            return;
        }
        previous_appointment = current_appointment;
        current_appointment = current_appointment->next;
    }
}

void print_appointments(struct appointment *head) {
    while (head!= NULL) {
        printf("Name: %s\nDate: %s\nTime: %s\n", head->name, head->date, head->time);
        head = head->next;
    }
}

int main() {
    struct appointment *head = NULL;

    add_appointment(&head, "John Doe", "2022-01-01", "10:00");
    add_appointment(&head, "Jane Doe", "2022-01-02", "15:30");
    add_appointment(&head, "Jim Smith", "2022-01-03", "09:00");

    print_appointments(head);

    delete_appointment(&head, "Jane Doe");

    print_appointments(head);

    return 0;
}