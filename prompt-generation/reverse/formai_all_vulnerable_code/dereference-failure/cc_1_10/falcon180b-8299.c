//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    int duration;
} appointment;

appointment* appointments = NULL;
int num_appointments = 0;

void add_appointment(char* name, time_t start_time, int duration) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Too many appointments!\n");
        return;
    }
    appointment* new_appointment = (appointment*) malloc(sizeof(appointment));
    strcpy(new_appointment->name, name);
    new_appointment->start_time = start_time;
    new_appointment->duration = duration;
    appointments = (appointment*) realloc(appointments, sizeof(appointment) * (num_appointments + 1));
    appointments[num_appointments] = *new_appointment;
    num_appointments++;
}

void print_appointments() {
    if (num_appointments == 0) {
        printf("No appointments found!\n");
        return;
    }
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s to %s (%d minutes)\n", appointments[i].name, ctime(&appointments[i].start_time), ctime(&appointments[i].start_time + appointments[i].duration * 60), appointments[i].duration);
    }
}

int main() {
    srand(time(NULL));
    int choice;
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    int duration;

    do {
        printf("1. Add appointment\n2. Print appointments\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name (max %d characters): ", MAX_NAME_LENGTH - 1);
                scanf("%s", name);
                printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", ctime(&start_time));
                printf("Enter duration (in minutes): ");
                scanf("%d", &duration);
                add_appointment(name, start_time, duration);
                break;
            case 2:
                print_appointments();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 3);

    return 0;
}