//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Appointments 10
#define MAX_NAME_LENGTH 20

typedef struct Appointment {
  char name[MAX_NAME_LENGTH];
  char date[MAX_NAME_LENGTH];
  char time[MAX_NAME_LENGTH];
  struct Appointment* next;
} Appointment;

void addAppointment(Appointment** head) {
  *head = malloc(sizeof(Appointment));
  (*head)->next = NULL;

  printf("Enter your name: ");
  scanf("%s", (*head)->name);

  printf("Enter the date of your appointment: ");
  scanf("%s", (*head)->date);

  printf("Enter the time of your appointment: ");
  scanf("%s", (*head)->time);

  (*head) = (*head)->next;
}

void displayAppointments(Appointment* head) {
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Date: %s\n", head->date);
    printf("Time: %s\n", head->time);
    printf("--------------------\n");
    head = head->next;
  }
}

int main() {
  Appointment* head = NULL;
  int choice;

  printf("Welcome to the Appointment Scheduler!\n");

  while (1) {
    printf("1. Add an appointment\n");
    printf("2. Display appointments\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addAppointment(&head);
        break;
      case 2:
        displayAppointments(head);
        break;
      default:
        printf("Invalid choice.\n");
    }

    printf("Would you like to continue? (Y/N) ");
    char continue_yn;
    scanf(" %c", &continue_yn);

    if (continue_yn == 'N') {
      break;
    }
  }

  return 0;
}