//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 10

struct csv_parser {
  FILE *fp;
  char line[MAX_LINE_LENGTH];
  char *fields[MAX_NUM_FIELDS];
  int num_fields;
};

struct csv_parser *csv_parser_init(FILE *fp) {
  struct csv_parser *parser = malloc(sizeof(struct csv_parser));
  if (!parser) {
    return NULL;
  }
  parser->fp = fp;
  parser->line[0] = '\0';
  parser->num_fields = 0;
  return parser;
}

void csv_parser_free(struct csv_parser *parser) {
  free(parser);
}

int csv_parser_next(struct csv_parser *parser) {
  int i;

  if (fgets(parser->line, MAX_LINE_LENGTH, parser->fp) == NULL) {
    return 0;
  }

  parser->num_fields = 0;
  for (i = 0; i < MAX_NUM_FIELDS; i++) {
    parser->fields[i] = NULL;
  }

  char *field = strtok(parser->line, ",");
  while (field) {
    parser->fields[parser->num_fields++] = field;
    field = strtok(NULL, ",");
  }

  return 1;
}

int main() {
  FILE *fp = fopen("input.csv", "r");
  if (!fp) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  struct csv_parser *parser = csv_parser_init(fp);
  if (!parser) {
    perror("csv_parser_init");
    return EXIT_FAILURE;
  }

  while (csv_parser_next(parser)) {
    for (int i = 0; i < parser->num_fields; i++) {
      printf("%s ", parser->fields[i]);
    }
    printf("\n");
  }

  csv_parser_free(parser);
  fclose(fp);

  return EXIT_SUCCESS;
}