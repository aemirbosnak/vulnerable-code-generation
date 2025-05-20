//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024
#define MAX_KEY_SIZE 128
#define MAX_VALUE_SIZE 256

typedef struct JsonKeyValue {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    struct JsonKeyValue* next;
} JsonKeyValue;

void trim_whitespace(char* str) {
    char* end;

    // Trim leading whitespace
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing whitespace
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0'; // Null-terminate after the last valid character
}

JsonKeyValue* parse_json(const char* json_str) {
    JsonKeyValue* head = NULL;
    JsonKeyValue* tail = NULL;
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    const char* p = json_str;
    int in_string = 0; // To keep track of string literals

    while (*p) {
        if (*p == '"') {
            in_string = !in_string; // Toggle in_string state
        }
        
        if (in_string) {
            // Read the key
            char* key_ptr = key;
            while ((*p != ':' && *p != '\0') || in_string) {
                if (*p == '\\') {
                    p++; // Skip the escape character
                }
                *key_ptr++ = *p++;
            }
            *key_ptr = '\0'; // Null-terminate the key

            // Skip colon
            if (*p == ':') p++;

            // Read the value
            char* value_ptr = value;
            while (*p != ',' && *p != '}' && *p != '\0') {
                if (*p == '\\') {
                    p++; // Skip escape character
                }
                *value_ptr++ = *p++;
            }
            *value_ptr = '\0'; // Null-terminate the value

            // Add key-value pair to the list
            JsonKeyValue* new_pair = malloc(sizeof(JsonKeyValue));
            strcpy(new_pair->key, key);
            strcpy(new_pair->value, value);
            new_pair->next = NULL;

            if (head == NULL) {
                head = new_pair;
                tail = new_pair;
            } else {
                tail->next = new_pair;
                tail = new_pair;
            }
        }

        if (*p == ',') {
            p++; // Skip comma
        } else if (*p == '}') {
            break; // End of JSON object
        }
        
        // Move to the next character
        p++;
    }

    return head;
}

void print_json(JsonKeyValue* kv) {
    while (kv != NULL) {
        printf("Key: %s, Value: %s\n", kv->key, kv->value);
        kv = kv->next;
    }
}

void free_json(JsonKeyValue* kv) {
    while (kv != NULL) {
        JsonKeyValue* temp = kv;
        kv = kv->next;
        free(temp);
    }
}

int main() {
    const char* json_example = "{\"name\":\"John Doe\",\"age\":\"30\",\"city\":\"New York\"}";
    JsonKeyValue* parsed_json = parse_json(json_example);

    printf("Parsed JSON:\n");
    print_json(parsed_json);

    free_json(parsed_json); // Clean up allocated memory

    return 0;
}