//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct json_value {
    enum {
        JSON_NULL,
        JSON_BOOL,
        JSON_NUM,
        JSON_STR,
        JSON_ARR,
        JSON_OBJ
    } type;

    union {
        int boolean;
        double number;
        char *string;
        struct json_value **array;
        size_t array_len;
        struct json_value **object;
        size_t object_len;
    } data;
} json_value;

static json_value *json_parse(const char *json) {
    json_value *value = malloc(sizeof(json_value));

    // Handle the null value
    if (!strcmp(json, "null")) {
        value->type = JSON_NULL;
        return value;
    }

    // Handle the boolean values
    if (!strcmp(json, "true")) {
        value->type = JSON_BOOL;
        value->data.boolean = 1;
        return value;
    } else if (!strcmp(json, "false")) {
        value->type = JSON_BOOL;
        value->data.boolean = 0;
        return value;
    }

    // Handle the numeric values
    char *endptr;
    value->type = JSON_NUM;
    value->data.number = strtod(json, &endptr);
    if (*endptr != '\0') {
        free(value);
        return NULL;
    }
    return value;

    // Handle the string values
    if (*json == '"') {
        value->type = JSON_STR;
        value->data.string = malloc(strlen(json) - 2);
        strncpy(value->data.string, json + 1, strlen(json) - 2);
        value->data.string[strlen(json) - 2] = '\0';
        return value;
    }

    // Handle the array values
    if (*json == '[') {
        value->type = JSON_ARR;
        value->data.array = NULL;
        value->data.array_len = 0;

        char *current_char = json + 1;
        while (*current_char != ']') {
            // Parse the array element
            json_value *element = json_parse(current_char);
            if (!element) {
                free(value);
                return NULL;
            }

            // Add the element to the array
            value->data.array = realloc(value->data.array, (value->data.array_len + 1) * sizeof(json_value *));
            value->data.array[value->data.array_len] = element;
            value->data.array_len++;

            // Advance the current character pointer past the element
            current_char += strlen(current_char) + 1;
        }

        return value;
    }

    // Handle the object values
    if (*json == '{') {
        value->type = JSON_OBJ;
        value->data.object = NULL;
        value->data.object_len = 0;

        char *current_char = json + 1;
        while (*current_char != '}') {
            // Parse the object key
            char *key = malloc(strlen(current_char));
            sscanf(current_char, "\"%[^\"]", key);
            current_char += strlen(key) + 3;

            // Parse the object value
            json_value *element = json_parse(current_char);
            if (!element) {
                free(value);
                return NULL;
            }

            // Add the element to the object
            value->data.object = realloc(value->data.object, (value->data.object_len + 1) * sizeof(json_value *));
            value->data.object[value->data.object_len] = element;
            value->data.object_len++;

            // Advance the current character pointer past the element
            current_char += strlen(current_char) + 1;
        }

        return value;
    }

    // Invalid JSON
    free(value);
    return NULL;
}

static void json_free(json_value *value) {
    switch (value->type) {
        case JSON_STR:
            free(value->data.string);
            break;
        case JSON_ARR:
            for (size_t i = 0; i < value->data.array_len; i++) {
                json_free(value->data.array[i]);
            }
            free(value->data.array);
            break;
        case JSON_OBJ:
            for (size_t i = 0; i < value->data.object_len; i++) {
                json_free(value->data.object[i]);
            }
            free(value->data.object);
            break;
    }
    free(value);
}

static void json_print(json_value *value, int indent) {
    switch (value->type) {
        case JSON_NULL:
            printf("null");
            break;
        case JSON_BOOL:
            printf("%s", value->data.boolean ? "true" : "false");
            break;
        case JSON_NUM:
            printf("%f", value->data.number);
            break;
        case JSON_STR:
            printf("\"%s\"", value->data.string);
            break;
        case JSON_ARR:
            printf("[");
            for (size_t i = 0; i < value->data.array_len; i++) {
                if (i > 0) printf(", ");
                json_print(value->data.array[i], indent + 1);
            }
            printf("]");
            break;
        case JSON_OBJ:
            printf("{");
            for (size_t i = 0; i < value->data.object_len; i++) {
                if (i > 0) printf(", ");
                printf("\"%s\": ", value->data.object[i]->data.string);
                json_print(value->data.object[i]->data.object, indent + 1);
            }
            printf("}");
            break;
    }
}

int main() {
    // Parse the JSON string
    const char *json_string = "{\"name\": \"John Doe\", \"age\": 30, \"occupation\": \"Software Engineer\"}";
    json_value *value = json_parse(json_string);

    // Print the JSON value
    printf("Original JSON:\n");
    json_print(value, 0);
    printf("\n\n");

    // Modify the JSON value
    value->data.object[0]->data.object[1]->data.number = 31;

    // Print the modified JSON value
    printf("Modified JSON:\n");
    json_print(value, 0);
    printf("\n");

    // Free the JSON value
    json_free(value);

    return 0;
}