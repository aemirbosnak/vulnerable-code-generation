//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    struct Appointment* next;
} Appointment;

Appointment* head = NULL;

void schedule_appointment(char* name, char* date, char* time) {
    Appointment* new_appointment = (Appointment*) malloc(sizeof(Appointment));
    strcpy(new_appointment->name, name);
    strcpy(new_appointment->date, date);
    strcpy(new_appointment->time, time);
    new_appointment->next = NULL;

    if (head == NULL) {
        head = new_appointment;
    } else {
        Appointment* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_appointment;
    }
}

void print_appointments() {
    Appointment* current = head;
    while (current) {
        printf("%s, %s, %s\n", current->name, current->date, current->time);
        current = current->next;
    }
}

int main() {
    time_t t = time(NULL);
    char* date = asctime(localtime(&t));
    char* time = asctime(localtime(&t));

    schedule_appointment("John Doe", date, time);
    schedule_appointment("Jane Doe", date, time);
    schedule_appointment("Bill Smith", date, time);

    print_appointments();

    return 0;
}