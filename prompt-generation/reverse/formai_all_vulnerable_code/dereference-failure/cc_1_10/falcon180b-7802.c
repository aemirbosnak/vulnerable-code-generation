//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_DATE_LENGTH 10
#define MAX_TIME_LENGTH 8

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} appointment;

appointment* appointments = NULL;
int num_appointments = 0;

void add_appointment() {
    appointment* new_appointment = (appointment*) malloc(sizeof(appointment));
    strcpy(new_appointment->name, "");
    strcpy(new_appointment->description, "");
    strcpy(new_appointment->date, "");
    strcpy(new_appointment->time, "");
    appointments = (appointment*) realloc(appointments, sizeof(appointment) * ++num_appointments);
    appointments[num_appointments-1] = *new_appointment;
    free(new_appointment);
}

void print_appointments() {
    printf("Name\tDescription\tDate\tTime\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%s\t%s\t%s\n", appointments[i].name, appointments[i].description, appointments[i].date, appointments[i].time);
    }
}

void delete_appointment(int index) {
    if (index >= num_appointments) {
        printf("Invalid appointment index.\n");
        return;
    }
    appointments = (appointment*) realloc(appointments, sizeof(appointment) * --num_appointments);
}

int main() {
    appointments = (appointment*) malloc(sizeof(appointment));
    strcpy(appointments[0].name, "");
    strcpy(appointments[0].description, "");
    strcpy(appointments[0].date, "");
    strcpy(appointments[0].time, "");
    num_appointments = 1;
    int choice;
    while (1) {
        printf("1. Add appointment\n2. Print appointments\n3. Delete appointment\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                print_appointments();
                break;
            case 3:
                printf("Enter appointment index to delete: ");
                scanf("%d", &choice);
                delete_appointment(choice);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}