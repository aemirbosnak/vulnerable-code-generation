//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024
#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 256

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL
} json_type;

typedef struct {
    json_type type;
    void *value;
} json_object;

typedef struct {
    char key[MAX_KEY_SIZE];
    json_object *value;
} json_pair;

typedef struct {
    json_pair *pairs;
    int count;
} json_object_value;

typedef struct {
    json_object **items;
    int count;
} json_array_value;

json_object* parse_json_object(char *json_string, int *offset);
json_object* parse_json_array(char *json_string, int *offset);
json_object* parse_json_string(char *json_string, int *offset);
json_object* parse_json_number(char *json_string, int *offset);
json_object* parse_json_boolean(char *json_string, int *offset);

char* get_next_token(char *json_string, int *offset) {
    char *token = malloc(MAX_VALUE_SIZE);
    memset(token, 0, MAX_VALUE_SIZE);

    int index = 0;
    while (json_string[*offset] != '\0') {
        if (isspace(json_string[*offset])) {
            (*offset)++;
            continue;
        }
        if (json_string[*offset] == ',' || json_string[*offset] == ':' ||
            json_string[*offset] == '{' || json_string[*offset] == '}' ||
            json_string[*offset] == '[' || json_string[*offset] == ']' ||
            json_string[*offset] == '\"' || json_string[*offset] == '\'') {
            if (index > 0) {
                break;
            }
            token[index++] = json_string[(*offset)++];
            break;
        }
        token[index++] = json_string[(*offset)++];
    }

    if (index == 0) {
        free(token);
        return NULL;
    }

    return token;
}

json_object* parse_json(char *json_string) {
    int offset = 0;
    return parse_json_object(json_string, &offset);
}

json_object* parse_json_object(char *json_string, int *offset) {
    json_object *object = malloc(sizeof(json_object));
    object->type = JSON_OBJECT;

    json_object_value *value = malloc(sizeof(json_object_value));
    value->pairs = malloc(sizeof(json_pair) * MAX_JSON_SIZE);
    value->count = 0;

    char *token = get_next_token(json_string, offset);
    if (token == NULL || token[0] != '{') {
        free(token);
        free(value->pairs);
        free(value);
        free(object);
        return NULL;
    }
    free(token);

    while (json_string[*offset] != '\0') {

        // Parse key
        token = get_next_token(json_string, offset);
        if (token == NULL || token[0] != '\"') {
            free(token);
            break;
        }
        strncpy(value->pairs[value->count].key, token + 1, strlen(token) - 2);
        value->pairs[value->count].key[strlen(token) - 2] = '\0';

        // Parse value
        token = get_next_token(json_string, offset);
        if (token == NULL || token[0] != ':') {
            free(token);
            break;
        }
        free(token);

        value->pairs[value->count].value = parse_json(json_string);
        value->count++;

        // Check for end of object
        token = get_next_token(json_string, offset);
        if (token == NULL || token[0] == '}') {
            free(token);
            break;
        } else if (token[0] != ',') {
            free(token);
            break;
        }
        free(token);
    }

    object->value = value;
    return object;
}

json_object* parse_json_array(char *json_string, int *offset) {
    json_object *object = malloc(sizeof(json_object));
    object->type = JSON_ARRAY;

    json_array_value *value = malloc(sizeof(json_array_value));
    value->items = malloc(sizeof(json_object*) * MAX_JSON_SIZE);
    value->count = 0;

    char *token = get_next_token(json_string, offset);
    if (token == NULL || token[0] != '[') {
        free(token);
        free(value->items);
        free(value);
        free(object);
        return NULL;
    }
    free(token);

    while (json_string[*offset] != '\0') {

        // Parse value
        json_object *item = parse_json(json_string);
        if (item != NULL) {
            value->items[value->count] = item;
            value->count++;
        }

        // Check for end of array
        token = get_next_token(json_string, offset);
        if (token == NULL || token[0] == ']') {
            free(token);
            break;
        } else if (token[0] != ',') {
            free(token);
            break;
        }
        free(token);
    }

    object->value = value;
    return object;
}

json_object* parse_json_string(char *json_string, int *offset) {
    json_object *object = malloc(sizeof(json_object));
    object->type = JSON_STRING;

    char *token = get_next_token(json_string, offset);
    if (token == NULL || token[0] != '\"') {
        free(token);
        free(object);
        return NULL;
    }

    object->value = malloc(sizeof(char) * (strlen(token) - 1));
    strncpy(object->value, token + 1, strlen(token) - 2);
    ((char*) object->value)[strlen(token) - 2] = '\0';

    free(token);
    return object;
}

json_object* parse_json_number(char *json_string, int *offset) {
    json_object *object = malloc(sizeof(json_object));
    object->type = JSON_NUMBER;

    char *token = get_next_token(json_string, offset);
    if (token == NULL || isalpha(token[0])) {
        free(token);
        free(object);
        return NULL;
    }

    object->value = malloc(sizeof(float));
    *((float*) object->value) = atof(token);

    free(token);
    return object;
}

json_object* parse_json_boolean(char *json_string, int *offset) {
    json_object *object = malloc(sizeof(json_object));
    object->type = JSON_BOOLEAN;

    char *token = get_next_token(json_string, offset);
    if (token == NULL || (strcmp(token, "true") != 0 && strcmp(token, "false") != 0)) {
        free(token);
        free(object);
        return NULL;
    }

    object->value = malloc(sizeof(int));
    if (strcmp(token, "true") == 0) {
        *((int*) object->value) = 1;
    } else {
        *((int*) object->value) = 0;
    }

    free(token);
    return object;
}

int main() {
    char json_string[] = "{\"name\":\"John Doe\", \"age\":30, \"isStudent\":true, \"marks\":[80,85,90], \"address\":{\"street\":\"Main St\", \"city\":\"San Francisco\"}}";

    json_object *root = parse_json(json_string);

    json_object_value *object_value = root->value;
    for (int i = 0; i < object_value->count; i++) {
        printf("Key: %s\n", object_value->pairs[i].key);
        json_object *value = object_value->pairs[i].value;
        if (value->type == JSON_OBJECT) {
            printf("Type: Object\n");
        } else if (value->type == JSON_ARRAY) {
            printf("Type: Array\n");
        } else if (value->type == JSON_STRING) {
            printf("Type: String\n");
            printf("Value: %s\n", (char*) value->value);
        } else if (value->type == JSON_NUMBER) {
            printf("Type: Number\n");
            printf("Value: %f\n", *((float*) value->value));
        } else if (value->type == JSON_BOOLEAN) {
            printf("Type: Boolean\n");
            printf("Value: %s\n", (*((int*) value->value) == 1) ? "true" : "false");
        } else if (value->type == JSON_NULL) {
            printf("Type: Null\n");
        }
    }

    return 0;
}