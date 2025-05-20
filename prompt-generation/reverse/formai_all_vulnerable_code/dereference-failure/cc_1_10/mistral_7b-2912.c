//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_INPUT_SIZE 100

void sanitize_input(char *input) {
  int i, j;
  char temp[MAX_INPUT_SIZE];

  for (i = 0; i < strlen(input); i++) {
    if (input[i] < ' ' || input[i] > '~') {
      temp[i] = '?';
    } else {
      temp[i] = input[i];
    }
  }
  temp[strlen(input)] = '\0';
  strcpy(input, temp);

  for (i = 0; i < strlen(input); i++) {
    for (j = i + 1; j <= strlen(input); j++) {
      if (i > 0 && input[i] == input[i - 1] && input[i] != ' ') {
        input[i] = '?';
      }
      if (i < strlen(input) - 1 && input[i] == input[i + 1] && input[i] != ' ') {
        input[i + 1] = '?';
      }
    }
  }

  input[strlen(input)] = '\0';
}

int main(int argc, char *argv[]) {
  char input[MAX_INPUT_SIZE];

  if (argc != 2) {
    printf("Usage: %s <input>\n", argv[0]);
    return 1;
  }

  sanitize_input(argv[1]);
  printf("Sanitized input: %s\n", argv[1]);

  return 0;
}