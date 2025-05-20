//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10
#define MAX_DAYS 7

typedef struct appointment {
    int day;
    char name[20];
} appointment_t;

typedef struct scheduler {
    int num_appointments;
    appointment_t* appointments;
} scheduler_t;

int main() {
    scheduler_t scheduler;

    appointment_t appts[MAX_APPOINTMENTS];
    int num_appts = 0;

    // Initialize scheduler
    scheduler.num_appointments = 0;
    scheduler.appointments = malloc(sizeof(appointment_t) * MAX_APPOINTMENTS);

    // Add appointments to scheduler
    printf("Enter appointment name and day (format: MM/DD/YYYY):\n");
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        char* name = NULL;
        int day = 0;
        fgets(name, 20, stdin);
        sscanf(name, "%d/%d/%d", &day, &name[2], &name[5]);
        if (num_appts < MAX_APPOINTMENTS) {
            appointment_t* ap = &appts[num_appts];
            ap->day = day;
            strncpy(ap->name, name, sizeof(ap->name));
            num_appts++;
            printf("Appointment %s added on %d/%d/%d\n", ap->name, ap->day, 2000 + ap->day / 100, ap->day % 100);
        } else {
            printf("No more slots available\n");
        }
    }

    // Print scheduler
    printf("Scheduler:\n");
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (scheduler.appointments[i].day!= 0) {
            printf("%s on %d/%d/%d\n", scheduler.appointments[i].name, 2000 + scheduler.appointments[i].day / 100, scheduler.appointments[i].day % 100, scheduler.appointments[i].day);
        }
    }

    // Free memory
    free(scheduler.appointments);

    return 0;
}