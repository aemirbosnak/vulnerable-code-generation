//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// What the heck is this sorcery?
typedef struct appointment {
    char *description;
    int start_time;
    int end_time;
} appointment_t;

// Oh my goodness, a linked list?
typedef struct node {
    appointment_t *appointment;
    struct node *next;
} node_t;

// Holy moly, a function to add an appointment?
void add_appointment(node_t **head, appointment_t *appointment) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->appointment = appointment;
    new_node->next = *head;
    *head = new_node;
}

// What the heck, a function to print the appointments?
void print_appointments(node_t *head) {
    while (head != NULL) {
        printf("Appointment: %s, Start time: %d, End time: %d\n", head->appointment->description, head->appointment->start_time, head->appointment->end_time);
        head = head->next;
    }
}

// Oh my goodness, a function to search for an appointment?
node_t *search_appointment(node_t *head, int start_time, int end_time) {
    while (head != NULL) {
        if (head->appointment->start_time == start_time && head->appointment->end_time == end_time) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// What the heck, a function to delete an appointment?
void delete_appointment(node_t **head, int start_time, int end_time) {
    node_t *current = *head;
    node_t *previous = NULL;
    while (current != NULL) {
        if (current->appointment->start_time == start_time && current->appointment->end_time == end_time) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->appointment);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Oh my goodness, a main function?
int main() {
    // Holy moly, creating a linked list?
    node_t *head = NULL;

    // What the heck, adding some appointments?
    appointment_t *appointment1 = malloc(sizeof(appointment_t));
    appointment1->description = "Meeting with the boss";
    appointment1->start_time = 9;
    appointment1->end_time = 10;
    add_appointment(&head, appointment1);

    appointment_t *appointment2 = malloc(sizeof(appointment_t));
    appointment2->description = "Lunch with a friend";
    appointment2->start_time = 12;
    appointment2->end_time = 13;
    add_appointment(&head, appointment2);

    appointment_t *appointment3 = malloc(sizeof(appointment_t));
    appointment3->description = "Go to the gym";
    appointment3->start_time = 17;
    appointment3->end_time = 18;
    add_appointment(&head, appointment3);

    // Oh my goodness, printing the appointments?
    printf("Appointments:\n");
    print_appointments(head);

    // What the heck, searching for an appointment?
    printf("\nSearching for appointment at 9 AM:\n");
    node_t *found_appointment = search_appointment(head, 9, 10);
    if (found_appointment != NULL) {
        printf("Found appointment: %s, Start time: %d, End time: %d\n", found_appointment->appointment->description, found_appointment->appointment->start_time, found_appointment->appointment->end_time);
    } else {
        printf("Appointment not found.\n");
    }

    // Holy moly, deleting an appointment?
    printf("\nDeleting appointment at 12 PM:\n");
    delete_appointment(&head, 12, 13);
    print_appointments(head);

    // What the heck, freeing the linked list?
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->appointment);
        free(current);
        current = next;
    }

    return 0;
}