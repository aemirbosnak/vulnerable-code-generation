//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct appointment {
    char *name;
    int date;
    int time;
};

void print_appointment(struct appointment appt) {
    printf("Name: %s\n", appt.name);
    printf("Date: %d\n", appt.date);
    printf("Time: %d\n\n", appt.time);
}

int compare_appointments(const void *a, const void *b) {
    struct appointment *appt1 = (struct appointment *)a;
    struct appointment *appt2 = (struct appointment *)b;

    if (appt1->date == appt2->date) {
        return appt1->time - appt2->time;
    } else {
        return appt1->date - appt2->date;
    }
}

int main() {
    int num_appointments;
    struct appointment *appointments;
    int i, j;

    printf("Enter the number of appointments: ");
    scanf("%d", &num_appointments);

    appointments = (struct appointment *)malloc(num_appointments * sizeof(struct appointment));

    for (i = 0; i < num_appointments; i++) {
        appointments[i].name = (char *)malloc(100 * sizeof(char));
        printf("Enter the name for appointment %d: ", i+1);
        scanf("%s", appointments[i].name);

        printf("Enter the date for appointment %d (YYYYMMDD): ", i+1);
        scanf("%d", &appointments[i].date);

        printf("Enter the time for appointment %d (HHMM): ", i+1);
        scanf("%d", &appointments[i].time);
    }

    qsort(appointments, num_appointments, sizeof(struct appointment), compare_appointments);

    printf("Appointments sorted by date and time:\n");
    for (i = 0; i < num_appointments; i++) {
        print_appointment(appointments[i]);
    }

    free(appointments);

    return 0;
}