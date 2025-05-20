//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: brave
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

JsonObject *create_json_object() {
    JsonObject *json = (JsonObject *)malloc(sizeof(JsonObject));
    json->head = NULL;
    return json;
}

void free_json_object(JsonObject *json) {
    JsonValue *current = json->head;
    while (current) {
        JsonValue *temp = current;
        current = current->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
    free(json);
}

JsonValue *create_json_value(const char *key, const char *value) {
    JsonValue *json_value = (JsonValue *)malloc(sizeof(JsonValue));
    json_value->key = strdup(key);
    json_value->value = strdup(value);
    json_value->next = NULL;
    return json_value;
}

void add_json_value(JsonObject *json, const char *key, const char *value) {
    JsonValue *new_value = create_json_value(key, value);
    new_value->next = json->head;
    json->head = new_value;
}

char *trim_whitespace(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) str++;

    if (*str == 0) return str;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = 0;

    return str;
}

int is_valid_json_key(char c) {
    return isalpha(c) || c == '_';
}

void parse_json(const char *json_string, JsonObject *json) {
    char key[256];
    char value[256];
    int key_index = 0, value_index = 0;
    int reading_key = 0, reading_value = 0;

    for (int i = 0; json_string[i] != '\0'; i++) {
        if (json_string[i] == '{') continue;
        if (json_string[i] == '}') break;

        if (json_string[i] == ':' && reading_key) {
            reading_key = 0;
            reading_value = 1;
            key[key_index] = '\0';
            continue;
        }

        if (json_string[i] == ',') {
            if (reading_value) {
                value[value_index] = '\0';
                add_json_value(json, trim_whitespace(key), trim_whitespace(value));
                key_index = 0;
                value_index = 0;
                reading_value = 0;
            }
            continue;
        }

        if (json_string[i] == '\"') {
            if (!reading_key && !reading_value) {
                reading_key = 1;
            } else if (reading_key) {
                reading_key = 0;
                continue;
            } else if (reading_value) {
                reading_value = 0;
                continue;
            }
        }

        if (reading_key) {
            key[key_index++] = json_string[i];
        } else if (reading_value) {
            value[value_index++] = json_string[i];
        }
    }

    if (reading_value) {
        value[value_index] = '\0';
        add_json_value(json, trim_whitespace(key), trim_whitespace(value));
    }
}

void print_json(JsonObject *json) {
    JsonValue *current = json->head;
    while (current) {
        printf("%s: %s\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    const char *json_string = "{\"name\": \"John\", \"age\": \"30\", \"city\": \"New York\"}";

    JsonObject *json = create_json_object();
    parse_json(json_string, json);
    
    printf("Parsed JSON:\n");
    print_json(json);

    free_json_object(json);
    return 0;
}