//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { FALSE, TRUE } bool;

typedef enum { 
    JSON_NULL, 
    JSON_BOOLEAN, 
    JSON_NUMBER, 
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT 
} json_type;

typedef struct json_object_tag json_object;
typedef struct json_array_tag json_array;
typedef struct json_value_tag json_value;
typedef struct json_string_tag json_string;
typedef struct json_parser_tag json_parser;

struct json_value_tag {
    json_type type;
};

struct json_string_tag {
    json_type type;
    char* value;
};

json_string* json_string_create(const char* value) {
    json_string* string = (json_string*)malloc(sizeof(json_string));
    string->type = JSON_STRING;
    string->value = strdup(value);
    return string;
}

struct json_object_tag {
    json_type type;
    int size;
    char** keys;
    json_value** values;
};

json_object* json_object_create() {
    json_object* object = (json_object*)malloc(sizeof(json_object));
    object->type = JSON_OBJECT;
    object->size = 0;
    object->keys = NULL;
    object->values = NULL;
    return object;
}

struct json_array_tag {
    json_type type;
    int size;
    json_value** values;
};

json_array* json_array_create() {
    json_array* array = (json_array*)malloc(sizeof(json_array));
    array->type = JSON_ARRAY;
    array->size = 0;
    array->values = NULL;
    return array;
}

struct json_parser_tag {
    char* current;
    char* end;
};

json_parser* json_parser_create() {
    json_parser* parser = (json_parser*)malloc(sizeof(json_parser));
    parser->current = NULL;
    parser->end = NULL;
    return parser;
}

void json_parser_set_input(json_parser* parser, const char* input) {
    parser->current = (char*)input;
    parser->end = parser->current + strlen(input);
}

bool json_parser_is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void json_parser_skip_whitespace(json_parser* parser) {
    while (parser->current < parser->end && json_parser_is_whitespace(*parser->current)) {
        parser->current++;
    }
}

bool json_parser_is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool json_parser_is_hex(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

json_value* json_parse_value(json_parser* parser);

json_string* json_parser_parse_string(json_parser* parser) {
    json_string* string = NULL;
    char* start = NULL;
    char* end = NULL;

    if (parser->current < parser->end && *parser->current == '"') {
        parser->current++;

        start = parser->current;
        while (parser->current < parser->end && *parser->current != '"') {
            if (*parser->current == '\\') {
                parser->current++;
            }
            parser->current++;
        }

        end = parser->current++;
        if (start && end) {
            int length = end - start;
            char* value = (char*)malloc(length + 1);
            memcpy(value, start, length);
            value[length] = '\0';
            string = json_string_create(value);
        }
    }

    return (json_value*)string;
}

json_value* json_parser_parse_number(json_parser* parser) {
    json_value* number = NULL;
    char* start = NULL;
    char* end = NULL;

    if (parser->current < parser->end && json_parser_is_digit(*parser->current)) {
        start = parser->current;
        while (parser->current < parser->end && json_parser_is_digit(*parser->current)) {
            parser->current++;
        }

        if (parser->current < parser->end && *parser->current == '.') {
            parser->current++;
            while (parser->current < parser->end && json_parser_is_digit(*parser->current)) {
                parser->current++;
            }
        }

        if (parser->current < parser->end && (*parser->current == 'e' || *parser->current == 'E')) {
            parser->current++;
            if (parser->current < parser->end && (*parser->current == '-' || *parser->current == '+')) {
                parser->current++;
            }
            while (parser->current < parser->end && json_parser_is_digit(*parser->current)) {
                parser->current++;
            }
        }

        end = parser->current;
        if (start && end) {
            int length = end - start;
            char* value = (char*)malloc(length + 1);
            memcpy(value, start, length);
            value[length] = '\0';
            number = (json_value*)json_string_create(value);
            number->type = JSON_NUMBER;
        }
    }

    return number;
}

json_value* json_parser_parse_boolean(json_parser* parser) {
    json_value* boolean = NULL;

    if (parser->current < parser->end && strncmp(parser->current, "true", 4) == 0) {
        boolean = (json_value*)malloc(sizeof(json_value));
        boolean->type = JSON_BOOLEAN;
        parser->current += 4;
    } else if (parser->current < parser->end && strncmp(parser->current, "false", 5) == 0) {
        boolean = (json_value*)malloc(sizeof(json_value));
        boolean->type = JSON_BOOLEAN;
        parser->current += 5;
    }

    return boolean;
}

json_value* json_parser_parse_null(json_parser* parser) {
    json_value* null = NULL;

    if (parser->current < parser->end && strncmp(parser->current, "null", 4) == 0) {
        null = (json_value*)malloc(sizeof(json_value));
        null->type = JSON_NULL;
        parser->current += 4;
    }

    return null;
}

json_array* json_parser_parse_array(json_parser* parser) {
    json_array* array = NULL;
    json_value* value = NULL;

    if (parser->current < parser->end && *parser->current == '[') {
        parser->current++;
        json_parser_skip_whitespace(parser);
        array = json_array_create();
        while (parser->current < parser->end && *parser->current != ']') {
            value = json_parse_value(parser);
            if (value) {
                array->size++;
                array->values = (json_value**)realloc(array->values, array->size * sizeof(json_value*));
                array->values[array->size - 1] = value;

                json_parser_skip_whitespace(parser);
                if (parser->current < parser->end && *parser->current == ',') {
                    parser->current++;
                    json_parser_skip_whitespace(parser);
                } else if (parser->current < parser->end && *parser->current != ']') {
                    break;
                }
            } else {
                break;
            }
        }

        if (parser->current < parser->end && *parser->current == ']') {
            parser->current++;
            return (json_value*)array;
        } else {
            return NULL;
        }
    }

    return array;
}

json_object* json_parser_parse_object(json_parser* parser) {
    json_object* object = NULL;
    json_value* value = NULL;
    json_string* key = NULL;

    if (parser->current < parser->end && *parser->current == '{') {
        parser->current++;
        json_parser_skip_whitespace(parser);
        object = json_object_create();
        while (parser->current < parser->end && *parser->current != '}') {
            key = json_parser_parse_string(parser);
            if (key) {
                json_parser_skip_whitespace(parser);
                if (parser->current < parser->end && *parser->current == ':') {
                    parser->current++;
                    json_parser_skip_whitespace(parser);
                    value = json_parse_value(parser);
                    if (value) {
                        object->size++;
                        object->keys = (char**)realloc(object->keys, object->size * sizeof(char*));
                        object->values = (json_value**)realloc(object->values, object->size * sizeof(json_value*));
                        object->keys[object->size - 1] = key->value;
                        object->values[object->size - 1] = value;

                        json_parser_skip_whitespace(parser);
                        if (parser->current < parser->end && *parser->current == ',') {
                            parser->current++;
                            json_parser_skip_whitespace(parser);
                        } else if (parser->current < parser->end && *parser->current != '}') {
                            break;
                        }
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            } else {
                break;
            }
        }

        if (parser->current < parser->end && *parser->current == '}') {
            parser->current++;
            return (json_value*)object;
        } else {
            return NULL;
        }
    }

    return object;
}

json_value* json_parse_value(json_parser* parser) {
    json_value* value = NULL;
    json_parser_skip_whitespace(parser);

    if (parser->current < parser->end) {
        switch (*parser->current) {
            case 'n':
                value = json_parser_parse_null(parser);
                break;
            case 't':
            case 'f':
                value = json_parser_parse_boolean(parser);
                break;
            case '"':
                value = (json_value*)json_parser_parse_string(parser);
                break;
            case '-':
            case '0'...'9':
                value = json_parser_parse_number(parser);
                break;
            case '[':
                value = (json_value*)json_parser_parse_array(parser);
                break;
            case '{':
                value = (json_value*)json_parser_parse_object(parser);
                break;
            default:
                break;
        }
    }

    return value;
}

int main(int argc, char** argv) {
    json_parser* parser = json_parser_create();
    const char* json = "{\"name\":\"John Smith\",\"age\":30,\"city\":\"New York\"}";
    json_parser_set_input(parser, json);
    json_object* object = json_parser_parse_object(parser);

    if (object) {
        for (int i = 0; i < object->size; i++) {
            json_string* key = (json_string*)object->values[i];
            json_value* value = object->values[i + 1];
            printf("\"%s\": ", key->value);
            switch (value->type) {
                case JSON_NULL:
                    printf("null\n");
                    break;
                case JSON_BOOLEAN:
                    printf(value ? "true\n" : "false\n");
                    break;
                case JSON_STRING:
                    printf("\"%s\"\n", ((json_string*)value)->value);
                    break;
                case JSON_NUMBER:
                    printf("%s\n", ((json_string*)value)->value);
                    break;
                case JSON_ARRAY:
                    printf("[\n");
                    for (int j = 0; j < ((json_array*)value)->size; j++) {
                        json_value* element = ((json_array*)value)->values[j];
                        switch (element->type) {
                            case JSON_NULL:
                                printf("  null\n");
                                break;
                            case JSON_BOOLEAN:
                                printf(element ? "  true\n" : "  false\n");
                                break;
                            case JSON_STRING:
                                printf("  \"%s\"\n", ((json_string*)element)->value);
                                break;
                            case JSON_NUMBER:
                                printf("  %s\n", ((json_string*)element)->value);
                                break;
                            default:
                                break;
                        }
                    }
                    printf("]\n");
                    break;
                case JSON_OBJECT:
                    printf("{\n");
                    for (int j = 0; j < ((json_object*)value)->size; j++) {
                        json_string* key = (json_string*)((json_object*)value)->values[j];
                        json_value* element = ((json_object*)value)->values[j + 1];
                        printf("  \"%s\": ", key->value);
                        switch (element->type) {
                            case JSON_NULL:
                                printf("null\n");
                                break;
                            case JSON_BOOLEAN:
                                printf(element ? "true\n" : "false\n");
                                break;
                            case JSON_STRING:
                                printf("\"%s\"\n", ((json_string*)element)->value);
                                break;
                            case JSON_NUMBER:
                                printf("%s\n", ((json_string*)element)->value);
                                break;
                            default:
                                break;
                        }
                    }
                    printf("}\n");
                    break;
                default:
                    break;
            }
        }
    }

    return 0;
}