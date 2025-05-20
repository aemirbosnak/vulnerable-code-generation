//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct Node {
  char name[20];
  struct Node* next;
};

struct Appointment {
  char name[20];
  char date[20];
  struct Appointment* next;
};

void insertNode(struct Node** head, char* name) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void insertAppointment(struct Appointment** head, char* name, char* date) {
  struct Appointment* newAppointment = (struct Appointment*)malloc(sizeof(struct Appointment));
  strcpy(newAppointment->name, name);
  strcpy(newAppointment->date, date);
  newAppointment->next = NULL;

  if (*head == NULL) {
    *head = newAppointment;
  } else {
    (*head)->next = newAppointment;
  }
}

int searchAppointment(struct Appointment* head, char* name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      return 1;
    }
    head = head->next;
  }

  return 0;
}

int main() {
  struct Node* head = NULL;
  struct Appointment* headApp = NULL;

  insertNode(&head, "John Doe");
  insertNode(&head, "Jane Doe");
  insertNode(&head, "Peter Pan");

  insertAppointment(&headApp, "John Doe", "2023-01-01");
  insertAppointment(&headApp, "Jane Doe", "2023-01-02");
  insertAppointment(&headApp, "Peter Pan", "2023-01-03");

  if (searchAppointment(headApp, "John Doe") == 1) {
    printf("John Doe has an appointment on 2023-01-01.\n");
  }

  return 0;
}