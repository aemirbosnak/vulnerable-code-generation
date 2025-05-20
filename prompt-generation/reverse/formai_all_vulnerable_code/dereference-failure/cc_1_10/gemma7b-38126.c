//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
} Appointment;

void append_appointment(Appointment** head, char* name, char* date, char* time) {
    Appointment* new_app = (Appointment*)malloc(sizeof(Appointment));
    strcpy(new_app->name, name);
    strcpy(new_app->date, date);
    strcpy(new_app->time, time);
    new_app->next = NULL;

    if (*head == NULL) {
        *head = new_app;
    } else {
        (*head)->next = new_app;
    }
}

int main() {
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    int hour = tm->tm_hour;
    int min = tm->tm_min;

    Appointment* head = NULL;

    append_appointment(&head, "Salvador Dalí", "04/01/2023", "10:00");
    append_appointment(&head, "Pablo Picasso", "04/02/2023", "12:00");
    append_appointment(&head, "Vincent van Gogh", "04/03/2023", "14:00");

    printf("Current time: %02d:%02d\n", hour, min);

    Appointment* current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Date: %s\n", current->date);
        printf("Time: %s\n", current->time);
        printf("\n");
        current = current->next;
    }

    return 0;
}