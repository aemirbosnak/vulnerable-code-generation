//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Define a structure to represent a JSON object
typedef struct json_object {
    char* key;
    char* value;
    struct json_object* next;
} JSON_Object;

// Define a function to create a new JSON object
JSON_Object* create_json_object(char* key, char* value) {
    JSON_Object* new_object = malloc(sizeof(JSON_Object));
    new_object->key = key;
    new_object->value = value;
    new_object->next = NULL;
    return new_object;
}

// Define a function to add a JSON object to a linked list of JSON objects
void add_json_object(JSON_Object** object_list, JSON_Object* new_object) {
    if (*object_list == NULL) {
        *object_list = new_object;
    } else {
        add_json_object(&((*object_list)->next), new_object);
    }
}

int main() {
    char json_string[MAX_LENGTH] = "{\"name\":\"Sherlock Holmes\",\"occupation\":\"detective\",\"address\":{\"street\":\"221B Baker Street\",\"city\":\"London\",\"country\":\"UK\"}}";
    JSON_Object* object_list = NULL;
    bool parsing_key = false;
    bool parsing_value = false;
    bool reading_string = false;
    char key[MAX_LENGTH];
    char value[MAX_LENGTH];
    int key_index = 0;
    int value_index = 0;
    int depth = 0;
    int i = 0;

    while (json_string[i] != '\0') {
        char c = json_string[i];

        // Ignore whitespace
        if (c == ' ' || c == '\n' || c == '\r' || c == '\t') {
            i++;
            continue;
        }

        if (!reading_string && c == '{') {
            depth++;
            i++;
            continue;
        } else if (!reading_string && c == '}') {
            depth--;
            if (depth == 0) {
                break;
            }
            i++;
            continue;
        } else if (!reading_string && c == ':') {
            parsing_value = true;
            i++;
            continue;
        } else if (!reading_string && c == ',') {
            parsing_key = false;
            parsing_value = false;
            add_json_object(&object_list, create_json_object(key, value));
            memset(key, 0, MAX_LENGTH);
            memset(value, 0, MAX_LENGTH);
            key_index = 0;
            value_index = 0;
            i++;
            continue;
        } else if (c == '"') {
            reading_string = !reading_string;
            i++;
            continue;
        }

        if (parsing_key) {
            key[key_index] = c;
            key_index++;
        } else if (parsing_value) {
            value[value_index] = c;
            value_index++;
        }

        i++;
    }

    // Print out the JSON object list
    JSON_Object* current_object = object_list;
    printf("{");
    while (current_object) {
        printf("\"%s\": \"%s\"", current_object->key, current_object->value);
        if (current_object->next) {
            printf(", ");
        }
        current_object = current_object->next;
    }
    printf("}");

    return 0;
}