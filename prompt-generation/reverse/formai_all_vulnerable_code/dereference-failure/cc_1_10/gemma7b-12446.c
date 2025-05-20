//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

typedef struct Appointment {
  char name[50];
  char date[10];
  char time[10];
  struct Appointment* next;
} Appointment;

void insertAppointment(Appointment** head) {
  Appointment* newAppt = (Appointment*)malloc(sizeof(Appointment));
  printf("Enter your name: ");
  scanf("%s", newAppt->name);
  printf("Enter the date (MM/DD): ");
  scanf("%s", newAppt->date);
  printf("Enter the time (HH:MM): ");
  scanf("%s", newAppt->time);
  newAppt->next = NULL;

  if (*head == NULL) {
    *head = newAppt;
  } else {
    (*head)->next = newAppt;
  }
}

void printAppointments(Appointment* head) {
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Date: %s\n", head->date);
    printf("Time: %s\n", head->time);
    printf("\n");
    head = head->next;
  }
}

int main() {
  Appointment* head = NULL;
  int choice;

  printf("Welcome to the Appointment Scheduler!\n");

  while (1) {
    printf("1. Insert Appointment\n");
    printf("2. Print Appointments\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        insertAppointment(&head);
        break;
      case 2:
        printAppointments(head);
        break;
      default:
        printf("Invalid choice.\n");
    }

    printf("Would you like to continue? (Y/N): ");
    char cont;
    scanf(" %c", &cont);

    if (cont == 'N') {
      break;
    }
  }

  return 0;
}