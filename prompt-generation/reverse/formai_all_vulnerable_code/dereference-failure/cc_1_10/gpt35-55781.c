//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 16

int main(int argc, char *argv[]) {
  // Check if filename is provided as command line argument
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Open the file
  FILE *file = fopen(argv[1], "r");
  if (!file) {
    printf("Error: unable to open file %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  char line[MAX_LINE_LENGTH];
  int line_count = 0;
  char *field, *ptr;
  char fields[MAX_FIELDS][MAX_FIELD_LENGTH];
  int field_count = 0;

  // Read each line of the file
  while (fgets(line, sizeof(line), file)) {
    line_count++;

    // Split the line into fields
    field_count = 0;
    field = strtok(line, ",");
    while (field) {
      // Remove any leading/trailing whitespace
      while (*field == ' ')
        field++;
      ptr = field + strlen(field) - 1;
      while (*ptr == ' ')
        *ptr-- = '\0';

      // Copy the field to the fields array
      strncpy(fields[field_count], field, MAX_FIELD_LENGTH);
      field_count++;

      // Move to the next field
      field = strtok(NULL, ",");
    }

    // Print the fields
    printf("Line %d: ", line_count);
    for (int i = 0; i < field_count; i++)
      printf("%s%s", fields[i], i == field_count - 1 ? "\n" : ", ");
  }

  // Close the file
  fclose(file);

  return 0;
}