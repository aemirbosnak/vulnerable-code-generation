//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *key;
    char *value;
} JsonPair;

typedef struct {
    JsonPair *pairs;
    size_t count;
} JsonObject;

void trim_whitespace(char *str) {
    char *end;

    while (isspace((unsigned char) *str)) str++;
    if (*str == 0) return;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char) *end)) end--;
    end[1] = '\0';
}

void parse_json(const char *json_str, JsonObject *json_obj) {
    json_obj->pairs = malloc(sizeof(JsonPair) * 10); // allocate memory for 10 pairs
    json_obj->count = 0;

    const char *key_start = NULL;
    const char *value_start = NULL;
    int is_key = 1; // to toggle between key and value

    for (const char *p = json_str; *p; p++) {
        if (*p == '\"') {
            if (is_key) {
                key_start = p + 1;
            } else {
                value_start = key_start; // complete key
                size_t key_len = p - key_start;
                json_obj->pairs[json_obj->count].key = strndup(key_start, key_len);
                trim_whitespace(json_obj->pairs[json_obj->count].key);
            }
            is_key = !is_key; // toggle from key to value
        } else if (is_key && *p == ':') {
            // Switch to value
            is_key = 0;
        } else if (!is_key && (*p == ',' || *(p + 1) == '}')) {
            value_start = p + 1; // complete value
            size_t value_len = p - value_start + 1;
            json_obj->pairs[json_obj->count].value = strndup(value_start, value_len);
            trim_whitespace(json_obj->pairs[json_obj->count].value);
            json_obj->count++;
            is_key = 1; // Go back to looking for key
        }
    }
}

void free_json_object(JsonObject *json_obj) {
    for (size_t i = 0; i < json_obj->count; i++) {
        free(json_obj->pairs[i].key);
        free(json_obj->pairs[i].value);
    }
    free(json_obj->pairs);
}

void print_json_object(const JsonObject *json_obj) {
    for (size_t i = 0; i < json_obj->count; i++) {
        printf("Key: %s, Value: %s\n", json_obj->pairs[i].key, json_obj->pairs[i].value);
    }
}

int main() {
    const char *json_input = "{\"name\": \"Alice\", \"age\": \"30\", \"city\": \"Wonderland\"}";
    JsonObject json_obj;

    parse_json(json_input, &json_obj);
    print_json_object(&json_obj);
    free_json_object(&json_obj);

    return 0;
}