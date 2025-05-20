//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JSONNode {
    char *key;
    char *value;
    struct JSONNode *next;
} JSONNode;

typedef struct JSONObject {
    JSONNode *head;
} JSONObject;

void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0';
}

JSONObject *create_json_object() {
    JSONObject *json = (JSONObject *)malloc(sizeof(JSONObject));
    json->head = NULL;
    return json;
}

void add_key_value(JSONObject *json, const char *key, const char *value) {
    JSONNode *new_node = (JSONNode *)malloc(sizeof(JSONNode));
    new_node->key = strdup(key);
    new_node->value = strdup(value);
    new_node->next = json->head;
    json->head = new_node;
}

char *get_value(JSONObject *json, const char *key) {
    JSONNode *current = json->head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

void free_json_object(JSONObject *json) {
    JSONNode *current = json->head;
    JSONNode *next_node;
    while (current) {
        next_node = current->next;
        free(current->key);
        free(current->value);
        free(current);
        current = next_node;
    }
    free(json);
}

void parse_json(JSONObject *json, const char *str) {
    char *temp = strdup(str);
    char *line = strtok(temp, ",");
    while (line != NULL) {
        char *key_value = strtok(line, ":");
        char *key = strtok(key_value, "\"");
        char *value = strtok(NULL, "\"");
        if (key && value) {
            trim_whitespace(key);
            trim_whitespace(value);
            add_key_value(json, key, value);
        }
        line = strtok(NULL, ",");
    }
    free(temp);
}

void print_json(JSONObject *json) {
    JSONNode *current = json->head;
    printf("{\n");
    while (current) {
        printf("  \"%s\": \"%s\"", current->key, current->value);
        if (current->next) {
            printf(",");
        }
        printf("\n");
        current = current->next;
    }
    printf("}\n");
}

int main() {
    const char *json_str = "\"name\":\"John\", \"age\":\"30\", \"city\":\"New York\"";
    
    JSONObject *json_obj = create_json_object();
    parse_json(json_obj, json_str);
    print_json(json_obj);
    
    char *name = get_value(json_obj, "name");
    char *age = get_value(json_obj, "age");
    
    printf("Retrieved from JSON - Name: %s, Age: %s\n", name, age);
    
    // Cleanup
    free_json_object(json_obj);
    return 0;
}