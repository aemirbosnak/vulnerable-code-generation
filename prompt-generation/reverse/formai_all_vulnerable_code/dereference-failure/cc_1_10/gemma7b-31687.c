//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 10

struct Appointment {
  char name[20];
  char time[20];
  char date[20];
  struct Appointment* next;
};

void addAppointment(struct Appointment** head) {
  struct Appointment* newAppointment = (struct Appointment*)malloc(sizeof(struct Appointment));
  printf("Enter your name: ");
  scanf("%s", newAppointment->name);
  printf("Enter the time: ");
  scanf("%s", newAppointment->time);
  printf("Enter the date: ");
  scanf("%s", newAppointment->date);

  newAppointment->next = NULL;

  if (*head == NULL) {
    *head = newAppointment;
  } else {
    (*head)->next = newAppointment;
  }
}

void listAppointments(struct Appointment* head) {
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Time: %s\n", head->time);
    printf("Date: %s\n", head->date);
    printf("\n");
    head = head->next;
  }
}

int main() {
  struct Appointment* head = NULL;

  printf("Welcome to the Appointment Scheduler!\n");

  while (1) {
    printf("1. Add an appointment\n");
    printf("2. List appointments\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addAppointment(&head);
        break;
      case 2:
        listAppointments(head);
        break;
      default:
        printf("Invalid choice.\n");
    }

    printf("Would you like to continue? (Y/N): ");
    char answer;
    scanf("%c", &answer);

    if (answer == 'N') {
      break;
    }
  }

  printf("Thank you for using the Appointment Scheduler!\n");

  return 0;
}