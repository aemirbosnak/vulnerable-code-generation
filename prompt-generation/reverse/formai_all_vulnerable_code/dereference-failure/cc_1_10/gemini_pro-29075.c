//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    int duration;
};

struct Node {
    struct Appointment appointment;
    struct Node *next;
};

struct List {
    struct Node *head;
    struct Node *tail;
    int size;
};

struct List *create_list() {
    struct List *list = (struct List *)malloc(sizeof(struct List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void insert_appointment(struct List *list, struct Appointment appointment) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->appointment = appointment;
    node->next = NULL;
    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void print_appointments(struct List *list) {
    struct Node *current = list->head;
    while (current != NULL) {
        printf("Name: %s\n", current->appointment.name);
        printf("Date: %s\n", current->appointment.date);
        printf("Time: %s\n", current->appointment.time);
        printf("Duration: %d\n\n", current->appointment.duration);
        current = current->next;
    }
}

void delete_appointment(struct List *list, struct Appointment appointment) {
    struct Node *current = list->head;
    struct Node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->appointment.name, appointment.name) == 0 &&
            strcmp(current->appointment.date, appointment.date) == 0 &&
            strcmp(current->appointment.time, appointment.time) == 0) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            list->size--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    // Create a new appointment list
    struct List *appointment_list = create_list();

    // Insert some appointments into the list
    struct Appointment appointment1 = {"John Doe", "2023-03-08", "10:00 AM", 60};
    insert_appointment(appointment_list, appointment1);
    struct Appointment appointment2 = {"Jane Doe", "2023-03-09", "11:00 AM", 30};
    insert_appointment(appointment_list, appointment2);
    struct Appointment appointment3 = {"Bill Smith", "2023-03-10", "12:00 PM", 45};
    insert_appointment(appointment_list, appointment3);

    // Print the appointments in the list
    printf("Appointments:\n");
    print_appointments(appointment_list);

    // Delete an appointment from the list
    struct Appointment appointment_to_delete = {"Jane Doe", "2023-03-09", "11:00 AM", 30};
    delete_appointment(appointment_list, appointment_to_delete);

    // Print the appointments in the list again
    printf("\nAppointments after deleting:\n");
    print_appointments(appointment_list);

    return 0;
}