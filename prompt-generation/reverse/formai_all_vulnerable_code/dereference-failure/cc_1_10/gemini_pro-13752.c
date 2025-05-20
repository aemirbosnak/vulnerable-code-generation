//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct json_object {
    char *name;
    char *value;
    struct json_object *next;
} json_object;

json_object *parse_json(const char *json_string) {
    json_object *head = NULL;
    json_object *current = NULL;
    int parsing_name = 1;
    char *name_buffer = NULL;
    char *value_buffer = NULL;
    int name_buffer_size = 0;
    int value_buffer_size = 0;
    int i = 0;

    while (json_string[i] != '\0') {
        if (json_string[i] == '\"' && parsing_name) {
            if (name_buffer_size == 0) {
                name_buffer = malloc(1);
                if (name_buffer == NULL) {
                    return NULL;
                }
                name_buffer_size = 1;
            }
            name_buffer[name_buffer_size - 1] = json_string[i];
            name_buffer_size += 1;
        } else if (json_string[i] == '\"' && !parsing_name) {
            if (value_buffer_size == 0) {
                value_buffer = malloc(1);
                if (value_buffer == NULL) {
                    return NULL;
                }
                value_buffer_size = 1;
            }
            value_buffer[value_buffer_size - 1] = json_string[i];
            value_buffer_size += 1;
        } else if (json_string[i] == ':' && !parsing_name) {
            parsing_name = 1;
        } else if (json_string[i] == ',' && !parsing_name) {
            json_object *new_object = malloc(sizeof(json_object));
            if (new_object == NULL) {
                return NULL;
            }
            new_object->name = malloc(name_buffer_size);
            if (new_object->name == NULL) {
                return NULL;
            }
            memcpy(new_object->name, name_buffer, name_buffer_size);
            new_object->value = malloc(value_buffer_size);
            if (new_object->value == NULL) {
                return NULL;
            }
            memcpy(new_object->value, value_buffer, value_buffer_size);
            new_object->next = NULL;
            if (head == NULL) {
                head = new_object;
            } else {
                current->next = new_object;
            }
            current = new_object;
            name_buffer_size = 0;
            free(name_buffer);
            name_buffer = NULL;
            value_buffer_size = 0;
            free(value_buffer);
            value_buffer = NULL;
            parsing_name = 1;
        }
        i++;
    }

    return head;
}

void print_json(json_object *object) {
    while (object != NULL) {
        printf("%s: %s\n", object->name, object->value);
        object = object->next;
    }
}

int main() {
    const char *json_string = "{ \"name\": \"John Doe\", \"age\": 30, \"occupation\": \"Software Engineer\" }";
    json_object *parsed_json = parse_json(json_string);
    if (parsed_json == NULL) {
        printf("Error parsing JSON");
        return 1;
    }
    print_json(parsed_json);
    return 0;
}