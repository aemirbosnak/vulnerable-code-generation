//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_LENGTH 1024
#define MAX_KEY_LENGTH 128
#define MAX_VALUE_LENGTH 512

typedef struct KeyValue {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct KeyValue *next;
} KeyValue;

typedef struct JSONObject {
    KeyValue *head;
} JSONObject;

// Function to create a new KeyValue
KeyValue* new_key_value(const char* key, const char* value) {
    KeyValue* kv = (KeyValue*) malloc(sizeof(KeyValue));
    strncpy(kv->key, key, MAX_KEY_LENGTH);
    strncpy(kv->value, value, MAX_VALUE_LENGTH);
    kv->next = NULL;
    return kv;
}

// Function to create a new JSONObject
JSONObject* new_json_object() {
    JSONObject* jsonObj = (JSONObject*) malloc(sizeof(JSONObject));
    jsonObj->head = NULL;
    return jsonObj;
}

// Function to trim whitespace
char* trim_whitespace(char* str) {
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;
    char* end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
    return str;
}

// Function to parse a JSON string
JSONObject* parse_json(const char* json_str) {
    JSONObject* jsonObj = new_json_object();
    const char* ptr = json_str;
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];

    while (*ptr) {
        if (*ptr == '"') {
            ptr++;
            char* key_start = (char*)ptr;
            while (*ptr && *ptr != '"') ptr++;
            strncpy(key, key_start, ptr - key_start);
            key[ptr - key_start] = '\0';
            ptr++; // move past closing quote

            ptr = trim_whitespace((char*)ptr);
            if (*ptr != ':') {
                printf("Error: Expected ':' after key\n");
                return NULL;
            }
            ptr++; // move past ':'
            ptr = trim_whitespace((char*)ptr);
            if (*ptr != '"') {
                printf("Error: Expected '\"' before value\n");
                return NULL;
            }
            ptr++;
            char* value_start = (char*)ptr;
            while (*ptr && *ptr != '"') ptr++;
            strncpy(value, value_start, ptr - value_start);
            value[ptr - value_start] = '\0';
            ptr++; // move past closing quote

            KeyValue* kv = new_key_value(key, value);
            kv->next = jsonObj->head;
            jsonObj->head = kv;
        } else {
            ptr++;
        }
    }

    return jsonObj;
}

// Function to print the parsed JSON
void print_json(JSONObject* jsonObj) {
    KeyValue* current = jsonObj->head;
    printf("{\n");
    while (current) {
        printf("  \"%s\": \"%s\",\n", current->key, current->value);
        current = current->next;
    }
    printf("}\n");
}

// Clean up memory used by JSONObject
void free_json(JSONObject* jsonObj) {
    KeyValue* current = jsonObj->head;
    while (current) {
        KeyValue* temp = current;
        current = current->next;
        free(temp);
    }
    free(jsonObj);
}

// Main function to demonstrate the JSON parser
int main() {
    const char* json_str = "{\"name\":\"Sherlock Holmes\",\"profession\":\"Detective\",\"city\":\"London\"}";
    
    printf("Parsing JSON string: %s\n", json_str);
    
    JSONObject* jsonObj = parse_json(json_str);
    if (jsonObj) {
        print_json(jsonObj);
        free_json(jsonObj);
    } else {
        printf("Failed to parse JSON.\n");
    }

    return 0;
}