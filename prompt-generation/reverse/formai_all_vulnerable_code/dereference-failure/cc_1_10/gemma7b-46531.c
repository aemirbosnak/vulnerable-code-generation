//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
    char name[50];
    time_t timestamp;
    struct Appointment* next;
} Appointment;

Appointment* head = NULL;

void schedule_appointment(char* name, time_t timestamp) {
    Appointment* new_appointment = (Appointment*)malloc(sizeof(Appointment));
    strcpy(new_appointment->name, name);
    new_appointment->timestamp = timestamp;
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

void list_appointments() {
    Appointment* current = head;
    while (current) {
        printf("%s, %s\n", current->name, asctime(localtime(&current->timestamp)));
        current = current->next;
    }
}

int main() {
    time_t timestamp = time(NULL);

    schedule_appointment("John Doe", timestamp + 3600);
    schedule_appointment("Jane Doe", timestamp + 7200);
    schedule_appointment("Peter Pan", timestamp + 10800);

    list_appointments();

    return 0;
}