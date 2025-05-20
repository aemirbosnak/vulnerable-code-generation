//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_JSON_OBJECTS 10

typedef struct {
  char key[50];
  char value[200];
} JsonObject;

typedef struct {
  JsonObject objects[MAX_JSON_OBJECTS];
  int count;
} Json;

JsonObject create_object(char* key, char* value) {

  JsonObject object;
  memset(&object, 0x00, sizeof(JsonObject));

  strcpy(object.key, key);
  strcpy(object.value, value);

  return object;
}

char* trim_quotes(char* string) {

  int len = strlen(string);
  if (string[0] == '"' && string[len - 1] == '"') {

    string[len - 1] = '\0';
    string++;
  }
  return string;
}

Json parse_json(char* json_string) {
  int length = strlen(json_string);

  Json json;
  memset(&json, 0x00, sizeof(Json));

  int object_start = -1;
  int nested_level = 0;

  char key[50];
  char value[200];

  for (int i = 0; i < length; i++) {

    char c = json_string[i];

    if (c == '{') {
      nested_level++;
      if (nested_level == 1) {
        // New object encountered
        object_start = i;
      }
    }

    if (c == '}') {
      nested_level--;
      if (nested_level == 0) {
        // End of current object
        char* object_str = strndup(&json_string[object_start + 1], i - object_start - 1);

        // Split key and value
        char* separator = strchr(object_str, ':');
        strncpy(key, object_str, separator - object_str);
        strcpy(value, &object_str[strlen(key) + 1]);

        // Remove quotes if present
        trim_quotes(key);
        trim_quotes(value);

        // Add object to json
        json.objects[json.count++] = create_object(key, value);
      }
    }
  }

  return json;
}

int main() {

  char* json_string = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";

  Json json = parse_json(json_string);

  for (int i = 0; i < json.count; i++) {
    printf("Key: %s, Value: %s\n", json.objects[i].key, json.objects[i].value);
  }

  return 0;
}