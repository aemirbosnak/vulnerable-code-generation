//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct Appointment {
    char *name;
    time_t start_time;
    time_t end_time;
} Appointment;

typedef struct Calendar {
    Appointment **arr;
    int size;
} Calendar;

Calendar *create_calendar(int size) {
    Calendar *calendar = malloc(sizeof(Calendar));
    calendar->arr = malloc(sizeof(Appointment *) * size);
    calendar->size = size;
    return calendar;
}

void destroy_calendar(Calendar *calendar) {
    for (int i = 0; i < calendar->size; i++) {
        if (calendar->arr[i] != NULL) {
            free(calendar->arr[i]->name);
            free(calendar->arr[i]);
        }
    }
    free(calendar->arr);
    free(calendar);
}

int add_appointment(Calendar *calendar, Appointment *appointment) {
    for (int i = 0; i < calendar->size; i++) {
        if (calendar->arr[i] == NULL) {
            calendar->arr[i] = appointment;
            return 0;
        }
    }
    return -1;
}

Appointment *find_appointment(Calendar *calendar, time_t start_time, time_t end_time) {
    for (int i = 0; i < calendar->size; i++) {
        if (calendar->arr[i] != NULL && calendar->arr[i]->start_time >= start_time && calendar->arr[i]->end_time <= end_time) {
            return calendar->arr[i];
        }
    }
    return NULL;
}

int main() {
    Calendar *calendar = create_calendar(10);

    Appointment *appointment1 = malloc(sizeof(Appointment));
    appointment1->name = strdup("John Doe");
    appointment1->start_time = time(NULL);
    appointment1->end_time = time(NULL) + 3600;

    Appointment *appointment2 = malloc(sizeof(Appointment));
    appointment2->name = strdup("Jane Doe");
    appointment2->start_time = time(NULL) + 1800;
    appointment2->end_time = time(NULL) + 2700;

    add_appointment(calendar, appointment1);
    add_appointment(calendar, appointment2);

    Appointment *found_appointment = find_appointment(calendar, time(NULL) + 1200, time(NULL) + 1500);

    if (found_appointment != NULL) {
        printf("Found appointment: %s\n", found_appointment->name);
    } else {
        printf("No appointment found.\n");
    }

    destroy_calendar(calendar);

    return 0;
}