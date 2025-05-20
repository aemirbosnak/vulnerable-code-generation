//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char *name;
    Date *date;
} Appointment;

int main() {
    int numAppointments;

    printf("How many appointments do you want to schedule? ");
    scanf("%d", &numAppointments);

    Appointment *appointments = (Appointment *) malloc(numAppointments * sizeof(Appointment));

    for (int i = 0; i < numAppointments; i++) {
        printf("Enter the name of appointment %d: ", i+1);
        char name[50];
        scanf("%s", name);

        appointments[i].name = (char *) malloc(sizeof(name));
        for (int j = 0; j < sizeof(name); j++) {
            appointments[i].name[j] = name[j];
        }

        appointments[i].date = (Date *) malloc(sizeof(Date));
        printf("Enter the date of appointment %d (dd/mm/yyyy): ", i+1);
        scanf("%d/%d/%d", &appointments[i].date->day, &appointments[i].date->month, &appointments[i].date->year);
    }

    printf("\nAppointments:\n\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%d. %s on %d/%d/%d\n", i+1, appointments[i].name, appointments[i].date->day, appointments[i].date->month, appointments[i].date->year);
    }

    printf("\n");

    for (int i = 0; i < numAppointments; i++) {
        free(appointments[i].name);
        free(appointments[i].date);
    }

    free(appointments);

    return 0;
}