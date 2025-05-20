//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define APPOINTMENT_LIST_SIZE 10
#define APPOINTMENT_LIST_MAX_SIZE 100

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

Appointment* appointment_list = NULL;

void schedule_appointment(char* name, char* date, char* time) {
    Appointment* new_appointment = malloc(sizeof(Appointment));
    new_appointment->name[0] = '\0';
    new_appointment->date[0] = '\0';
    new_appointment->time[0] = '\0';
    new_appointment->next = NULL;

    strcpy(new_appointment->name, name);
    strcpy(new_appointment->date, date);
    strcpy(new_appointment->time, time);

    if (appointment_list == NULL) {
        appointment_list = new_appointment;
    } else {
        appointment_list->next = new_appointment;
        appointment_list = new_appointment;
    }
}

void print_appointments() {
    Appointment* current_appointment = appointment_list;

    while (current_appointment) {
        printf("%s, %s, %s\n", current_appointment->name, current_appointment->date, current_appointment->time);
        current_appointment = current_appointment->next;
    }
}

int main() {
    schedule_appointment("John Doe", "2023-04-01", "10:00");
    schedule_appointment("Jane Doe", "2023-04-02", "12:00");
    schedule_appointment("Bill Smith", "2023-04-03", "14:00");

    print_appointments();

    return 0;
}