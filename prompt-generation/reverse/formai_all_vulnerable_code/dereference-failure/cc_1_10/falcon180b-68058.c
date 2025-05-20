//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LEN 50

struct appointment {
    char name[MAX_NAME_LEN];
    int year;
    int month;
    int day;
    int hour;
    int minute;
};

void add_appointment(struct appointment* list, int num_appointments, char* name, int year, int month, int day, int hour, int minute) {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Cannot add more than %d appointments.\n", MAX_APPOINTMENTS);
        return;
    }

    strncpy(list[num_appointments].name, name, MAX_NAME_LEN);
    list[num_appointments].year = year;
    list[num_appointments].month = month;
    list[num_appointments].day = day;
    list[num_appointments].hour = hour;
    list[num_appointments].minute = minute;

    num_appointments++;
}

void print_appointments(struct appointment* list, int num_appointments) {
    if (num_appointments == 0) {
        printf("No appointments found.\n");
        return;
    }

    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s on %04d-%02d-%02d %02d:%02d\n", list[i].name, list[i].year, list[i].month, list[i].day, list[i].hour, list[i].minute);
    }
}

int main() {
    struct appointment* list = malloc(sizeof(struct appointment) * MAX_APPOINTMENTS);
    int num_appointments = 0;

    add_appointment(list, num_appointments, "Meeting with boss", 2022, 1, 1, 9, 0);
    add_appointment(list, num_appointments, "Lunch with friends", 2022, 1, 6, 12, 30);
    add_appointment(list, num_appointments, "Doctor's appointment", 2022, 1, 10, 15, 0);

    print_appointments(list, num_appointments);

    free(list);
    return 0;
}