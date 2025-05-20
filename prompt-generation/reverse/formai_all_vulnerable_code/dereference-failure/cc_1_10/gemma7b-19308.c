//Gemma-7B DATASET v1.0 Category: Error handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SURVIVORS 10

typedef struct survivor {
  char name[50];
  int age;
  struct survivor* next;
} survivor;

survivor* head = NULL;

void handle_error(char* error_message)
{
  printf("Error: %s\n", error_message);
  exit(1);
}

void add_survivor(char* name, int age)
{
  survivor* new_survivor = (survivor*)malloc(sizeof(survivor));
  if (new_survivor == NULL)
  {
    handle_error("Memory allocation failed.");
  }

  strcpy(new_survivor->name, name);
  new_survivor->age = age;
  new_survivor->next = NULL;

  if (head == NULL)
  {
    head = new_survivor;
  }
  else
  {
    survivor* tail = head;
    while (tail->next != NULL)
    {
      tail = tail->next;
    }
    tail->next = new_survivor;
  }
}

void list_survivors()
{
  survivor* current = head;
  while (current)
  {
    printf("%s (%d) ", current->name, current->age);
    current = current->next;
  }
  printf("\n");
}

int main()
{
  add_survivor("John", 25);
  add_survivor("Jane", 30);
  add_survivor("Bob", 40);

  list_survivors();

  return 0;
}