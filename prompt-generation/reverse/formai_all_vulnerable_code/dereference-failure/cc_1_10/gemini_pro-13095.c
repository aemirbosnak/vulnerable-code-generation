//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the JSON types
typedef enum {
    JSON_NULL,
    JSON_BOOL,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JSON_TYPE;

// Define the JSON object
typedef struct JSON {
    JSON_TYPE type;
    union {
        int boolean;
        double number;
        char *string;
        struct JSON **array;
        int array_size;
        struct JSON **object;
        int object_size;
    } value;
} JSON;

// Create a new JSON object
JSON *json_new() {
    JSON *json = malloc(sizeof(JSON));
    json->type = JSON_NULL;
    return json;
}

// Free a JSON object
void json_free(JSON *json) {
    switch (json->type) {
        case JSON_STRING:
            free(json->value.string);
            break;
        case JSON_ARRAY:
            for (int i = 0; i < json->value.array_size; i++) {
                json_free(json->value.array[i]);
            }
            free(json->value.array);
            break;
        case JSON_OBJECT:
            for (int i = 0; i < json->value.object_size; i++) {
                json_free(json->value.object[i]);
            }
            free(json->value.object);
            break;
    }
    free(json);
}

// Parse a JSON string
JSON *json_parse(char *string) {
    JSON *json = json_new();

    // Check if the string is empty
    if (string == NULL || strlen(string) == 0) {
        return json;
    }

    // Remove leading and trailing whitespace
    while (*string == ' ' || *string == '\t' || *string == '\n' || *string == '\r') {
        string++;
    }
    while (*(string + strlen(string) - 1) == ' ' || *(string + strlen(string) - 1) == '\t' || *(string + strlen(string) - 1) == '\n' || *(string + strlen(string) - 1) == '\r') {
        *(string + strlen(string) - 1) = '\0';
    }

    // Check if the string is empty
    if (string == NULL || strlen(string) == 0) {
        return json;
    }

    // Parse the JSON string
    switch (*string) {
        case 'n':
            json->type = JSON_NULL;
            break;
        case 't':
            json->type = JSON_BOOL;
            json->value.boolean = 1;
            break;
        case 'f':
            json->type = JSON_BOOL;
            json->value.boolean = 0;
            break;
        case '"':
            json->type = JSON_STRING;
            json->value.string = strdup(string + 1);
            break;
        case '[':
            json->type = JSON_ARRAY;
            json->value.array = NULL;
            json->value.array_size = 0;
            break;
        case '{':
            json->type = JSON_OBJECT;
            json->value.object = NULL;
            json->value.object_size = 0;
            break;
    }

    // Return the JSON object
    return json;
}

// Print a JSON object
void json_print(JSON *json) {
    switch (json->type) {
        case JSON_NULL:
            printf("null");
            break;
        case JSON_BOOL:
            printf("%s", json->value.boolean ? "true" : "false");
            break;
        case JSON_NUMBER:
            printf("%f", json->value.number);
            break;
        case JSON_STRING:
            printf("\"%s\"", json->value.string);
            break;
        case JSON_ARRAY:
            printf("[");
            for (int i = 0; i < json->value.array_size; i++) {
                json_print(json->value.array[i]);
                if (i < json->value.array_size - 1) {
                    printf(",");
                }
            }
            printf("]");
            break;
        case JSON_OBJECT:
            printf("{");
            for (int i = 0; i < json->value.object_size; i++) {
                printf("\"%s\":", json->value.object[i]->value.string);
                json_print(json->value.object[i]);
                if (i < json->value.object_size - 1) {
                    printf(",");
                }
            }
            printf("}");
            break;
    }
}

int main() {
    // Create a JSON string
    char *json_string = "{\n  \"name\": \"John Doe\",\n  \"age\": 30,\n  \"occupation\": \"Software Engineer\"\n}";

    // Parse the JSON string
    JSON *json = json_parse(json_string);

    // Print the JSON object
    json_print(json);

    // Free the JSON object
    json_free(json);

    return 0;
}