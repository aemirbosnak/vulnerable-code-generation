//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of appointments
#define MAX_APPOINTMENTS 10

// Define the structure of an appointment
typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

// Create a linked list of appointments
Appointment* createAppointmentList() {
    return NULL;
}

// Insert an appointment into the linked list
void insertAppointment(Appointment* list, char* name, char* date, char* time) {
    Appointment* newAppt = malloc(sizeof(Appointment));
    strcpy(newAppt->name, name);
    strcpy(newAppt->date, date);
    strcpy(newAppt->time, time);
    newAppt->next = NULL;

    if (list == NULL) {
        list = newAppt;
    } else {
        newAppt->next = list;
        list = newAppt;
    }
}

// Print the appointments in the linked list
void printAppointments(Appointment* list) {
    Appointment* currentAppt = list;
    while (currentAppt) {
        printf("Name: %s\n", currentAppt->name);
        printf("Date: %s\n", currentAppt->date);
        printf("Time: %s\n", currentAppt->time);
        printf("\n");
        currentAppt = currentAppt->next;
    }
}

int main() {
    Appointment* list = createAppointmentList();

    // Insert some appointments
    insertAppointment(list, "John Doe", "2023-08-01", "10:00");
    insertAppointment(list, "Jane Doe", "2023-08-02", "12:00");
    insertAppointment(list, "Peter Pan", "2023-08-03", "14:00");

    // Print the appointments
    printAppointments(list);

    return 0;
}