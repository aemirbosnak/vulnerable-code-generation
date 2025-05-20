//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CUSTOMERS 10

typedef struct customer {
  char name[20];
  int available;
  struct customer* next;
} customer;

customer* head = NULL;

void addCustomer(char* name) {
  customer* newCustomer = (customer*)malloc(sizeof(customer));
  strcpy(newCustomer->name, name);
  newCustomer->available = 1;
  newCustomer->next = NULL;

  if (head == NULL) {
    head = newCustomer;
  } else {
    head->next = newCustomer;
  }
}

void scheduleAppointment(char* customerName, int hour) {
  customer* currentCustomer = head;

  while (currentCustomer) {
    if (strcmp(currentCustomer->name, customerName) == 0) {
      if (currentCustomer->available) {
        printf("Appointment scheduled for %s at %d.\n", customerName, hour);
        currentCustomer->available = 0;
      } else {
        printf("Error: customer is not available.\n");
      }
    }
    currentCustomer = currentCustomer->next;
  }

  if (currentCustomer == NULL) {
    printf("Error: customer not found.\n");
  }
}

int main() {
  addCustomer("John Doe");
  addCustomer("Jane Doe");
  addCustomer("Peter Pan");

  scheduleAppointment("John Doe", 10);
  scheduleAppointment("Jane Doe", 12);
  scheduleAppointment("Peter Pan", 14);

  return 0;
}