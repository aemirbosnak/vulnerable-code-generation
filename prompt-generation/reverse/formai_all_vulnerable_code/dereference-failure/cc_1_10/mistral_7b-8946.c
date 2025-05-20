//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define APPOINTMENT_LENGTH 60

typedef struct {
    int id;
    char name[50];
    int start_time;
    int end_time;
} appointment;

appointment appointments[MAX_APPOINTMENTS];

int find_next_available_time(int start_time) {
    int i;
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].start_time == 0 || appointments[i].end_time > start_time) {
            return start_time;
        }
        start_time++;
    }
    return start_time;
}

void add_appointment(char *name, int start_time, int duration) {
    int i, index;
    appointment new_appointment = {0};

    strcpy(new_appointment.name, name);
    new_appointment.start_time = find_next_available_time(start_time);
    new_appointment.end_time = new_appointment.start_time + duration;

    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].start_time == new_appointment.start_time) {
            index = i;
            break;
        }
    }

    if (index == MAX_APPOINTMENTS) {
        printf("Error: Could not add appointment.\n");
        return;
    }

    appointments[index] = new_appointment;
}

void print_schedule() {
    int i;
    for (i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].start_time != 0) {
            printf("%s (%d-%d)\n", appointments[i].name, appointments[i].start_time, appointments[i].end_time);
        }
    }
}

int main(int argc, char *argv[]) {
    int i;

    for (i = 1; i < argc; i++) {
        char *name = argv[i];
        int start_time = atoi(argv[i+1]);
        int duration = atoi(argv[i+2]);

        add_appointment(name, start_time, duration);
        i += 2;
    }

    print_schedule();

    return 0;
}