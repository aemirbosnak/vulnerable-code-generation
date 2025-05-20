//MISTRAL-7B DATASET v1.0 Category: Appointment Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEC_PER_MIN 60
#define MIN_PER_HR 60

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
} Appointment;

typedef struct Node {
    Appointment data;
    struct Node *next;
} Node;

Node* createNode(int y, int m, int d, int h, int min) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data.year = y;
    newNode->data.month = m;
    newNode->data.day = d;
    newNode->data.hour = h;
    newNode->data.minute = min;
    newNode->next = NULL;
    return newNode;
}

Node* addAppointment(Node* head, int y, int m, int d, int h, int min) {
    Node* newNode = createNode(y, m, d, h, min);
    Node* current = head;

    if (head == NULL) {
        head = newNode;
        return head;
    }

    while (current->next != NULL && current->next->data.hour < h)
        current = current->next;

    if (current->next == NULL || current->next->data.hour > h) {
        newNode->next = current->next;
        current->next = newNode;
    } else {
        Node* temp = current->next;
        current->next = newNode;
        newNode->next = temp;
    }

    return head;
}

void printAppointments(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("%d:%02d %d-%02d-%d\n", current->data.hour, current->data.minute,
               current->data.month, current->data.day, current->data.year);
        current = current->next;
    }
}

int main() {
    srand(time(NULL));
    int numAppointments = 10;
    Node* head = NULL;

    for (int i = 0; i < numAppointments; i++) {
        int y = 1999 + rand() % 11;
        int m = rand() % 13;
        int d = rand() % 31;
        int h = rand() % 24;
        int min = rand() % 61;
        head = addAppointment(head, y, m, d, h, min);
    }

    printf("Appointments:\n");
    printAppointments(head);

    return 0;
}