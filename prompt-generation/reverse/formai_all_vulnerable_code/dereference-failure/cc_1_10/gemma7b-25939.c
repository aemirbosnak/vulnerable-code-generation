//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define APPOINTMENT_SIZE 10

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

Appointment* appointment_list = NULL;

void create_appointment(char* name, char* date, char* time) {
    Appointment* new_appointment = (Appointment*)malloc(sizeof(Appointment));

    strcpy(new_appointment->name, name);
    strcpy(new_appointment->date, date);
    strcpy(new_appointment->time, time);
    new_appointment->next = NULL;

    if (appointment_list == NULL) {
        appointment_list = new_appointment;
    } else {
        appointment_list->next = new_appointment;
        appointment_list = new_appointment;
    }
}

void delete_appointment(char* name) {
    Appointment* current_appointment = appointment_list;
    Appointment* previous_appointment = NULL;

    while (current_appointment) {
        if (strcmp(current_appointment->name, name) == 0) {
            if (previous_appointment) {
                previous_appointment->next = current_appointment->next;
                free(current_appointment);
            } else {
                appointment_list = current_appointment->next;
                free(current_appointment);
            }
            return;
        }

        previous_appointment = current_appointment;
        current_appointment = current_appointment->next;
    }

    printf("Error: Appointment not found.\n");
}

int main() {
    create_appointment("John Doe", "2023-08-01", "10:00");
    create_appointment("Jane Doe", "2023-08-02", "12:00");
    create_appointment("Bob Smith", "2023-08-03", "14:00");

    delete_appointment("Jane Doe");

    Appointment* current_appointment = appointment_list;

    while (current_appointment) {
        printf("%s, %s, %s\n", current_appointment->name, current_appointment->date, current_appointment->time);
        current_appointment = current_appointment->next;
    }

    return 0;
}