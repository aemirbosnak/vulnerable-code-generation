//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Appt {
  char name[50];
  char date[50];
  char time[50];
  char type[50];
  struct Appt* next;
};

typedef struct Appt Appt;

void add_appt(Appt** head) {
  Appt* new_appt = malloc(sizeof(Appt));
  new_appt->next = NULL;

  printf("Enter your name: ");
  scanf("%s", new_appt->name);

  printf("Enter the date (dd/mm/yyyy): ");
  scanf("%s", new_appt->date);

  printf("Enter the time (hh:mm): ");
  scanf("%s", new_appt->time);

  printf("Enter the type of appointment: ");
  scanf("%s", new_appt->type);

  if (*head == NULL) {
    *head = new_appt;
  } else {
    (*head)->next = new_appt;
  }
}

void print_appts(Appt* head) {
  while (head) {
    printf("Name: %s\n", head->name);
    printf("Date: %s\n", head->date);
    printf("Time: %s\n", head->time);
    printf("Type: %s\n", head->type);
    printf("\n");
    head = head->next;
  }
}

int main() {
  Appt* head = NULL;

  while (1) {
    printf("Enter 1 to add an appointment, 2 to print appointments, or 3 to exit: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_appt(&head);
        break;
      case 2:
        print_appts(head);
        break;
      case 3:
        exit(0);
    }
  }

  return 0;
}