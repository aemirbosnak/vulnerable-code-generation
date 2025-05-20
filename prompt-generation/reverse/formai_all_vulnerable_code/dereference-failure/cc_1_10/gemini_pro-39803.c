//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    char *description;
    int start_time;
    int end_time;
} appointment_t;

typedef struct calendar {
    appointment_t *appointments;
    int num_appointments;
} calendar_t;

calendar_t *create_calendar() {
    calendar_t *calendar = malloc(sizeof(calendar_t));
    calendar->appointments = NULL;
    calendar->num_appointments = 0;
    return calendar;
}

void destroy_calendar(calendar_t *calendar) {
    for (int i = 0; i < calendar->num_appointments; i++) {
        free(calendar->appointments[i].description);
    }
    free(calendar->appointments);
    free(calendar);
}

void add_appointment(calendar_t *calendar, appointment_t appointment) {
    calendar->appointments = realloc(calendar->appointments, (calendar->num_appointments + 1) * sizeof(appointment_t));
    calendar->appointments[calendar->num_appointments] = appointment;
    calendar->num_appointments++;
}

void print_calendar(calendar_t *calendar) {
    for (int i = 0; i < calendar->num_appointments; i++) {
        printf("%s: %d-%d\n", calendar->appointments[i].description, calendar->appointments[i].start_time, calendar->appointments[i].end_time);
    }
}

int main() {
    calendar_t *calendar = create_calendar();

    appointment_t appointment1 = {"Meeting with Bob", 1000, 1100};
    add_appointment(calendar, appointment1);

    appointment_t appointment2 = {"Lunch with Alice", 1200, 1300};
    add_appointment(calendar, appointment2);

    print_calendar(calendar);

    destroy_calendar(calendar);

    return 0;
}