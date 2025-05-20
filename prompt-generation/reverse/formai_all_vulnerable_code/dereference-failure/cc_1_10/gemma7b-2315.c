//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Node {
  char name[20];
  struct Node* next;
  struct Node* prev;
  int hour;
  int minute;
};

struct Node* createNode(char* name, int hour, int minute) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->name, name);
  newNode->hour = hour;
  newNode->minute = minute;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void insertAtTail(struct Node* head, struct Node* newNode) {
  if (head == NULL) {
    head = newNode;
  } else {
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
  }
}

void printAppointments(struct Node* head) {
  while (head) {
    printf("%s, %d:%d\n", head->name, head->hour, head->minute);
    head = head->next;
  }
}

int findAppointment(struct Node* head, char* name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      return 1;
    } else {
      head = head->next;
    }
  }
  return 0;
}

int main() {
  struct Node* head = NULL;
  struct Node* newNode1 = createNode("John Doe", 10, 30);
  insertAtTail(head, newNode1);
  struct Node* newNode2 = createNode("Jane Doe", 12, 00);
  insertAtTail(head, newNode2);
  struct Node* newNode3 = createNode("Peter Pan", 14, 00);
  insertAtTail(head, newNode3);

  printAppointments(head);

  if (findAppointment(head, "John Doe")) {
    printf("John Doe's appointment found.\n");
  } else {
    printf("John Doe's appointment not found.\n");
  }

  return 0;
}