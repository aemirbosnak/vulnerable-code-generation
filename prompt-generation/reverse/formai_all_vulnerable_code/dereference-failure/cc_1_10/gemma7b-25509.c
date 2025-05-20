//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10

struct Appointment {
    char name[20];
    char date[20];
    char time[20];
    struct Appointment* next;
};

struct Appointment* insertAppointment(struct Appointment* head, char* name, char* date, char* time) {
    struct Appointment* newAppt = (struct Appointment*)malloc(sizeof(struct Appointment));
    strcpy(newAppt->name, name);
    strcpy(newAppt->date, date);
    strcpy(newAppt->time, time);
    newAppt->next = NULL;

    if (head == NULL) {
        head = newAppt;
    } else {
        struct Appointment* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newAppt;
    }

    return head;
}

void displayAppointments(struct Appointment* head) {
    struct Appointment* temp = head;
    printf("Appointments:\n");
    while (temp) {
        printf("Name: %s\n", temp->name);
        printf("Date: %s\n", temp->date);
        printf("Time: %s\n", temp->time);
        printf("\n");
        temp = temp->next;
    }
}

int main() {
    struct Appointment* head = NULL;

    insertAppointment(head, "John Doe", "2023-04-01", "10:00 AM");
    insertAppointment(head, "Jane Doe", "2023-04-02", "1:00 PM");
    insertAppointment(head, "Peter Pan", "2023-04-03", "4:00 PM");

    displayAppointments(head);

    return 0;
}