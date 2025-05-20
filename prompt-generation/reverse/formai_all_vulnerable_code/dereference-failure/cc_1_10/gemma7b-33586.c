//Gemma-7B DATASET v1.0 Category: System administration ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

typedef struct Cmd {
  char **cmd_line;
  int cmd_len;
  struct Cmd *next;
} Cmd;

Cmd *create_cmd(char *cmd_line, int cmd_len) {
  Cmd *new_cmd = malloc(sizeof(Cmd));
  new_cmd->cmd_line = malloc(MAX_CMD_LEN * sizeof(char *));
  new_cmd->cmd_len = cmd_len;
  new_cmd->next = NULL;

  for (int i = 0; i < cmd_len; i++) {
    new_cmd->cmd_line[i] = malloc(MAX_CMD_LEN * sizeof(char));
  }

  return new_cmd;
}

void add_cmd(Cmd *head, char *cmd_line, int cmd_len) {
  Cmd *new_cmd = create_cmd(cmd_line, cmd_len);

  if (head == NULL) {
    head = new_cmd;
  } else {
    new_cmd->next = head;
    head = new_cmd;
  }
}

int main() {
  Cmd *head = NULL;

  char cmd_line[] = "ls -l";
  add_cmd(head, cmd_line, strlen(cmd_line));

  char cmd_line2[] = "pwd";
  add_cmd(head, cmd_line2, strlen(cmd_line2));

  char cmd_line3[] = "echo hello, world!";
  add_cmd(head, cmd_line3, strlen(cmd_line3));

  for (Cmd *cmd = head; cmd; cmd = cmd->next) {
    printf("%s\n", cmd->cmd_line[0]);
  }

  return 0;
}