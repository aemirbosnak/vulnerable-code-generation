//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 1024

typedef struct JSON_Value {
    char *key;
    char *value;
    struct JSON_Value *next;
} JSON_Value;

JSON_Value *json_values = NULL;

void free_json_values(JSON_Value *value) {
    while (value) {
        JSON_Value *temp = value;
        value = value->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
}

void add_json_value(const char *key, const char *value) {
    JSON_Value *new_value = (JSON_Value *)malloc(sizeof(JSON_Value));
    new_value->key = strdup(key);
    new_value->value = strdup(value);
    new_value->next = json_values;
    json_values = new_value;
}

void parse_json(const char *json) {
    const char *p = json;
    char key[MAX_BUFFER];
    char value[MAX_BUFFER];
    while (*p) {
        if (isspace(*p)) {
            p++;
            continue;
        }
        if (*p == '{' || *p == ',') {
            p++;
            continue;
        }
        char *key_ptr = key;
        char *value_ptr = value;

        // Parse key
        while (*p && *p != ':' && *p != '}') {
            if (*p == '"') {
                p++;
                while (*p && *p != '"') {
                    *key_ptr++ = *p++;
                }
                *key_ptr = '\0';
                p++;
                break;
            }
            p++;
        }

        // Parse value
        while (*p && (*p == ' ' || *p == ',')) {
            p++;
        }

        if (*p == '"') {
            p++;
            while (*p && *p != '"') {
                *value_ptr++ = *p++;
            }
            *value_ptr = '\0';
            p++;
        }

        if (key[0] != '\0' && value[0] != '\0') {
            add_json_value(key, value);
        }
        
        // Clear buffers for next iteration
        memset(key, 0, sizeof(key));
        memset(value, 0, sizeof(value));
    }
}

void print_json_values() {
    JSON_Value *current = json_values;
    while (current) {
        printf("Key: %s, Value: %s\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    const char *json_str = "{\"name\":\"John Doe\",\"age\":\"30\",\"city\":\"New York\"}";
    
    printf("Parsing JSON string:\n%s\n", json_str);
    parse_json(json_str);
    
    printf("\nParsed JSON values:\n");
    print_json_values();
    
    free_json_values(json_values);
    return 0;
}