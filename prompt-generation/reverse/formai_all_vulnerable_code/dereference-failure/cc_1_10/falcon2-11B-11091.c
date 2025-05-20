//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct appointment {
    struct appointment *next;
    char* title;
    int start_time;
    int duration;
} Appointment;

typedef struct scheduler {
    struct appointment *first;
} Scheduler;

void add_appointment(Scheduler *scheduler, char *title, int start_time, int duration) {
    struct appointment *new_appointment = malloc(sizeof(struct appointment));
    new_appointment->title = strdup(title);
    new_appointment->start_time = start_time;
    new_appointment->duration = duration;
    new_appointment->next = NULL;

    if (scheduler->first == NULL) {
        scheduler->first = new_appointment;
    } else {
        struct appointment *current = scheduler->first;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_appointment;
    }
}

void list_appointments(Scheduler *scheduler) {
    struct appointment *current = scheduler->first;
    while (current!= NULL) {
        printf("Title: %s\nStart Time: %d\nDuration: %d\n\n", current->title, current->start_time, current->duration);
        current = current->next;
    }
}

void remove_appointment(Scheduler *scheduler, char *title) {
    struct appointment *current = scheduler->first;
    struct appointment *prev = NULL;
    while (current!= NULL) {
        if (strcmp(current->title, title) == 0) {
            if (prev == NULL) {
                scheduler->first = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->title);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    Scheduler *scheduler = malloc(sizeof(Scheduler));
    scheduler->first = NULL;

    add_appointment(scheduler, "Meeting", 10, 1);
    add_appointment(scheduler, "Lunch", 14, 0);
    add_appointment(scheduler, "Workout", 16, 0.5);
    add_appointment(scheduler, "Dinner", 18, 1);
    add_appointment(scheduler, "Movie", 20, 2);

    list_appointments(scheduler);

    remove_appointment(scheduler, "Meeting");

    list_appointments(scheduler);

    free(scheduler);
    return 0;
}