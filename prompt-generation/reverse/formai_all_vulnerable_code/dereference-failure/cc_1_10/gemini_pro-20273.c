//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    int id;
    char *description;
    int day;
    int month;
    int year;
    int hour;
    int minute;
} appointment;

typedef struct scheduler {
    appointment **appointments;
    int num_appointments;
} scheduler;

scheduler *create_scheduler() {
    scheduler *s = malloc(sizeof(scheduler));
    s->appointments = malloc(sizeof(appointment *) * 10);
    s->num_appointments = 0;
    return s;
}

void destroy_scheduler(scheduler *s) {
    for (int i = 0; i < s->num_appointments; i++) {
        free(s->appointments[i]->description);
        free(s->appointments[i]);
    }
    free(s->appointments);
    free(s);
}

void add_appointment(scheduler *s, appointment *a) {
    s->appointments[s->num_appointments++] = a;
}

void print_appointments(scheduler *s) {
    for (int i = 0; i < s->num_appointments; i++) {
        printf("%d: %s %d/%d/%d %d:%d\n", s->appointments[i]->id, s->appointments[i]->description, s->appointments[i]->day, s->appointments[i]->month, s->appointments[i]->year, s->appointments[i]->hour, s->appointments[i]->minute);
    }
}

int main() {
    scheduler *s = create_scheduler();

    appointment *a1 = malloc(sizeof(appointment));
    a1->id = 1;
    a1->description = strdup("Meeting with John");
    a1->day = 1;
    a1->month = 1;
    a1->year = 2023;
    a1->hour = 10;
    a1->minute = 0;

    appointment *a2 = malloc(sizeof(appointment));
    a2->id = 2;
    a2->description = strdup("Lunch with Mary");
    a2->day = 2;
    a2->month = 1;
    a2->year = 2023;
    a2->hour = 12;
    a2->minute = 0;

    appointment *a3 = malloc(sizeof(appointment));
    a3->id = 3;
    a3->description = strdup("Call with Peter");
    a3->day = 3;
    a3->month = 1;
    a3->year = 2023;
    a3->hour = 14;
    a3->minute = 0;

    add_appointment(s, a1);
    add_appointment(s, a2);
    add_appointment(s, a3);

    print_appointments(s);

    destroy_scheduler(s);

    return 0;
}