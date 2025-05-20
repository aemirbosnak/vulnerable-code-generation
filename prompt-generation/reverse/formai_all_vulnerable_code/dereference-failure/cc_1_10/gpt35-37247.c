//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum JsonType {
  JSON_OBJECT,
  JSON_ARRAY,
  JSON_STRING,
  JSON_NUMBER,
  JSON_TRUE,
  JSON_FALSE,
  JSON_NULL
} JsonType;

typedef struct JsonValue {
  JsonType type;
  union {
    char *string;
    double number;
    int boolean;
    struct JsonObject *object;
    struct JsonArray *array;
  } value;
} JsonValue;

typedef struct JsonPair {
  char *key;
  struct JsonValue *value;
  struct JsonPair *next;
} JsonPair;

typedef struct JsonObject {
  struct JsonPair *pairs;
} JsonObject;

typedef struct JsonArray {
  struct JsonValue **values;
  size_t size;
} JsonArray;

typedef struct JsonError {
  char *message;
  size_t line;
  size_t column;
} JsonError;

static JsonValue *parse_value(const char **, JsonError *);
static JsonPair *parse_pair(const char **, JsonError *);
static JsonValue *parse_string(const char **, JsonError *);
static JsonValue *parse_number(const char **, JsonError *);
static JsonArray *parse_array(const char **, JsonError *);
static JsonObject *parse_object(const char **, JsonError *);
static int parse_whitespace(const char **);
static int parse_char(const char **, char);
static int is_digit(char);
static int is_hex_digit(char);
static int is_whitespace(char);
static void free_pair(JsonPair *);
static void free_array(JsonArray *);
static void free_object(JsonObject *);
static void free_value(JsonValue *);
static void free_error(JsonError *);
static void print_value(JsonValue *);

int main(void) {
  const char *json = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
  JsonError *error = NULL;
  JsonValue *value = parse_value(&json, &error);
  if (value == NULL) {
    printf("Error: %s at line %lu, column %lu\n", error->message, error->line, error->column);
  } else {
    print_value(value);
    free_value(value);
  }
  return 0;
}

static JsonValue *parse_value(const char **json, JsonError *error) {
  parse_whitespace(json);
  switch (**json) {
    case '{': return (JsonValue *) parse_object(json, error);
    case '[': return (JsonValue *) parse_array(json, error);
    case '\"': return parse_string(json, error);
    case '-': return parse_number(json, error);
    default:
      if (is_digit(**json)) {
        return parse_number(json, error);
      } else if (**json == '\0') {
        error->message = "Unexpected end of input";
        error->line = 0;
        error->column = 0;
        return NULL;
      } else {
        error->message = "Invalid value";
        error->line = 0;
        error->column = 0;
        return NULL;
      }
  }
}

static JsonPair *parse_pair(const char **json, JsonError *error) {
  parse_whitespace(json);
  char *key = parse_string(json, error)->value.string;
  if (key == NULL) {
    return NULL;
  }
  parse_whitespace(json);
  if (!parse_char(json, ':')) {
    error->message = "Expected ':'";
    error->line = 0;
    error->column = 0;
    free(key);
    return NULL;
  }
  parse_whitespace(json);
  JsonValue *value = parse_value(json, error);
  if (value == NULL) {
    free(key);
    return NULL;
  }
  JsonPair *pair = malloc(sizeof(JsonPair));
  pair->key = key;
  pair->value = value;
  pair->next = NULL;
  return pair;
}

static JsonValue *parse_string(const char **json, JsonError *error) {
  if (**json != '\"') {
    error->message = "Expected '\"'";
    error->line = 0;
    error->column = 0;
    return NULL;
  }
  (*json)++;
  const char *start = *json;
  while (**json != '\"' && **json != '\0') {
    if (**json == '\\') {
      (*json)++;
    }
    (*json)++;
  }
  if (**json == '\0') {
    error->message = "Unexpected end of input";
    error->line = 0;
    error->column = 0;
    return NULL;
  }
  size_t len = *json - start;
  char *string = malloc(len + 1);
  strncpy(string, start, len);
  string[len] = '\0';
  (*json)++;
  JsonValue *value = malloc(sizeof(JsonValue));
  value->type = JSON_STRING;
  value->value.string = string;
  return value;
}

static JsonValue *parse_number(const char **json, JsonError *error) {
  const char *start = *json;
  if (**json == '-') {
    (*json)++;
  }
  if (**json == '0') {
    (*json)++;
  } else if (is_digit(**json)) {
    while (is_digit(**json)) {
      (*json)++;
    }
  } else {
    error->message = "Invalid number";
    error->line = 0;
    error->column = 0;
    return NULL;
  }
  if (**json == '.') {
    (*json)++;
    if (!is_digit(**json)) {
      error->message = "Invalid number";
      error->line = 0;
      error->column = 0;
      return NULL;
    }
    while (is_digit(**json)) {
      (*json)++;
    }
  }
  if (**json == 'e' || **json == 'E') {
    (*json)++;
    if (**json == '+' || **json == '-') {
      (*json)++;
    }
    if (!is_digit(**json)) {
      error->message = "Invalid number";
      error->line = 0;
      error->column = 0;
      return NULL;
    }
    while (is_digit(**json)) {
      (*json)++;
    }
  }
  size_t len = *json - start;
  char *string = malloc(len + 1);
  strncpy(string, start, len);
  string[len] = '\0';
  JsonValue *value = malloc(sizeof(JsonValue));
  value->type = JSON_NUMBER;
  value->value.number = strtod(string, NULL);
  free(string);
  return value;
}

static JsonArray *parse_array(const char **json, JsonError *error) {
  if (**json != '[') {
    error->message = "Expected '['";
    error->line = 0;
    error->column = 0;
    return NULL;
  }
  (*json)++;
  parse_whitespace(json);
  if (**json == ']') {
    (*json)++;
    return NULL;
  }
  JsonArray *array = malloc(sizeof(JsonArray));
  array->values = malloc(sizeof(JsonValue *));
  size_t capacity = 1;
  size_t size = 0;
  while (1) {
    JsonValue *value = parse_value(json, error);
    if (value == NULL) {
      free_array(array);
      return NULL;
    }
    if (size == capacity) {
      capacity *= 2;
      array->values = realloc(array->values, capacity * sizeof(JsonValue *));
    }
    array->values[size++] = value;
    parse_whitespace(json);
    if (**json == ']') {
      (*json)++;
      array->size = size;
      array->values = realloc(array->values, size * sizeof(JsonValue *));
      return array;
    }
    if (!parse_char(json, ',')) {
      error->message = "Expected ','";
      error->line = 0;
      error->column = 0;
      free_array(array);
      return NULL;
    }
    parse_whitespace(json);
  }
}

static JsonObject *parse_object(const char **json, JsonError *error) {
  if (**json != '{') {
    error->message = "Expected '{'";
    error->line = 0;
    error->column = 0;
    return NULL;
  }
  (*json)++;
  parse_whitespace(json);
  if (**json == '}') {
    (*json)++;
    return NULL;
  }
  JsonObject *object = malloc(sizeof(JsonObject));
  object->pairs = NULL;
  while (1) {
    JsonPair *pair = parse_pair(json, error);
    if (pair == NULL) {
      free_object(object);
      return NULL;
    }
    if (object->pairs == NULL) {
      object->pairs = pair;
    } else {
      JsonPair *last_pair = object->pairs;
      while (last_pair->next != NULL) {
        last_pair = last_pair->next;
      }
      last_pair->next = pair;
    }
    parse_whitespace(json);
    if (**json == '}') {
      (*json)++;
      return object;
    }
    if (!parse_char(json, ',')) {
      error->message = "Expected ','";
      error->line = 0;
      error->column = 0;
      free_object(object);
      return NULL;
    }
    parse_whitespace(json);
  }
}

static int parse_whitespace(const char **json) {
  int consumed = 0;
  while (is_whitespace(**json)) {
    (*json)++;
    consumed++;
  }
  return consumed;
}

static int parse_char(const char **json, char c) {
  if (**json == c) {
    (*json)++;
    return 1;
  } else {
    return 0;
  }
}

static int is_digit(char c) {
  return c >= '0' && c <= '9';
}

static int is_hex_digit(char c) {
  return is_digit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

static int is_whitespace(char c) {
  return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

static void free_pair(JsonPair *pair) {
  free(pair->key);
  free_value(pair->value);
  free(pair);
}

static void free_array(JsonArray *array) {
  for (size_t i = 0; i < array->size; i++) {
    free_value(array->values[i]);
  }
  free(array->values);
  free(array);
}

static void free_object(JsonObject *object) {
  JsonPair *pair = object->pairs;
  while (pair != NULL) {
    JsonPair *next_pair = pair->next;
    free_pair(pair);
    pair = next_pair;
  }
  free(object);
}

static void free_value(JsonValue *value) {
  switch (value->type) {
    case JSON_STRING:
      free(value->value.string);
      break;
    case JSON_OBJECT:
      free_object(value->value.object);
      break;
    case JSON_ARRAY:
      free_array(value->value.array);
      break;
    default:
      break;
  }
  free(value);
}

static void free_error(JsonError *error) {
  free(error->message);
  free(error);
}

static void print_value(JsonValue *value) {
  switch (value->type) {
    case JSON_TRUE:
      printf("true");
      break;
    case JSON_FALSE:
      printf("false");
      break;
    case JSON_NULL:
      printf("null");
      break;
    case JSON_STRING:
      printf("\"%s\"", value->value.string);
      break;
    case JSON_NUMBER:
      printf("%g", value->value.number);
      break;
    case JSON_ARRAY:
      printf("[");
      for (size_t i = 0; i < value->value.array->size; i++) {
        if (i > 0) {
          printf(", ");
        }
        print_value(value->value.array->values[i]);
      }
      printf("]");
      break;
    case JSON_OBJECT:
      printf("{");
      JsonPair *pair = value->value.object->pairs;
      while (pair != NULL) {
        printf("\"%s\": ", pair->key);
        print_value(pair->value);
        pair = pair->next;
        if (pair != NULL) {
          printf(", ");
        }
      }
      printf("}");
      break;
  }
}