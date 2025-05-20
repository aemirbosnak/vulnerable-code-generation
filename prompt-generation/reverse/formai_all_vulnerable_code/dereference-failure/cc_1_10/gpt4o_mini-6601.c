//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JSONValue {
    char *key;
    char *value;
    struct JSONValue *next;
} JSONValue;

typedef struct JSONObject {
    JSONValue *head;
} JSONObject;

void trim_whitespace(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) str++;

    if (*str == 0) return;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0';
}

char* parse_string(const char **json) {
    const char *start = *json + 1; // skip the opening quote
    char *value;
    size_t length = 0;

    while (**json && **json != '"') {
        length++;
        (*json)++;
    }

    value = (char *)malloc(length + 1);
    strncpy(value, start, length);
    value[length] = '\0';
    
    // Skip the closing quote
    if (**json == '"') (*json)++;

    return value;
}

char* parse_value(const char **json) {
    if (**json == '"') {
        return parse_string(json);
    }
    // Additional value parsing can be added here.

    return NULL;
}

JSONValue* parse_key_value(const char **json) {
    JSONValue *item = (JSONValue *)malloc(sizeof(JSONValue));
    
    item->key = parse_string(json);
    if (!item->key) {
        free(item);
        return NULL;
    }

    while (**json && **json != ':') (*json)++; // Skip to colon

    if (**json == ':') (*json)++; // Skip the colon

    item->value = parse_value(json);
    if (!item->value) {
        free(item->key);
        free(item);
        return NULL;
    }

    item->next = NULL;
    return item;
}

JSONObject* parse_json(const char *json_text) {
    JSONObject *json_object = (JSONObject *)malloc(sizeof(JSONObject));
    json_object->head = NULL;
    JSONValue *last_item = NULL;
    
    const char *json = json_text;

    while (*json) {
        while (*json && (*json != '{' && *json != '}')) json++; // Skip to beginning of JSON

        if (*json == '{') json++; // Skip the opening brace

        JSONValue *item = parse_key_value(&json);
        if (!item) {
            free(json_object);
            return NULL; // Error
        }

        // Add item to JSON object linked list
        if (last_item) {
            last_item->next = item;
        } else {
            json_object->head = item;
        }
        last_item = item;

        while (*json && *json != '}') json++; // Skip to end of JSON

        if (*json == '}') json++; // Skip the closing brace
    }

    return json_object;
}

void free_json_object(JSONObject *json_object) {
    JSONValue *current = json_object->head;
    JSONValue *temp;

    while (current) {
        temp = current;
        current = current->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
    
    free(json_object);
}

void print_json(JSONObject *json_object) {
    JSONValue *current = json_object->head;
    
    while (current) {
        printf("Key: %s, Value: %s\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    const char *json_text = "{\"name\":\"John\", \"age\":\"30\", \"city\":\"New York\"}";

    JSONObject *json_object = parse_json(json_text);
    
    if (json_object) {
        print_json(json_object);
        free_json_object(json_object);
    } else {
        printf("Error parsing JSON.\n");
    }

    return 0;
}