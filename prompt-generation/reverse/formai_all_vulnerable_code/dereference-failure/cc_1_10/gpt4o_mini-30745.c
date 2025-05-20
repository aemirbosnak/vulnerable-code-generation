//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct JsonValue {
    char *key;
    char *value;
    struct JsonValue *next;
} JsonValue;

typedef struct JsonObject {
    JsonValue *head;
} JsonObject;

// Function to create a new JsonValue
JsonValue* create_json_value(const char *key, const char *value) {
    JsonValue *new_value = (JsonValue *)malloc(sizeof(JsonValue));
    new_value->key = strdup(key);
    new_value->value = strdup(value);
    new_value->next = NULL;
    return new_value;
}

// Function to initialize a JsonObject
JsonObject* init_json_object() {
    JsonObject *obj = (JsonObject *)malloc(sizeof(JsonObject));
    obj->head = NULL;
    return obj;
}

// Function to add a key-value pair to the JsonObject
void add_json_value(JsonObject *obj, const char *key, const char *value) {
    JsonValue *new_value = create_json_value(key, value);
    new_value->next = obj->head;
    obj->head = new_value;
}

// Function to print the JsonObject
void print_json_object(JsonObject *obj) {
    JsonValue *current = obj->head;
    printf("{\n");
    while (current != NULL) {
        printf("  \"%s\": \"%s\"", current->key, current->value);
        current = current->next;
        if (current != NULL) {
            printf(",\n");
        }
    }
    printf("\n}\n");
}

// Function to free the memory of JsonObject
void free_json_object(JsonObject *obj) {
    JsonValue *current = obj->head;
    JsonValue *tmp;
    while (current != NULL) {
        tmp = current;
        current = current->next;
        free(tmp->key);
        free(tmp->value);
        free(tmp);
    }
    free(obj);
}

// Function to parse a simple JSON-like string
JsonObject* parse_json(const char *input) {
    JsonObject *obj = init_json_object();
    char *input_copy = strdup(input);
    char *token = strtok(input_copy, ",");
    
    while (token != NULL) {
        char *key_value = strtok(token, ":");
        char *key = strtok(key_value, "\"");
        char *value = strtok(NULL, "\"");
        add_json_value(obj, key, value);
        
        token = strtok(NULL, ",");
    }
    
    free(input_copy);
    return obj;
}

// Driver function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s '<json-string>'\n", argv[0]);
        return EXIT_FAILURE;
    }

    JsonObject *json_obj = parse_json(argv[1]);
    if (json_obj) {
        print_json_object(json_obj);
        free_json_object(json_obj);
    } else {
        fprintf(stderr, "Failed to parse JSON.\n");
    }

    return EXIT_SUCCESS;
}