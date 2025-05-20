//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Appointment {
    char name[50];
    char date[10];
    char time[10];
    struct Appointment* next;
} Appointment;

void insert(Appointment** head, char* name, char* date, char* time) {
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

void search(Appointment* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Name: %s\n", head->name);
            printf("Date: %s\n", head->date);
            printf("Time: %s\n", head->time);
            return;
        }
        head = head->next;
    }
    printf("No appointment found for name: %s\n", name);
}

int main() {
    Appointment* head = NULL;

    insert(&head, "John Doe", "2023-08-01", "10:00");
    insert(&head, "Jane Doe", "2023-08-02", "12:00");
    insert(&head, "Peter Pan", "2023-08-03", "14:00");

    search(head, "John Doe");
    search(head, "Jane Doe");
    search(head, "Jack Sparrow");

    return 0;
}