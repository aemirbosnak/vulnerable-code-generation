//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1024

char *json_string;
int json_size;

void parse_json(char *json_string, int json_size) {
  int i, j;
  char *key, *value;

  for (i = 0; i < json_size; i++) {
    if (json_string[i] == '"') {
      i++;
      key = &json_string[i];

      while (json_string[i] != '"') i++;
      json_string[i] = '\0';

      i++;
      if (json_string[i] == ':') {
        i++;
        while (json_string[i] == ' ') i++;

        if (json_string[i] == '"') {
          i++;
          value = &json_string[i];

          while (json_string[i] != '"') i++;
          json_string[i] = '\0';
        } else if (json_string[i] == '{') {
          i++;
          value = &json_string[i];

          int depth = 1;
          while (depth > 0) {
            i++;
            if (json_string[i] == '{') depth++;
            else if (json_string[i] == '}') depth--;
          }
          json_string[i] = '\0';
        } else if (json_string[i] == '[') {
          i++;
          value = &json_string[i];

          int depth = 1;
          while (depth > 0) {
            i++;
            if (json_string[i] == '[') depth++;
            else if (json_string[i] == ']') depth--;
          }
          json_string[i] = '\0';
        } else {
          while (json_string[i] != ',' && json_string[i] != '}') i++;
          json_string[i] = '\0';
          value = NULL;
        }

        printf("%s: %s\n", key, value);
      }
    }
  }
}

int main() {
  json_string = malloc(MAX_JSON_SIZE);
  json_size = fread(json_string, 1, MAX_JSON_SIZE, stdin);

  parse_json(json_string, json_size);

  free(json_string);
  return 0;
}