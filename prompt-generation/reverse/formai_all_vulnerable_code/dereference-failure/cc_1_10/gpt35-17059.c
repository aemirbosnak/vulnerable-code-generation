//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  JSON_TYPE_NULL,
  JSON_TYPE_BOOLEAN,
  JSON_TYPE_NUMBER,
  JSON_TYPE_STRING,
  JSON_TYPE_OBJECT,
  JSON_TYPE_ARRAY
} JSONType;

typedef struct JSONValue JSONValue;
typedef struct JSONPair JSONPair;
typedef struct JSONArray JSONArray;
typedef struct JSONObject JSONObject;

struct JSONValue {
  JSONType type;
  union {
    int boolean;
    double number;
    char* string;
    JSONObject* object;
    JSONArray* array;
  } data;
};

struct JSONPair {
  char* key;
  JSONValue* value;
};

struct JSONArray {
  JSONValue** elements;
  int size;
};

struct JSONObject {
  JSONPair** pairs;
  int size;
};

JSONPair* parse_json_pair(const char* json, int* i);
JSONValue* parse_json_value(const char* json, int* i);
JSONArray* parse_json_array(const char* json, int* i);
JSONObject* parse_json_object(const char* json, int* i);

JSONValue* parse_json(const char* json) {
  int i = 0;
  JSONValue* value = parse_json_value(json, &i);
  if (json[i] != '\0') {
    fprintf(stderr, "Unexpected character: %c\n", json[i]);
    exit(EXIT_FAILURE);
  }
  return value;
}

JSONPair* parse_json_pair(const char* json, int* i) {
  char key[1024];
  int j = 0;
  while (json[*i] != '\"') {
    key[j] = json[*i];
    j++;
    (*i)++;
  }
  key[j] = '\0';
  (*i)++;

  if (json[*i] != ':') {
    fprintf(stderr, "Expected ':' after key\n");
    exit(EXIT_FAILURE);
  }
  (*i)++;

  JSONValue* value = parse_json_value(json, i);

  JSONPair* pair = malloc(sizeof(JSONPair));
  pair->key = strdup(key);
  pair->value = value;
  return pair;
}

JSONValue* parse_json_value(const char* json, int* i) {
  switch (json[*i]) {
    case 'n':
      (*i) += 4;
      return malloc(sizeof(JSONValue));  // null
    case 't':
      (*i) += 4;
      JSONValue* true_value = malloc(sizeof(JSONValue));
      true_value->type = JSON_TYPE_BOOLEAN;
      true_value->data.boolean = 1;
      return true_value;
    case 'f':
      (*i) += 5;
      JSONValue* false_value = malloc(sizeof(JSONValue));
      false_value->type = JSON_TYPE_BOOLEAN;
      false_value->data.boolean = 0;
      return false_value;
    case '\"':
      (*i)++;
      char* string = malloc(1024);
      int j = 0;
      while (json[*i] != '\"') {
        string[j] = json[*i];
        j++;
        (*i)++;
      }
      string[j] = '\0';
      (*i)++;
      JSONValue* string_value = malloc(sizeof(JSONValue));
      string_value->type = JSON_TYPE_STRING;
      string_value->data.string = string;
      return string_value;
    case '[':
      (*i)++;
      return parse_json_array(json, i);
    case '{':
      (*i)++;
      return parse_json_object(json, i);
    default:
      if (json[*i] >= '0' && json[*i] <= '9') {
        char number[1024];
        int j = 0;
        while ((json[*i] >= '0' && json[*i] <= '9') || json[*i] == '.') {
          number[j] = json[*i];
          j++;
          (*i)++;
        }
        number[j] = '\0';
        JSONValue* number_value = malloc(sizeof(JSONValue));
        number_value->type = JSON_TYPE_NUMBER;
        number_value->data.number = strtod(number, NULL);
        return number_value;
      } else {
        fprintf(stderr, "Unexpected character: %c\n", json[*i]);
        exit(EXIT_FAILURE);
      }
  }
}

JSONArray* parse_json_array(const char* json, int* i) {
  JSONArray* array = malloc(sizeof(JSONArray));
  array->size = 0;
  array->elements = NULL;
  while (json[*i] != ']') {
    JSONValue* value = parse_json_value(json, i);
    array->size++;
    array->elements = realloc(array->elements, array->size * sizeof(JSONValue*));
    array->elements[array->size - 1] = value;
    if (json[*i] == ',') (*i)++;
  }
  (*i)++;
  return array;
}

JSONObject* parse_json_object(const char* json, int* i) {
  JSONObject* object = malloc(sizeof(JSONObject));
  object->size = 0;
  object->pairs = NULL;
  while (json[*i] != '}') {
    JSONPair* pair = parse_json_pair(json, i);
    object->size++;
    object->pairs = realloc(object->pairs, object->size * sizeof(JSONPair*));
    object->pairs[object->size - 1] = pair;
    if (json[*i] == ',') (*i)++;
  }
  (*i)++;
  return object;
}

int main() {
  const char* json = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
  JSONValue* value = parse_json(json);
  if (value->type != JSON_TYPE_OBJECT) {
    fprintf(stderr, "Expected object\n");
    exit(EXIT_FAILURE);
  }
  JSONObject* object = value->data.object;
  for (int i = 0; i < object->size; i++) {
    JSONPair* pair = object->pairs[i];
    printf("%s: ", pair->key);
    JSONValue* value = pair->value;
    switch (value->type) {
      case JSON_TYPE_NULL:
        printf("null\n");
        break;
      case JSON_TYPE_BOOLEAN:
        printf("%s\n", value->data.boolean ? "true" : "false");
        break;
      case JSON_TYPE_NUMBER:
        printf("%lf\n", value->data.number);
        break;
      case JSON_TYPE_STRING:
        printf("%s\n", value->data.string);
        break;
      case JSON_TYPE_OBJECT:
        printf("object\n");
        break;
      case JSON_TYPE_ARRAY:
        printf("array\n");
        break;
    }
  }
}