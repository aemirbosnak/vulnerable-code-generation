//Gemma-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

char shellPrompt[] = "$ ";

void parseCmd(char **cmd) {
  char *argv[MAX_CMD_LEN];
  int i = 0;
  *cmd = strdup(*cmd);
  cmd = strtok(*cmd, " ");
  while (cmd) {
    argv[i++] = cmd;
    cmd = strtok(NULL, " ");
  }
  argv[i] = NULL;
  *cmd = argv;
}

int main() {
  char cmd[MAX_CMD_LEN];
  char **cmdArgs;

  while (1) {
    printf("%s", shellPrompt);
    fgets(cmd, MAX_CMD_LEN, stdin);
    parseCmd(&cmdArgs);

    if (!strcmp(cmdArgs[0], "exit")) {
      exit(0);
    } else if (!strcmp(cmdArgs[0], "calc")) {
      double num1, num2;
      char operator;

      printf("Enter two numbers: ");
      scanf("%lf %lf", &num1, &num2);
      printf("Enter an operator (+, -, *, /): ");
      scanf(" %c", &operator);

      switch (operator) {
        case '+':
          printf("%lf + %lf = %lf\n", num1, num2, num1 + num2);
          break;
        case '-':
          printf("%lf - %lf = %lf\n", num1, num2, num1 - num2);
          break;
        case '*':
          printf("%lf * %lf = %lf\n", num1, num2, num1 * num2);
          break;
        case '/':
          if (num2 == 0) {
            printf("Cannot divide by 0!\n");
          } else {
            printf("%lf / %lf = %lf\n", num1, num2, num1 / num2);
          }
          break;
        default:
          printf("Invalid operator.\n");
      }
    } else {
      printf("Unknown command.\n");
    }
  }

  return 0;
}