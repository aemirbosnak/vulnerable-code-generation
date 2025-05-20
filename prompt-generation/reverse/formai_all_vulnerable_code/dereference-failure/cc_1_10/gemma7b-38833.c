//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

Appointment* createAppointment(char* name, char* date, char* time) {
    Appointment* newAppt = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppt->name, name);
    strcpy(newAppt->date, date);
    strcpy(newAppt->time, time);
    newAppt->next = NULL;
    return newAppt;
}

int main() {
    Appointment* head = NULL;
    char name[50];
    char date[50];
    char time[50];

    // Create a loop to get the desired number of appointments
    int numAppointments = 0;
    printf("Enter the number of appointments you want to create: ");
    scanf("%d", &numAppointments);

    // Create and insert each appointment into the linked list
    for (int i = 0; i < numAppointments; i++) {
        printf("Enter the name of the appointment: ");
        scanf("%s", name);

        printf("Enter the date of the appointment (dd/mm/yyyy): ");
        scanf("%s", date);

        printf("Enter the time of the appointment (hh:mm): ");
        scanf("%s", time);

        Appointment* newAppt = createAppointment(name, date, time);
        if (head == NULL) {
            head = newAppt;
        } else {
            newAppt->next = head;
            head = newAppt;
        }
    }

    // Print the appointments
    printf("Your appointments:\n");
    for (Appointment* currentAppt = head; currentAppt; currentAppt = currentAppt->next) {
        printf("Name: %s\n", currentAppt->name);
        printf("Date: %s\n", currentAppt->date);
        printf("Time: %s\n", currentAppt->time);
        printf("\n");
    }

    return 0;
}