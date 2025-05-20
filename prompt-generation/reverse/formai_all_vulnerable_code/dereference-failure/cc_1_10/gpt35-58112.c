//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NESTING_DEPTH 32

typedef enum {
    TYPE_NULL,
    TYPE_BOOLEAN,
    TYPE_NUMBER,
    TYPE_STRING,
    TYPE_ARRAY,
    TYPE_OBJECT
} json_type_t;

typedef struct json_value {
    json_type_t type;
    union {
        int boolean;
        double number;
        char *string;
        struct {
            struct json_value **values;
            size_t count;
        } array;
        struct {
            char **keys;
            struct json_value **values;
            size_t count;
        } object;
    } data;
} json_value_t;

typedef struct json_parser {
    const char *input;
    size_t len;
    size_t pos;
    int error;
} json_parser_t;

json_parser_t *new_parser(const char *input) {
    json_parser_t *parser = malloc(sizeof(json_parser_t));

    parser->input = input;
    parser->len = strlen(input);
    parser->pos = 0;
    parser->error = 0;

    return parser;
}

json_value_t *parse_value(json_parser_t *parser);

void skip_whitespace(json_parser_t *parser) {
    while (parser->pos < parser->len && parser->input[parser->pos] == ' ')
        parser->pos++;
}

char peek(json_parser_t *parser) {
    if (parser->pos < parser->len)
        return parser->input[parser->pos];
    else
        return '\0';
}

char next(json_parser_t *parser) {
    if (parser->pos < parser->len)
        return parser->input[parser->pos++];
    else
        return '\0';
}

int expect(json_parser_t *parser, char c) {
    if (parser->pos < parser->len && parser->input[parser->pos] == c) {
        parser->pos++;
        return 1;
    } else {
        parser->error = 1;
        return 0;
    }
}

json_value_t *parse_null(json_parser_t *parser) {
    expect(parser, 'n');
    expect(parser, 'u');
    expect(parser, 'l');
    expect(parser, 'l');

    json_value_t *value = malloc(sizeof(json_value_t));
    value->type = TYPE_NULL;

    return value;
}

json_value_t *parse_boolean(json_parser_t *parser) {
    if (peek(parser) == 't') {
        expect(parser, 't');
        expect(parser, 'r');
        expect(parser, 'u');
        expect(parser, 'e');

        json_value_t *value = malloc(sizeof(json_value_t));
        value->type = TYPE_BOOLEAN;
        value->data.boolean = 1;

        return value;
    } else if (peek(parser) == 'f') {
        expect(parser, 'f');
        expect(parser, 'a');
        expect(parser, 'l');
        expect(parser, 's');
        expect(parser, 'e');

        json_value_t *value = malloc(sizeof(json_value_t));
        value->type = TYPE_BOOLEAN;
        value->data.boolean = 0;

        return value;
    } else {
        parser->error = 1;
        return NULL;
    }
}

json_value_t *parse_number(json_parser_t *parser) {
    char *endptr;
    double number = strtod(&parser->input[parser->pos], &endptr);

    if (endptr == &parser->input[parser->pos])
        parser->error = 1;

    parser->pos += endptr - &parser->input[parser->pos];

    json_value_t *value = malloc(sizeof(json_value_t));
    value->type = TYPE_NUMBER;
    value->data.number = number;

    return value;
}

json_value_t *parse_string(json_parser_t *parser) {
    expect(parser, '\"');

    char *start = &parser->input[parser->pos];
    char *end = strchr(start, '\"');

    if (end == NULL)
        parser->error = 1;

    parser->pos += end - start + 1;

    json_value_t *value = malloc(sizeof(json_value_t));
    value->type = TYPE_STRING;
    value->data.string = strndup(start, end - start);

    return value;
}

json_value_t *parse_array(json_parser_t *parser) {
    expect(parser, '[');

    json_value_t *value = malloc(sizeof(json_value_t));
    value->type = TYPE_ARRAY;
    value->data.array.count = 0;
    value->data.array.values = NULL;

    int depth = 0;

    while (parser->pos < parser->len && depth <= MAX_NESTING_DEPTH) {
        skip_whitespace(parser);

        if (peek(parser) == ']') {
            parser->pos++;
            return value;
        }

        if (value->data.array.count > 0)
            expect(parser, ',');
        skip_whitespace(parser);

        json_value_t **values = realloc(value->data.array.values,
                                         sizeof(json_value_t *) * (value->data.array.count + 1));
        if (values == NULL) {
            parser->error = 1;
            return NULL;
        }

        value->data.array.values = values;
        value->data.array.values[value->data.array.count++] = parse_value(parser);

        if (parser->error)
            return NULL;

        skip_whitespace(parser);

        if (peek(parser) == ',') {
            depth++;
            parser->pos++;
        } else if (peek(parser) == ']') {
            depth--;
        } else {
            parser->error = 1;
            return NULL;
        }
    }

    parser->error = 1;
    return NULL;
}

json_value_t *parse_object(json_parser_t *parser) {
    expect(parser, '{');

    json_value_t *value = malloc(sizeof(json_value_t));
    value->type = TYPE_OBJECT;
    value->data.object.count = 0;
    value->data.object.keys = NULL;
    value->data.object.values = NULL;

    int depth = 0;

    while (parser->pos < parser->len && depth <= MAX_NESTING_DEPTH) {
        skip_whitespace(parser);

        if (peek(parser) == '}') {
            parser->pos++;
            return value;
        }

        if (value->data.object.count > 0)
            expect(parser, ',');
        skip_whitespace(parser);

        char *start = &parser->input[parser->pos];
        char *end = strchr(start, '\"');

        if (end == NULL)
            parser->error = 1;

        parser->pos += end - start + 1;

        char *key = strndup(start, end - start);

        skip_whitespace(parser);
        expect(parser, ':');
        skip_whitespace(parser);

        json_value_t **values = realloc(value->data.object.values,
                                         sizeof(json_value_t *) * (value->data.object.count + 1));
        char **keys = realloc(value->data.object.keys,
                              sizeof(char *) * (value->data.object.count + 1));

        if (values == NULL || keys == NULL) {
            parser->error = 1;
            return NULL;
        }

        value->data.object.values = values;
        value->data.object.keys = keys;
        value->data.object.keys[value->data.object.count] = key;
        value->data.object.values[value->data.object.count++] = parse_value(parser);

        if (parser->error)
            return NULL;

        skip_whitespace(parser);

        if (peek(parser) == ',') {
            depth++;
            parser->pos++;
        } else if (peek(parser) == '}') {
            depth--;
        } else {
            parser->error = 1;
            return NULL;
        }
    }

    parser->error = 1;
    return NULL;
}

json_value_t *parse_value(json_parser_t *parser) {
    skip_whitespace(parser);

    switch (peek(parser)) {
        case 'n':
            return parse_null(parser);
        case 't':
        case 'f':
            return parse_boolean(parser);
        case '\"':
            return parse_string(parser);
        case '[':
            return parse_array(parser);
        case '{':
            return parse_object(parser);
        default:
            return parse_number(parser);
    }
}

void free_value(json_value_t *value) {
    if (value == NULL)
        return;

    switch (value->type) {
        case TYPE_STRING:
            free(value->data.string);
            break;
        case TYPE_ARRAY:
            for (size_t i = 0; i < value->data.array.count; i++)
                free_value(value->data.array.values[i]);
            free(value->data.array.values);
            break;
        case TYPE_OBJECT:
            for (size_t i = 0; i < value->data.object.count; i++) {
                free(value->data.object.keys[i]);
                free_value(value->data.object.values[i]);
            }
            free(value->data.object.keys);
            free(value->data.object.values);
            break;
        default:
            break;
    }

    free(value);
}

int main(void) {
    const char *input = "{ \"hello\": \"world\", \"array\": [1, 2, 3], \"nested\": { \"key\": 123 } }";
    json_parser_t *parser = new_parser(input);
    json_value_t *value = parse_value(parser);

    if (parser->error) {
        printf("Error parsing JSON\n");
    } else {
        printf("Parsed JSON successfully\n");

        free_value(value);
    }

    free(parser);

    return 0;
}