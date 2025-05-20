//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct appointment {
    char *subject;
    char *description;
    time_t start_time;
    time_t end_time;
} appointment;

typedef struct node {
    appointment *appt;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;

void add_appointment(appointment *appt) {
    node *new_node = malloc(sizeof(node));
    new_node->appt = appt;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void print_appointments() {
    node *current = head;
    while (current != NULL) {
        printf("Subject: %s\n", current->appt->subject);
        printf("Description: %s\n", current->appt->description);
        printf("Start time: %s\n", ctime(&current->appt->start_time));
        printf("End time: %s\n\n", ctime(&current->appt->end_time));
        current = current->next;
    }
}

void delete_appointment(appointment *appt) {
    node *current = head;
    node *previous = NULL;

    while (current != NULL) {
        if (current->appt == appt) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->appt);
            free(current);
            break;
        }

        previous = current;
        current = current->next;
    }
}

int main() {
    appointment *app1 = malloc(sizeof(appointment));
    app1->subject = "Meeting with client";
    app1->description = "Discuss new project";
    app1->start_time = time(NULL) + 3600; // 1 hour from now
    app1->end_time = time(NULL) + 7200; // 2 hours from now

    add_appointment(app1);

    appointment *app2 = malloc(sizeof(appointment));
    app2->subject = "Doctor's appointment";
    app2->description = "Annual checkup";
    app2->start_time = time(NULL) + 86400; // 1 day from now
    app2->end_time = time(NULL) + 90000; // 1 day and 1 hour from now

    add_appointment(app2);

    print_appointments();

    delete_appointment(app1);

    print_appointments();

    return 0;
}