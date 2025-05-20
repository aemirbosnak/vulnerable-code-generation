//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_OBJECT_LENGTH 1024

typedef enum {
  JSON_OBJECT,
  JSON_ARRAY
} json_type;

typedef struct {
  json_type type;
  char *name;
  union {
    char *string_value;
    int int_value;
    double double_value;
    struct json_object *sub_objects;
  } value;
  struct json_object *next;
} json_object;

json_object *parse_json(char *json_string);
json_object *parse_json_object(char **json_string);
json_object *parse_json_array(char **json_string);
void add_json_object(json_object **object_list, json_object *new_object);
void free_json_objects(json_object *object_list);
void print_json_object(json_object *object);

int main() {
  char json_string[MAX_JSON_OBJECT_LENGTH] = "{\"name\": \"John Smith\", \"age\": 38, \"is_married\": true, \"hobbies\": [\"reading\", \"running\"]}";

  json_object *root_object = parse_json(json_string);

  print_json_object(root_object);

  free_json_objects(root_object);

  return 0;
}

json_object *parse_json(char *json_string) {
  json_object *root_object = NULL;
  char *string_cursor = json_string;

  while (*string_cursor) {
    if (*string_cursor == '{') {
      json_object *new_object = parse_json_object(&string_cursor);
      add_json_object(&root_object, new_object);
    }
    string_cursor++;
  }

  return root_object;
}

json_object *parse_json_object(char **json_string) {
  json_object *new_object = malloc(sizeof(json_object));
  new_object->type = JSON_OBJECT;
  new_object->value.sub_objects = NULL;
  new_object->next = NULL;

  char *string_cursor = *json_string;
  while (*string_cursor) {
    if (*string_cursor == '\"') {
      char property_name[MAX_JSON_OBJECT_LENGTH] = {0};
      sscanf(string_cursor + 1, "%[^\"]\"", property_name);

      new_object->name = strdup(property_name);

      string_cursor += strlen(property_name) + 2;
    }

    if (*string_cursor == ':') {
      string_cursor++;
      if (*string_cursor == '{') {
        new_object->value.sub_objects = parse_json_object(&string_cursor);
      } else if (*string_cursor == '[') {
        new_object->value.sub_objects = parse_json_array(&string_cursor);
      } else if (*string_cursor == '\"') {
        char property_value[MAX_JSON_OBJECT_LENGTH] = {0};
        sscanf(string_cursor + 1, "%[^\"]\"", property_value);

        new_object->value.string_value = strdup(property_value);

        string_cursor += strlen(property_value) + 2;
      } else {
        char *end_ptr;
        double double_value = strtod(string_cursor, &end_ptr);
        if (end_ptr > string_cursor) {
          new_object->value.double_value = double_value;
          new_object->value.int_value = (int)double_value;
          string_cursor = end_ptr;
        }
      }
    }

    if (*string_cursor == '}') {
      string_cursor++;
      break;
    }

    string_cursor++;
  }

  *json_string = string_cursor;

  return new_object;
}

json_object *parse_json_array(char **json_string) {
  json_object *array_objects = NULL;
  json_object **head_ptr = &array_objects;

  char *string_cursor = *json_string;
  while (*string_cursor) {
    if (*string_cursor == '\"') {
      json_object *new_object = malloc(sizeof(json_object));
      new_object->type = JSON_OBJECT;
      new_object->value.sub_objects = NULL;
      new_object->next = NULL;

      char string_value[MAX_JSON_OBJECT_LENGTH] = {0};
      sscanf(string_cursor + 1, "%[^\"]\"", string_value);
      new_object->value.string_value = strdup(string_value);

      add_json_object(head_ptr, new_object);

      string_cursor += strlen(string_value) + 2;
    } else if (*string_cursor == ']') {
      string_cursor++;
      break;
    }
    string_cursor++;
  }

  *json_string = string_cursor;

  return array_objects;
}

void add_json_object(json_object **object_list, json_object *new_object) {
  if (*object_list == NULL) {
    *object_list = new_object;
  } else {
    json_object *cursor = *object_list;
    while (cursor->next) {
      cursor = cursor->next;
    }
    cursor->next = new_object;
  }
}

void free_json_objects(json_object *object_list) {
  while (object_list) {
    json_object *next_object = object_list->next;
    free(object_list->name);
    if (object_list->type == JSON_ARRAY || object_list->type == JSON_OBJECT) {
      free_json_objects(object_list->value.sub_objects);
    } else if (object_list->type == JSON_OBJECT && object_list->value.string_value) {
      free(object_list->value.string_value);
    }
    free(object_list);
    object_list = next_object;
  }
}

void print_json_object(json_object *object) {
  while (object) {
    printf("\"%s\": ", object->name);
    if (object->type == JSON_OBJECT) {
      printf("{\n");
      print_json_object(object->value.sub_objects);
      printf("}");
    } else if (object->type == JSON_ARRAY) {
      printf("[ ");
      print_json_object(object->value.sub_objects);
      printf(" ]");
    } else if (object->value.string_value) {
      printf("\"%s\"", object->value.string_value);
    } else if (object->value.double_value != 0) {
      printf("%f", object->value.double_value);
    } else {
      printf("%d", object->value.int_value);
    }
    printf(",\n");

    object = object->next;
  }
}