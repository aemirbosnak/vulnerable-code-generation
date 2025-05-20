//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

typedef struct cmd_node {
  char *args[MAX_ARGS];
  int num_args;
  struct cmd_node *next;
} cmd_node;

cmd_node *head = NULL;
cmd_node *tail = NULL;

void add_cmd(char *line) {
  cmd_node *new_node = malloc(sizeof(cmd_node));
  new_node->num_args = 0;
  char *arg = strtok(line, " ");
  while (arg != NULL) {
    new_node->args[new_node->num_args++] = arg;
    arg = strtok(NULL, " ");
  }
  new_node->args[new_node->num_args] = NULL;
  if (head == NULL) {
    head = new_node;
    tail = new_node;
  } else {
    tail->next = new_node;
    tail = new_node;
  }
}

void execute_cmds() {
  cmd_node *current = head;
  while (current != NULL) {
    pid_t pid = fork();
    if (pid == 0) {
      execvp(current->args[0], current->args);
      perror("execvp");
      exit(EXIT_FAILURE);
    } else if (pid > 0) {
      int status;
      waitpid(pid, &status, 0);
    } else {
      perror("fork");
      exit(EXIT_FAILURE);
    }
    current = current->next;
  }
}

int main() {
  char line[MAX_LINE_LENGTH];
  while (1) {
    printf("myshell> ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    if (strcmp(line, "exit\n") == 0) {
      break;
    }
    add_cmd(line);
  }
  execute_cmds();
  return 0;
}