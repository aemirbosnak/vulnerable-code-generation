//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Appointments 10
#define MAX_TIME_SLOTS 5

typedef struct Appointment {
    char name[50];
    char timeSlot;
    struct Appointment* next;
} Appointment;

Appointment* insertAppointment(Appointment* head, char name, char timeSlot) {
    Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(newAppointment->name, name);
    newAppointment->timeSlot = timeSlot;
    newAppointment->next = NULL;

    if (head == NULL) {
        head = newAppointment;
    } else {
        head->next = newAppointment;
    }

    return head;
}

void displayAppointments(Appointment* head) {
    while (head) {
        printf("%s, %c\n", head->name, head->timeSlot);
        head = head->next;
    }
}

int main() {
    time_t t = time(NULL);
    srand(t);

    Appointment* head = NULL;

    // Insert some random appointments
    insertAppointment(head, "John Doe", 'A');
    insertAppointment(head, "Jane Doe", 'B');
    insertAppointment(head, "Bill Smith", 'C');
    insertAppointment(head, "Mary Johnson", 'D');

    // Display all appointments
    displayAppointments(head);

    return 0;
}