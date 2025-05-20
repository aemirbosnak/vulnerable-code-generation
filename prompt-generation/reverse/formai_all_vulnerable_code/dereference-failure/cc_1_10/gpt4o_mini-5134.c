//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { JSON_OBJECT, JSON_ARRAY, JSON_STRING, JSON_NUMBER, JSON_BOOLEAN, JSON_NULL } json_type;

typedef struct json_value {
    json_type type;
    union {
        char *string_value;
        double number_value;
        int boolean_value; // (0 for false, 1 for true)
        struct json_value *array_value; // Array elements
        struct json_value *object_value; // Key-value pairs
    };
    struct json_value *next;
} json_value;

void declareJSON(json_value *value, const char *type, const char *content) {
    if (strcmp(type, "string") == 0) {
        value->type = JSON_STRING;
        value->string_value = strdup(content);
    } else if (strcmp(type, "number") == 0) {
        value->type = JSON_NUMBER;
        value->number_value = atof(content);
    } else if (strcmp(type, "boolean") == 0) {
        value->type = JSON_BOOLEAN;
        value->boolean_value = (strcmp(content, "true") == 0) ? 1 : 0;
    } else if (strcmp(type, "null") == 0) {
        value->type = JSON_NULL;
    }
}

void printJSON(json_value *value) {
    if (!value) return;

    switch (value->type) {
        case JSON_STRING:
            printf("\"%s\"", value->string_value);
            break;
        case JSON_NUMBER:
            printf("%f", value->number_value);
            break;
        case JSON_BOOLEAN:
            printf(value->boolean_value ? "true" : "false");
            break;
        case JSON_NULL:
            printf("null");
            break;
        case JSON_OBJECT:
        case JSON_ARRAY:
            // For simplicity, we're treating objects and arrays the same
            putchar('[');
            json_value *temp = value->next;
            while (temp) {
                printJSON(temp);
                temp = temp->next;
                if (temp) putchar(',');
            }
            putchar(']');
            break;
        default:
            break;
    }
}

void freeJSON(json_value *value) {
    if (!value) return;

    if (value->type == JSON_STRING) {
        free(value->string_value);
    } else if (value->type == JSON_OBJECT || value->type == JSON_ARRAY) {
        json_value *temp = value->next;
        while (temp) {
            json_value *to_free = temp;
            temp = temp->next;
            freeJSON(to_free);
        }
    }
    free(value);
}

int main() {
    // Declare a JSON object for Romeo and Juliet
    json_value *romeo_juliet = malloc(sizeof(json_value));
    romeo_juliet->type = JSON_OBJECT;
    romeo_juliet->next = NULL;

    // Crafting Romeo's heart
    json_value *romeo = malloc(sizeof(json_value));
    declareJSON(romeo, "string", "Romeo Montague");
    
    // Crafting Juliet's heart
    json_value *juliet = malloc(sizeof(json_value));
    declareJSON(juliet, "string", "Juliet Capulet");
    
    // Add their actions
    json_value *action_1 = malloc(sizeof(json_value));
    declareJSON(action_1, "string", "loves");

    json_value *action_2 = malloc(sizeof(json_value));
    declareJSON(action_2, "string", "mourns");

    // Linking actions together to the characters
    romeo->next = action_1;
    action_1->next = juliet;
    juliet->next = action_2;

    // The grand display of JSON
    printf("In the realm of love, behold:\n");
    printJSON(romeo); // Print the JSON structure

    // Clean up the allocated memory
    freeJSON(romeo_juliet);
    
    return 0;
}