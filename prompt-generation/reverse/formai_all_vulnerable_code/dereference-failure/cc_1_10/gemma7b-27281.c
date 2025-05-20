//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_Appointments 100

typedef struct Appointment {
    char name[50];
    char date[10];
    char time[10];
    struct Appointment* next;
} Appointment;

Appointment* insert_appointment(Appointment* head, char* name, char* date, char* time) {
    Appointment* new_appointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(new_appointment->name, name);
    strcpy(new_appointment->date, date);
    strcpy(new_appointment->time, time);
    new_appointment->next = NULL;

    if (head == NULL) {
        head = new_appointment;
    } else {
        head->next = new_appointment;
    }

    return head;
}

void print_appointments(Appointment* head) {
    while (head) {
        printf("%s, %s, %s\n", head->name, head->date, head->time);
        head = head->next;
    }
}

int main() {
    Appointment* head = NULL;

    // Insert some appointments
    insert_appointment(head, "John Doe", "2023-04-01", "10:00");
    insert_appointment(head, "Jane Doe", "2023-04-02", "12:00");
    insert_appointment(head, "Bill Smith", "2023-04-03", "14:00");

    // Print all appointments
    print_appointments(head);

    return 0;
}