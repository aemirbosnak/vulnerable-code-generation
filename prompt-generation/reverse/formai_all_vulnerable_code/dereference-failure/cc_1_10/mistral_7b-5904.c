//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_APPT_NUM 10
#define MAX_NAME_LEN 20
#define MAX_TIME_LEN 10

typedef struct Appointment {
    char name[MAX_NAME_LEN];
    int start_time[MAX_APPT_NUM];
    int duration[MAX_APPT_NUM];
} Appointment;

Appointment schedule;

void print_schedule() {
    printf("\n-------------------------------------------------\n");
    printf("| Time   | Appointment        |\n");
    printf("-------------------------------------------------|\n");
    int time = 0;

    for (int i = 0; i < MAX_APPT_NUM; ++i) {
        if (schedule.start_time[i] != -1) {
            printf("| %02d:%02d | %s          |\n", time / 60, time % 60, schedule.name[i]);
            time += schedule.duration[i];
        } else {
            time++;
        }
    }

    printf("-------------------------------------------------\n");
}

void add_appointment(char* name, int start_time, int duration) {
    for (int i = 0; i < MAX_APPT_NUM; ++i) {
        if (schedule.start_time[i] == -1) {
            strcpy(schedule.name[i], name);
            schedule.start_time[i] = start_time;
            schedule.duration[i] = duration;
            break;
        } else if (schedule.start_time[i] > start_time) {
            for (int j = i; j < MAX_APPT_NUM; ++j) {
                schedule.start_time[j] += duration;
            }

            strcpy(schedule.name[i], name);
            schedule.start_time[i] = start_time;
            schedule.duration[i] = duration;
            break;
        }
    }
}

int main(void) {
    memset(&schedule, -1, sizeof(schedule));

    add_appointment("John Doe", 9 * 60, 30);
    add_appointment("Jane Smith", 12 * 60, 60);
    add_appointment("Bob Johnson", 14 * 60, 45);

    print_schedule();

    return 0;
}