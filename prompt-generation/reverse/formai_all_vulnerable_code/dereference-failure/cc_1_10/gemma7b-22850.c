//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    char name[50];
    char date[10];
    char time[10];
    struct Appointment* next;
};

struct Appointment* insert(struct Appointment* head, char* name, char* date, char* time) {
    struct Appointment* new_app = malloc(sizeof(struct Appointment));
    strcpy(new_app->name, name);
    strcpy(new_app->date, date);
    strcpy(new_app->time, time);
    new_app->next = NULL;

    if (head == NULL) {
        head = new_app;
    } else {
        struct Appointment* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_app;
    }

    return head;
}

void print_appointments(struct Appointment* head) {
    struct Appointment* temp = head;
    while (temp) {
        printf("%s, %s, %s\n", temp->name, temp->date, temp->time);
        temp = temp->next;
    }
}

int main() {
    struct Appointment* head = NULL;

    insert(head, "John Doe", "2023-01-01", "10:00");
    insert(head, "Jane Doe", "2023-01-02", "12:00");
    insert(head, "Peter Pan", "2023-01-03", "14:00");

    print_appointments(head);

    return 0;
}