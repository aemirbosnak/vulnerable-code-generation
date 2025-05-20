//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_MAX_DEPTH 100

typedef struct {
    char *key;
    char *value;
    struct json_object *next;
} json_object;

typedef struct {
    int depth;
    json_object *root;
} json_parser;

json_parser *json_parser_init() {
    json_parser *parser = malloc(sizeof(json_parser));
    parser->depth = 0;
    parser->root = NULL;
    return parser;
}

void json_parser_free(json_parser *parser) {
    json_object *object = parser->root;
    while (object) {
        json_object *next = object->next;
        free(object->key);
        free(object->value);
        free(object);
        object = next;
    }
    free(parser);
}

int json_parser_parse(json_parser *parser, const char *json) {
    int i = 0;
    char key[JSON_MAX_DEPTH];
    char value[JSON_MAX_DEPTH];
    json_object *object = NULL;

    while (json[i]) {
        char c = json[i];
        switch (c) {
        case '{':
            if (parser->depth >= JSON_MAX_DEPTH) {
                return -1;
            }
            object = malloc(sizeof(json_object));
            object->key = NULL;
            object->value = NULL;
            object->next = parser->root;
            parser->root = object;
            parser->depth++;
            break;
        case '}':
            if (parser->depth == 0) {
                return -1;
            }
            parser->depth--;
            if (parser->depth > 0) {
                object = parser->root;
            }
            break;
        case ':':
            key[strlen(key)] = '\0';
            break;
        case ',':
            value[strlen(value)] = '\0';
            object->value = strdup(value);
            object->key = strdup(key);
            object = object->next;
            key[0] = '\0';
            value[0] = '\0';
            break;
        case '"':
            i++;
            while (json[i] && json[i] != '"') {
                value[strlen(value)] = json[i];
                i++;
            }
            break;
        default:
            if (parser->depth > 0) {
                key[strlen(key)] = c;
            }
            break;
        }
        i++;
    }

    if (parser->depth != 0) {
        return -1;
    }

    return 0;
}

void json_parser_print(json_parser *parser) {
    json_object *object = parser->root;
    while (object) {
        printf("%s: %s\n", object->key, object->value);
        object = object->next;
    }
}

int main() {
    const char *json = "{ \"name\": \"John Doe\", \"age\": 30, \"city\": \"Los Angeles\" }";
    json_parser *parser = json_parser_init();
    int result = json_parser_parse(parser, json);
    if (result == 0) {
        printf("JSON parsed successfully.\n");
        json_parser_print(parser);
    } else {
        printf("Error parsing JSON.\n");
    }
    json_parser_free(parser);
    return 0;
}