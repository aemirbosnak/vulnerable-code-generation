//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the appointment structure
typedef struct Appointment {
    char patientName[50];
    char doctorName[50];
    char date[20];
    char time[10];
} Appointment;

// Define the appointment node structure
typedef struct AppointmentNode {
    Appointment appointment;
    struct AppointmentNode* next;
} AppointmentNode;

// Define the appointment list structure
typedef struct AppointmentList {
    AppointmentNode* head;
    int length;
} AppointmentList;

// Initialize an empty appointment list
void initAppointmentList(AppointmentList* appointmentList) {
    appointmentList->head = NULL;
    appointmentList->length = 0;
}

// Find an appointment in the list by date and time
AppointmentNode* findAppointment(AppointmentList* appointmentList, char* date, char* time) {
    AppointmentNode* current = appointmentList->head;
    while (current != NULL) {
        if (strcmp(current->appointment.date, date) == 0 && strcmp(current->appointment.time, time) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Add a new appointment to the list
void addAppointment(AppointmentList* appointmentList, Appointment appointment) {
    // Check if appointment already exists at this date and time
    if (findAppointment(appointmentList, appointment.date, appointment.time) != NULL) {
        printf("Appointment already scheduled at this time.\n");
        return;
    }
    // Create a new appointment node and add it to the list
    AppointmentNode* newAppointmentNode = (AppointmentNode*) malloc(sizeof(AppointmentNode));
    newAppointmentNode->appointment = appointment;
    newAppointmentNode->next = NULL;
    if (appointmentList->head == NULL) {
        appointmentList->head = newAppointmentNode;
    } else {
        AppointmentNode* current = appointmentList->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newAppointmentNode;
    }
    appointmentList->length++;
    // Print confirmation message
    printf("Appointment scheduled for %s with Dr. %s on %s at %s.\n", appointment.patientName, appointment.doctorName, appointment.date, appointment.time);
}

// Remove an appointment from the list by date and time
void removeAppointment(AppointmentList* appointmentList, char* date, char* time) {
    AppointmentNode* previous = NULL;
    AppointmentNode* current = appointmentList->head;
    while (current != NULL) {
        if (strcmp(current->appointment.date, date) == 0 && strcmp(current->appointment.time, time) == 0) {
            if (previous == NULL) {
                appointmentList->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            appointmentList->length--;
            // Print confirmation message
            printf("Appointment cancelled for %s with Dr. %s on %s at %s.\n", current->appointment.patientName, current->appointment.doctorName, current->appointment.date, current->appointment.time);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Appointment not found.\n");
}

// Display the list of appointments
void displayAppointments(AppointmentList* appointmentList) {
    AppointmentNode* current = appointmentList->head;
    while (current != NULL) {
        printf("%s\t%s\t%s\t%s\n", current->appointment.patientName, current->appointment.doctorName, current->appointment.date, current->appointment.time);
        current = current->next;
    }
}

// Main function
int main() {
    // Initialize an empty appointment list
    AppointmentList appointmentList;
    initAppointmentList(&appointmentList);
    // Add some sample appointments
    addAppointment(&appointmentList, (Appointment) {"Alice", "Bob", "2022-01-01", "10:00:00"});
    addAppointment(&appointmentList, (Appointment) {"Charlie", "David", "2022-01-01", "11:00:00"});
    addAppointment(&appointmentList, (Appointment) {"Eve", "Frank", "2022-01-02", "10:30:00"});
    addAppointment(&appointmentList, (Appointment) {"Grace", "Henry", "2022-01-03", "09:00:00"});
    addAppointment(&appointmentList, (Appointment) {"Isabel", "John", "2022-01-03", "13:00:00"});
    // Display the list of appointments
    printf("List of Appointments:\n");
    displayAppointments(&appointmentList);
    // Remove an appointment
    removeAppointment(&appointmentList, "2022-01-01", "11:00:00");
    // Display the list of appointments again
    printf("List of Appointments:\n");
    displayAppointments(&appointmentList);
    // Add a new appointment that conflicts with an existing one
    addAppointment(&appointmentList, (Appointment) {"Karen", "Larry", "2022-01-02", "10:30:00"});
    // Display the list of appointments again
    printf("List of Appointments:\n");
    displayAppointments(&appointmentList);
    // Exit the program
    return 0;
}