//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256

char shell_prompt[] = "$ ";

void parse_command(char *command) {
  char **args = NULL;
  int num_args = 0;

  // Paranoidly strip all quotes and escape characters from the command
  char *stripped_command = strdup(command);
  char *quote_start = strstr(stripped_command, "\"");
  if (quote_start) {
    char *quote_end = strstr(quote_start, "\"");
    if (quote_end) {
      *quote_end = '\0';
    }
  }

  // Count the number of arguments
  char *arg_start = stripped_command;
  while (*arg_start) {
    args = realloc(args, (num_args + 1) * sizeof(char *));
    args[num_args++] = arg_start;
    arg_start = strchr(arg_start, ' ') + 1;
  }

  // Execute the command
  if (num_args > 0) {
    pid_t pid = fork();
    if (pid == 0) {
      execvp(args[0], args);
      _exit(1);
    } else {
      wait(NULL);
    }
  }

  free(args);
  free(stripped_command);
}

int main() {
  char command[MAX_CMD_LEN];

  // Enter the shell prompt
  printf("%s", shell_prompt);

  // Get the command
  fgets(command, MAX_CMD_LEN, stdin);

  // Parse the command
  parse_command(command);

  return 0;
}