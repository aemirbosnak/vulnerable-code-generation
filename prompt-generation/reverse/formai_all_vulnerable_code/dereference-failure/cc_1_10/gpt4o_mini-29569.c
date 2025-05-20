//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JsonValue {
    char *key;
    char *value;
    struct JsonValue *next;
} JsonValue;

typedef struct JsonObject {
    JsonValue *head;
} JsonObject;

// Function to initialize a new JsonObject
JsonObject* create_json_object() {
    JsonObject *obj = (JsonObject *)malloc(sizeof(JsonObject));
    obj->head = NULL;
    return obj;
}

// Function to create a new JsonValue
JsonValue* create_json_value(char *key, char *value) {
    JsonValue *new_value = (JsonValue *)malloc(sizeof(JsonValue));
    new_value->key = strdup(key);
    new_value->value = strdup(value);
    new_value->next = NULL;
    return new_value;
}

// Function to add a JsonValue to a JsonObject
void add_json_value(JsonObject *obj, char *key, char *value) {
    JsonValue *new_value = create_json_value(key, value);
    new_value->next = obj->head;
    obj->head = new_value;
}

// Function to free a JsonValue
void free_json_value(JsonValue *value) {
    free(value->key);
    free(value->value);
    free(value);
}

// Function to free a JsonObject
void free_json_object(JsonObject *obj) {
    JsonValue *current = obj->head;
    JsonValue *next;
    while (current != NULL) {
        next = current->next;
        free_json_value(current);
        current = next;
    }
    free(obj);
}

// Function to trim whitespace
char* trim_whitespace(char *str) {
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str; // All spaces
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = 0;
    return str;
}

// Function to parse a JSON string
JsonObject* parse_json(const char *json) {
    JsonObject *obj = create_json_object();
    const char *p = json;
    char key[256], value[256];
    
    while (*p) {
        // Skip whitespace
        if (isspace(*p)) {
            p++;
            continue;
        }
        
        // Expecting key
        if (*p == '\"') {
            p++;
            int i = 0;
            while (*p && *p != '\"') {
                key[i++] = *p++;
            }
            key[i] = '\0';
            if (*p == '\"') p++;
            p = trim_whitespace(p); // Trim after key
            
            // Expecting colon
            if (*p != ':') {
                printf("Invalid JSON format\n");
                free_json_object(obj);
                return NULL;
            }
            p++; // Skip colon
            p = trim_whitespace(p); // Trim after colon
            
            // Expecting value
            if (*p == '\"') {
                p++;
                i = 0;
                while (*p && *p != '\"') {
                    value[i++] = *p++;
                }
                value[i] = '\0';
                if (*p == '\"') p++;
                add_json_value(obj, trim_whitespace(key), trim_whitespace(value));
            }
        }
        
        p = trim_whitespace(p); // Trim after value
    }
    
    return obj;
}

// Function to print the JSON object
void print_json(JsonObject *obj) {
    JsonValue *current = obj->head;
    printf("{\n");
    while (current != NULL) {
        printf("  \"%s\": \"%s\",\n", current->key, current->value);
        current = current->next;
    }
    printf("}\n");
}

int main() {
    const char *json_string = "{\"name\": \"John\", \"age\": \"30\", \"city\": \"New York\"}";
    
    JsonObject *json_obj = parse_json(json_string);
    
    if (json_obj) {
        print_json(json_obj);
        free_json_object(json_obj);
    } else {
        printf("Failed to parse JSON\n");
    }
    
    return 0;
}