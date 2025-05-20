//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    char *start_time;
    char *end_time;
    char *description;
} appointment;

typedef struct appointment_list {
    appointment *appointment;
    struct appointment_list *next;
} appointment_list;

void add_appointment(appointment_list **head, appointment *new_appointment) {
    appointment_list *new_node = malloc(sizeof(appointment_list));
    new_node->appointment = new_appointment;
    new_node->next = *head;
    *head = new_node;
}

void print_appointment_list(appointment_list *head) {
    while (head != NULL) {
        printf("%s - %s: %s\n", head->appointment->start_time, head->appointment->end_time, head->appointment->description);
        head = head->next;
    }
}

void free_appointment_list(appointment_list *head) {
    while (head != NULL) {
        appointment_list *next = head->next;
        free(head->appointment->start_time);
        free(head->appointment->end_time);
        free(head->appointment->description);
        free(head->appointment);
        free(head);
        head = next;
    }
}

int main() {
    appointment_list *head = NULL;

    appointment *appointment1 = malloc(sizeof(appointment));
    appointment1->start_time = "9:00 AM";
    appointment1->end_time = "10:00 AM";
    appointment1->description = "Meeting with the boss";
    add_appointment(&head, appointment1);

    appointment *appointment2 = malloc(sizeof(appointment));
    appointment2->start_time = "10:30 AM";
    appointment2->end_time = "11:30 AM";
    appointment2->description = "Coffee with a friend";
    add_appointment(&head, appointment2);

    appointment *appointment3 = malloc(sizeof(appointment));
    appointment3->start_time = "1:00 PM";
    appointment3->end_time = "2:00 PM";
    appointment3->description = "Lunch with a coworker";
    add_appointment(&head, appointment3);

    print_appointment_list(head);

    free_appointment_list(head);

    return 0;
}