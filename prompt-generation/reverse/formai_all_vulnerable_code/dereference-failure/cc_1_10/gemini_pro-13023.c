//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *data;
  size_t size;
} CSVLine;

CSVLine *CSVLine_new() {
  CSVLine *line = malloc(sizeof(CSVLine));
  line->data = NULL;
  line->size = 0;
  return line;
}

void CSVLine_free(CSVLine *line) {
  if (line->data != NULL) {
    free(line->data);
  }
  free(line);
}

int CSVLine_append(CSVLine *line, char *data, size_t size) {
  if (line->size == 0) {
    line->data = malloc(size + 1);
  } else {
    line->data = realloc(line->data, line->size + size + 1);
  }
  if (line->data == NULL) {
    return -1;
  }
  memcpy(line->data + line->size, data, size);
  line->data[line->size + size] = '\0';
  line->size += size;
  return 0;
}

int CSVLine_parse(CSVLine *line, char *data, size_t size) {
  int in_quote = 0;
  int escaped = 0;
  int start = 0;
  int end = 0;
  for (size_t i = 0; i < size; i++) {
    char c = data[i];
    if (c == '"' && !escaped) {
      in_quote = !in_quote;
      continue;
    }
    if (c == ',' && !in_quote) {
      end = i;
      if (start < end) {
        CSVLine_append(line, data + start, end - start);
      }
      start = i + 1;
      continue;
    }
    if (c == '\n' && !in_quote) {
      end = i;
      if (start < end) {
        CSVLine_append(line, data + start, end - start);
      }
      return 0;
    }
    escaped = (c == '\\' && !escaped);
  }
  end = size;
  if (start < end) {
    CSVLine_append(line, data + start, end - start);
  }
  return 0;
}

int main() {
  char *data = "name,age,city\nJohn,30,New York\nJane,25,London";
  CSVLine *line = CSVLine_new();
  CSVLine_parse(line, data, strlen(data));
  for (size_t i = 0; i < line->size; i++) {
    printf("%s\n", line->data + i);
  }
  CSVLine_free(line);
  return 0;
}