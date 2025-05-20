//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Define a structure for JSON object */
typedef struct json_object {
  char key[50];
  char value[50];
  struct json_object *next;
} json_object;

/* Define a function to parse JSON string */
json_object* parse_json(char* json_string) {
  /* Create a new object */
  json_object *obj = NULL;
  json_object *curr_obj = NULL;

  /* Skip whitespace */
  while (isspace(*json_string)) {
    json_string++;
  }

  /* Check for start of JSON object */
  if (*json_string == '{') {
    json_string++;
    while (*json_string != '\0' && *json_string != '}') {
      /* Skip whitespace */
      while (isspace(*json_string)) {
        json_string++;
      }

      /* Find key */
      char key[50] = "";
      int key_index = 0;
      while (*json_string != ':' && *json_string != '\0') {
        if (*json_string != '\"') {
          key[key_index++] = *json_string;
        }
        json_string++;
      }
      json_string++;

      /* Skip whitespace */
      while (isspace(*json_string)) {
        json_string++;
      }

      /* Find value */
      char value[50] = "";
      int value_index = 0;
      while (*json_string != ',' && *json_string != '}' && *json_string != '\0') {
        if (*json_string != '\"') {
          value[value_index++] = *json_string;
        }
        json_string++;
      }

      /* Add object to list */
      json_object *new_obj = (json_object*) malloc(sizeof(json_object));
      strcpy(new_obj->key, key);
      strcpy(new_obj->value, value);
      new_obj->next = NULL;

      if (obj == NULL) {
        obj = new_obj;
        curr_obj = obj;
      } else {
        curr_obj->next = new_obj;
        curr_obj = curr_obj->next;
      }

      /* Skip whitespace */
      while (isspace(*json_string)) {
        json_string++;
      }

      /* Check for end of JSON object */
      if (*json_string == '}') {
        break;
      } else {
        json_string++;
      }
    }
  }

  return obj;
}

int main() {
  char json_string[] = "{\"key1\":\"value1\",\"key2\":\"value2\",\"key3\":\"value3\"}";

  /* Parse JSON string */
  json_object *obj = parse_json(json_string);

  /* Print JSON object */
  json_object *curr_obj = obj;
  while (curr_obj != NULL) {
    printf("%s: %s\n", curr_obj->key, curr_obj->value);
    curr_obj = curr_obj->next;
  }

  return 0;
}