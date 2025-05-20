//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom type to represent the JSON object
typedef struct {
    char *key;
    char *value;
} JSONObject;

// Define a custom type to represent the JSON array
typedef struct {
    int length;
    JSONObject *elements;
} JSONArray;

// Define a custom function to parse a JSON object
JSONObject* parse_object(char *json_string) {
    JSONObject *object = malloc(sizeof(JSONObject));
    char *key = strtok(json_string, ":");
    char *value = strtok(NULL, ",");
    object->key = strdup(key);
    object->value = strdup(value);
    printf("Parsed object: { %s: %s }\n", object->key, object->value);
    return object;
}

// Define a custom function to parse a JSON array
JSONArray* parse_array(char *json_string) {
    JSONArray *array = malloc(sizeof(JSONArray));
    char *element = strtok(json_string, ",");
    int length = 0;
    while (element != NULL) {
        length++;
        element = strtok(NULL, ",");
    }
    array->length = length;
    array->elements = malloc(length * sizeof(JSONObject));
    element = strtok(json_string, ",");
    int i = 0;
    while (element != NULL) {
        array->elements[i++] = *parse_object(element);
        element = strtok(NULL, ",");
    }
    printf("Parsed array with length %d\n", array->length);
    return array;
}

int main() {
    printf("Hello! I am a cheerful JSON parser.\n");
    printf("Please enter a JSON string to parse: ");

    char json_string[100];
    fgets(json_string, sizeof(json_string), stdin);
    json_string[strcspn(json_string, "\n")] = '\0';

    if (json_string[0] == '{') {
        printf("Detected JSON object!\n");
        JSONObject *object = parse_object(json_string);
        printf("Parsed: { %s: %s }\n", object->key, object->value);
        free(object);
    } else if (json_string[0] == '[') {
        printf("Detected JSON array!\n");
        JSONArray *array = parse_array(json_string);
        printf("Parsed array with length %d:\n", array->length);
        for (int i = 0; i < array->length; i++) {
            printf("{ %s: %s }\n", array->elements[i].key, array->elements[i].value);
        }
        free(array->elements);
        free(array);
    } else {
        printf("Invalid JSON input!\n");
    }
    printf("Thanks for using my cheerful JSON parser program!\n");
    return 0;
}