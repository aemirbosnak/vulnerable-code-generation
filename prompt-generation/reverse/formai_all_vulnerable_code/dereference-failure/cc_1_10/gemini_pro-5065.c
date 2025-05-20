//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: funny
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

json_object *json_parse(char *json) {
    json_object *obj = malloc(sizeof(json_object));
    obj->pairs = NULL;
    obj->num_pairs = 0;

    char *start = json;
    while (*start != '\0') {
        // Skip whitespace
        while (*start == ' ' || *start == '\n' || *start == '\r' || *start == '\t') {
            start++;
        }

        // If we're at the end of the string, we're done
        if (*start == '\0') {
            break;
        }

        // Parse the key
        char *key = start;
        while (*start != ':' && *start != '\0') {
            start++;
        }
        if (*start == '\0') {
            fprintf(stderr, "Error: Unterminated key in JSON string\n");
            return NULL;
        }
        *start = '\0';
        start++;

        // Skip whitespace
        while (*start == ' ' || *start == '\n' || *start == '\r' || *start == '\t') {
            start++;
        }

        // Parse the value
        char *value = start;
        while (*start != ',' && *start != '}' && *start != '\0') {
            start++;
        }
        if (*start == '\0') {
            fprintf(stderr, "Error: Unterminated value in JSON string\n");
            return NULL;
        }
        *start = '\0';
        start++;

        // Add the key-value pair to the object
        json_pair *pair = malloc(sizeof(json_pair));
        pair->key = key;
        pair->value = value;
        obj->pairs = realloc(obj->pairs, (obj->num_pairs + 1) * sizeof(json_pair));
        obj->pairs[obj->num_pairs] = *pair;
        obj->num_pairs++;
    }

    return obj;
}

void json_free(json_object *obj) {
    for (int i = 0; i < obj->num_pairs; i++) {
        free(obj->pairs[i].key);
        free(obj->pairs[i].value);
    }
    free(obj->pairs);
    free(obj);
}

int main() {
    char *json = "{\"name\": \"John Doe\", \"age\": 30, \"occupation\": \"Software Engineer\"}";

    json_object *obj = json_parse(json);
    if (obj == NULL) {
        fprintf(stderr, "Error: Could not parse JSON string\n");
        return EXIT_FAILURE;
    }

    printf("Parsed JSON object:\n");
    for (int i = 0; i < obj->num_pairs; i++) {
        printf("  %s: %s\n", obj->pairs[i].key, obj->pairs[i].value);
    }

    json_free(obj);

    return EXIT_SUCCESS;
}