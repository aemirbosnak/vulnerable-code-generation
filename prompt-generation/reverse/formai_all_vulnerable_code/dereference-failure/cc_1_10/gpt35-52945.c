//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct Appointment {
   int day;
   int month;
   int year;
   int time;
};

struct Appointment* newAppointment(int day, int month, int year, int time) {
   struct Appointment* appointment = (struct Appointment*) malloc(sizeof(struct Appointment));
   appointment->day = day;
   appointment->month = month;
   appointment->year = year;
   appointment->time = time;
   return appointment;
}

struct Node {
    struct Appointment* appointment;
    struct Node* next;
};

struct Node* head = NULL;

void printAppointments() {
    struct Node* currentNode = head;
    printf("Scheduled Appointments:\n");
    int i = 1;
    while(currentNode != NULL) {
        printf("%d. %d/%d/%d at %d:00\n", i, currentNode->appointment->day, currentNode->appointment->month, currentNode->appointment->year, currentNode->appointment->time);
        currentNode = currentNode->next;
        i++;
    }
    printf("\n");
}

void makeAppointment() {
    int day, month, year, time;
    printf("Enter year (yyyy): ");
    scanf("%d", &year);
    printf("Enter month (mm): ");
    scanf("%d", &month);
    printf("Enter day (dd): ");
    scanf("%d", &day);
    printf("Enter time (24-hour, 1-24): ");
    scanf("%d", &time);
    struct Appointment* appointment = newAppointment(day, month, year, time);
    struct Node* currentNode = head;
    if(currentNode == NULL || ((appointment->year*10000)+(appointment->month*100)+appointment->day) < ((currentNode->appointment->year*10000)+(currentNode->appointment->month*100)+currentNode->appointment->day)) {
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->appointment = appointment;
        newNode->next = head;
        head = newNode;
        printf("Appointment scheduled for %d/%d/%d at %d:00\n\n", day, month, year, time);
        return;
    }
    while(currentNode->next != NULL && ((appointment->year*10000)+(appointment->month*100)+appointment->day) > ((currentNode->next->appointment->year*10000)+(currentNode->next->appointment->month*100)+currentNode->next->appointment->day)) {
        currentNode = currentNode->next;
    }
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->appointment = appointment;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    printf("Appointment scheduled for %d/%d/%d at %d:00\n\n", day, month, year, time);
}

void cancelAppointment() {
    int appointmentNumber;
    printf("Enter appointment number to cancel: ");
    scanf("%d", &appointmentNumber);
    struct Node* previousNode = NULL;
    struct Node* currentNode = head;
    int i = 1;
    while(currentNode != NULL && i != appointmentNumber) {
        previousNode = currentNode;
        currentNode = currentNode->next;
        i++;
    }
    if(currentNode == NULL) {
        printf("Invalid appointment number\n\n");
        return;
    }
    if(previousNode == NULL) {
        head = currentNode->next;
    }
    else {
        previousNode->next = currentNode->next;
    }
    printf("Appointment %d/%d/%d at %d:00 cancelled\n\n", currentNode->appointment->day, currentNode->appointment->month, currentNode->appointment->year, currentNode->appointment->time);
    free(currentNode);
}

int main() {
    char option;
    do {
        printf("Appointment Scheduler\n");
        printf("1. View Scheduled Appointments\n");
        printf("2. Schedule New Appointment\n");
        printf("3. Cancel Appointment\n");
        printf("4. Exit\n");
        printf("\nEnter option (1-4): ");
        scanf(" %c", &option);
        switch(option) {
            case '1':
                printf("\n");
                printAppointments();
                break;
            case '2':
                printf("\n");
                makeAppointment();
                break;
            case '3':
                printf("\n");
                cancelAppointment();
                break;
            case '4':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option\n\n");
                break;
        }
    } while(option != '4');
    return 0;
}