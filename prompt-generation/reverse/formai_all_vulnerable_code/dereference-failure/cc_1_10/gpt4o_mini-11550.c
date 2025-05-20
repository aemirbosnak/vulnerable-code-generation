//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct JsonValue {
    char *key;
    char *value;
    struct JsonValue *next;
} JsonValue;

typedef struct JsonObject {
    JsonValue *head;
} JsonObject;

// Function Prototypes
JsonObject* create_json_object();
void add_json_entry(JsonObject *obj, const char *key, const char *value);
void free_json(JsonObject *obj);
void print_json(JsonObject *obj);
char* trim_whitespace(char *str);
bool parse_json(const char *json_str, JsonObject *obj);

// Main function
int main() {
    const char *json_str = "{ \"name\": \"John\", \"age\": \"30\", \"city\": \"New York\" }";
    
    JsonObject *json_obj = create_json_object();
    
    if (parse_json(json_str, json_obj)) {
        printf("Parsed JSON:\n");
        print_json(json_obj);
    } else {
        printf("Failed to parse JSON.\n");
    }

    free_json(json_obj);
    return 0;
}

// Create a new JSON object
JsonObject* create_json_object() {
    JsonObject *obj = (JsonObject *)malloc(sizeof(JsonObject));
    obj->head = NULL;
    return obj;
}

// Add an entry to the JSON object
void add_json_entry(JsonObject *obj, const char *key, const char *value) {
    JsonValue *new_entry = (JsonValue *)malloc(sizeof(JsonValue));
    new_entry->key = strdup(key);
    new_entry->value = strdup(value);
    new_entry->next = obj->head;
    obj->head = new_entry;
}

// Free the allocated memory for JSON object
void free_json(JsonObject *obj) {
    JsonValue *current = obj->head;
    JsonValue *next;

    while (current != NULL) {
        next = current->next;
        free(current->key);
        free(current->value);
        free(current);
        current = next;
    }
  
    free(obj);
}

// Print the JSON object
void print_json(JsonObject *obj) {
    JsonValue *current = obj->head;
    while (current != NULL) {
        printf("\"%s\": \"%s\"\n", current->key, current->value);
        current = current->next;
    }
}

// Trim whitespace from the beginning and end of a string
char* trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after the last non-space character
    *(end + 1) = '\0';

    return str;
}

// Parse the JSON string into a JsonObject
bool parse_json(const char *json_str, JsonObject *obj) {
    char *str_copy = strdup(json_str);
    char *key;
    char *value;
    char *token;

    // Extract key-value pairs from the JSON string
    token = strtok(str_copy, "{:},\"");
    while (token != NULL) {
        key = trim_whitespace(token);
        token = strtok(NULL, "{:},\"");
        if (token == NULL) {
            free(str_copy);
            return false;
        }
        value = trim_whitespace(token);
        add_json_entry(obj, key, value);
        token = strtok(NULL, "{:},\"");
    }

    free(str_copy);
    return true;
}