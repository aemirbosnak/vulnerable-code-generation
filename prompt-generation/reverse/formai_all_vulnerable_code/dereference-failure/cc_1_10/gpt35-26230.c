//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1024

typedef enum {
  JSON_NULL,
  JSON_NUMBER,
  JSON_STRING,
  JSON_BOOLEAN,
  JSON_ARRAY,
  JSON_OBJECT
} json_type;

typedef struct json_object {
  json_type type;
  int size;
  union {
    double number;
    char* string;
    int boolean;
    struct json_object* array;
    struct {
      char* key;
      struct json_object* value;
    }* properties;
  };
} json_object;

/* Helper function to skip whitespace and return the next character */
char next_character(char **json) {
  char c;
  do {
    c = *(*json)++;
  } while(c == ' ' || c == '\t' || c == '\n' || c == '\r');
  return c;
}

/* Helper function to parse a string */
char* parse_string(char **json) {
  char *start = *json+1;
  char *end = start;
  while (*end != '\"' && *(end-1) != '\\') {
    end++;
  }
  char *string = malloc(end - start + 1);
  strncpy(string, start, end - start);
  string[end - start] = '\0';
  *json = end;
  return string;
}

/* Helper function to parse a number */
double parse_number(char **json) {
  char *end;
  double number = strtod(*json, &end);
  *json = end;
  return number;
}

/* Helper function to parse a boolean */
int parse_boolean(char **json) {
  char *end;
  int boolean = strtol(*json, &end, 10);
  *json = end;
  return boolean;
}

/* Helper function to parse an array */
json_object* parse_array(char **json) {
  json_object *array = malloc(sizeof(json_object));
  array->type = JSON_ARRAY;
  array->size = 0;
  array->array = NULL;
  char c = next_character(json);
  
  if (c == ']') { /* Empty array */
    return array;
  }
  
  /* Parse the first item */
  json_object *current = malloc(sizeof(json_object));
  switch (c) {
    case '{':
      current->type = JSON_OBJECT;
      current->properties = NULL; /* Not implemented */
      break;
    case '[':
      current->type = JSON_ARRAY;
      current->size = 0;
      current->array = parse_array(json);
      break;
    case '\"':
      current->type = JSON_STRING;
      current->string = parse_string(json);
      break;
    case 't':
    case 'f':
      current->type = JSON_BOOLEAN;
      current->boolean = parse_boolean(json);
      break;
    default:
      current->type = JSON_NUMBER;
      current->number = parse_number(json);
      break;
  }
  array->size++;
  array->array = realloc(array->array, sizeof(json_object) * array->size);
  array->array[0] = *current;
  free(current);
  
  /* Parse the rest of the items */
  int i = 1;
  while (c == ',') {
    current = malloc(sizeof(json_object));
    c = next_character(json);
    switch (c) {
      case '{':
        current->type = JSON_OBJECT;
        current->properties = NULL; /* Not implemented */
        break;
      case '[':
        current->type = JSON_ARRAY;
        current->size = 0;
        current->array = parse_array(json);
        break;
      case '\"':
        current->type = JSON_STRING;
        current->string = parse_string(json);
        break;
      case 't':
      case 'f':
        current->type = JSON_BOOLEAN;
        current->boolean = parse_boolean(json);
        break;
      default:
        current->type = JSON_NUMBER;
        current->number = parse_number(json);
        break;
    }
    array->size++;
    array->array = realloc(array->array, sizeof(json_object) * array->size);
    array->array[i] = *current;
    free(current);
    i++;
    c = next_character(json);
  }
  return array;
}

/* Helper function to parse a JSON object */
json_object* parse_object(char **json) {
  json_object *object = malloc(sizeof(json_object));
  object->type = JSON_OBJECT;
  object->size = 0;
  object->properties = NULL; /* Not implemented */
  char c = next_character(json);
  
  if (c == '}') { /* Empty object */
    return object;
  }
  
  /* Parse the first property */
  c = next_character(json);
  char *key = parse_string(json);
  c = next_character(json); /* Skip the colon */
  
  json_object *value = malloc(sizeof(json_object));
  switch (c) {
    case '{':
      value->type = JSON_OBJECT;
      value->properties = NULL; /* Not implemented */
      break;
    case '[':
      value->type = JSON_ARRAY;
      value->size = 0;
      value->array = parse_array(json);
      break;
    case '\"':
      value->type = JSON_STRING;
      value->string = parse_string(json);
      break;
    case 't':
    case 'f':
      value->type = JSON_BOOLEAN;
      value->boolean = parse_boolean(json);
      break;
    default:
      value->type = JSON_NUMBER;
      value->number = parse_number(json);
      break;
  }
  object->size++;
  object->properties = realloc(object->properties, sizeof(struct json_object) * object->size);
  object->properties[0].key = key;
  object->properties[0].value = value;
  
  /* Parse the rest of the properties */
  int i = 1;
  while (c == ',') {
    c = next_character(json); /* Skip the next property's whitespace */
    key = parse_string(json);
    c = next_character(json); /* Skip the colon */
    
    value = malloc(sizeof(json_object));
    switch (c) {
      case '{':
        value->type = JSON_OBJECT;
        value->properties = NULL; /* Not implemented */
        break;
      case '[':
        value->type = JSON_ARRAY;
        value->size = 0;
        value->array = parse_array(json);
        break;
      case '\"':
        value->type = JSON_STRING;
        value->string = parse_string(json);
        break;
      case 't':
      case 'f':
        value->type = JSON_BOOLEAN;
        value->boolean = parse_boolean(json);
        break;
      default:
        value->type = JSON_NUMBER;
        value->number = parse_number(json);
        break;
    }
    object->size++;
    object->properties = realloc(object->properties, sizeof(struct json_object) * object->size);
    object->properties[i].key = key;
    object->properties[i].value = value;
    i++;
    c = next_character(json);
  }
  return object;
}

/* Wrapper function to parse a JSON object or array */
json_object* parse_json(char *json) {
  char c = next_character(&json);
  json_object *object;
  switch (c) {
    case '{':
      object = parse_object(&json);
      break;
    case '[':
      object = parse_array(&json);
      break;
    default:
      printf("Error: Invalid JSON\n");
      return NULL;
  }
  return object;
}

/* Example usage */
int main() {
  char json[MAX_JSON_SIZE] = "{\"name\":\"John\",\"age\":30,\"isMarried\":true,\"hobbies\":[\"reading\",\"coding\",\"music\"]}";
  json_object *object = parse_json(json);
  
  printf("Name: %s\n", object->properties[0].value->string);
  printf("Age: %g\n", object->properties[1].value->number);
  printf("Is married? %s\n", object->properties[2].value->boolean ? "Yes" : "No");
  
  printf("Hobbies:\n");
  for (int i = 0; i < object->properties[3].value->size; i++) {
    printf("- %s\n", object->properties[3].value->array[i].string);
  }
  
  return 0;
}