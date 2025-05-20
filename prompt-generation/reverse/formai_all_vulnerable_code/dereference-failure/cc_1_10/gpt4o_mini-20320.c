//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: invasive
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

// Function to create a new JSON value
JSONValue* create_json_value(const char *key, const char *value) {
    JSONValue *new_value = (JSONValue *) malloc(sizeof(JSONValue));
    new_value->key = strdup(key);
    new_value->value = strdup(value);
    new_value->next = NULL;
    return new_value;
}

// Function to create a new JSON object
JSONObject* create_json_object() {
    JSONObject *new_object = (JSONObject *) malloc(sizeof(JSONObject));
    new_object->head = NULL;
    return new_object;
}

// Function to add a JSON value to a JSON object
void add_json_value(JSONObject *obj, const char *key, const char *value) {
    JSONValue *new_value = create_json_value(key, value);
    new_value->next = obj->head;
    obj->head = new_value;
}

// Function to trim whitespace from both sides of a string
char *trim_whitespace(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) str++;

    if (*str == 0) return str;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0';

    return str;
}

// Function to parse a simple JSON string
JSONObject* parse_json(const char *json_str) {
    JSONObject *obj = create_json_object();
    char *json_copy = strdup(json_str);
    char *line = strtok(json_copy, ",");

    while (line != NULL) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, ":");

        if (key && value) {
            trim_whitespace(key);
            trim_whitespace(value);
            add_json_value(obj, key, value);
        }

        line = strtok(NULL, ",");
    }

    free(json_copy);
    return obj;
}

// Function to print the JSON object
void print_json_object(JSONObject *obj) {
    JSONValue *current = obj->head;
    printf("{\n");
    while (current != NULL) {
        printf("    \"%s\": \"%s\"", current->key, current->value);
        current = current->next;
        if (current != NULL) {
            printf(",");
        }
        printf("\n");
    }
    printf("}\n");
}

// Function to free memory allocated for JSON object
void free_json_object(JSONObject *obj) {
    JSONValue *current = obj->head;
    JSONValue *temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
    free(obj);
}

int main() {
    const char *json = "name: John Doe, age: 30, city: New York, occupation: Developer";
    printf("Parsing JSON:\n%s\n\n", json);

    JSONObject *json_object = parse_json(json);
    print_json_object(json_object);
    free_json_object(json_object);

    return 0;
}