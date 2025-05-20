//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Appointment {
  char name[50];
  char date[50];
  char time[50];
  struct Appointment* next;
};

void createAppointment(struct Appointment** head) {
  struct Appointment* newAppointment = (struct Appointment*)malloc(sizeof(struct Appointment));
  scanf("Enter name: ", newAppointment->name);
  scanf("Enter date: ", newAppointment->date);
  scanf("Enter time: ", newAppointment->time);
  newAppointment->next = NULL;
  if (*head == NULL) {
    *head = newAppointment;
  } else {
    (*head)->next = newAppointment;
    *head = newAppointment;
  }
}

void displayAppointments(struct Appointment* head) {
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Date: %s\n", head->date);
    printf("Time: %s\n", head->time);
    printf("\n");
    head = head->next;
  }
}

int main() {
  struct Appointment* head = NULL;
  int choice;

  while (1) {
    printf("1. Create Appointment\n");
    printf("2. Display Appointments\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        createAppointment(&head);
        break;
      case 2:
        displayAppointments(head);
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }

    printf("Do you want to continue? (Y/N): ");
    char continueChoice;
    scanf(" %c", &continueChoice);

    if (continueChoice == 'N') {
      break;
    }
  }

  return 0;
}