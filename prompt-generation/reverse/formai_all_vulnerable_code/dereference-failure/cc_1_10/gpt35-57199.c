//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    int id;
    char name[50];
    char date[20];
    char time[20];
};

struct Node {
    struct Appointment data;
    struct Node* next;
};
typedef struct Node node;

node* head = NULL;

void addAppointment(int id, char name[], char date[], char time[]) {
    node* new = (node*)malloc(sizeof(node));
    new->data.id = id;
    strcpy(new->data.name, name);
    strcpy(new->data.date, date);
    strcpy(new->data.time, time);
    new->next = NULL;

    if (head == NULL) {
        head = new;
        return;
    }

    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new;
}

void printAppointments() {
    printf("Scheduled Appointments:\n");
    if (head == NULL) {
        printf("None\n");
        return;
    }

    node* current = head;
    while (current != NULL) {
        printf("ID #%d: %s on %s at %s\n", current->data.id, current->data.name, current->data.date, current->data.time);
        current = current->next;
    }
}

void cancelAppointment(int id) {
    if (head == NULL) {
        printf("No appointments scheduled\n");
        return;
    }

    node* current = head;
    node* prev = NULL;
    while (current != NULL && current->data.id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Appointment ID not found\n");
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    printf("Appointment ID #%d cancelled\n", id);
}

int main() {
    addAppointment(1, "John", "1/1/2022", "10:00 AM");
    addAppointment(2, "Jane", "1/1/2022", "11:00 AM");
    addAppointment(3, "Bob", "1/2/2022", "3:00 PM");

    printAppointments();

    cancelAppointment(2);

    printAppointments();

    return 0;
}