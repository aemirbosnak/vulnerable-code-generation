//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define BUFFER_SIZE 1024

typedef struct {
  char *key;
  char *value;
} JsonPair;

typedef struct {
  int num_pairs;
  JsonPair *pairs;
} JsonObject;

char *read_file(char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    printf("Could not open file.\n");
    exit(1);
  }

  char *buffer = malloc(BUFFER_SIZE * sizeof(char));
  char ch;
  int i = 0;

  while ((ch = fgetc(file)) != EOF) {
    buffer[i] = ch;
    i++;

    if (i == BUFFER_SIZE) {
      buffer = realloc(buffer, i * 2);
    }
  }

  buffer[i] = '\0';
  fclose(file);

  return buffer;
}

void clean_string(char *str) {
  int i, j = 0;
  for (i = 0; str[i]; i++) {
    if (!isspace(str[i])) {
      str[j] = str[i];
      j++;
    }
  }
  str[j] = '\0';
}

char *get_value(char *str) {
  int start = strchr(str, ':') - str + 1;
  int end = strlen(str);

  char *value = malloc((end - start + 1) * sizeof(char));
  strncpy(value, &str[start], end - start);
  clean_string(value);

  return value;
}

char *get_key(char *str) {
  int end = strchr(str, ':') - str;
  char *key = malloc((end + 1) * sizeof(char));

  strncpy(key, str, end);
  clean_string(key);

  return key;
}

int count_pairs(char *str) {
  int count = 0;

  while (*str != '\0') {
    if (*str == ',') {
      count++;
    }
    str++;
  }

  return count + 1;
}

void parse_pair(JsonObject *object, char *str) {
  char *key = get_key(str);
  char *value = get_value(str);

  JsonPair pair = {key, value};
  object->pairs[object->num_pairs] = pair;
  object->num_pairs++;
}

JsonObject *parse_json(char *json_string) {
  JsonObject *object = malloc(sizeof(JsonObject));
  object->num_pairs = 0;
  object->pairs = malloc(count_pairs(json_string) * sizeof(JsonPair));

  char *token = strtok(json_string, "{}");

  while (token) {
    parse_pair(object, token);
    token = strtok(NULL, "{}");
  }

  return object;
}

void print_object(JsonObject *object) {
  int i;
  for (i = 0; i < object->num_pairs; i++) {
    printf("%s: %s\n", object->pairs[i].key, object->pairs[i].value);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s filename.json\n", argv[0]);
    exit(1);
  }

  char *json_string = read_file(argv[1]);
  JsonObject *object = parse_json(json_string);

  print_object(object);

  free(json_string);
  free(object->pairs);
  free(object);

  return SUCCESS;
}