//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: optimized
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

    if (*str == 0)  
        return; 

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = 0;
}

JSONValue *create_json_value(const char *key, const char *value) {
    JSONValue *new_value = (JSONValue *)malloc(sizeof(JSONValue));
    new_value->key = strdup(key);
    new_value->value = strdup(value);
    new_value->next = NULL;
    return new_value;
}

void add_json_value(JSONObject *obj, const char *key, const char *value) {
    JSONValue *new_value = create_json_value(key, value);
    new_value->next = obj->head;
    obj->head = new_value;
}

void free_json_value(JSONValue *value) {
    if (value) {
        free(value->key);
        free(value->value);
        free(value);
    }
}

void free_json_object(JSONObject *obj) {
    JSONValue *current = obj->head;
    JSONValue *next;

    while (current != NULL) {
        next = current->next;
        free_json_value(current);
        current = next;
    }
    free(obj);
}

JSONObject *parse_json(const char *json_string) {
    JSONObject *json_obj = (JSONObject *)malloc(sizeof(JSONObject));
    json_obj->head = NULL;

    char *copy = strdup(json_string);
    trim_whitespace(copy);

    char *key_start = strchr(copy, '"');
    
    while (key_start != NULL) {
        char *key_end = strchr(key_start + 1, '"');
        if (key_end == NULL) break;

        *key_end = '\0';
        char *value_start = strchr(key_end + 1, ':');
        if (value_start == NULL) break;

        value_start++;
        trim_whitespace(value_start);
        char *value_end = strchr(value_start, ',');
        if (value_end == NULL) {
            value_end = strchr(value_start, '}');
        }

        if (value_end == NULL) break;

        *value_end = '\0';
        trim_whitespace(value_start);

        add_json_value(json_obj, key_start + 1, value_start);

        key_start = strchr(value_end + 1, '"');
    }

    free(copy);
    return json_obj;
}

void print_json_object(const JSONObject *obj) {
    printf("{\n");
    JSONValue *current = obj->head;
    while (current != NULL) {
        printf("  \"%s\": \"%s\"", current->key, current->value);
        current = current->next;
        if (current != NULL) {
            printf(",\n");
        } else {
            printf("\n");
        }
    }
    printf("}\n");
}

int main() {
    const char *json_input = "{\"name\":\"John\", \"age\":\"30\", \"city\":\"New York\"}";
    
    JSONObject *json_obj = parse_json(json_input);
    
    if (json_obj) {
        print_json_object(json_obj);
        free_json_object(json_obj);
    }

    return 0;
}