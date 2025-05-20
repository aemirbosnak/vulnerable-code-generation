//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_DEPTH 20

typedef struct {
    char *key;
    char *value;
} json_field_t;

typedef struct {
    int num_fields;
    json_field_t *fields;
} json_object_t;

json_object_t *parse_json(char *json_str);
void free_json_object(json_object_t *obj);

// function to skip all whitespace characters in the given input string
char *skip_whitespace(char *str) {
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r') {
        str++;
    }
    return str;
}

// function to parse a JSON value from the input string, returning a new JSON object
json_object_t *parse_value(char **cursor) {
    char *start = *cursor;

    if (**cursor == '{') {
        // parse object
        *cursor = skip_whitespace(*cursor + 1);

        if (**cursor == '}') {
            // empty object
            *cursor = skip_whitespace(*cursor + 1);
            return NULL;
        }

        json_object_t *obj = malloc(sizeof(json_object_t));
        obj->num_fields = 0;
        obj->fields = NULL;

        while (**cursor != '}') {
            // parse key
            char *key_start = *cursor;
            while (**cursor != ':') {
                (*cursor)++;
            }
            **cursor = '\0';
            (*cursor)++;
            *cursor = skip_whitespace(*cursor);

            // parse value
            json_object_t *value = parse_value(cursor);

            // add field to object
            obj->num_fields++;
            obj->fields = realloc(obj->fields, obj->num_fields * sizeof(json_field_t));
            obj->fields[obj->num_fields - 1].key = strdup(key_start);
            obj->fields[obj->num_fields - 1].value = value;

            if (**cursor == ',') {
                (*cursor)++;
                *cursor = skip_whitespace(*cursor);
            }
        }

        (*cursor)++;
        *cursor = skip_whitespace(*cursor);

        return obj;
    } else if (**cursor == '"') {
        // parse string
        (*cursor)++;
        char *end = *cursor;
        while (*end != '\0' && *end != '"') {
            end++;
        }
        if (*end == '\0') {
            printf("Error: unclosed string literal\n");
            exit(1);
        }
        *end = '\0';
        (*cursor)++;
        *cursor = skip_whitespace(*cursor);

        return strdup(start + 1);
    } else if (**cursor == 't' || **cursor == 'f' || **cursor == 'n' || (**cursor >= '0' && **cursor <= '9') || **cursor == '-') {
        // parse boolean, null, or number
        char *end = *cursor;
        while (*end != '\0' && *end != ',' && *end != '}' && *end != ']' && *end != '\n' && *end != '\r') {
            end++;
        }
        char c = *end;
        *end = '\0';
        (*cursor) = skip_whitespace(*cursor);
        if (**cursor == 't' || **cursor == 'f') {
            return (**cursor == 't' ? strdup("true") : strdup("false"));
        } else if (**cursor == 'n') {
            return strdup("null");
        } else {
            return strdup(start);
        }
    } else {
        // invalid JSON value
        printf("Error: invalid JSON value\n");
        exit(1);
    }
}

json_object_t *parse_json(char *json_str) {
    // parse JSON object from string
    char *cursor = skip_whitespace(json_str);
    return parse_value(&cursor);
}

void free_json_object(json_object_t *obj) {
    if (obj != NULL) {
        for (int i = 0; i < obj->num_fields; i++) {
            free(obj->fields[i].key);
            free_json_object(obj->fields[i].value);
        }
        free(obj->fields);
        free(obj);
    }
}

int main() {
    char json_str[] = "{\n"
                      "  \"name\": \"Neo\",\n"
                      "  \"age\": 25,\n"
                      "  \"in_city\": true,\n"
                      "  \"skills\": {\n"
                      "    \"programming\": \"C\",\n"
                      "    \"combat\": \"hand-to-hand\"\n"
                      "  },\n"
                      "  \"friends\": [\n"
                      "    \"Trinity\",\n"
                      "    \"Morpheus\"\n"
                      "  ]\n"
                      "}";
    json_object_t *obj = parse_json(json_str);

    printf("Name: %s\n", (char *)obj->fields[0].value);
    printf("Age: %s\n", (char *)obj->fields[1].value);
    printf("In City: %s\n", (char *)obj->fields[2].value);
    printf("Programming Skill: %s\n", (char *)((json_object_t *)obj->fields[3].value)->fields[0].value);
    printf("Combat Skill: %s\n", (char *)((json_object_t *)obj->fields[3].value)->fields[1].value);
    printf("Friend 1: %s\n", (char *)((json_object_t *)obj->fields[4].value)->fields[0].value);
    printf("Friend 2: %s\n", (char *)((json_object_t *)obj->fields[4].value)->fields[1].value);

    free_json_object(obj);

    return 0;
}