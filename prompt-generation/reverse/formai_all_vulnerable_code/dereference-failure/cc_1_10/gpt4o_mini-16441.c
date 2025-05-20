//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JsonObject {
    char *key;
    char *value;
    struct JsonObject *next;
} JsonObject;

JsonObject *parse_json(const char *json);
void free_json(JsonObject *obj);
void trim_whitespace(const char **str);
void parse_pair(const char **str, JsonObject *obj);
void parse_value(const char **str, JsonObject *obj);
void parse_key(const char **str, JsonObject *obj);

int main() {
    const char *json = "{\"name\": \"John Doe\", \"age\": \"30\", \"city\": \"New York\"}";
    JsonObject *json_obj = parse_json(json);
    
    JsonObject *curr = json_obj;
    while (curr != NULL) {
        printf("Key: %s, Value: %s\n", curr->key, curr->value);
        curr = curr->next;
    }

    free_json(json_obj);
    return 0;
}

void trim_whitespace(const char **str) {
    while (isspace((unsigned char)**str)) (*str)++;
}

void parse_key(const char **str, JsonObject *obj) {
    trim_whitespace(str);
    if (**str == '"') {
        (*str)++; // skip opening quote
        const char *start = *str;
        while (**str && **str != '"') (*str)++;
        size_t len = *str - start;
        obj->key = malloc(len + 1);
        strncpy(obj->key, start, len);
        obj->key[len] = '\0';
        (*str)++; // skip closing quote
    }
}

void parse_value(const char **str, JsonObject *obj) {
    trim_whitespace(str);
    if (**str == '"') {
        (*str)++; // skip opening quote
        const char *start = *str;
        while (**str && **str != '"') (*str)++;
        size_t len = *str - start;
        obj->value = malloc(len + 1);
        strncpy(obj->value, start, len);
        obj->value[len] = '\0';
        (*str)++; // skip closing quote
    } else {
        // In this example we'll only handle string values
        // An enhancement would be to handle numbers, booleans, etc.
        fprintf(stderr, "Error: Unexpected value type\n");
        exit(EXIT_FAILURE);
    }
}

void parse_pair(const char **str, JsonObject *obj) {
    parse_key(str, obj);
    trim_whitespace(str);
    if (**str == ':') {
        (*str)++; // skip the colon
        parse_value(str, obj);
    }
}

JsonObject *parse_json(const char *json) {
    JsonObject *head = NULL;
    JsonObject *tail = NULL;

    // Skip the opening brace
    trim_whitespace(&json);
    if (*json == '{') json++;

    while (*json) {
        JsonObject *new_obj = malloc(sizeof(JsonObject));
        new_obj->next = NULL;

        parse_pair(&json, new_obj);

        if (head == NULL) {
            head = new_obj;
            tail = new_obj;
        } else {
            tail->next = new_obj;
            tail = new_obj;
        }

        trim_whitespace(&json);
        if (*json == ',') json++; // skip the comma
        else break; // end parsing if there's no comma
    }

    // Skip the closing brace
    trim_whitespace(&json);
    if (*json == '}') json++;
    return head;
}

void free_json(JsonObject *obj) {
    while (obj) {
        JsonObject *tmp = obj;
        obj = obj->next;
        free(tmp->key);
        free(tmp->value);
        free(tmp);
    }
}