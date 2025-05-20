//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Appointment data structure
typedef struct Appointment {
    int id;
    char *description;
    int start_time;
    int end_time;
    struct Appointment *next;
} Appointment;

// Appointment list data structure
typedef struct AppointmentList {
    Appointment *head;
    Appointment *tail;
} AppointmentList;

// Function to create a new appointment
Appointment *create_appointment(int id, char *description, int start_time, int end_time) {
    Appointment *new_appointment = malloc(sizeof(Appointment));
    if (new_appointment == NULL) {
        return NULL;
    }
    new_appointment->id = id;
    new_appointment->description = description;
    new_appointment->start_time = start_time;
    new_appointment->end_time = end_time;
    new_appointment->next = NULL;
    return new_appointment;
}

// Function to add a new appointment to the list
void add_appointment(AppointmentList *list, Appointment *new_appointment) {
    if (list->head == NULL) {
        list->head = new_appointment;
        list->tail = new_appointment;
    } else {
        list->tail->next = new_appointment;
        list->tail = new_appointment;
    }
}

// Function to print the list of appointments
void print_appointments(AppointmentList *list) {
    Appointment *current_appointment = list->head;
    while (current_appointment != NULL) {
        printf("Appointment ID: %d\n", current_appointment->id);
        printf("Description: %s\n", current_appointment->description);
        printf("Start time: %d\n", current_appointment->start_time);
        printf("End time: %d\n\n", current_appointment->end_time);
        current_appointment = current_appointment->next;
    }
}

// Function to free the memory allocated for the list of appointments
void free_appointments(AppointmentList *list) {
    Appointment *current_appointment = list->head;
    while (current_appointment != NULL) {
        Appointment *next_appointment = current_appointment->next;
        free(current_appointment->description);
        free(current_appointment);
        current_appointment = next_appointment;
    }
    free(list);
}

// Main function
int main() {
    // Create a new appointment list
    AppointmentList *list = malloc(sizeof(AppointmentList));
    if (list == NULL) {
        return 1;
    }
    list->head = NULL;
    list->tail = NULL;

    // Add some appointments to the list
    add_appointment(list, create_appointment(1, "Meeting with client", 1000, 1100));
    add_appointment(list, create_appointment(2, "Lunch with team", 1200, 1300));
    add_appointment(list, create_appointment(3, "Coding session", 1400, 1600));

    // Print the list of appointments
    print_appointments(list);

    // Free the memory allocated for the list of appointments
    free_appointments(list);

    return 0;
}