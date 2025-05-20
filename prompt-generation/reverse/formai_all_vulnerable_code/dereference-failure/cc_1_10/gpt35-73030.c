//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: imaginative
/* Program to parse a JSON string */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct json_object {
    char* key;
    char* value;
    struct json_object* next;
} json_object;

/* helper function to append a JSON object to the list */
void append_object(json_object** object_list, json_object* new_object) {
    if (*object_list == NULL) {
        *object_list = new_object;
    } else {
        json_object* curr_object = *object_list;
        while (curr_object->next != NULL) {
            curr_object = curr_object->next;
        }
        curr_object->next = new_object;
    }
}

/* function to parse a JSON string */
json_object* parse_json(char* json_str) {
    json_object* object_list = NULL;
    char* key = NULL;
    char* value = NULL;
    char c;
    int i = 0;
    int is_key = 0;
    int is_value = 0;
    int is_string = 0;
    while ((c = json_str[i++]) != '\0') {
        if (c == '{') {
            is_key = 1;
            is_value = 0;
        } else if (c == '}') {
            is_key = 0;
            is_value = 0;
            key = NULL;
            value = NULL;
        } else if (c == ':') {
            is_key = 0;
            is_value = 1;
        } else if (c == '"') {
            if (key == NULL) {
                is_key = 1;
                key = (char*) malloc(sizeof(char) * 256);
            } else {
                is_key = 0;
                is_value = 1;
                value = (char*) malloc(sizeof(char) * 256);
            }
            is_string = !is_string;
        } else if (c == ',') {
            is_key = 1;
            is_value = 0;
            json_object* new_object = (json_object*) malloc(sizeof(json_object));
            new_object->key = key;
            new_object->value = value;
            new_object->next = NULL;
            append_object(&object_list, new_object);
            key = NULL;
            value = NULL;
        } else {
            if (is_string) {
                if (is_key) {
                    strncat(key, &c, 1);
                } else if (is_value) {
                    strncat(value, &c, 1);
                }
            }
        }
    }
    return object_list;
}

int main() {
    char* json_str = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";
    json_object* object_list = parse_json(json_str);
    while (object_list != NULL) {
        printf("%s: %s\n", object_list->key, object_list->value);
        json_object* temp = object_list;
        object_list = object_list->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
    return 0;
}