//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} json_pair;

typedef struct {
    json_pair *pairs;
    int num_pairs;
} json_object;

json_object *json_parse(char *json);
void json_free(json_object *json);
void json_print(json_object *json);

int main() {
    char *json = "{ \"name\": \"John Doe\", \"age\": 30, \"email\": \"john.doe@example.com\" }";
    json_object *object = json_parse(json);
    json_print(object);
    json_free(object);
    return 0;
}

json_object *json_parse(char *json) {
    json_object *object = malloc(sizeof(json_object));
    object->pairs = NULL;
    object->num_pairs = 0;

    char *start = json;
    while (*start != '\0') {
        // Skip whitespace
        while (*start == ' ' || *start == '\t' || *start == '\n' || *start == '\r') {
            start++;
        }

        // Check for the start of an object
        if (*start == '{') {
            start++;

            // Parse the object's pairs
            while (*start != '}') {
                // Skip whitespace
                while (*start == ' ' || *start == '\t' || *start == '\n' || *start == '\r') {
                    start++;
                }

                // Parse the key
                char *key_start = start;
                while (*start != ':' && *start != '\0') {
                    start++;
                }
                int key_length = start - key_start;
                char *key = malloc(key_length + 1);
                strncpy(key, key_start, key_length);
                key[key_length] = '\0';

                // Skip the colon
                start++;

                // Skip whitespace
                while (*start == ' ' || *start == '\t' || *start == '\n' || *start == '\r') {
                    start++;
                }

                // Parse the value
                char *value_start = start;
                while (*start != ',' && *start != '}' && *start != '\0') {
                    start++;
                }
                int value_length = start - value_start;
                char *value = malloc(value_length + 1);
                strncpy(value, value_start, value_length);
                value[value_length] = '\0';

                // Add the pair to the object
                object->pairs = realloc(object->pairs, (object->num_pairs + 1) * sizeof(json_pair));
                object->pairs[object->num_pairs].key = key;
                object->pairs[object->num_pairs].value = value;
                object->num_pairs++;

                // Skip the comma
                if (*start == ',') {
                    start++;
                }
            }

            // Skip the closing brace
            start++;
        }

        // Check for the start of an array
        else if (*start == '[') {
            // TODO: Parse the array
        }

        // Check for a string
        else if (*start == '"') {
            // TODO: Parse the string
        }

        // Check for a number
        else if (*start >= '0' && *start <= '9') {
            // TODO: Parse the number
        }

        // Check for a boolean
        else if (*start == 't' || *start == 'f') {
            // TODO: Parse the boolean
        }

        // Check for a null value
        else if (*start == 'n') {
            // TODO: Parse the null value
        }

        // Skip the value
        while (*start != ',' && *start != '}' && *start != '\0') {
            start++;
        }

        // Skip the comma
        if (*start == ',') {
            start++;
        }
    }

    return object;
}

void json_free(json_object *json) {
    for (int i = 0; i < json->num_pairs; i++) {
        free(json->pairs[i].key);
        free(json->pairs[i].value);
    }
    free(json->pairs);
    free(json);
}

void json_print(json_object *json) {
    printf("{");
    for (int i = 0; i < json->num_pairs; i++) {
        printf("\"%s\": \"%s\"", json->pairs[i].key, json->pairs[i].value);
        if (i < json->num_pairs - 1) {
            printf(",");
        }
    }
    printf("}\n");
}