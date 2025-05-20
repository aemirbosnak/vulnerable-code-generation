//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: random
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Appointment {
    char* name;
    int hour;
    int minute;
} Appointment;

typedef struct Node {
    Appointment appointment;
    struct Node* next;
} Node;

struct {
    Node* head;
    Node* tail;
} appointmentList;

void insertAppointment(char* name, int hour, int minute) {
    Node* newAppointment = malloc(sizeof(Node));
    newAppointment->appointment.name = name;
    newAppointment->appointment.hour = hour;
    newAppointment->appointment.minute = minute;
    newAppointment->next = NULL;
    
    if (appointmentList.head == NULL) {
        appointmentList.head = newAppointment;
        appointmentList.tail = newAppointment;
    } else {
        appointmentList.tail->next = newAppointment;
        appointmentList.tail = newAppointment;
    }
}

void printAppointments() {
    Node* current = appointmentList.head;
    while (current != NULL) {
        printf("%s - %02d:%02d\n", current->appointment.name, current->appointment.hour, current->appointment.minute);
        current = current->next;
    }
}

int main() {
    insertAppointment("John", 10, 30);
    insertAppointment("Mary", 11, 0);
    insertAppointment("Bob", 12, 30);
    
    printAppointments();
    
    return 0;
}