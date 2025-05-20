//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL,
} json_type;

typedef struct {
    json_type type;
    union {
        char* string;
        double number;
        int boolean;
    } value;
} json_token;

typedef struct {
    char* source;
    size_t index;
} json_scanner;

json_token* parse_value(json_scanner* scanner);
json_token* parse_object(json_scanner* scanner);
json_token* parse_array(json_scanner* scanner);
json_token* parse_string(json_scanner* scanner);
json_token* parse_number(json_scanner* scanner);
json_token* parse_true(json_scanner* scanner);
json_token* parse_false(json_scanner* scanner);
json_token* parse_null(json_scanner* scanner);
json_token* create_token(json_type type, void* value);

json_token* parse_json(char* json) {
    json_scanner* scanner = malloc(sizeof(json_scanner));
    scanner->source = json;
    scanner->index = 0;

    json_token* token = parse_value(scanner);

    free(scanner);
    return token;
}

json_token* parse_value(json_scanner* scanner) {
    char c = scanner->source[scanner->index];
    if (c == '{') {
        return parse_object(scanner);
    } else if (c == '[') {
        return parse_array(scanner);
    } else if (c == '\"') {
        return parse_string(scanner);
    } else if (isdigit(c) || c == '-') {
        return parse_number(scanner);
    } else if (c == 't') {
        return parse_true(scanner);
    } else if (c == 'f') {
        return parse_false(scanner);
    } else if (c == 'n') {
        return parse_null(scanner);
    } else {
        // unknown character
        return NULL;
    }
}

json_token* parse_object(json_scanner* scanner) {
    char c = scanner->source[scanner->index];
    if (c != '{') {
        // not an object
        return NULL;
    }

    scanner->index++; // skip the opening brace
    json_token* token = create_token(JSON_OBJECT, NULL);

    while ((c = scanner->source[scanner->index]) != '}') {
        if (c == ',') {
            scanner->index++; // skip the comma
            continue;
        }

        json_token* key = parse_string(scanner);
        if (!key) {
            // invalid key
            return NULL;
        }

        c = scanner->source[scanner->index];
        if (c != ':') {
            // error: expected colon after key
            return NULL;
        }

        scanner->index++; // skip the colon
        json_token* value = parse_value(scanner);
        if (!value) {
            // invalid value
            return NULL;
        }

        // add key-value pair to object
        // assuming key is always a string
        token->value.string = realloc(token->value.string, strlen(token->value.string) + strlen(key->value.string) + strlen(value->value.string) + 10);
        strcat(token->value.string, "\"");
        strcat(token->value.string, key->value.string);
        strcat(token->value.string, "\":");
        strcat(token->value.string, value->value.string);
    }

    scanner->index++; // skip the closing brace
    return token;
}

json_token* parse_array(json_scanner* scanner) {
    char c = scanner->source[scanner->index];
    if (c != '[') {
        // not an array
        return NULL;
    }

    scanner->index++; // skip the opening bracket
    json_token* token = create_token(JSON_ARRAY, NULL);

    while ((c = scanner->source[scanner->index]) != ']') {
        if (c == ',') {
            scanner->index++; // skip the comma
            continue;
        }

        json_token* value = parse_value(scanner);
        if (!value) {
            // invalid value
            return NULL;
        }

        // add value to array
        token->value.string = realloc(token->value.string, strlen(token->value.string) + strlen(value->value.string) + 10);
        strcat(token->value.string, value->value.string);
    }

    scanner->index++; // skip the closing bracket
    return token;
}

json_token* parse_string(json_scanner* scanner) {
    char c = scanner->source[scanner->index];
    if (c != '\"') {
        // not a string
        return NULL;
    }

    scanner->index++; // skip the opening quote
    size_t start = scanner->index;
    size_t len = 0;

    while ((c = scanner->source[scanner->index]) != '\"') {
        if (c == '\\') {
            scanner->index++; // skip the escaped character
        }
        scanner->index++;
        len++;
    }

    // create string token
    json_token* token = create_token(JSON_STRING, NULL);
    token->value.string = malloc(len);
    strncpy(token->value.string, scanner->source + start, len);

    scanner->index++; // skip the closing quote
    return token;
}

json_token* parse_number(json_scanner* scanner) {
    char c = scanner->source[scanner->index];
    size_t start = scanner->index;
    size_t len = 0;

    if (c == '-') {
        scanner->index++; // skip the negative sign
        len++;
    }

    while (isdigit(c = scanner->source[scanner->index])) {
        scanner->index++;
        len++;
    }

    if (c == '.') {
        scanner->index++; // skip decimal point

        while (isdigit(c = scanner->source[scanner->index])) {
            scanner->index++;
            len++;
        }
    }

    if (tolower(c) == 'e') {
        scanner->index++; // skip the 'e'

        if ((c = scanner->source[scanner->index]) == '+' || c == '-') {
            scanner->index++; // skip sign
            len++;
        }

        while (isdigit(c = scanner->source[scanner->index])) {
            scanner->index++;
            len++;
        }
    }

    // create number token
    json_token* token = create_token(JSON_NUMBER, NULL);
    char* number = malloc(len + 1);
    strncpy(number, scanner->source + start, len);
    number[len] = '\0';
    token->value.number = atof(number);
    free(number);

    return token;
}

json_token* parse_true(json_scanner* scanner) {
    char c = scanner->source[scanner->index];
    if (c != 't') {
        // not "true"
        return NULL;
    }

    if (strncmp(scanner->source + scanner->index, "true", 4) != 0) {
        // invalid token
        return NULL;
    }

    scanner->index += 4; // skip "true"
    return create_token(JSON_TRUE, &"true");
}

json_token* parse_false(json_scanner* scanner) {
    char c = scanner->source[scanner->index];
    if (c != 'f') {
        // not "false"
        return NULL;
    }

    if (strncmp(scanner->source + scanner->index, "false", 5) != 0) {
        // invalid token
        return NULL;
    }

    scanner->index += 5; // skip "false"
    return create_token(JSON_FALSE, &"false");
}

json_token* parse_null(json_scanner* scanner) {
    char c = scanner->source[scanner->index];
    if (c != 'n') {
        // not "null"
        return NULL;
    }

    if (strncmp(scanner->source + scanner->index, "null", 4) != 0) {
        // invalid token
        return NULL;
    }

    scanner->index += 4; // skip "null"
    return create_token(JSON_NULL, &"null");
}

json_token* create_token(json_type type, void* value) {
    json_token* token = malloc(sizeof(json_token));
    token->type = type;
    token->value.string = NULL;

    switch (type) {
        case JSON_STRING:
        case JSON_TRUE:
        case JSON_FALSE:
        case JSON_NULL:
            token->value.string = value;
            break;
        case JSON_NUMBER:
            token->value.number = *(double*)value;
            break;
    }

    return token;
}

int main() {
    char* json = "{ \"name\": \"John\", \"age\": 30, \"is_student\": false, \"courses\": [\"math\", \"physics\"] }";
    json_token* root = parse_json(json);

    if (root) {
        printf("%s\n", root->value.string);
        free(root->value.string);
        free(root);
        return 0;
    } else {
        fprintf(stderr, "Failed to parse JSON!\n");
        return 1;
    }
}