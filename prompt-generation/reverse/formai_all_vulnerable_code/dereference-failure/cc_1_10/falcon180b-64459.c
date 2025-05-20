//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LEN 50
#define MAX_DURATION 120 // 2 hours

typedef struct {
    char name[MAX_NAME_LEN];
    time_t start_time;
    int duration;
} appointment;

appointment* create_appointment(char* name, time_t start_time, int duration) {
    appointment* app = (appointment*) malloc(sizeof(appointment));
    strncpy(app->name, name, MAX_NAME_LEN);
    app->start_time = start_time;
    app->duration = duration;
    return app;
}

void print_appointment(appointment* app) {
    printf("Name: %s\n", app->name);
    printf("Start time: %s\n", ctime(&app->start_time));
    printf("Duration: %d minutes\n", app->duration);
}

int main() {
    int num_appointments;
    printf("Enter the number of appointments (max %d): ", MAX_APPOINTMENTS);
    scanf("%d", &num_appointments);

    appointment* appointments[MAX_APPOINTMENTS];
    for (int i = 0; i < num_appointments; i++) {
        char name[MAX_NAME_LEN];
        printf("Enter the name for appointment %d: ", i+1);
        scanf("%s", name);

        time_t start_time;
        printf("Enter the start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", ctime(&start_time));

        int duration;
        printf("Enter the duration in minutes: ");
        scanf("%d", &duration);

        if (duration > MAX_DURATION) {
            printf("Error: duration too long\n");
            exit(1);
        }

        appointments[i] = create_appointment(name, start_time, duration);
    }

    for (int i = 0; i < num_appointments; i++) {
        printf("Appointment %d:\n", i+1);
        print_appointment(appointments[i]);
    }

    return 0;
}