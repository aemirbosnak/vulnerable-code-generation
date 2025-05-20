//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PHONE_NUMBER_LENGTH 10

typedef struct PhoneNumber {
  char *number;
  struct PhoneNumber *next;
} PhoneNumber;

PhoneNumber *insertPhoneNumber(PhoneNumber *head, char *number)
{
  PhoneNumber *newPhoneNumber = malloc(sizeof(PhoneNumber));
  newPhoneNumber->number = strdup(number);
  newPhoneNumber->next = NULL;

  if (head == NULL)
  {
    head = newPhoneNumber;
  }
  else
  {
    PhoneNumber *currentPhoneNumber = head;
    while (currentPhoneNumber->next)
    {
      currentPhoneNumber = currentPhoneNumber->next;
    }
    currentPhoneNumber->next = newPhoneNumber;
  }

  return head;
}

void printPhoneNumber(PhoneNumber *head)
{
  PhoneNumber *currentPhoneNumber = head;
  while (currentPhoneNumber)
  {
    printf("%s\n", currentPhoneNumber->number);
    currentPhoneNumber = currentPhoneNumber->next;
  }
}

int main()
{
  PhoneNumber *head = NULL;
  head = insertPhoneNumber(head, "12345");
  head = insertPhoneNumber(head, "65432");
  head = insertPhoneNumber(head, "98413");
  printPhoneNumber(head);

  return 0;
}