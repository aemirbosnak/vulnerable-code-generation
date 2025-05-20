//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

struct Appointment {
    char name[50];
    char date[50];
    char time[50];
    struct Appointment* next;
};

struct Appointment* Insert(struct Appointment* head, char* name, char* date, char* time) {
    struct Appointment* newNode = (struct Appointment*)malloc(sizeof(struct Appointment));
    strcpy(newNode->name, name);
    strcpy(newNode->date, date);
    strcpy(newNode->time, time);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Appointment* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    return head;
}

void PrintAppointments(struct Appointment* head) {
    struct Appointment* temp = head;
    while (temp) {
        printf("Name: %s\n", temp->name);
        printf("Date: %s\n", temp->date);
        printf("Time: %s\n", temp->time);
        printf("\n");
        temp = temp->next;
    }
}

int main() {
    struct Appointment* head = NULL;

    Insert(head, "John Doe", "2023-08-01", "10:00");
    Insert(head, "Jane Doe", "2023-08-02", "12:00");
    Insert(head, "Peter Pan", "2023-08-03", "09:00");

    PrintAppointments(head);

    return 0;
}