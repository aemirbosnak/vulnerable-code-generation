//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_SIZE 256

typedef enum {
    JSON_NULL,
    JSON_BOOL,
    JSON_NUMBER,
    JSON_STRING,
    JSON_OBJECT,
    JSON_ARRAY
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        char* string;
        double number;
        int boolean;
        struct JsonValue* object; // Start of a key-value pair.
        struct JsonValue* array;   // Start of an array of values.
    };
    struct JsonValue* next; // For linked lists of objects and arrays.
} JsonValue;

typedef struct {
    FILE* file;
    char current_char;
} JsonParser;

void parse_error(JsonParser* parser) {
    fprintf(stderr, "Parser Error: Unexpected character '%c'\n",
            parser->current_char);
    exit(EXIT_FAILURE);
}

void next_char(JsonParser* parser) {
    parser->current_char = fgetc(parser->file);
}

void skip_whitespace(JsonParser* parser) {
    while (isspace(parser->current_char)) {
        next_char(parser);
    }
}

JsonValue* parse_string(JsonParser* parser) {
    JsonValue* value = malloc(sizeof(JsonValue));
    value->type = JSON_STRING;
    value->string = malloc(MAX_TOKEN_SIZE);
    size_t index = 0;

    // To remove the enclosing quotes
    next_char(parser);
    while (parser->current_char != '"') {
        if (parser->current_char == '\\') { // Handle escape character
            next_char(parser);
            if (parser->current_char == '"') {
                value->string[index++] = '"';
            } else if (parser->current_char == '\\') {
                value->string[index++] = '\\';
            } else {
                parse_error(parser);
            }
        } else {
            value->string[index++] = parser->current_char;
        }
        next_char(parser);
    }
    value->string[index] = '\0';  // Null-terminate the string
    next_char(parser);             // Skip the closing quote
    return value;
}

JsonValue* parse_number(JsonParser* parser) {
    JsonValue* value = malloc(sizeof(JsonValue));
    value->type = JSON_NUMBER;
    char buffer[MAX_TOKEN_SIZE];
    
    size_t index = 0;
    while (isdigit(parser->current_char) || parser->current_char == '-' || parser->current_char == '.') {
        buffer[index++] = parser->current_char;
        next_char(parser);
    }
    buffer[index] = '\0';  // Null-terminate the number string
    value->number = atof(buffer); // Convert string to double

    return value;
}

JsonValue* parse_value(JsonParser* parser);

JsonValue* parse_object(JsonParser* parser) {
    JsonValue* object = malloc(sizeof(JsonValue));
    object->type = JSON_OBJECT;
    object->next = NULL;
    JsonValue** current = &object->object;

    next_char(parser);  // Skip '{'
    skip_whitespace(parser);

    while (parser->current_char != '}') {
        JsonValue* key = parse_string(parser);
        skip_whitespace(parser);
        next_char(parser);  // Skip ':'
        skip_whitespace(parser);
        JsonValue* value = parse_value(parser);
        
        // Link key and value in an object
        *current = key;
        key->next = value;
        current = &value->next;

        skip_whitespace(parser);
        if (parser->current_char == ',') {
            next_char(parser);
            skip_whitespace(parser);
        } else if (parser->current_char != '}') {
            parse_error(parser);
        }
    }
    next_char(parser);  // Skip '}'

    return object;
}

JsonValue* parse_array(JsonParser* parser) {
    JsonValue* array = malloc(sizeof(JsonValue));
    array->type = JSON_ARRAY;
    array->next = NULL;
    JsonValue** current = &array->array;

    next_char(parser);  // Skip '['
    skip_whitespace(parser);

    while (parser->current_char != ']') {
        JsonValue* value = parse_value(parser);
        *current = value;
        current = &value->next;

        skip_whitespace(parser);
        if (parser->current_char == ',') {
            next_char(parser);
            skip_whitespace(parser);
        } else if (parser->current_char != ']') {
            parse_error(parser);
        }
    }
    next_char(parser);  // Skip ']'

    return array;
}

JsonValue* parse_value(JsonParser* parser) {
    skip_whitespace(parser);
    JsonValue* value;

    if (parser->current_char == '"') {
        return parse_string(parser);
    } else if (isdigit(parser->current_char) || parser->current_char == '-') {
        return parse_number(parser);
    } else if (parser->current_char == '{') {
        return parse_object(parser);
    } else if (parser->current_char == '[') {
        return parse_array(parser);
    } else if (parser->current_char == 'n') {
        // Parse null
        next_char(parser); next_char(parser); next_char(parser); next_char(parser);
        value = malloc(sizeof(JsonValue));
        value->type = JSON_NULL;
        return value;
    } else if (parser->current_char == 't' || parser->current_char == 'f') {
        // Parse boolean
        int boolean = (parser->current_char == 't');
        if (boolean) {
            next_char(parser); next_char(parser); next_char(parser); next_char(parser);
        } else {
            next_char(parser); next_char(parser); next_char(parser);
        }
        value = malloc(sizeof(JsonValue));
        value->type = JSON_BOOL;
        value->boolean = boolean;
        return value;
    } else {
        parse_error(parser);
    }

    return NULL; // Should never reach here
}

void print_json(JsonValue* value) {
    if (!value) return;

    switch (value->type) {
        case JSON_STRING:
            printf("\"%s\"", value->string);
            break;
        case JSON_NUMBER:
            printf("%f", value->number);
            break;
        case JSON_BOOL:
            printf(value->boolean ? "true" : "false");
            break;
        case JSON_NULL:
            printf("null");
            break;
        case JSON_OBJECT:
            printf("{");
            JsonValue* current = value->object;
            while (current) {
                print_json(current);
                current = current->next;
                if (current) printf(", ");
            }
            printf("}");
            break;
        case JSON_ARRAY:
            printf("[");
            JsonValue* item = value->array;
            while (item) {
                print_json(item);
                item = item->next;
                if (item) printf(", ");
            }
            printf("]");
            break;
    }
}

void free_json(JsonValue* value) {
    if (!value) return;

    switch (value->type) {
        case JSON_STRING:
            free(value->string);
            break;
        case JSON_OBJECT:
            free_json(value->object);
            break;
        case JSON_ARRAY:
            free_json(value->array);
            break;
        default:
            break;
    }
    free(value);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <json_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    JsonParser parser;
    parser.file = fopen(argv[1], "r");
    if (!parser.file) {
        perror("Failed to open JSON file");
        return EXIT_FAILURE;
    }
    
    parser.current_char = fgetc(parser.file);
    JsonValue* json_value = parse_value(&parser);

    print_json(json_value);
    printf("\n");

    free_json(json_value);
    fclose(parser.file);
    return EXIT_SUCCESS;
}