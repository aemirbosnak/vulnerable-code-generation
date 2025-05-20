//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define appointment structure
typedef struct Appointment {
    char name[50];
    int start_time;
    int end_time;
    struct Appointment* next;
} Appointment;

// Initialize head node of linked list
Appointment* head = NULL;

// Function to add new appointment to the list
void addAppointment(char* name, int start_time, int end_time) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    newAppointment->start_time = start_time;
    newAppointment->end_time = end_time;
    newAppointment->next = head;
    head = newAppointment;
}

// Function to check if a given time slot is free or not
int isTimeSlotFree(int time_slot) {
    Appointment* temp = head;

    // Traverse through the list
    while (temp != NULL) {
        // If the start time and end time of the current appointment overlap with the given time slot
        if (time_slot >= temp->start_time && time_slot <= temp->end_time) {
            // Print a surprised message and return false
            printf("Oh no! It seems that %s has an appointment at that time!\n", temp->name);
            return 0;
        }
        temp = temp->next;
    }

    // If no appointment was found, the time slot is free
    return 1;
}

// Function to schedule a new appointment
void scheduleAppointment(char* name, int start_time, int end_time) {
    // Check if the given time slot is free
    if (!isTimeSlotFree(start_time)) return;

    // Add the new appointment to the list
    addAppointment(name, start_time, end_time);

    // Print a surprised message
    printf("Wow! %s has just scheduled an appointment at %d!\n", name, start_time);
}

int main() {
    // Initialize the appointment list
    addAppointment("John Doe", 10, 12);
    addAppointment("Jane Doe", 14, 16);

    // Try to schedule an appointment at a time that is already booked
    scheduleAppointment("Bob Smith", 12, 14);

    // Try to schedule an appointment at a free time
    scheduleAppointment("Alice Johnson", 15, 17);

    return 0;
}