//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024

typedef struct JSONValue {
    char *key;
    char *value;
    struct JSONValue *next;
} JSONValue;

void free_json(JSONValue *head) {
    while (head) {
        JSONValue *temp = head;
        free(temp->key);
        free(temp->value);
        head = head->next;
        free(temp);
    }
}

void skip_whitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

char *parse_string(const char **json) {
    (*json)++; // Skip the opening quote
    const char *start = *json;

    while (**json && **json != '"') {
        (*json)++;
    }

    size_t len = *json - start;
    char *string_value = (char *)malloc(len + 1);
    strncpy(string_value, start, len);
    string_value[len] = '\0';

    (*json)++; // Skip the closing quote
    return string_value;
}

char *parse_value(const char **json);

JSONValue *parse_object(const char **json) {
    JSONValue *head = NULL;
    JSONValue *tail = NULL;

    (*json)++; // Skip '{'
    skip_whitespace(json);

    while (**json && **json != '}') {
        JSONValue *new_value = (JSONValue *)malloc(sizeof(JSONValue));
        new_value->next = NULL;

        new_value->key = parse_string(json);
        skip_whitespace(json);
        (*json)++; // Skip ':'
        skip_whitespace(json);
        new_value->value = parse_value(json);
        skip_whitespace(json);

        if (head == NULL) {
            head = new_value; // First element
            tail = head;
        } else {
            tail->next = new_value; // Attach to the end
            tail = new_value;
        }

        if (**json == ',') {
            (*json)++; // Skip ','
            skip_whitespace(json);
        }
    }
    (*json)++; // Skip '}'
    return head;
}

char *parse_number(const char **json) {
    const char *start = *json;

    while (isdigit(**json) || **json == '.' || **json == '-') {
        (*json)++;
    }

    size_t len = *json - start;
    char *number_value = (char *)malloc(len + 1);
    strncpy(number_value, start, len);
    number_value[len] = '\0';

    return number_value;
}

char *parse_value(const char **json) {
    skip_whitespace(json);

    if (**json == '"') {
        return parse_string(json);
    }
    else if (isdigit(**json) || **json == '-') {
        return parse_number(json);
    }
    else if (**json == '{') {
        JSONValue *obj = parse_object(json);
        char *object_representation = (char *)malloc(MAX_LENGTH);
        strcpy(object_representation, "{...}"); // Simplified for output
        free_json(obj); // Free the JSON object directly.
        return object_representation;
    }
    return NULL;
}

void print_json(JSONValue *head) {
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

int main() {
    const char *json_string = "{\"name\": \"John\", \"age\": \"30\", \"city\": \"New York\"}";
    const char *json_ptr = json_string;

    JSONValue *json_object = parse_object(&json_ptr);

    print_json(json_object);
    free_json(json_object);

    return 0;
}