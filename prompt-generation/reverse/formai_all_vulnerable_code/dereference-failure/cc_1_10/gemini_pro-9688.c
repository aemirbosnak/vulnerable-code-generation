//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    int id;
    char* description;
    char* date;
    char* time;
} appointment;

typedef struct node {
    appointment* data;
    struct node* next;
} node;

node* head = NULL;
node* tail = NULL;

void add_appointment(appointment* appt) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = appt;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void print_appointments() {
    node* current = head;
    while (current != NULL) {
        printf("ID: %d\n", current->data->id);
        printf("Description: %s\n", current->data->description);
        printf("Date: %s\n", current->data->date);
        printf("Time: %s\n", current->data->time);
        printf("\n");
        current = current->next;
    }
}

int main() {
    appointment* appt1 = (appointment*)malloc(sizeof(appointment));
    appt1->id = 1;
    appt1->description = "Meeting with client";
    appt1->date = "2023-03-08";
    appt1->time = "10:00 AM";

    appointment* appt2 = (appointment*)malloc(sizeof(appointment));
    appt2->id = 2;
    appt2->description = "Interview with candidate";
    appt2->date = "2023-03-10";
    appt2->time = "2:00 PM";

    add_appointment(appt1);
    add_appointment(appt2);

    print_appointments();

    return 0;
}