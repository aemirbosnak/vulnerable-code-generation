//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define JSON_TYPE_INT 0
#define JSON_TYPE_FLOAT 1
#define JSON_TYPE_STRING 2
#define JSON_TYPE_BOOL 3
#define JSON_TYPE_ARRAY 4
#define JSON_TYPE_OBJECT 5
#define JSON_MAX_DEPTH 10

typedef struct json_object {
    int type;
    union {
        int int_val;
        float float_val;
        char* string_val;
        int bool_val;
        struct json_object* array_val;
        struct json_object* object_val;
    } data;
} json_object;

char* get_token(char* json, int* index);
json_object* parse_json(char* json, int* index, int depth);
json_object* parse_array(char* json, int* index, int depth);
json_object* parse_object(char* json, int* index, int depth);

// helper function to get the next token in the json string
char* get_token(char* json, int* index) {
    char* token = malloc(sizeof(char) * 256);
    int i = 0;
    char c;
    while ((c = json[*index]) != '\0') {
        if (c == ',' || c == ':' || c == '[' || c == ']' || c == '{' || c == '}' || c == ' ' || c == '\n') {
            (*index)++;
            if (i > 0) {
                token[i] = '\0';
                return token;
            }
        } else {
            token[i] = c;
            i++;
            (*index)++;
        }
    }
    return NULL;
}

// function to parse a json string
json_object* parse_json(char* json, int* index, int depth) {
    if (depth > JSON_MAX_DEPTH) {
        fprintf(stderr, "Error: Maximum JSON depth exceeded");
        exit(1);
    }
    char* token = get_token(json, index);
    if (token == NULL) {
        return NULL;
    }
    json_object* obj = malloc(sizeof(json_object));
    if (strcmp(token, "null") == 0) {
        obj->type = JSON_TYPE_INT;
        obj->data.int_val = 0;
    } else if (strcmp(token, "true") == 0 || strcmp(token, "false") == 0) {
        obj->type = JSON_TYPE_BOOL;
        obj->data.bool_val = strcmp(token, "true") == 0;
    } else if (token[0] == '\"') {
        obj->type = JSON_TYPE_STRING;
        obj->data.string_val = token + 1;
    } else if (token[0] == '[') {
        obj->type = JSON_TYPE_ARRAY;
        obj->data.array_val = parse_array(json, index, depth + 1);
    } else if (token[0] == '{') {
        obj->type = JSON_TYPE_OBJECT;
        obj->data.object_val = parse_object(json, index, depth + 1);
    } else {
        if (strstr(token, ".") == NULL) {
            obj->type = JSON_TYPE_INT;
            obj->data.int_val = atoi(token);
        } else {
            obj->type = JSON_TYPE_FLOAT;
            obj->data.float_val = atof(token);
        }
    }
    free(token);
    return obj;
}

// function to parse a json array
json_object* parse_array(char* json, int* index, int depth) {
    json_object* arr[1024];
    int i = 0;
    while (json[*index] != ']') {
        (*index)++;
        arr[i] = parse_json(json, index, depth);
        i++;
    }
    (*index)++;
    arr[i] = NULL;
    json_object* obj = malloc(sizeof(json_object));
    obj->type = JSON_TYPE_ARRAY;
    obj->data.array_val = malloc(sizeof(json_object) * i);
    memcpy(obj->data.array_val, arr, sizeof(json_object) * i);
    return obj;
}

// function to parse a json object
json_object* parse_object(char* json, int* index, int depth) {
    json_object* obj = malloc(sizeof(json_object));
    obj->type = JSON_TYPE_OBJECT;
    obj->data.object_val = malloc(sizeof(json_object) * 1024);
    int i = 0;
    while (json[*index] != '}') {
        (*index)++;
        char* key = get_token(json, index);
        (*index)++;
        json_object* val = parse_json(json, index, depth);
        obj->data.object_val[i].type = JSON_TYPE_OBJECT;
        obj->data.object_val[i].data.object_val = malloc(sizeof(json_object) * 2);
        obj->data.object_val[i].data.object_val[0].type = JSON_TYPE_STRING;
        obj->data.object_val[i].data.object_val[0].data.string_val = key;
        obj->data.object_val[i].data.object_val[1] = *val;
        i++;
        (*index)++;
        free(key);
        free(val);
    }
    obj->data.object_val[i].type = JSON_TYPE_INT;
    obj->data.object_val[i].data.int_val = 0;
    return obj;
}

int main() {
    char json[] = "{ \"foo\": [1, 2, 3], \"bar\": { \"a\": true, \"b\": 3.14159, \"c\": null } }";
    int index = 0;
    json_object* obj = parse_json(json, &index, 0);
    printf("JSON type: %d\n", obj->type);
    printf("JSON array element 1 type: %d\n", obj->data.object_val[0].data.array_val[0].type);
    printf("JSON object key: %s\n", obj->data.object_val[1].data.object_val[0].data.string_val);
    printf("JSON object value type: %d\n", obj->data.object_val[1].data.object_val[1].type);
    free(obj);
    return 0;
}