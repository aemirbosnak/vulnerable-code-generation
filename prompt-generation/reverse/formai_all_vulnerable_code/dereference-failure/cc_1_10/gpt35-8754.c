//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

struct Appointment {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

struct Node {
    struct Appointment appointment;
    struct Node* next;
};

void addAppointment(struct Node** headRef, struct Appointment appointment) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->appointment = appointment;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct Node* lastNode = *headRef;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
}

void printAppointments(struct Node* head) {
    if (head == NULL) {
        printf("No appointments scheduled.\n");
        return;
    }

    printf("Appointments:\n");
    while (head != NULL) {
        printf("%s: %d/%d/%d %02d:%02d\n", 
            head->appointment.name, head->appointment.day, head->appointment.month, 
            head->appointment.year, head->appointment.hour, head->appointment.minute);
        head = head->next;
    }
}

int main() {
    struct Node* head = NULL;

    struct Appointment ap1 = {"Meeting with John", 1, 2, 2022, 10, 0};
    addAppointment(&head, ap1);

    struct Appointment ap2 = {"Lunch with Sarah", 1, 2, 2022, 12, 30};
    addAppointment(&head, ap2);

    struct Appointment ap3 = {"Doctor's appointment", 1, 2, 2022, 14, 0};
    addAppointment(&head, ap3);

    printAppointments(head);

    return 0;
}