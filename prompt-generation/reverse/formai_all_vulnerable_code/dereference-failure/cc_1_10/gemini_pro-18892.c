//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appointment struct
typedef struct Appointment {
    char *name;
    char *date;
    char *time;
} Appointment;

// Appointment list struct
typedef struct AppointmentList {
    Appointment *appointment;
    struct AppointmentList *next;
} AppointmentList;

// Create a new appointment
Appointment *create_appointment(char *name, char *date, char *time) {
    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->name = strdup(name);
    appointment->date = strdup(date);
    appointment->time = strdup(time);
    return appointment;
}

// Add an appointment to the list
void add_appointment(AppointmentList **list, Appointment *appointment) {
    AppointmentList *new_node = malloc(sizeof(AppointmentList));
    new_node->appointment = appointment;
    new_node->next = *list;
    *list = new_node;
}

// Print the appointment list
void print_appointments(AppointmentList *list) {
    while (list) {
        printf("%s, %s, %s\n", list->appointment->name, list->appointment->date, list->appointment->time);
        list = list->next;
    }
}

// Free the appointment list
void free_appointments(AppointmentList *list) {
    while (list) {
        AppointmentList *next = list->next;
        free(list->appointment->name);
        free(list->appointment->date);
        free(list->appointment->time);
        free(list->appointment);
        free(list);
        list = next;
    }
}

// Main function
int main() {
    // Create a new appointment list
    AppointmentList *list = NULL;

    // Add some appointments to the list
    add_appointment(&list, create_appointment("John Doe", "2023-03-08", "10:00"));
    add_appointment(&list, create_appointment("Jane Doe", "2023-03-09", "11:00"));
    add_appointment(&list, create_appointment("Jack Doe", "2023-03-10", "12:00"));

    // Print the appointment list
    printf("Appointments:\n");
    print_appointments(list);

    // Free the appointment list
    free_appointments(list);

    return 0;
}