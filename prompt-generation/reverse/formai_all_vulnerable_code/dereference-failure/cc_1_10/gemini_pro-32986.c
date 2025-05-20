//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Romeo and Juliet style
#define FOR_THEE mine
#define QUERY_THEE query
#define LIST_THEE list

// Appointment structure
typedef struct Appointment {
    char *name;
    char *time;
    char *location;
} Appointment;

// Appointment list structure
typedef struct AppointmentList {
    Appointment *appointments;
    int size;
    int capacity;
} AppointmentList;

// Create a new appointment
Appointment *create_appointment(char *name, char *time, char *location) {
    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->name = strdup(name);
    appointment->time = strdup(time);
    appointment->location = strdup(location);
    return appointment;
}

// Create a new appointment list
AppointmentList *create_appointment_list(int capacity) {
    AppointmentList *list = malloc(sizeof(AppointmentList));
    list->appointments = malloc(sizeof(Appointment) * capacity);
    list->size = 0;
    list->capacity = capacity;
    return list;
}

// Add an appointment to the list
void add_appointment(AppointmentList *FOR_THEE, Appointment *appointment) {
    if (FOR_THEE->size == FOR_THEE->capacity) {
        FOR_THEE->capacity *= 2;
        FOR_THEE->appointments = realloc(FOR_THEE->appointments, sizeof(Appointment) * FOR_THEE->capacity);
    }
    FOR_THEE->appointments[FOR_THEE->size++] = *appointment;
}

// Remove an appointment from the list
void remove_appointment(AppointmentList *FOR_THEE, int index) {
    if (index < 0 || index >= FOR_THEE->size) {
        return;
    }
    for (int i = index; i < FOR_THEE->size - 1; i++) {
        FOR_THEE->appointments[i] = FOR_THEE->appointments[i + 1];
    }
    FOR_THEE->size--;
}

// Query the list for appointments with a given name
AppointmentList *QUERY_THEE(AppointmentList *FOR_THEE, char *name) {
    AppointmentList *results = create_appointment_list(FOR_THEE->capacity);
    for (int i = 0; i < FOR_THEE->size; i++) {
        if (strcmp(FOR_THEE->appointments[i].name, name) == 0) {
            add_appointment(results, &FOR_THEE->appointments[i]);
        }
    }
    return results;
}

// List all appointments in the list
void LIST_THEE(AppointmentList *FOR_THEE) {
    for (int i = 0; i < FOR_THEE->size; i++) {
        printf("%s, %s, %s\n", FOR_THEE->appointments[i].name, FOR_THEE->appointments[i].time, FOR_THEE->appointments[i].location);
    }
}

// Main function
int main() {
    // Create an appointment list
    AppointmentList *appointments = create_appointment_list(10);

    // Add some appointments to the list
    add_appointment(appointments, create_appointment("Romeo", "10:00 AM", "Montague Manor"));
    add_appointment(appointments, create_appointment("Juliet", "11:00 AM", "Capulet Castle"));
    add_appointment(appointments, create_appointment("Tybalt", "12:00 PM", "The Square"));

    // Query the list for appointments with a given name
    AppointmentList *results = QUERY_THEE(appointments, "Romeo");

    // List all appointments in the list
    LIST_THEE(results);

    // Free the memory allocated for the appointments
    for (int i = 0; i < appointments->size; i++) {
        free(appointments->appointments[i].name);
        free(appointments->appointments[i].time);
        free(appointments->appointments[i].location);
    }
    free(appointments->appointments);
    free(appointments);

    return 0;
}