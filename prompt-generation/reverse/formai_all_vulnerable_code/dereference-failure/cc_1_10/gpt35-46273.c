//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LEN 100
#define MAX_ARRAY_LEN 100

typedef enum {
  TYPE_NULL,
  TYPE_BOOLEAN,
  TYPE_NUMBER,
  TYPE_STRING,
  TYPE_ARRAY,
  TYPE_OBJECT
} json_type;

typedef struct json_value {
  json_type type;
  union {
    bool boolean;
    double number;
    char string[MAX_STRING_LEN];
    struct json_array {
      struct json_value *elems[MAX_ARRAY_LEN];
      int length;
    } array;
    struct json_object {
      char *keys[MAX_ARRAY_LEN];
      struct json_value *values[MAX_ARRAY_LEN];
      int length;
    } object;
  } data;
} json_value;

json_value *parse_value(char *str); // function prototype

int main() {
  char *str = "{\"name\": \"John Doe\",\n\
    \"age\": 25,\n\
    \"isStudent\": true,\n\
    \"grades\": [90, 85, 95],\n\
    \"address\": {\n\
        \"street\": \"123 Main St\",\n\
        \"city\": \"Anytown\",\n\
        \"state\": \"CA\",\n\
        \"zip\": 12345\n\
    }\n\
  }";

  json_value *json = parse_value(str);

  printf("Name: %s\n", json->data.object.values[0]->data.string);
  printf("Age: %f\n", json->data.object.values[1]->data.number);
  printf("Is Student: %d\n", json->data.object.values[2]->data.boolean);

  for (int i = 0; i < json->data.object.values[3]->data.array.length; i++) {
    printf("Grade %d: %f\n", i + 1, json->data.object.values[3]->data.array.elems[i]->data.number);
  }

  printf("Street: %s\n", json->data.object.values[4]->data.object.values[0]->data.string);
  printf("City: %s\n", json->data.object.values[4]->data.object.values[1]->data.string);
  printf("State: %s\n", json->data.object.values[4]->data.object.values[2]->data.string);
  printf("Zip: %f\n", json->data.object.values[4]->data.object.values[3]->data.number);

  return 0;
}

// JSON Parser implementation
// Recursive descent parser
json_value *parse_value(char *str) {
  char first_char = str[0];
  json_value *value = malloc(sizeof(json_value));

  if (first_char == '{') {
    value->type = TYPE_OBJECT;
    value->data.object.length = 0;
    int i = 1; // skip opening brace
    while (str[i] != '}') {
      char *key_str = strtok(str + i, "\"");
      i += strlen(key_str) + 2; // skip key string and colon
      json_value *val = parse_value(str + i);
      value->data.object.keys[value->data.object.length] = strdup(key_str);
      value->data.object.values[value->data.object.length] = val;
      value->data.object.length++;
      i += strlen(str + i) - strlen(strtok(str + i, "{}")) + 1; // skip object or comma
    }
  } else if (first_char == '[') {
    value->type = TYPE_ARRAY;
    value->data.array.length = 0;
    int i = 1; // skip opening bracket
    while (str[i] != ']') {
      json_value *val = parse_value(str + i);
      value->data.array.elems[value->data.array.length] = val;
      value->data.array.length++;
      i += strlen(str + i) - strlen(strtok(str + i, "[]")) + 1; // skip array or comma
    }
  } else if (first_char == '\"') {
    value->type = TYPE_STRING;
    char *val_str = strtok(str + 1, "\"");
    strcpy(value->data.string, val_str);
  } else if (first_char == 't' || first_char == 'f') {
    value->type = TYPE_BOOLEAN;
    value->data.boolean = first_char == 't' ? true : false;
  } else { // assume number type
    value->type = TYPE_NUMBER;
    value->data.number = atof(str);
  }

  return value;
}