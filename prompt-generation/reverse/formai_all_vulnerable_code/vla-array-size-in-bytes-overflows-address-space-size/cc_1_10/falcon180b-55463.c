//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50

struct appointment {
    char name[MAX_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
};

void print_appointment(const struct appointment *a) {
    printf("%s: %s - %s\n", a->name, ctime(&a->start_time), ctime(&a->end_time));
}

int compare_appointments(const void *a, const void *b) {
    const struct appointment *appointment_a = a;
    const struct appointment *appointment_b = b;

    time_t start_time_a = appointment_a->start_time;
    time_t start_time_b = appointment_b->start_time;

    return difftime(start_time_a, start_time_b);
}

int main() {
    int num_appointments;
    printf("Enter the number of appointments: ");
    scanf("%d", &num_appointments);

    if (num_appointments > MAX_APPOINTMENTS) {
        printf("Error: Too many appointments.\n");
        return 1;
    }

    struct appointment appointments[num_appointments];

    for (int i = 0; i < num_appointments; i++) {
        printf("Enter appointment %d:\n", i+1);
        printf("Name: ");
        scanf("%s", appointments[i].name);

        printf("Start time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", appointments[i].name);
        appointments[i].start_time = time(NULL);

        printf("End time (YYYY-MM-DD HH:MM:SS): ");
        scanf("%s", appointments[i].name);
        appointments[i].end_time = time(NULL);
    }

    qsort(appointments, num_appointments, sizeof(struct appointment), compare_appointments);

    for (int i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }

    return 0;
}