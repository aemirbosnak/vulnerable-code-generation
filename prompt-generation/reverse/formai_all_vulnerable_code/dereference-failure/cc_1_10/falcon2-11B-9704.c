//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    char *name;
    int start_time;
    int end_time;
    char *description;
};

void print_appointments(struct Appointment *appointments, int num_appointments) {
    int i;
    printf("Appointments:\n");
    for (i = 0; i < num_appointments; i++) {
        printf("Name: %s\n", appointments[i].name);
        printf("Start Time: %d\n", appointments[i].start_time);
        printf("End Time: %d\n", appointments[i].end_time);
        printf("Description: %s\n", appointments[i].description);
        printf("\n");
    }
}

int main() {
    struct Appointment appointments[5];
    int num_appointments = 0;

    appointments[num_appointments].name = (char *)malloc(sizeof(char) * 20);
    appointments[num_appointments].start_time = 0;
    appointments[num_appointments].end_time = 0;
    appointments[num_appointments].description = (char *)malloc(sizeof(char) * 100);

    appointments[num_appointments].name = "Appointment 1";
    appointments[num_appointments].start_time = 10;
    appointments[num_appointments].end_time = 12;
    appointments[num_appointments].description = "Description for appointment 1";

    num_appointments++;

    appointments[num_appointments].name = "Appointment 2";
    appointments[num_appointments].start_time = 15;
    appointments[num_appointments].end_time = 17;
    appointments[num_appointments].description = "Description for appointment 2";

    num_appointments++;

    appointments[num_appointments].name = "Appointment 3";
    appointments[num_appointments].start_time = 20;
    appointments[num_appointments].end_time = 22;
    appointments[num_appointments].description = "Description for appointment 3";

    num_appointments++;

    appointments[num_appointments].name = "Appointment 4";
    appointments[num_appointments].start_time = 25;
    appointments[num_appointments].end_time = 27;
    appointments[num_appointments].description = "Description for appointment 4";

    num_appointments++;

    appointments[num_appointments].name = "Appointment 5";
    appointments[num_appointments].start_time = 30;
    appointments[num_appointments].end_time = 32;
    appointments[num_appointments].description = "Description for appointment 5";

    num_appointments++;

    print_appointments(appointments, num_appointments);

    return 0;
}