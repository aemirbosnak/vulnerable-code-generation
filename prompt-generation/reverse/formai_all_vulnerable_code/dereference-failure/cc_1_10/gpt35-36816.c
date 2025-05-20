//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store appointment information
typedef struct Appointment {
    char name[50];
    char date[20];
    char time[20];
    char notes[200];
} Appointment;

// Define a linked list node to store each appointment
typedef struct ListNode {
    Appointment* appointment;
    struct ListNode* next;
} ListNode;

// Define a function to create a new appointment
Appointment* createAppointment() {
    Appointment* appointment = (Appointment*) malloc(sizeof(Appointment));
    printf("Enter name: ");
    fgets(appointment->name, 50, stdin);
    printf("Enter date (MM/DD/YYYY): ");
    fgets(appointment->date, 20, stdin);
    printf("Enter time (HH:MM AM/PM): ");
    fgets(appointment->time, 20, stdin);
    printf("Enter notes: ");
    fgets(appointment->notes, 200, stdin);
    return appointment;
}

// Define a function to print appointment details
void printAppointment(Appointment* appointment) {
    printf("Name: %s", appointment->name);
    printf("Date: %s", appointment->date);
    printf("Time: %s", appointment->time);
    printf("Notes: %s", appointment->notes);
}

// Define a function to add an appointment to the linked list
void addAppointment(ListNode** headRef, Appointment* appointment) {
    ListNode* newNode = (ListNode*) malloc(sizeof(ListNode));
    newNode->appointment = appointment;
    newNode->next = NULL;
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        ListNode* current = *headRef;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Define a function to print all appointments in the linked list
void printAppointments(ListNode* head) {
    if (head == NULL) {
        printf("No appointments scheduled.\n");
    } else {
        int count = 1;
        ListNode* current = head;
        while (current != NULL) {
            printf("Appointment %d:\n", count);
            printAppointment(current->appointment);
            printf("\n");
            current = current->next;
            count++;
        }
    }
}

// Define a function to remove an appointment from the linked list
void removeAppointment(ListNode** headRef, int index) {
    if (*headRef == NULL) {
        printf("No appointments scheduled.\n");
    } else {
        ListNode* current = *headRef;
        ListNode* previous = NULL;
        int count = 1;
        while (current != NULL && count != index) {
            previous = current;
            current = current->next;
            count++;
        }
        if (current == NULL) {
            printf("Invalid appointment index.\n");
        } else {
            if (previous == NULL) {
                *headRef = current->next;
            } else {
                previous->next = current->next;
            }
            printf("Appointment %d removed.\n", index);
        }
    }
}

// Define a function to clear all appointments from the linked list
void clearAppointments(ListNode** headRef) {
    ListNode* current = *headRef;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        free(temp->appointment);
        free(temp);
    }
    *headRef = NULL;
    printf("All appointments cleared.\n");
}

int main() {
    ListNode* head = NULL;
    char choice[50];
    while (1) {
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Remove appointment\n");
        printf("4. Clear all appointments\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        fgets(choice, 50, stdin);
        choice[strcspn(choice, "\n")] = 0; // remove trailing newline character
        if (strcmp(choice, "1") == 0) {
            Appointment* appointment = createAppointment();
            addAppointment(&head, appointment);
            printf("Appointment added.\n\n");
        } else if (strcmp(choice, "2") == 0) {
            printAppointments(head);
        } else if (strcmp(choice, "3") == 0) {
            int index;
            printf("Enter index of appointment to remove: ");
            scanf("%d", &index);
            getchar(); // remove trailing newline character
            removeAppointment(&head, index);
            printf("\n");
        } else if (strcmp(choice, "4") == 0) {
            clearAppointments(&head);
            printf("\n");
        } else if (strcmp(choice, "5") == 0) {
            clearAppointments(&head);
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice, try again.\n\n");
        }
    }
    return 0;
}