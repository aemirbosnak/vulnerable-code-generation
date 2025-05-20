//Gemma-7B DATASET v1.0 Category: System administration ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

typedef struct CmdNode {
  char *cmd;
  struct CmdNode *next;
} CmdNode;

CmdNode *cmd_create(char *cmd)
{
  CmdNode *new_node = malloc(sizeof(CmdNode));
  new_node->cmd = strdup(cmd);
  new_node->next = NULL;
  return new_node;
}

void cmd_add(CmdNode **head, char *cmd)
{
  CmdNode *new_node = cmd_create(cmd);
  if (*head == NULL) {
    *head = new_node;
  } else {
    (*head)->next = new_node;
  }
}

int main()
{
  CmdNode *commands = NULL;
  char cmd_buffer[MAX_CMD_LEN];

  printf("Enter a command: ");
  fgets(cmd_buffer, MAX_CMD_LEN, stdin);

  // Parse the command and add it to the list
  char *cmd = strtok(cmd_buffer, " ");
  while (cmd) {
    cmd_add(&commands, cmd);
    cmd = strtok(NULL, " ");
  }

  // Print the list of commands
  printf("List of commands:\n");
  for (CmdNode *curr = commands; curr; curr = curr->next) {
    printf("%s\n", curr->cmd);
  }

  return 0;
}