//FormAI DATASET v1.0 Category: Error handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void handle_error(int errnum) {
  char* error = "";

  switch (errnum) {
    case 1:
      error = "File not found";
      break;
    case 2:
      error = "Permission denied";
      break;
    case 3:
      error = "Memory allocation failed";
      break;
    case 4:
      error = "Illegal argument";
      break;
    case 5:
      error = "Invalid operation";
      break;
    default:
      error = "Unknown error occurred";
      break;
  }

  printf("Error: %s\n", error);
  exit(errnum);
}

int main() {
  FILE* file = fopen("unexisting_file.txt", "r");
  if (!file) {
    handle_error(1);
  }

  char* buffer = malloc(sizeof(char) * 100);
  if (!buffer) {
    handle_error(3);
  }

  int c, i = 0;
  while ((c = fgetc(file)) != EOF && i < 100) {
    buffer[i] = (char)c;
    i++;
  }

  if (c == EOF && ferror(file)) {
    handle_error(2);
  }

  buffer[i] = '\0';
  fclose(file);

  free(buffer);

  printf("No errors detected\n");

  return 0;
}