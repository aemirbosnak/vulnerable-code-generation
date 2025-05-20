//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Appointment structure
typedef struct Appointment {
    char name[50];
    char date[11];
    char time[6];
    char reason[100];
    struct Appointment *next;
} Appointment;

// Appointment list structure
typedef struct AppointmentList {
    Appointment *head;
    Appointment *tail;
    int size;
} AppointmentList;

// Function to create an appointment
Appointment *createAppointment(char *name, char *date, char *time, char *reason) {
    Appointment *newAppointment = (Appointment *)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    strcpy(newAppointment->reason, reason);
    newAppointment->next = NULL;
    return newAppointment;
}

// Function to add an appointment to the list
void addAppointment(AppointmentList *list, Appointment *newAppointment) {
    if (list->head == NULL) {
        list->head = newAppointment;
        list->tail = newAppointment;
    } else {
        list->tail->next = newAppointment;
        list->tail = newAppointment;
    }
    list->size++;
}

// Function to remove an appointment from the list
void removeAppointment(AppointmentList *list, char *name) {
    Appointment *current = list->head;
    Appointment *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            list->size--;
            break;
        }
        previous = current;
        current = current->next;
    }
}

// Function to print the appointment list
void printAppointmentList(AppointmentList *list) {
    Appointment *current = list->head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Date: %s\n", current->date);
        printf("Time: %s\n", current->time);
        printf("Reason: %s\n\n", current->reason);
        current = current->next;
    }
}

// Main function
int main() {
    // Create an appointment list
    AppointmentList *list = (AppointmentList *)malloc(sizeof(AppointmentList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    // Add some appointments to the list
    addAppointment(list, createAppointment("John Doe", "2023-03-08", "10:00", "Meeting"));
    addAppointment(list, createAppointment("Jane Smith", "2023-03-15", "11:00", "Consultation"));
    addAppointment(list, createAppointment("Bill Jones", "2023-03-22", "12:00", "Interview"));

    // Print the appointment list
    printf("Appointment List:\n");
    printAppointmentList(list);

    // Remove an appointment from the list
    removeAppointment(list, "John Doe");

    // Print the appointment list again
    printf("\nUpdated Appointment List:\n");
    printAppointmentList(list);

    // Free the appointment list
    Appointment *current = list->head;
    while (current != NULL) {
        Appointment *next = current->next;
        free(current);
        current = next;
    }
    free(list);

    return 0;
}