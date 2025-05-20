//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer;
  size_t bufsize = 32;
  size_t characters;
  int i;

  buffer = (char *)malloc(bufsize * sizeof(char));
  if (buffer == NULL) {
    perror("Unable to allocate buffer");
    exit(1);
  }

  printf("Enter a hexadecimal number: ");
  characters = getline(&buffer, &bufsize, stdin);

  if (characters == -1) {
    perror("Unable to read input");
    exit(1);
  }

  // Trim the newline character from the end of the string
  buffer[strcspn(buffer, "\n")] = 0;

  // Check if the input is a valid hexadecimal number
  for (i = 0; i < strlen(buffer); i++) {
    if (!isxdigit(buffer[i])) {
      fprintf(stderr, "Invalid hexadecimal number: %s\n", buffer);
      exit(1);
    }
  }

  // Convert the hexadecimal number to an integer
  int value = 0;
  for (i = 0; i < strlen(buffer); i++) {
    if (isdigit(buffer[i])) {
      value = value * 16 + (buffer[i] - '0');
    } else {
      value = value * 16 + (toupper(buffer[i]) - 'A' + 10);
    }
  }

  // Print the converted integer
  printf("The integer value is: %d\n", value);

  free(buffer);

  return 0;
}