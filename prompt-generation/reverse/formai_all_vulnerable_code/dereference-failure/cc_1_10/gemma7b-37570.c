//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

char shell_prompt[] = "$ ";

void parse_command(char **cmd) {
  *cmd = malloc(MAX_CMD_LEN);
  printf("%s", shell_prompt);
  fgets(*cmd, MAX_CMD_LEN, stdin);
  *cmd = realloc(*cmd, strlen(*cmd) + 1);
}

void execute_command(char *cmd) {
  FILE *fp;
  char **argv;
  int i;

  argv = malloc(MAX_CMD_LEN);
  i = 0;
  while (cmd[i] != '\0') {
    argv[i] = cmd[i];
    i++;
  }
  argv[i] = NULL;

  fp = popen(argv[0], "r");
  if (fp == NULL) {
    perror("Error opening pipe");
  } else {
    char buf[1024];
    while (fgets(buf, 1024, fp) != NULL) {
      printf("%s", buf);
    }
    pclose(fp);
  }

  free(argv);
  free(cmd);
}

int main() {
  char *cmd;

  while (1) {
    parse_command(&cmd);
    execute_command(cmd);
  }

  return 0;
}