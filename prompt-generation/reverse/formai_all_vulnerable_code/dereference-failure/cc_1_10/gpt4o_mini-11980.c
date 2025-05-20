//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1024

typedef struct JsonValue {
    char* key;
    char* value;
} JsonValue;

typedef struct JsonObject {
    JsonValue* entries;
    size_t size;
} JsonObject;

// Function prototypes
JsonObject* create_json_object();
void add_json_entry(JsonObject* obj, const char* key, const char* value);
void free_json_object(JsonObject* obj);
void print_json_object(const JsonObject* obj);
JsonObject* parse_json(const char* json_str);

int main() {
    const char* json_data = "{\"name\": \"John\", \"age\": \"30\", \"city\": \"New York\"}";
    
    JsonObject* json_obj = parse_json(json_data);
    if (json_obj) {
        print_json_object(json_obj);
        free_json_object(json_obj);
    } else {
        printf("Failed to parse JSON.\n");
    }

    return 0;
}

// Function to create a new JsonObject
JsonObject* create_json_object() {
    JsonObject* obj = (JsonObject*)malloc(sizeof(JsonObject));
    obj->size = 0;
    obj->entries = NULL;
    return obj;
}

// Function to add a key-value entry to a JsonObject
void add_json_entry(JsonObject* obj, const char* key, const char* value) {
    obj->entries = realloc(obj->entries, sizeof(JsonValue) * (obj->size + 1));
    obj->entries[obj->size].key = strdup(key);
    obj->entries[obj->size].value = strdup(value);
    obj->size++;
}

// Function to free a JsonObject
void free_json_object(JsonObject* obj) {
    for (size_t i = 0; i < obj->size; i++) {
        free(obj->entries[i].key);
        free(obj->entries[i].value);
    }
    free(obj->entries);
    free(obj);
}

// Function to print a JsonObject
void print_json_object(const JsonObject* obj) {
    printf("{\n");
    for (size_t i = 0; i < obj->size; i++) {
        printf("  \"%s\": \"%s\"", obj->entries[i].key, obj->entries[i].value);
        if (i < obj->size - 1) {
            printf(",\n");
        }
    }
    printf("\n}\n");
}

// Function to parse a JSON string into a JsonObject
JsonObject* parse_json(const char* json_str) {
    JsonObject* obj = create_json_object();
    const char* key_start;
    const char* value_start;
    const char* cursor = json_str;

    while (*cursor) {
        // Skip whitespace
        while (*cursor == ' ' || *cursor == '\n' || *cursor == '\t') cursor++;

        if (*cursor == '{') {
            cursor++; // Skip the opening brace
            continue;
        }

        // Find the key (must be in quotes)
        if (*cursor == '"') {
            key_start = ++cursor;
            while (*cursor != '"' && *cursor) cursor++;
            if (*cursor == '"') {
                size_t key_length = cursor - key_start;
                char* key = strndup(key_start, key_length);
                
                // Move cursor to the next char after closing quote
                cursor++;

                // Skip to value (must be after colon)
                while (*cursor == ' ') cursor++;
                if (*cursor == ':') cursor++;
                while (*cursor == ' ') cursor++;

                // Find the value (must be in quotes)
                if (*cursor == '"') {
                    value_start = ++cursor;
                    while (*cursor != '"' && *cursor) cursor++;
                    if (*cursor == '"') {
                        size_t value_length = cursor - value_start;
                        char* value = strndup(value_start, value_length);
                        
                        add_json_entry(obj, key, value);
                        free(key);
                        free(value);
                    }
                }
            }
        }

        // Move cursor to the next char
        cursor++;
    }

    return obj;
}