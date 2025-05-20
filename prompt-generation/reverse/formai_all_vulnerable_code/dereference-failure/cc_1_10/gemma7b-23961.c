//Gemma-7B DATASET v1.0 Category: System administration ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

typedef struct SystemCommand {
  char *command;
  char *arguments;
  struct SystemCommand *next;
} SystemCommand;

SystemCommand *system_command_create(char *command, char *arguments)
{
  SystemCommand *new_command = malloc(sizeof(SystemCommand));
  new_command->command = strdup(command);
  new_command->arguments = strdup(arguments);
  new_command->next = NULL;

  return new_command;
}

void system_command_add(SystemCommand *head, char *command, char *arguments)
{
  SystemCommand *new_command = system_command_create(command, arguments);

  if (head)
  {
    new_command->next = head;
  }

  head = new_command;
}

void system_command_execute(SystemCommand *head)
{
  for (SystemCommand *current = head; current; current = current->next)
  {
    printf("Command: %s, Arguments: %s\n", current->command, current->arguments);
  }
}

int main()
{
  SystemCommand *head = NULL;

  system_command_add(head, "ls", "-l");
  system_command_add(head, "pwd", "");
  system_command_add(head, "echo", "Hello, world!");

  system_command_execute(head);

  return 0;
}