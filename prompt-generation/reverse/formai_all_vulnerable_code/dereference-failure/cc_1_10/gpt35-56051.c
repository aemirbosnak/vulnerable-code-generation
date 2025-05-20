//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} JsonType;

typedef struct json_object_t {
    char *key;
    struct json_t *value;
    struct json_object_t *next;
} JsonObject;

typedef struct json_array_t {
    struct json_t *value;
    struct json_array_t *next;
} JsonArray;

typedef struct json_t {
    JsonType type;
    union {
        char *string_value;
        double number_value;
        JsonObject *object_value;
        JsonArray *array_value;
    } data;
} Json;

int is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

void skip_whitespace(char **json) {
    while (is_whitespace(**json)) {
        (*json)++;
    }
}

Json *parse_value(char **json);

Json *parse_object(char **json) {
    skip_whitespace(json);
    if (**json != '{') {
        fprintf(stderr, "Unexpected character in object: '%c'\n", **json);
        return NULL;
    }
    (*json)++;
    JsonObject *object = NULL;
    skip_whitespace(json);
    while (**json != '}') {
        skip_whitespace(json);
        if (**json == ',') {
            (*json)++;
            skip_whitespace(json);
        }
        if (**json == '}') {
            break;
        }
        if (**json != '"') {
            fprintf(stderr, "Unexpected character in object: '%c'\n", **json);
            return NULL;
        }
        (*json)++;
        char *key = malloc(sizeof(char) * 256);
        int i;
        for (i = 0; i < 255 && **json != '"'; i++, (*json)++) {
            key[i] = **json;
        }
        key[i] = '\0';
        if (**json != '"') {
            fprintf(stderr, "Unexpected character in object: '%c'\n", **json);
            return NULL;
        }
        (*json)++;
        skip_whitespace(json);
        if (**json != ':') {
            fprintf(stderr, "Unexpected character in object: '%c'\n", **json);
            return NULL;
        }
        (*json)++;
        skip_whitespace(json);
        Json *value = parse_value(json);
        if (value == NULL) {
            fprintf(stderr, "Expected value in object\n");
            return NULL;
        }
        JsonObject *next = malloc(sizeof(JsonObject));
        next->key = key;
        next->value = value;
        next->next = object;
        object = next;
    }
    (*json)++;
    Json *result = malloc(sizeof(Json));
    result->type = JSON_OBJECT;
    result->data.object_value = object;
    return result;
}

Json *parse_array(char **json) {
    skip_whitespace(json);
    if (**json != '[') {
        fprintf(stderr, "Unexpected character in array: '%c'\n", **json);
        return NULL;
    }
    (*json)++;
    JsonArray *array = NULL;
    skip_whitespace(json);
    while (**json != ']') {
        skip_whitespace(json);
        if (**json == ',') {
            (*json)++;
            skip_whitespace(json);
        }
        if (**json == ']') {
            break;
        }
        Json *value = parse_value(json);
        if (value == NULL) {
            fprintf(stderr, "Expected value in array\n");
            return NULL;
        }
        JsonArray *next = malloc(sizeof(JsonArray));
        next->value = value;
        next->next = array;
        array = next;
    }
    (*json)++;
    Json *result = malloc(sizeof(Json));
    result->type = JSON_ARRAY;
    result->data.array_value = array;
    return result;
}

Json *parse_string(char **json) {
    skip_whitespace(json);
    if (**json != '"') {
        fprintf(stderr, "Unexpected character in string: '%c'\n", **json);
        return NULL;
    }
    (*json)++;
    char *string = malloc(sizeof(char) * 256);
    int i;
    for (i = 0; i < 255 && **json != '"'; i++, (*json)++) {
        string[i] = **json;
    }
    string[i] = '\0';
    if (**json != '"') {
        fprintf(stderr, "Unexpected character in string: '%c'\n", **json);
        return NULL;
    }
    (*json)++;
    Json *result = malloc(sizeof(Json));
    result->type = JSON_STRING;
    result->data.string_value = string;
    return result;
}

Json *parse_number(char **json) {
    skip_whitespace(json);
    char string[256] = "";
    int i;
    for (i = 0; i < 255 && (**json == '.' || (**json >= '0' && **json <= '9')); i++, (*json)++) {
        string[i] = **json;
    }
    string[i] = '\0';
    double number = atof(string);
    Json *result = malloc(sizeof(Json));
    result->type = JSON_NUMBER;
    result->data.number_value = number;
    return result;
}

Json *parse_true(char **json) {
    skip_whitespace(json);
    if (strncmp(*json, "true", 4) != 0) {
        fprintf(stderr, "Unexpected value: '%s'\n", *json);
        return NULL;
    }
    *json += 4;
    Json *result = malloc(sizeof(Json));
    result->type = JSON_TRUE;
    return result;
}

Json *parse_false(char **json) {
    skip_whitespace(json);
    if (strncmp(*json, "false", 5) != 0) {
        fprintf(stderr, "Unexpected value: '%s'\n", *json);
        return NULL;
    }
    *json += 5;
    Json *result = malloc(sizeof(Json));
    result->type = JSON_FALSE;
    return result;
}

Json *parse_null(char **json) {
    skip_whitespace(json);
    if (strncmp(*json, "null", 4) != 0) {
        fprintf(stderr, "Unexpected value: '%s'\n", *json);
        return NULL;
    }
    *json += 4;
    Json *result = malloc(sizeof(Json));
    result->type = JSON_NULL;
    return result;
}

Json *parse_value(char **json) {
    skip_whitespace(json);
    switch (**json) {
        case '{':
            return parse_object(json);
        case '[':
            return parse_array(json);
        case '"':
            return parse_string(json);
        case '-':
        case '.':
        case '0'...'9':
            return parse_number(json);
        case 't':
            return parse_true(json);
        case 'f':
            return parse_false(json);
        case 'n':
            return parse_null(json);
        default:
            fprintf(stderr, "Unexpected character: '%c'\n", **json);
            return NULL;
    }
}

Json *parse(char *json) {
    return parse_value(&json);
}

int main() {
    char *json = "{"
                 "    \"name\": \"John Smith\","
                 "    \"age\": 27,"
                 "    \"languages\": ["
                 "        \"English\","
                 "        \"Spanish\","
                 "        \"French\""
                 "    ],"
                 "    \"isMarried\": false,"
                 "    \"spouse\": null,"
                 "    \"children\": ["
                 "        {"
                 "            \"name\": \"Samantha\","
                 "            \"age\": 3"
                 "        },"
                 "        {"
                 "            \"name\": \"Michael\","
                 "            \"age\": 1"
                 "        }"
                 "    ]"
                 "}";
    Json *result = parse(json);
    if (result != NULL) {
        printf("Parsed successfully\n");
    }
    return 0;
}