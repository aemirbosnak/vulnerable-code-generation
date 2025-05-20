//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: irregular
#include <stdio.h>
#include <string.h>

void parse_syntax(char **buffer) {
  int i = 0;
  char state = 'S';
  while (buffer[i] && state != 'E') {
    switch (state) {
      case 'S':
        if (buffer[i] == '(') {
          state = 'P';
        } else if (buffer[i] == ')') {
          state = 'E';
        } else if (buffer[i] == '"') {
          state = 'D';
        } else {
          state = 'B';
        }
        break;
      case 'P':
        if (buffer[i] == ')') {
          state = 'S';
        } else if (buffer[i] == '"') {
          state = 'D';
        } else {
          state = 'P';
        }
        break;
      case 'D':
        if (buffer[i] == '"') {
          state = 'S';
        } else {
          state = 'D';
        }
        break;
      case 'B':
        if (buffer[i] == ')') {
          state = 'E';
        } else if (buffer[i] == '"') {
          state = 'D';
        } else {
          state = 'B';
        }
        break;
    }
    i++;
  }
  state = 'E';
}

int main() {
  char buffer[] = "((a)b\"c)\n";
  parse_syntax(buffer);
  printf("Syntax parsed successfully!\n");
  return 0;
}