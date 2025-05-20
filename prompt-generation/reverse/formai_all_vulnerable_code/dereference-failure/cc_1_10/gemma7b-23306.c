//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char name[50];
    int hour;
    struct Node* next;
};

struct Appointment {
    char name[50];
    int hour;
    struct Appointment* next;
};

void insertNode(struct Node** head, char* name, int hour) {
    struct Node* newNode = malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->hour = hour;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void insertAppointment(struct Appointment** head, char* name, int hour) {
    struct Appointment* newAppointment = malloc(sizeof(struct Appointment));
    strcpy(newAppointment->name, name);
    newAppointment->hour = hour;
    newAppointment->next = NULL;

    if (*head == NULL) {
        *head = newAppointment;
    } else {
        (*head)->next = newAppointment;
    }
}

void printAppointments(struct Appointment* head) {
    while (head) {
        printf("%s at %d\n", head->name, head->hour);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;
    struct Appointment* appointmentHead = NULL;

    insertNode(&head, "John Doe", 10);
    insertNode(&head, "Jane Doe", 12);
    insertNode(&head, "Bill Smith", 14);

    insertAppointment(&appointmentHead, "Alice White", 10);
    insertAppointment(&appointmentHead, "Bob Green", 12);
    insertAppointment(&appointmentHead, "Charlie Brown", 14);

    printAppointments(appointmentHead);

    return 0;
}