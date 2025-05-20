//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  JSON_STRING,
  JSON_NUMBER,
  JSON_OBJECT,
  JSON_ARRAY,
  JSON_TRUE,
  JSON_FALSE,
  JSON_NULL
} json_type_e;

typedef struct json_value {
  json_type_e type;
  union {
    char *string;
    double number;
    struct json_object *object;
    struct json_array *array;
  } data;
} json_value_t;

typedef struct json_object {
  char *key;
  struct json_value *value;
  struct json_object *next;
} json_object_t;

typedef struct json_array {
  struct json_value *value;
  struct json_array *next;
} json_array_t;

json_value_t *parse_json(char *json_string, int *index);
json_value_t *parse_string(char *json_string, int *index);
double parse_number(char *json_string, int *index);
json_object_t *parse_object(char *json_string, int *index);
json_array_t *parse_array(char *json_string, int *index);

json_value_t *parse_json(char *json_string, int *index) {
  while (json_string[*index] != '{' && json_string[*index] != '[') {
    (*index)++;
  }
  if (json_string[*index] == '{') {
    return (json_value_t *)parse_object(json_string, index);
  } else {
    return (json_value_t *)parse_array(json_string, index);
  }
}

json_value_t *parse_string(char *json_string, int *index) {
  char *str = malloc(1024 * sizeof(char));
  int i = 0;
  while (json_string[++(*index)] != '\"') {
    if (json_string[*index] == '\\') {
      switch (json_string[++(*index)]) {
        case '\"': str[i++] = '\"'; break;
        case '\\': str[i++] = '\\'; break;
        case '/': str[i++] = '/'; break;
        case 'b': str[i++] = '\b'; break;
        case 'f': str[i++] = '\f'; break;
        case 'n': str[i++] = '\n'; break;
        case 'r': str[i++] = '\r'; break;
        case 't': str[i++] = '\t'; break;
        default: str[i++] = '\\'; str[i++] = json_string[*index];
      }
    } else {
      str[i++] = json_string[*index];
    }
  }
  str[i] = '\0';
  json_value_t *value = malloc(sizeof(json_value_t));
  value->type = JSON_STRING;
  value->data.string = str;
  return value;
}

double parse_number(char *json_string, int *index) {
  double number = 0;
  while (json_string[*index] >= '0' && json_string[*index] <= '9') {
    number = (number * 10) + (json_string[*index] - '0');
    (*index)++;
  }
  if (json_string[*index] == '.') {
    (*index)++;
    double fraction = 0.1;
    while (json_string[*index] >= '0' && json_string[*index] <= '9') {
      number += (json_string[*index] - '0') * fraction;
      fraction *= 0.1;
      (*index)++;
    }
  }
  return number;
}

json_object_t *parse_object(char *json_string, int *index) {
  json_object_t *object = NULL, *last_obj = NULL;
  (*index)++;
  while (json_string[*index] != '}') {
    json_value_t *key = parse_string(json_string, index);
    (*index)++;
    json_value_t *value = parse_json(json_string, index);
    json_object_t *new_obj = malloc(sizeof(json_object_t));
    new_obj->key = key->data.string;
    new_obj->value = value;
    new_obj->next = NULL;
    if (!object) {
      object = new_obj;
    } else {
      last_obj->next = new_obj;
    }
    last_obj = new_obj;
    if (json_string[*index] == ',') {
      (*index)++;
    } else {
      break;
    }
  }
  (*index)++;
  json_value_t *value = malloc(sizeof(json_value_t));
  value->type = JSON_OBJECT;
  value->data.object = object;
  return object;
}

json_array_t *parse_array(char *json_string, int *index) {
  json_array_t *array = NULL, *last_array = NULL;
  (*index)++;
  while (json_string[*index] != ']') {
    json_value_t *value = parse_json(json_string, index);
    json_array_t *new_array = malloc(sizeof(json_array_t));
    new_array->value = value;
    new_array->next = NULL;
    if (!array) {
      array = new_array;
    } else {
      last_array->next = new_array;
    }
    last_array = new_array;
    if (json_string[*index] == ',') {
      (*index)++;
    } else {
      break;
    }
  }
  (*index)++;
  json_value_t *value = malloc(sizeof(json_value_t));
  value->type = JSON_ARRAY;
  value->data.array = array;
  return array;
}

int main() {
  char *json_string = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";
  int index = -1;
  json_value_t *root = parse_json(json_string, &index);
  return 0;
}