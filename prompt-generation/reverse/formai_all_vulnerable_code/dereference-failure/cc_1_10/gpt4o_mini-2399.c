//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JsonValue {
    char *key;
    char *value;
    struct JsonValue *next;
} JsonValue;

JsonValue* createJsonValue(const char *key, const char *value) {
    JsonValue *item = (JsonValue *)malloc(sizeof(JsonValue));
    item->key = strdup(key);
    item->value = strdup(value);
    item->next = NULL;
    return item;
}

void addJsonValue(JsonValue **head, const char *key, const char *value) {
    JsonValue *new_value = createJsonValue(key, value);
    new_value->next = *head;
    *head = new_value;
}

void freeJsonValues(JsonValue *head) {
    JsonValue *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
}

void trimWhitespace(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) str++;

    if (*str == 0) return;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = 0;
}

int parseJson(const char *json, JsonValue **head) {
    const char *p = json;
    char key[256] = {0};
    char value[256] = {0};

    while (*p) {
        if (*p == '"') {
            p++;
            char *key_start = key;
            while (*p && *p != '"') {
                *key_start++ = *p++;
            }
            *key_start = '\0';  // Null-terminate the key

            if (*p == '"') p++; // Skip over closing quote

            while (isspace(*p)) p++; // Skip whitespace
            if (*p != ':') return -1; // Expecting a colon
            p++; // Skip over colon
            while (isspace(*p)) p++; // Skip whitespace

            if (*p == '"') {
                p++;
                char *value_start = value;
                while (*p && *p != '"') {
                    *value_start++ = *p++;
                }
                *value_start = '\0'; // Null-terminate the value
                if (*p == '"') p++; // Skip over closing quote

                trimWhitespace(key);
                trimWhitespace(value);

                addJsonValue(head, key, value);
                memset(key, 0, sizeof(key)); // Clear key
                memset(value, 0, sizeof(value)); // Clear value
            }
        } else {
            p++;
        }
    }
    return 0; // Parsing successful
}

void printJsonValues(JsonValue *head) {
    printf("{\n");
    while (head) {
        printf("  \"%s\": \"%s\"", head->key, head->value);
        head = head->next;
        if (head) {
            printf(",\n");
        } else {
            printf("\n");
        }
    }
    printf("}\n");
}

int main(int argc, char *argv[]) {
    JsonValue *json_values = NULL;

    const char *json_string = "{\"name\": \"Alice\", \"age\": \"30\", \"city\": \"Wonderland\"}";

    if (parseJson(json_string, &json_values) == 0) {
        printJsonValues(json_values);
    } else {
        fprintf(stderr, "Error parsing JSON\n");
    }

    freeJsonValues(json_values);
    return 0;
}