//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Appointment {
    int id;
    char* date;
    char* time;
    int duration;
    int status;
};

int main(int argc, char *argv[]) {
    struct Appointment appointments[10];
    int numAppointments = 10;

    for (int i = 0; i < numAppointments; i++) {
        appointments[i].id = i + 1;
        appointments[i].date = malloc(sizeof(char) * 20);
        appointments[i].time = malloc(sizeof(char) * 20);
        appointments[i].duration = rand() % 100;
        appointments[i].status = 0;

        if (appointments[i].date == NULL || appointments[i].time == NULL) {
            perror("Malloc failed");
            exit(EXIT_FAILURE);
        }

        srand(time(NULL));
        appointments[i].date[0] = '1' + rand() % 10;
        appointments[i].date[1] = '0' + rand() % 10;
        appointments[i].date[2] = '0' + rand() % 10;
        appointments[i].date[3] = '0' + rand() % 10;
        appointments[i].date[4] = '0' + rand() % 10;

        appointments[i].time[0] = '1' + rand() % 10;
        appointments[i].time[1] = '0' + rand() % 10;
        appointments[i].time[2] = '0' + rand() % 10;
        appointments[i].time[3] = '0' + rand() % 10;
        appointments[i].time[4] = '0' + rand() % 10;
    }

    int appointmentIndex = 0;
    while (appointmentIndex < numAppointments) {
        if (appointments[appointmentIndex].status == 0) {
            printf("Appointment %d - %s at %s for %d hours\n", appointments[appointmentIndex].id, appointments[appointmentIndex].date, appointments[appointmentIndex].time, appointments[appointmentIndex].duration);
            appointments[appointmentIndex].status = 1;
            appointmentIndex++;
        } else if (appointmentIndex + 1 < numAppointments) {
            if (appointments[appointmentIndex].status == 1 && appointments[appointmentIndex + 1].status == 0) {
                appointments[appointmentIndex].status = 2;
                appointments[appointmentIndex + 1].status = 1;
                appointmentIndex += 2;
            } else {
                appointmentIndex++;
            }
        } else {
            appointmentIndex = numAppointments;
        }
    }

    return 0;
}