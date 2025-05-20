//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1024

// Struct for holding key-value pair
typedef struct {
    char* key;
    char* value;
} KeyValuePair;

// Struct for holding JSON object
typedef struct {
    int num_pairs;
    KeyValuePair* pairs;
} JSONObject;

// Function for parsing JSON string into JSON object
JSONObject* parse_JSON(char* json_str) {
    int len = strlen(json_str);
    // Ensure the JSON string is not empty or too long
    if (len == 0 || len >= MAX_SIZE) {
        return NULL;
    }

    JSONObject* json_obj = (JSONObject*) malloc(sizeof(JSONObject));
    json_obj->num_pairs = 0;
    json_obj->pairs = (KeyValuePair*) malloc(sizeof(KeyValuePair) * MAX_SIZE);

    char key_buf[MAX_SIZE] = {0};
    char val_buf[MAX_SIZE] = {0};

    int i = 0;
    while (i < len) {
        // Find start of key
        int start_key = i;
        while (i < len && json_str[i] != '\"') {
            i++;
        }
        // Verify start of key
        if (i >= len-1 || json_str[i+1] != ':') {
            return NULL;
        }
        // Copy key into buffer
        strncpy(key_buf, json_str + start_key + 1, i - start_key - 1);

        // Find start of value
        int start_val = i + 2;
        bool is_string = false;
        if (json_str[start_val] == '\"') {
            is_string = true;
            start_val++;
        }

        // Find end of value
        i = start_val;
        while (i < len && (is_string ? json_str[i] != '\"' : json_str[i] != ',')) {
            i++;
        }

        // Copy value into buffer
        strncpy(val_buf, json_str + start_val, i - start_val);

        // Add key-value pair to JSON object
        KeyValuePair pair = {
            .key = strdup(key_buf),
            .value = strdup(val_buf)
        };
        json_obj->pairs[json_obj->num_pairs] = pair;
        json_obj->num_pairs++;

        // Reset key and value buffers
        memset(key_buf, 0, MAX_SIZE);
        memset(val_buf, 0, MAX_SIZE);

        // Move past the comma
        if (i < len && !is_string) {
            i++;
        }
    }

    return json_obj;
}

int main() {
    char* json_str = "{\"name\": \"John Doe\", \"age\": 30, \"isMarried\": true}";
    JSONObject* json_obj = parse_JSON(json_str);

    if (json_obj != NULL) {
        for (int i = 0; i < json_obj->num_pairs; i++) {
            printf("Key: %s, Value: %s\n", json_obj->pairs[i].key, json_obj->pairs[i].value);
        }
    }

    return 0;
}