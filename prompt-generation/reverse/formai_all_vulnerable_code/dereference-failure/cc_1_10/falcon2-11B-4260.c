//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[100];
    int start_time;
    int end_time;
    int duration;
} Appointment;

typedef struct {
    Appointment appointments[50];
    int num_appointments;
} AppointmentSchedule;

void add_appointment(AppointmentSchedule *schedule, char name[], int start_time, int end_time, int duration) {
    Appointment new_appointment;
    strcpy(new_appointment.name, name);
    new_appointment.start_time = start_time;
    new_appointment.end_time = end_time;
    new_appointment.duration = duration;
    schedule->appointments[schedule->num_appointments] = new_appointment;
    schedule->num_appointments++;
}

void print_appointments(AppointmentSchedule *schedule) {
    for (int i = 0; i < schedule->num_appointments; i++) {
        printf("Name: %s\n", schedule->appointments[i].name);
        printf("Start Time: %d\n", schedule->appointments[i].start_time);
        printf("End Time: %d\n", schedule->appointments[i].end_time);
        printf("Duration: %d\n", schedule->appointments[i].duration);
        printf("\n");
    }
}

void print_all_appointments(AppointmentSchedule *schedule) {
    printf("Appointments:\n");
    print_appointments(schedule);
    printf("\n");
}

int main() {
    AppointmentSchedule schedule;
    srand(time(NULL));
    char name[100];
    int start_time, end_time, duration;

    while (1) {
        printf("Enter appointment details: ");
        fflush(stdin);
        scanf("%s %d %d %d", name, &start_time, &end_time, &duration);
        add_appointment(&schedule, name, start_time, end_time, duration);
        printf("Appointment added.\n");
        print_all_appointments(&schedule);
        printf("Do you want to add another appointment? (y/n): ");
        char input;
        scanf(" %c", &input);
        if (input!= 'y')
            break;
    }

    return 0;
}