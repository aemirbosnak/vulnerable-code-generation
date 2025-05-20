//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
} Appointment;

void add_appointment(Appointment* appointments, int num_appointments) {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter description: ");
    scanf("%s", description);

    time_t start_time;
    time_t end_time;

    printf("Enter start time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", &start_time);
    printf("Enter end time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", &end_time);

    Appointment appointment = {
       .name = strdup(name),
       .description = strdup(description),
       .start_time = start_time,
       .end_time = end_time
    };

    num_appointments++;
    appointments = realloc(appointments, sizeof(Appointment) * num_appointments);
    appointments[num_appointments - 1] = appointment;
}

void print_appointments(Appointment* appointments, int num_appointments) {
    for (int i = 0; i < num_appointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Description: %s\n", appointments[i].description);
        printf("Start time: %s\n", ctime(&appointments[i].start_time));
        printf("End time: %s\n\n", ctime(&appointments[i].end_time));
    }
}

int main() {
    int num_appointments = 0;
    Appointment* appointments = NULL;

    while (num_appointments < MAX_APPOINTMENTS) {
        printf("1. Add appointment\n2. Print appointments\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment(appointments, num_appointments);
                break;
            case 2:
                print_appointments(appointments, num_appointments);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    free(appointments);
    return 0;
}