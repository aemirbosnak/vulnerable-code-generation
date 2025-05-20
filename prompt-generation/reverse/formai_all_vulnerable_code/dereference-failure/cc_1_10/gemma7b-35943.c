//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[10];
    char time[10];
    struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, char* date, char* time) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    strcpy(newAppointment->date, date);
    strcpy(newAppointment->time, time);
    newAppointment->next = NULL;
    return newAppointment;
}

void displayAppointments(Appointment* head) {
    while (head) {
        printf("%s, %s, %s\n", head->name, head->date, head->time);
        head = head->next;
    }
}

int main() {
    Appointment* head = NULL;
    char name[50];
    char date[10];
    char time[10];

    // Create a few appointments
    createAppointment("John Doe", "2023-04-01", "10:00");
    createAppointment("Jane Doe", "2023-04-02", "12:00");
    createAppointment("Peter Pan", "2023-04-03", "14:00");

    // Display the appointments
    displayAppointments(head);

    // Get the user's name, date, and time
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the date: ");
    scanf("%s", date);

    printf("Enter the time: ");
    scanf("%s", time);

    // Create a new appointment
    createAppointment(name, date, time);

    // Display the updated appointments
    displayAppointments(head);

    return 0;
}