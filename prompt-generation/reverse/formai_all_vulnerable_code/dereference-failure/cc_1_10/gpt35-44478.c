//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { JSON_OBJECT, JSON_ARRAY, JSON_STRING, JSON_NUMBER, JSON_BOOLEAN, JSON_NULL } json_type_t;

typedef struct {
    json_type_t type;
    union {
        char *string;
        double number;
        int boolean;
        struct json_object *object;
        struct json_array *array;
    } value;
} json_token_t;

typedef struct json_object {
    char *key;
    json_token_t token;
    struct json_object *next;
} json_object_t;

typedef struct json_array {
    json_token_t *tokens;
    int size;
    int capacity;
} json_array_t;

json_token_t parse_json_token(char *json);

json_array_t *parse_json_array(char *json, int *pos);

json_object_t *parse_json_object(char *json, int *pos);

json_token_t parse_json_token(char *json) {
    json_token_t token;
    int len = strlen(json);
    if (json[0] == '{') {
        token.type = JSON_OBJECT;
        int pos = 1;
        token.value.object = parse_json_object(json, &pos);
        return token;
    } else if (json[0] == '[') {
        token.type = JSON_ARRAY;
        int pos = 1;
        token.value.array = parse_json_array(json, &pos);
        return token;
    } else if (strncmp(json, "true", 4) == 0) {
        token.type = JSON_BOOLEAN;
        token.value.boolean = 1;
        return token;
    } else if (strncmp(json, "false", 5) == 0) {
        token.type = JSON_BOOLEAN;
        token.value.boolean = 0;
        return token;
    } else if (strncmp(json, "null", 4) == 0) {
        token.type = JSON_NULL;
        return token;
    } else if (json[0] == '\"') {
        token.type = JSON_STRING;
        token.value.string = malloc(len-1);
        strncpy(token.value.string, json+1, len-2);
        token.value.string[len-2] = '\0';
        return token;
    } else {
        token.type = JSON_NUMBER;
        token.value.number = atof(json);
        return token;
    }
}

json_array_t *parse_json_array(char *json, int *pos) {
    json_array_t *array = malloc(sizeof(json_array_t));
    array->size = 0;
    array->capacity = 4;
    array->tokens = malloc(array->capacity * sizeof(json_token_t));
    int len = strlen(json);
    while (*pos < len) {
        if (json[*pos] == ',') {
            (*pos)++;
            continue;
        } else if (json[*pos] == ']') {
            (*pos)++;
            return array;
        }
        array->tokens[array->size] = parse_json_token(json + *pos);
        (*pos) += strlen(json + *pos);
        array->size++;
        if (array->size == array->capacity) {
            array->capacity *= 2;
            array->tokens = realloc(array->tokens, array->capacity * sizeof(json_token_t));
        }
    }
    return array;
}

json_object_t *parse_json_object(char *json, int *pos) {
    json_object_t *object = NULL;
    json_object_t *tail = NULL;
    int len = strlen(json);
    while (*pos < len) {
        if (json[*pos] == ',') {
            (*pos)++;
            continue;
        } else if (json[*pos] == '}') {
            (*pos)++;
            return object;
        }
        char *key = malloc(50);
        int keylen = 0;
        while (json[*pos] != ':') {
            key[keylen++] = json[(*pos)++];
        }
        key[keylen] = '\0';
        (*pos)++;
        json_token_t token = parse_json_token(json + *pos);
        (*pos) += strlen(json + *pos);
        json_object_t *newobj = malloc(sizeof(json_object_t));
        newobj->key = key;
        newobj->token = token;
        newobj->next = NULL;
        if (!object) {
            object = newobj;
            tail = newobj;
        } else {
            tail->next = newobj;
            tail = newobj;
        }
        if (json[*pos] == '}') {
            (*pos)++;
            return object;
        }
    }
    return object;
}

int main() {
    char *json = "{\"name\":\"John\",\"age\":30,\"cars\":[\"Ford\",\"BMW\",\"Fiat\"],\"pets\":{\"dog\":{\"name\":\"Barkley\",\"age\":3},\"cat\":{\"name\":\"Whiskers\",\"age\":2}},\"has_children\":false}";
    json_token_t token = parse_json_token(json);
    printf("Name: %s\n", token.value.object->next->token.value.string);
    printf("Age: %g\n", token.value.object->next->next->token.value.number);
    printf("First car: %s\n", token.value.object->next->next->next->token.value.array->tokens[0].value.string);
    printf("Dog name: %s\n", token.value.object->next->next->next->next->token.value.object->token.value.string);
    printf("Cat age: %g\n", token.value.object->next->next->next->next->next->token.value.object->next->token.value.number);
    printf("Has children: %s\n", token.value.object->next->next->next->next->next->next->token.value.boolean ? "true" : "false");
    return 0;
}