//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: imaginative
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

void trim_whitespace(char **str) {
    char *end;

    while (isspace((unsigned char)**str)) (*str)++;

    if (**str == 0)  // All spaces?
        return;

    end = *str + strlen(*str) - 1;
    while (end > *str && isspace((unsigned char)*end)) end--;

    end[1] = '\0';
}

JSONValue* create_json_value(const char *key, const char *value) {
    JSONValue *json_value = (JSONValue *)malloc(sizeof(JSONValue));
    json_value->key = strdup(key);
    json_value->value = strdup(value);
    json_value->next = NULL;
    return json_value;
}

JSONObject* create_json_object() {
    JSONObject *json_object = (JSONObject *)malloc(sizeof(JSONObject));
    json_object->head = NULL;
    return json_object;
}

void add_json_value(JSONObject *json_object, const char *key, const char *value) {
    JSONValue *new_value = create_json_value(key, value);
    new_value->next = json_object->head;
    json_object->head = new_value;
}

void parse_json(const char *json_string, JSONObject *json_object) {
    char key[128], value[128];
    const char *p = json_string;
    while (*p) {
        // Skip whitespace
        if (isspace((unsigned char)*p)) {
            p++;
            continue;
        }

        // Expect a key
        if (*p == '"') {
            p++;
            int i = 0;
            while (*p && *p != '"') {
                key[i++] = *p++;
            }
            key[i] = '\0';
            p++; // skip closing quote

            // Skip whitespace and expect a colon
            while (isspace((unsigned char)*p)) p++;
            if (*p != ':') {
                fprintf(stderr, "Error: expected ':' after key\n");
                return;
            }
            p++; // skip colon

            // Skip whitespace and expect a value
            while (isspace((unsigned char)*p)) p++;
            if (*p == '"') {
                p++;
                i = 0;
                while (*p && *p != '"') {
                    value[i++] = *p++;
                }
                value[i] = '\0';
                p++; // skip closing quote
            } else {
                int i = 0;
                while (*p && !isspace((unsigned char)*p) && *p != ',') {
                    value[i++] = *p++;
                }
                value[i] = '\0';
            }

            // Add key-value pair to the JSON object
            add_json_value(json_object, key, value);
        } else {
            fprintf(stderr, "Error: expected '\"' at the start of key\n");
            return;
        }

        while (*p && *p != ',') p++;
        p++; // Skip comma for the next iteration or end
    }
}

void print_json(const JSONObject *json_object) {
    JSONValue *current = json_object->head;
    while (current) {
        printf("\"%s\": \"%s\"\n", current->key, current->value);
        current = current->next;
    }
}

void free_json_object(JSONObject *json_object) {
    JSONValue *current = json_object->head;
    while (current) {
        JSONValue *temp = current;
        current = current->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
    free(json_object);
}

int main() {
    const char *json_string = "{\"name\": \"Alice\", \"age\": \"30\", \"city\": \"Wonderland\"}";
    JSONObject *json_object = create_json_object();

    parse_json(json_string, json_object);

    printf("Parsed JSON:\n");
    print_json(json_object);

    free_json_object(json_object);
    return 0;
}