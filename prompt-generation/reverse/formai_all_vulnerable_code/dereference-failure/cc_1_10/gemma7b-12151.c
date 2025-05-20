//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonValue {
    union {
        int number;
        double decimal;
        char *string;
        struct JsonArray *array;
        struct JsonObject *object;
    } value;
    struct JsonValue *next;
} JsonValue;

struct JsonArray {
    struct JsonValue **values;
    int size;
    int capacity;
    struct JsonArray *next;
};

struct JsonObject {
    struct JsonValue **values;
    char *key;
    int size;
    int capacity;
    struct JsonObject *next;
};

JsonValue *parseJson(char *jsonStr) {
    // Allocate and initialize the JSON value
    JsonValue *root = malloc(sizeof(JsonValue));
    root->next = NULL;

    // Parse the JSON string
    char *ptr = jsonStr;
    while (*ptr) {
        // Handle quotes and strings
        if (*ptr == '"') {
            // Allocate and store the string value
            JsonValue *stringValue = malloc(sizeof(JsonValue));
            stringValue->value.string = strdup(ptr + 1);
            stringValue->next = root;
            root = stringValue;
        }

        // Handle numbers
        else if (isdigit(*ptr)) {
            // Allocate and store the number value
            JsonValue *numberValue = malloc(sizeof(JsonValue));
            numberValue->value.number = atoi(ptr);
            numberValue->next = root;
            root = numberValue;
        }

        // Handle braces and commas
        else if (*ptr == '{' || *ptr == '}') {
            // Allocate and store the object or array value
            JsonValue *objectValue = malloc(sizeof(JsonValue));
            objectValue->value.object = malloc(sizeof(struct JsonObject));
            objectValue->next = root;
            root = objectValue;
        }

        ptr++;
    }

    return root;
}

int main() {
    char jsonStr[] = "{ 'name': 'John Doe', 'age': 30 }";
    JsonValue *root = parseJson(jsonStr);

    // Print the JSON data
    printf("Name: %s\n", root->value.object->values[0]->value.string);
    printf("Age: %d\n", root->value.object->values[1]->value.number);

    return 0;
}