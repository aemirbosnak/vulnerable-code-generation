//Gemma-7B DATASET v1.0 Category: Password management ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 20

struct Password {
  char *name;
  char *password;
  struct Password *next;
};

void insertPassword(struct Password *head, char *name, char *password)
{
  struct Password *new_password = malloc(sizeof(struct Password));
  new_password->name = strdup(name);
  new_password->password = strdup(password);
  new_password->next = NULL;

  if (head == NULL)
  {
    head = new_password;
  }
  else
  {
    head->next = new_password;
  }
}

struct Password *searchPassword(struct Password *head, char *name)
{
  struct Password *current = head;
  while (current)
  {
    if (strcmp(current->name, name) == 0)
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

int main()
{
  struct Password *passwords = NULL;

  // Insert passwords
  insertPassword(passwords, "John Doe", "secret123");
  insertPassword(passwords, "Jane Doe", "secret456");
  insertPassword(passwords, "Alice White", "secret789");

  // Search for a password
  struct Password *found_password = searchPassword(passwords, "John Doe");

  // Print the password
  if (found_password)
  {
    printf("Password for %s: %s\n", found_password->name, found_password->password);
  }

  return 0;
}