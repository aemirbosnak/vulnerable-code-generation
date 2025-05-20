//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_STRING 2048
#define MAX_KEY_LENGTH 256
#define MAX_VALUE_LENGTH 256

typedef struct JsonKeyValue {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct JsonKeyValue* next;
} JsonKeyValue;

typedef struct JsonObject {
    JsonKeyValue* head;
} JsonObject;

// Function to create a new JsonObject
JsonObject* create_json_object() {
    JsonObject* obj = (JsonObject*)malloc(sizeof(JsonObject));
    obj->head = NULL;
    return obj;
}

// Function to create a new key-value pair
JsonKeyValue* create_key_value(const char* key, const char* value) {
    JsonKeyValue* kv = (JsonKeyValue*)malloc(sizeof(JsonKeyValue));
    strncpy(kv->key, key, MAX_KEY_LENGTH);
    strncpy(kv->value, value, MAX_VALUE_LENGTH);
    kv->next = NULL;
    return kv;
}

// Function to add a key-value pair to the JsonObject
void add_key_value(JsonObject* obj, const char* key, const char* value) {
    JsonKeyValue* new_kv = create_key_value(key, value);
    new_kv->next = obj->head;
    obj->head = new_kv;
}

// Function to parse a simple JSON string
JsonObject* parse_json(const char* json_string) {
    JsonObject* json_obj = create_json_object();
    const char* key_start;
    const char* value_start;

    const char* cursor = json_string;
    while (*cursor) {
        if (*cursor == '\"') {
            key_start = cursor + 1;
            cursor = strchr(key_start, '\"');
            if (cursor == NULL) break;

            char key[MAX_KEY_LENGTH];
            strncpy(key, key_start, cursor - key_start);
            key[cursor - key_start] = '\0';

            cursor += 1;  // move past closing quote
            while (*cursor && *cursor != ':') cursor++;  // skip to colon
            cursor++; // skip over ':'

            if (*cursor == '\"') {
                value_start = cursor + 1;
                cursor = strchr(value_start, '\"');
                if (cursor == NULL) break;

                char value[MAX_VALUE_LENGTH];
                strncpy(value, value_start, cursor - value_start);
                value[cursor - value_start] = '\0';

                add_key_value(json_obj, key, value);
            }
        }
        cursor++;
    }
    return json_obj;
}

// Function to print the JsonObject
void print_json_object(JsonObject* obj) {
    JsonKeyValue* current = obj->head;
    printf("{\n");
    while (current) {
        printf("\t\"%s\": \"%s\",\n", current->key, current->value);
        current = current->next;
    }
    printf("}\n");
}

// Cleanup function
void free_json_object(JsonObject* obj) {
    JsonKeyValue* current = obj->head;
    while (current) {
        JsonKeyValue* temp = current;
        current = current->next;
        free(temp);
    }
    free(obj);
}

int main() {
    const char* json_input = "{\"name\":\"John Doe\", \"age\":\"30\", \"city\":\"New York\"}";
    
    JsonObject* json_obj = parse_json(json_input);
    print_json_object(json_obj);
    
    free_json_object(json_obj);
    return 0;
}