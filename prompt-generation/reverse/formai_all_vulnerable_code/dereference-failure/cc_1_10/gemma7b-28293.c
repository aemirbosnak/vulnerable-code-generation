//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct appointment {
    char name[20];
    char date[20];
    char time[20];
    struct appointment* next;
} appointment;

void insert(appointment** head, char* name, char* date, char* time) {
    appointment* new_app = (appointment*)malloc(sizeof(appointment));
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

void search(appointment* head, char* name) {
    while (head) {
        if (strcmp(head->name, name) == 0) {
            printf("Name: %s\n", head->name);
            printf("Date: %s\n", head->date);
            printf("Time: %s\n", head->time);
            break;
        }
        head = head->next;
    }
    if (head == NULL) {
        printf("No appointment found.\n");
    }
}

int main() {
    appointment* head = NULL;

    insert(&head, "John Doe", "2023-08-01", "10:00");
    insert(&head, "Jane Doe", "2023-08-02", "12:00");
    insert(&head, "Peter Pan", "2023-08-03", "14:00");

    search(head, "Jane Doe");

    return 0;
}