//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_JSON_OBJECTS 1024
#define MAX_JSON_DEPTH 32

typedef enum {
    JSON_OBJECT_NULL,
    JSON_OBJECT_BOOLEAN,
    JSON_OBJECT_NUMBER,
    JSON_OBJECT_STRING,
    JSON_OBJECT_ARRAY,
    JSON_OBJECT_OBJECT
} json_object_type_t;

typedef struct {
    json_object_type_t type;
    union {
        int boolean;
        double number;
        char* string;
        struct {
            int count;
            void** values;
        } array;
        struct {
            int count;
            char** keys;
            void** values;
        } object;
    } data;
} json_object_t;

typedef struct {
    char* data;
    int index;
    int length;
} json_parser_t;

void json_skip_whitespace(json_parser_t* parser) {
    while (isspace(parser->data[parser->index])) {
        parser->index++;
    }
}

int json_parse_string(json_parser_t* parser, char** value) {
    int start = parser->index;

    while (parser->index < parser->length) {
        if (parser->data[parser->index] == '\"') {
            int end = parser->index++;
            *value = (char*)malloc(end - start + 1);
            memcpy(*value, &parser->data[start], end - start);
            (*value)[end - start] = '\0';

            return 1;
        } else if (parser->data[parser->index] == '\\') {
            parser->index++;
        }

        parser->index++;
    }

    return 0;
}

int json_parse_number(json_parser_t* parser, double* value) {
    int start = parser->index;

    while (isdigit(parser->data[parser->index]) || parser->data[parser->index] == '.') {
        parser->index++;
    }

    if (parser->index > start) {
        char temp = parser->data[parser->index];
        parser->data[parser->index] = '\0';
        *value = strtod(&parser->data[start], NULL);
        parser->data[parser->index] = temp;

        return 1;
    }

    return 0;
}

int json_parse_boolean(json_parser_t* parser, int* value) {
    if (strncmp(&parser->data[parser->index], "true", 4) == 0) {
        *value = 1;
        parser->index += 4;
        return 1;
    }

    if (strncmp(&parser->data[parser->index], "false", 5) == 0) {
        *value = 0;
        parser->index += 5;
        return 1;
    }

    return 0;
}

void json_delete_object(json_object_t* object) {
    switch(object->type) {
        case JSON_OBJECT_STRING:
            free((char*)object->data.string);
            break;
        case JSON_OBJECT_ARRAY: {
            int i;
            for (i = 0; i < object->data.array.count; i++) {
                json_delete_object(object->data.array.values[i]);
                free(object->data.array.values[i]);
            }
            free(object->data.array.values);
            break;
        }
        case JSON_OBJECT_OBJECT: {
            int i;
            for (i = 0; i < object->data.object.count; i++) {
                free(object->data.object.keys[i]);
                json_delete_object(object->data.object.values[i]);
                free(object->data.object.values[i]);
            }
            free(object->data.object.keys);
            free(object->data.object.values);
            break;
        }
        default:
            break;
    }
}

int json_parse_value(json_parser_t* parser, json_object_t* object, int depth) {
    json_skip_whitespace(parser);

    if (depth >= MAX_JSON_DEPTH) {
        return 0;
    }

    switch(parser->data[parser->index]) {
        case '{': {
            int i = 0;

            parser->index++;
            object->type = JSON_OBJECT_OBJECT;

            json_skip_whitespace(parser);

            if (parser->data[parser->index] == '}') {
                parser->index++;
                return 1;
            }

            while (1) {
                char* key = NULL;
                json_object_t* value = NULL;

                if (!json_parse_string(parser, &key)) {
                    break;
                }

                json_skip_whitespace(parser);

                if (parser->data[parser->index++] != ':') {
                    free(key);
                    return 0;
                }

                json_skip_whitespace(parser);

                value = (json_object_t*)malloc(sizeof(json_object_t));
                memset(value, 0, sizeof(json_object_t));

                if (json_parse_value(parser, value, depth + 1)) {
                    object->data.object.count++;
                    object->data.object.keys =
                        (char**)realloc(object->data.object.keys, object->data.object.count * sizeof(char*));
                    object->data.object.values =
                        (void**)realloc(object->data.object.values, object->data.object.count * sizeof(void*));
                    object->data.object.keys[object->data.object.count - 1] = key;
                    object->data.object.values[object->data.object.count - 1] = value;
                } else {
                    free(key);
                    json_delete_object(value);
                    free(value);
                }

                json_skip_whitespace(parser);

                if (parser->data[parser->index] == '}') {
                    parser->index++;
                    break;
                } else if (parser->data[parser->index++] != ',') {
                    return 0;
                }

                json_skip_whitespace(parser);
            }

            return 1;
        }
        case '[': {
            int i = 0;

            parser->index++;
            object->type = JSON_OBJECT_ARRAY;

            json_skip_whitespace(parser);

            if (parser->data[parser->index] == ']') {
                parser->index++;
                return 1;
            }

            while (1) {
                json_object_t* value = (json_object_t*)malloc(sizeof(json_object_t));
                memset(value, 0, sizeof(json_object_t));

                if (json_parse_value(parser, value, depth + 1)) {
                    object->data.array.count++;
                    object->data.array.values =
                        (void**)realloc(object->data.array.values, object->data.array.count * sizeof(void*));
                    object->data.array.values[object->data.array.count - 1] = value;
                } else {
                    json_delete_object(value);
                    free(value);
                }

                json_skip_whitespace(parser);

                if (parser->data[parser->index] == ']') {
                    parser->index++;
                    break;
                } else if (parser->data[parser->index++] != ',') {
                    return 0;
                }

                json_skip_whitespace(parser);
            }

            return 1;
        }
        case '\"': {
            char* string = NULL;

            if (json_parse_string(parser, &string)) {
                object->type = JSON_OBJECT_STRING;
                object->data.string = string;

                return 1;
            }

            return 0;
        }
        case 't':
        case 'f': {
            int boolean = 0;

            if (json_parse_boolean(parser, &boolean)) {
                object->type = JSON_OBJECT_BOOLEAN;
                object->data.boolean = boolean;

                return 1;
            }

            return 0;
        }
        default: {
            double number = 0;

            if (json_parse_number(parser, &number)) {
                object->type = JSON_OBJECT_NUMBER;
                object->data.number = number;

                return 1;
            }

            return 0;
        }
    }
}

json_object_t* json_parse(char* json) {
    json_parser_t* parser = (json_parser_t*)malloc(sizeof(json_parser_t));
    json_object_t* root = NULL;

    memset(parser, 0, sizeof(json_parser_t));
    parser->data = json;
    parser->length = strlen(json);

    root = (json_object_t*)malloc(sizeof(json_object_t));
    memset(root, 0, sizeof(json_object_t));

    if (!json_parse_value(parser, root, 0)) {
        json_delete_object(root);
        free(root);
        root = NULL;
    }

    free(parser);

    return root;
}

void json_print(json_object_t* object, int depth) {
    int i;

    switch(object->type) {
        case JSON_OBJECT_BOOLEAN:
            printf("%s", object->data.boolean ? "true" : "false");
            break;
        case JSON_OBJECT_NUMBER:
            printf("%g", object->data.number);
            break;
        case JSON_OBJECT_STRING:
            printf("\"%s\"", object->data.string);
            break;
        case JSON_OBJECT_ARRAY:
            printf("[");
            for (i = 0; i < object->data.array.count; i++) {
                if (i > 0) printf(", ");
                json_print((json_object_t*)object->data.array.values[i], depth + 1);
            }
            printf("]");
            break;
        case JSON_OBJECT_OBJECT:
            printf("{");
            for (i = 0; i < object->data.object.count; i++) {
                if (i > 0) printf(", ");
                printf("\n%*s\"%s\": ", (depth + 1) * 2, "", object->data.object.keys[i]);
                json_print((json_object_t*)object->data.object.values[i], depth + 1);
            }
            if (i > 0) printf("\n%*s", depth * 2, "");
            printf("}");
            break;
        default:
            printf("null");
            break;
    }
}

int main() {
    char json[] = "{\"name\": \"John Smith\", \"age\": 27, \"is_employed\": true, \"hobbies\": [\"reading\", \"swimming\", \"cooking\"], \"address\": {\"street\": \"123 Main St\", \"city\": \"Anytown\", \"state\": \"CO\", \"zip\": \"12345\"}}";
    json_object_t* root = json_parse(json);

    if (root) {
        json_print(root, 0);
        printf("\n");

        json_delete_object(root);
        free(root);
    }

    return 0;
}