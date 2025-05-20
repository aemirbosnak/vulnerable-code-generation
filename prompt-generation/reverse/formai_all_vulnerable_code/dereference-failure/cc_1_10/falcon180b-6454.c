//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MINUTES_IN_A_DAY (24 * 60)

typedef struct appointment {
    char *name;
    int start_time;
    int end_time;
} Appointment;

void surrealist_appointment_scheduler() {
    srand(time(NULL));

    // Generate random appointments
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = rand() % MAX_APPOINTMENTS + 1;
    for (int i = 0; i < num_appointments; i++) {
        appointments[i].name = (char *)malloc(10 * sizeof(char));
        for (int j = 0; j < 10; j++) {
            appointments[i].name[j] = 'A' + rand() % 26;
        }
        appointments[i].name[10] = '\0';

        appointments[i].start_time = rand() % MINUTES_IN_A_DAY;
        appointments[i].end_time = appointments[i].start_time + rand() % 60;
    }

    // Sort appointments by start time
    for (int i = 0; i < num_appointments - 1; i++) {
        for (int j = i + 1; j < num_appointments; j++) {
            if (appointments[i].start_time > appointments[j].start_time) {
                Appointment temp = appointments[i];
                appointments[i] = appointments[j];
                appointments[j] = temp;
            }
        }
    }

    // Print schedule
    printf("Surrealist Appointment Schedule:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%.2d:%.2d - ", appointments[i].start_time / 60, appointments[i].start_time % 60);
        printf("%s\n", appointments[i].name);
    }
}

int main() {
    surrealist_appointment_scheduler();
    return 0;
}