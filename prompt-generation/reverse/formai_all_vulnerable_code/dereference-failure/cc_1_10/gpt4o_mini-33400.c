//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JsonValue {
    char *key;
    char *value;
    struct JsonValue *next;
} JsonValue;

JsonValue *init_value(const char *key, const char *value) {
    JsonValue *new_value = (JsonValue *)malloc(sizeof(JsonValue));
    new_value->key = strdup(key);
    new_value->value = strdup(value);
    new_value->next = NULL;
    return new_value;
}

void free_values(JsonValue *head) {
    JsonValue *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
}

void parse_json(const char *json, JsonValue **head) {
    const char *ptr = json;
    char key[100];
    char value[100];
    int in_key = 0, in_value = 0;
    int key_index = 0, value_index = 0;
    
    while (*ptr) {
        if (*ptr == '{' || *ptr == '}' || isspace(*ptr)) {
            ptr++;
            continue;
        }

        if (*ptr == '\"' && !in_value) {
            in_key = !in_key;
            if (in_key) {
                key_index = 0;
            } else {
                key[key_index] = '\0';
            }
        } else if (*ptr == ':' && !in_key) {
            in_value = 1;
            value_index = 0;
        } else if (*ptr == '\"' && in_value) {
            in_value = 0;
            value[value_index] = '\0';
            JsonValue *new_val = init_value(key, value);
            new_val->next = *head;
            *head = new_val;
        } else {
            if (in_key) {
                key[key_index++] = *ptr;
            } else if (in_value) {
                value[value_index++] = *ptr;
            }
        }
        ptr++;
    }
}

void print_json_values(JsonValue *head) {
    printf("The whispering keys of expectation:\n");
    while (head) {
        printf("Key: %s, Value: %s\n", head->key, head->value);
        head = head->next;
    }
}

int main() {
    const char *json = "{\"name\":\"Alice\", \"age\":\"30\", \"city\":\"Wonderland\"}";
    JsonValue *json_values = NULL;
    
    // The dance begins in the realm of JSON
    parse_json(json, &json_values);
    
    // Echos of the earth and skies reveal the treasure
    print_json_values(json_values);
    
    // As soft shadows exit through the door
    free_values(json_values);
    return 0;
}