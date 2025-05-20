//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _json {
  char *key;
  char *value;
  struct _json *next;
} json;

json *json_parse(char *json_string) {
  json *head = NULL, *current = NULL;
  char *key, *value, *colon, *comma;

  while (*json_string != '\0') {
    key = json_string;
    colon = strchr(json_string, ':');
    if (colon == NULL) {
      break;
    }
    *colon = '\0';
    json_string = colon + 1;

    value = json_string;
    comma = strchr(json_string, ',');
    if (comma != NULL) {
      *comma = '\0';
      json_string = comma + 1;
    }

    if (head == NULL) {
      head = (json *)malloc(sizeof(json));
      head->key = (char *)malloc(strlen(key) + 1);
      strcpy(head->key, key);
      head->value = (char *)malloc(strlen(value) + 1);
      strcpy(head->value, value);
      head->next = NULL;
      current = head;
    } else {
      current->next = (json *)malloc(sizeof(json));
      current = current->next;
      current->key = (char *)malloc(strlen(key) + 1);
      strcpy(current->key, key);
      current->value = (char *)malloc(strlen(value) + 1);
      strcpy(current->value, value);
      current->next = NULL;
    }
  }

  return head;
}

void json_print(json *head) {
  json *current = head;

  while (current != NULL) {
    printf("%s: %s\n", current->key, current->value);
    current = current->next;
  }
}

void json_free(json *head) {
  json *current = head;

  while (current != NULL) {
    free(current->key);
    free(current->value);
    free(current);
    current = current->next;
  }
}

int main() {
  char *json_string = "{'key1':'value1','key2':'value2','key3':'value3'}";
  json *head = json_parse(json_string);
  json_print(head);
  json_free(head);
  return 0;
}