//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define MAX_DESCRIPTION_LEN 100
#define MAX_LOCATION_LEN 100

typedef struct appointment {
    char name[MAX_DESCRIPTION_LEN];
    char location[MAX_LOCATION_LEN];
    struct appointment* next;
} Appointment;

Appointment* appointment_list = NULL;

void add_appointment(char name[], char location[]) {
    Appointment* new_appointment = (Appointment*) malloc(sizeof(Appointment));
    strcpy(new_appointment->name, name);
    strcpy(new_appointment->location, location);
    new_appointment->next = NULL;

    if (appointment_list == NULL) {
        appointment_list = new_appointment;
    } else {
        Appointment* current = appointment_list;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_appointment;
    }
}

void delete_appointment(char name[], char location[]) {
    Appointment* current = appointment_list;
    Appointment* prev = NULL;

    while (current!= NULL) {
        if (strcmp(current->name, name) == 0 && strcmp(current->location, location) == 0) {
            if (prev!= NULL) {
                prev->next = current->next;
            } else {
                appointment_list = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

void print_appointments() {
    Appointment* current = appointment_list;
    while (current!= NULL) {
        printf("%s (%s)\n", current->name, current->location);
        current = current->next;
    }
}

int main() {
    char name[MAX_DESCRIPTION_LEN], location[MAX_LOCATION_LEN];

    printf("Enter the name of the appointment: ");
    fgets(name, MAX_DESCRIPTION_LEN, stdin);
    printf("Enter the location of the appointment: ");
    fgets(location, MAX_LOCATION_LEN, stdin);

    add_appointment(name, location);

    printf("Current appointments:\n");
    print_appointments();

    printf("Enter the name of the appointment to delete: ");
    fgets(name, MAX_DESCRIPTION_LEN, stdin);
    printf("Enter the location of the appointment to delete: ");
    fgets(location, MAX_LOCATION_LEN, stdin);

    delete_appointment(name, location);

    printf("Current appointments:\n");
    print_appointments();

    return 0;
}