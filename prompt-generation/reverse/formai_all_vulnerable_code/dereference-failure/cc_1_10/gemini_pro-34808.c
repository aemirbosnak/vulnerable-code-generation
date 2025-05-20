//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Appointment {
    char *name;
    int hour;
    int minute;
    char *notes;
} Appointment;

typedef struct Calendar {
    Appointment **appointments;
    int num_appointments;
    int max_appointments;
} Calendar;

Calendar *create_calendar(int max_appointments) {
    Calendar *calendar = malloc(sizeof(Calendar));
    calendar->appointments = malloc(sizeof(Appointment *) * max_appointments);
    calendar->num_appointments = 0;
    calendar->max_appointments = max_appointments;
    return calendar;
}

void destroy_calendar(Calendar *calendar) {
    for (int i = 0; i < calendar->num_appointments; i++) {
        free(calendar->appointments[i]->name);
        free(calendar->appointments[i]->notes);
        free(calendar->appointments[i]);
    }
    free(calendar->appointments);
    free(calendar);
}

void add_appointment(Calendar *calendar, Appointment *appointment) {
    if (calendar->num_appointments == calendar->max_appointments) {
        calendar->appointments = realloc(calendar->appointments, sizeof(Appointment *) * (calendar->max_appointments * 2));
        calendar->max_appointments *= 2;
    }
    calendar->appointments[calendar->num_appointments++] = appointment;
}

void remove_appointment(Calendar *calendar, int index) {
    for (int i = index; i < calendar->num_appointments - 1; i++) {
        calendar->appointments[i] = calendar->appointments[i + 1];
    }
    calendar->num_appointments--;
}

void print_calendar(Calendar *calendar) {
    for (int i = 0; i < calendar->num_appointments; i++) {
        printf("%s %02d:%02d %s\n", calendar->appointments[i]->name, calendar->appointments[i]->hour, calendar->appointments[i]->minute, calendar->appointments[i]->notes);
    }
}

int main() {
    Calendar *calendar = create_calendar(10);

    Appointment *appointment = malloc(sizeof(Appointment));
    appointment->name = strdup("John Doe");
    appointment->hour = 10;
    appointment->minute = 30;
    appointment->notes = strdup("Meeting with client");
    add_appointment(calendar, appointment);

    appointment = malloc(sizeof(Appointment));
    appointment->name = strdup("Jane Doe");
    appointment->hour = 14;
    appointment->minute = 0;
    appointment->notes = strdup("Lunch with friend");
    add_appointment(calendar, appointment);

    print_calendar(calendar);

    remove_appointment(calendar, 1);

    print_calendar(calendar);

    destroy_calendar(calendar);

    return 0;
}