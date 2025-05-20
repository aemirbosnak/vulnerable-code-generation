//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_PHONE_NUMBERS 10

typedef struct PhoneNumber {
  char name[50];
  int phone_number[10];
  struct PhoneNumber* next;
} PhoneNumber;

PhoneNumber* insertPhoneNumber(PhoneNumber* head, char* name, int phone_number) {
  PhoneNumber* new_node = (PhoneNumber*)malloc(sizeof(PhoneNumber));
  strcpy(new_node->name, name);
  for (int i = 0; i < 10; i++) {
    new_node->phone_number[i] = phone_number % 10;
    phone_number /= 10;
  }
  new_node->next = NULL;

  if (head == NULL) {
    return new_node;
  }

  head->next = new_node;
  return head;
}

void printPhoneNumbers(PhoneNumber* head) {
  while (head) {
    printf("%s: ", head->name);
    for (int i = 0; i < 10; i++) {
      printf("%d ", head->phone_number[i]);
    }
    printf("\n");
    head = head->next;
  }
}

int main() {
  PhoneNumber* head = NULL;

  insertPhoneNumber(head, "John Doe", 123456);
  insertPhoneNumber(head, "Jane Doe", 555123);
  insertPhoneNumber(head, "Jack Doe", 444321);

  printPhoneNumbers(head);

  return 0;
}