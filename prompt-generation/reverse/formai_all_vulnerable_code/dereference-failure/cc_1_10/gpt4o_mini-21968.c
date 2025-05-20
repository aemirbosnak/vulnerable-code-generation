//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 1024
#define MAX_TOKENS 100

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL
} JsonType;

typedef struct json_token {
    JsonType type;
    char *key; // Only used for objects
    char *value; // Only used for strings and numbers
    struct json_token *next;
} JsonToken;

typedef struct json_parser {
    const char *input;
    size_t pos;
} JsonParser;

JsonParser *create_parser(const char *input) {
    JsonParser *parser = (JsonParser *)malloc(sizeof(JsonParser));
    parser->input = input;
    parser->pos = 0;
    return parser;
}

void free_token(JsonToken *token) {
    if (token) {
        free(token->key);
        free(token->value);
        free(token);
    }
}

void free_tokens(JsonToken *token) {
    while (token) {
        JsonToken *next = token->next;
        free_token(token);
        token = next;
    }
}

void skip_whitespace(JsonParser *parser) {
    while (isspace(parser->input[parser->pos])) {
        parser->pos++;
    }
}

JsonToken *parse_value(JsonParser *parser);

JsonToken *parse_string(JsonParser *parser) {
    JsonToken *token = (JsonToken *)malloc(sizeof(JsonToken));
    token->type = JSON_STRING;
    token->key = NULL;
    token->value = NULL;
    token->next = NULL;

    if (parser->input[parser->pos] != '\"') {
        free(token);
        return NULL; // Not a string
    }

    parser->pos++; // Skip opening quote
    size_t start_pos = parser->pos;

    while (parser->input[parser->pos] != '\"') {
        if (parser->input[parser->pos] == '\\') {
            parser->pos++; // Skip escape character
        }
        parser->pos++;
    }

    size_t length = parser->pos - start_pos;
    token->value = (char *)malloc(length + 1);
    strncpy(token->value, parser->input + start_pos, length);
    token->value[length] = '\0';

    parser->pos++; // Skip closing quote
    return token;
}

JsonToken *parse_number(JsonParser *parser) {
    JsonToken *token = (JsonToken *)malloc(sizeof(JsonToken));
    token->type = JSON_NUMBER;
    token->key = NULL;
    token->value = NULL;
    token->next = NULL;

    size_t start_pos = parser->pos;

    while (isdigit(parser->input[parser->pos]) || parser->input[parser->pos] == '-') {
        parser->pos++;
    }

    size_t length = parser->pos - start_pos;
    token->value = (char *)malloc(length + 1);
    strncpy(token->value, parser->input + start_pos, length);
    token->value[length] = '\0';

    return token;
}

JsonToken *parse_bool_or_null(JsonParser *parser) {
    JsonToken *token = (JsonToken *)malloc(sizeof(JsonToken));
    token->key = NULL;
    token->value = NULL;
    token->next = NULL;

    if (strncmp(&parser->input[parser->pos], "true", 4) == 0) {
        token->type = JSON_BOOL;
        token->value = strdup("true");
        parser->pos += 4;
    } else if (strncmp(&parser->input[parser->pos], "false", 5) == 0) {
        token->type = JSON_BOOL;
        token->value = strdup("false");
        parser->pos += 5;
    } else if (strncmp(&parser->input[parser->pos], "null", 4) == 0) {
        token->type = JSON_NULL;
        token->value = strdup("null");
        parser->pos += 4;
    } else {
        free(token);
        return NULL;
    }

    return token;
}

JsonToken *parse_array(JsonParser *parser) {
    JsonToken *array = (JsonToken *)malloc(sizeof(JsonToken));
    array->type = JSON_ARRAY;
    array->key = NULL;
    array->value = NULL;
    array->next = NULL;

    parser->pos++; // Skip opening bracket

    skip_whitespace(parser);
    JsonToken *last_token = NULL;

    while (parser->input[parser->pos] != ']') {
        JsonToken *value = parse_value(parser);
        if (!value) {
            free(array);
            return NULL; // Error in parsing value
        }
        if (last_token) {
            last_token->next = value;
        } else {
            array->next = value;
        }
        last_token = value;

        skip_whitespace(parser);
        if (parser->input[parser->pos] == ',') {
            parser->pos++; // Skip comma
        }
        skip_whitespace(parser);
    }

    parser->pos++; // Skip closing bracket
    return array;
}

JsonToken *parse_object(JsonParser *parser) {
    JsonToken *object = (JsonToken *)malloc(sizeof(JsonToken));
    object->type = JSON_OBJECT;
    object->key = NULL;
    object->value = NULL;
    object->next = NULL;

    parser->pos++; // Skip opening brace

    skip_whitespace(parser);
    JsonToken *last_token = NULL;

    while (parser->input[parser->pos] != '}') {
        JsonToken *key = parse_string(parser);
        if (!key) {
            free(object);
            return NULL; // Error in parsing key
        }

        skip_whitespace(parser);
        if (parser->input[parser->pos] != ':') {
            free_token(key);
            free(object);
            return NULL; // Expected colon
        }
        parser->pos++; // Skip colon

        JsonToken *value = parse_value(parser);
        if (!value) {
            free_token(key);
            free(object);
            return NULL; // Error in parsing value
        }
        value->key = key->value; // Store the key

        if (last_token) {
            last_token->next = value;
        } else {
            object->next = value;
        }
        last_token = value;

        skip_whitespace(parser);
        if (parser->input[parser->pos] == ',') {
            parser->pos++; // Skip comma
        }
        skip_whitespace(parser);
    }

    parser->pos++; // Skip closing brace
    return object;
}

JsonToken *parse_value(JsonParser *parser) {
    skip_whitespace(parser);
    if (parser->input[parser->pos] == '\"') {
        return parse_string(parser);
    } else if (isdigit(parser->input[parser->pos]) || parser->input[parser->pos] == '-') {
        return parse_number(parser);
    } else if (strncmp(&parser->input[parser->pos], "true", 4) == 0 || 
               strncmp(&parser->input[parser->pos], "false", 5) == 0 ||
               strncmp(&parser->input[parser->pos], "null", 4) == 0) {
        return parse_bool_or_null(parser);
    } else if (parser->input[parser->pos] == '[') {
        return parse_array(parser);
    } else if (parser->input[parser->pos] == '{') {
        return parse_object(parser);
    }

    return NULL; // Not a valid value
}

void print_json(JsonToken *token, int indent) {
    while (token) {
        for (int i = 0; i < indent; i++) printf("  ");
        switch (token->type) {
        case JSON_OBJECT:
            printf("{\n");
            print_json(token->next, indent + 1);
            for (int i = 0; i < indent; i++) printf("  ");
            printf("}\n");
            break;
        case JSON_ARRAY:
            printf("[\n");
            print_json(token->next, indent + 1);
            for (int i = 0; i < indent; i++) printf("  ");
            printf("]\n");
            break;
        case JSON_STRING:
            printf("\"%s\"\n", token->value);
            break;
        case JSON_NUMBER:
            printf("%s\n", token->value);
            break;
        case JSON_BOOL:
            printf("%s\n", token->value);
            break;
        case JSON_NULL:
            printf("null\n");
            break;
        }
        token = token->next;
    }
}

void free_json(JsonToken *token) {
    free_tokens(token);
}

int main() {
    const char *json_input = "{\"name\":\"John\", \"age\":30, \"is_student\":false, \"skills\":[\"C\",\"C++\",\"Python\"]}";
    
    JsonParser *parser = create_parser(json_input);
    JsonToken *result = parse_value(parser);

    if (result) {
        print_json(result, 0);
        free_json(result);
    } else {
        printf("Failed to parse JSON\n");
    }

    free(parser);
    return 0;
}