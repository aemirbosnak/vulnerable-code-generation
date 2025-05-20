//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_T_OBJECT,
    JSON_T_ARRAY,
    JSON_T_STRING,
    JSON_T_NUMBER,
    JSON_T_BOOLEAN,
    JSON_T_NULL
} json_type;

typedef struct json_value_t {
    json_type type;
    void* value;
    int length;
} json_value;

void* parse_json_value(char* json_str, int* index);

void* parse_json_object(char* json_str, int* index) {
    json_value* object = malloc(sizeof(json_value));
    object->type = JSON_T_OBJECT;
    object->value = NULL;
    object->length = 0;

    // start parsing
    printf("Parsing object... \n");

    // TODO: implement object parsing logic

    return object;
}

void* parse_json_value(char* json_str, int* index) {
    if (json_str[*index] == '{') {
        return parse_json_object(json_str, index);
    }
    // TODO: implement logic for other value types
    return NULL;
}

int main(int argc, char* argv[]) {
    char* test_json = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";

    int index = 0;
    json_value* root = parse_json_value(test_json, &index);

    printf("JSON: %s\n", test_json);

    // TODO: implement print functionality for JSON object

    return 0;
}