//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JsonValue {
    char *key;
    char *value;
    struct JsonValue *next;
} JsonValue;

JsonValue* create_json_value(const char *key, const char *value) {
    JsonValue *new_value = (JsonValue *)malloc(sizeof(JsonValue));
    new_value->key = strdup(key);
    new_value->value = strdup(value);
    new_value->next = NULL;
    return new_value;
}

void free_json_value(JsonValue *json_value) {
    if (json_value) {
        free(json_value->key);
        free(json_value->value);
        free(json_value);
    }
}

void free_json_list(JsonValue *head) {
    JsonValue *current = head;
    JsonValue *next;
    while (current != NULL) {
        next = current->next;
        free_json_value(current);
        current = next;
    }
}

void parse_json(const char *json, JsonValue **head) {
    const char *ptr = json;
    char key[256], value[256];
    char *key_ptr = key;
    char *value_ptr = value;
    int in_quotes = 0;

    while (*ptr) {
        if (*ptr == '\"') {
            in_quotes = !in_quotes;
            ptr++;
            continue;
        }

        if (in_quotes) {
            if (*ptr == ':') {
                *key_ptr++ = '\0';
                ptr++; // Skip the colon
                while (isspace(*ptr)) ptr++; // Skip whitespace
                continue;
            }
            if (*ptr == ',') {
                *value_ptr++ = '\0';
                *head = create_json_value(key, value);
                head = &((*head)->next);
                key_ptr = key;
                value_ptr = value;
                ptr++; // Skip the comma
                continue;
            }
            if (*ptr == '}') {
                *value_ptr++ = '\0';
                *head = create_json_value(key, value);
                break; // End of object
            }
            *key_ptr++ = *ptr; // Add character to key or value
        } else {
            if (!isspace(*ptr)) {
                ptr++; // Skip non-whitespace
            }
        }
        ptr++;
    }
}

void print_json(JsonValue *head) {
    JsonValue *current = head;
    while (current) {
        printf("Key: %s, Value: %s\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    const char *json_data = "{\"name\":\"John Doe\",\"age\":\"30\",\"city\":\"New York\"}";
    JsonValue *json_values = NULL;

    parse_json(json_data, &json_values);
    
    printf("Parsed JSON Data:\n");
    print_json(json_values);
    
    free_json_list(json_values);
    
    return 0;
}