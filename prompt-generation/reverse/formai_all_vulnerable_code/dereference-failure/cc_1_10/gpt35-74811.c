//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

typedef struct {
    KeyValuePair *items;
    int num_items;
} JsonObject;

void parse_object(const char *json_str, JsonObject *json_object);
char *parse_string(const char *json_str);
char *parse_value(const char *json_str);
KeyValuePair parse_key_value_pair(const char *json_str);

int main() {
    const char *json_str = "{\"name\":\"John Doe\",\"age\":25}";
    JsonObject json_object = {NULL, 0};
    parse_object(json_str, &json_object);
    for (int i = 0; i < json_object.num_items; i++) {
        printf("%s: %s\n", json_object.items[i].key, json_object.items[i].value);
    }
    return 0;
}

void parse_object(const char *json_str, JsonObject *json_object) {
    json_object->items = malloc(sizeof(KeyValuePair));
    json_object->num_items = 0;

    json_str++; // ignore starting curly brace
    while (*json_str != '}') {
        KeyValuePair item = parse_key_value_pair(json_str);
        json_object->items = realloc(json_object->items, (json_object->num_items + 1) * sizeof(KeyValuePair));
        json_object->items[json_object->num_items] = item;
        json_object->num_items++;

        json_str = strchr(json_str, ',');
        if (json_str == NULL) {
            break;
        }
        json_str++; // ignore comma
    }
}

KeyValuePair parse_key_value_pair(const char *json_str) {
    KeyValuePair item;
    item.key = parse_string(json_str);
    json_str = strchr(json_str, ':');
    json_str++; // ignore colon
    item.value = parse_value(json_str);
    return item;
}

char *parse_string(const char *json_str) {
    int str_len = strchr(json_str, '\"') - json_str - 1;
    char *str = malloc((str_len + 1) * sizeof(char));
    strncpy(str, json_str + 1, str_len);
    str[str_len] = '\0';
    return str;
}

char *parse_value(const char *json_str) {
    switch (*json_str) {
        case '{': { // parse object
            JsonObject json_object = {NULL, 0};
            parse_object(json_str, &json_object);
            char *str = malloc(sizeof(char));
            *str = '\0';
            for (int i = 0; i < json_object.num_items; i++) {
                str = realloc(str, strlen(str) + strlen(json_object.items[i].key) + strlen(json_object.items[i].value) + 3);
                strcat(str, json_object.items[i].key);
                strcat(str, ": ");
                strcat(str, json_object.items[i].value);
                if (i < json_object.num_items - 1) {
                    strcat(str, ", ");
                }
            }
            return str;
        }
        case '\"': { // parse string
            return parse_string(json_str);
        }
        default: { // parse number, bool, or null
            return strdup(strtok(json_str, ",}"));
        }
    }
}