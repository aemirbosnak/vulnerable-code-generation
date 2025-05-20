//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct JSON {
  char *key;
  char *value;
  struct JSON *next;
  struct JSON *child;
} json;

json *parse_json(char *json_string, int *index);

void display_json(json *j) {
  json *tmp = j;
  while (tmp != NULL) {
    if (tmp->key != NULL) {
      printf("%s : ", tmp->key);
    }
    if (tmp->value != NULL) {
      printf("%s\n", tmp->value);
    } else {
      printf("\n");
    }
    if (tmp->child != NULL) {
      display_json(tmp->child);
    }
    tmp = tmp->next;
  }
}

json *create_new_json() {
  json *j = (json *)malloc(sizeof(json));
  j->key = NULL;
  j->value = NULL;
  j->next = NULL;
  j->child = NULL;
  return j;
}

int is_digit(char c) { return (c >= '0' && c <= '9') ? 1 : 0; }

int is_alpha(char c) { return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? 1 : 0; }

char *get_string(char *json_string, int *index) {
  char *str = (char *)malloc(sizeof(char) * MAX);
  int i = 0;
  while (json_string[*index] != '\"') {
    str[i++] = json_string[(*index)++];
  }
  str[i] = '\0';
  (*index)++;
  return str;
}

char *get_number(char *json_string, int *index) {
  char *num = (char *)malloc(sizeof(char) * MAX);
  int i = 0;
  while (is_digit(json_string[*index])) {
    num[i++] = json_string[(*index)++];
  }
  num[i] = '\0';
  return num;
}

json *parse_key_value_pair(char *json_string, int *index) {
  char *key = get_string(json_string, index);
  json *new_json = create_new_json();
  new_json->key = key;
  (*index)++;
  char *value;
  if (json_string[*index] == '\"') {
    value = get_string(json_string, index);
  } else if (is_digit(json_string[*index])) {
    value = get_number(json_string, index);
  }
  new_json->value = value;
  return new_json;
}

json *parse_array(char *json_string, int *index) {
  json *new_json = create_new_json();
  new_json->value = NULL;
  new_json->key = NULL;
  (*index)++;
  while (json_string[*index] != ']') {
    (*index)++;
    json *tmp = parse_json(json_string, index);
    if (new_json->child == NULL) {
      new_json->child = tmp;
    } else {
      json *last = new_json->child;
      while (last->next != NULL) {
        last = last->next;
      }
      last->next = tmp;
    }
    if (json_string[*index] == ',') {
      (*index)++;
    }
  }
  (*index)++;
  return new_json;
}

json *parse_object(char *json_string, int *index) {
  json *new_json = create_new_json();
  new_json->value = NULL;
  new_json->key = NULL;
  (*index)++;
  while (json_string[*index] != '}') {
    (*index)++;
    json *tmp = parse_key_value_pair(json_string, index);
    if (new_json->child == NULL) {
      new_json->child = tmp;
    } else {
      json *last = new_json->child;
      while (last->next != NULL) {
        last = last->next;
      }
      last->next = tmp;
    }
    if (json_string[*index] == ',') {
      (*index)++;
    }
  }
  (*index)++;
  return new_json;
}

json *parse_json(char *json_string, int *index) {
  json *new_json = create_new_json();
  new_json->value = NULL;
  new_json->key = NULL;
  if (json_string[*index] == '{') {
    new_json = parse_object(json_string, index);
  } else if (json_string[*index] == '[') {
    new_json = parse_array(json_string, index);
  } else if (json_string[*index] == '\"') {
    new_json = parse_key_value_pair(json_string, index);
  } else if (is_digit(json_string[*index])) {
    char *value = get_number(json_string, index);
    new_json->value = value;
  }
  return new_json;
}

int main() {
  char *json_string = "{\"name\":\"John\", \"age\":31, \"city\":\"New York\",\"hobbies\":[\"Reading\",\"Playing Guitar\"]}";
  int index = 0;
  json *parsed_json = parse_json(json_string, &index);
  display_json(parsed_json);
  return 0;
}