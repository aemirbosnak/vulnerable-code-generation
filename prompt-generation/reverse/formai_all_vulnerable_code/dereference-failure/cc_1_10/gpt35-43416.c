//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_LINE_LENGTH 1024
#define MAX_FIELDS 20
#define DELIMITER ","

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s filename.csv\n", argv[0]);
    exit(1);
  }

  char file_path[MAX_FILE_LINE_LENGTH];
  strcpy(file_path, argv[1]);

  FILE *file_pointer = fopen(file_path, "r");
  if (!file_pointer) {
    printf("Error: Could not open file %s\n", file_path);
    exit(1);
  }

  char *line = NULL;
  size_t line_length = 0;
  ssize_t read_length;
  int line_num = 0;
  int num_fields = 0;
  char *fields[MAX_FIELDS];

  while ((read_length = getline(&line, &line_length, file_pointer)) != -1) {
    if (line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0';
    }

    char *field = strtok(line, DELIMITER);
    num_fields = 0;

    while (field != NULL) {
      if (num_fields >= MAX_FIELDS) {
        printf("Error: Line %d contains too many fields\n", line_num);
        exit(1);
      }

      fields[num_fields] = field;

      num_fields++;
      field = strtok(NULL, DELIMITER);
    }

    for (int i = 0; i < num_fields; i++) {
      printf("%s ", fields[i]);
    }
    printf("\n");

    line_num++;
  }

  if (line) {
    free(line);
  }

  fclose(file_pointer);

  return 0;
}