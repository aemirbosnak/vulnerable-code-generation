//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// The JSON parser
typedef struct {
    char *str;
    int len;
    int pos;
} JSONParser;

// Parse a JSON string
int json_parse(JSONParser *parser, char *str) {
    parser->str = str;
    parser->len = strlen(str);
    parser->pos = 0;
    return 0;
}

// Get the next character in the JSON string
int json_getc(JSONParser *parser) {
    if (parser->pos < parser->len) {
        return parser->str[parser->pos++];
    } else {
        return -1;
    }
}

// Skip whitespace
void json_skip_whitespace(JSONParser *parser) {
    int c;
    do {
        c = json_getc(parser);
    } while (c != -1 && isspace(c));
}

// Parse a JSON object
int json_parse_object(JSONParser *parser) {
    int c;
    json_skip_whitespace(parser);
    if ((c = json_getc(parser)) != '{') {
        return -1;
    }
    json_skip_whitespace(parser);
    while ((c = json_getc(parser)) != -1 && c != '}') {
        if (c != '"') {
            return -1;
        }
        json_skip_whitespace(parser);
        while ((c = json_getc(parser)) != -1 && c != '"') {
            if (!isalnum(c)) {
                return -1;
            }
        }
        json_skip_whitespace(parser);
        if ((c = json_getc(parser)) != ':') {
            return -1;
        }
        json_skip_whitespace(parser);
        if (json_parse_value(parser) == -1) {
            return -1;
        }
        json_skip_whitespace(parser);
        if ((c = json_getc(parser)) != ',' && c != '}') {
            return -1;
        }
    }
    return 0;
}

// Parse a JSON array
int json_parse_array(JSONParser *parser) {
    int c;
    json_skip_whitespace(parser);
    if ((c = json_getc(parser)) != '[') {
        return -1;
    }
    json_skip_whitespace(parser);
    while ((c = json_getc(parser)) != -1 && c != ']') {
        if (json_parse_value(parser) == -1) {
            return -1;
        }
        json_skip_whitespace(parser);
        if ((c = json_getc(parser)) != ',' && c != ']') {
            return -1;
        }
    }
    return 0;
}

// Parse a JSON value
int json_parse_value(JSONParser *parser) {
    int c;
    json_skip_whitespace(parser);
    if ((c = json_getc(parser)) == '"') {
        // Parse a string
        json_skip_whitespace(parser);
        while ((c = json_getc(parser)) != -1 && c != '"') {
            if (!isprint(c)) {
                return -1;
            }
        }
        return 0;
    } else if (c == '{') {
        // Parse an object
        return json_parse_object(parser);
    } else if (c == '[') {
        // Parse an array
        return json_parse_array(parser);
    } else if (isdigit(c) || c == '-') {
        // Parse a number
        json_skip_whitespace(parser);
        while ((c = json_getc(parser)) != -1 && (isdigit(c) || c == '.')) {
            if (c == '.' && json_getc(parser) == '.') {
                return -1;
            }
        }
        return 0;
    } else if (c == 't' || c == 'f' || c == 'n') {
        // Parse a boolean
        json_skip_whitespace(parser);
        while ((c = json_getc(parser)) != -1 && (c == 't' || c == 'f' || c == 'n')) {
            if (c == 't' && json_getc(parser) != 'r' && json_getc(parser) != 'u' && json_getc(parser) != 'e') {
                return -1;
            }
            if (c == 'f' && json_getc(parser) != 'a' && json_getc(parser) != 'l' && json_getc(parser) != 's' && json_getc(parser) != 'e') {
                return -1;
            }
            if (c == 'n' && json_getc(parser) != 'u' && json_getc(parser) != 'l' && json_getc(parser) != 'l') {
                return -1;
            }
        }
        return 0;
    } else {
        return -1;
    }
}

// Print a JSON string
void json_print(JSONParser *parser) {
    int c;
    while ((c = json_getc(parser)) != -1) {
        putchar(c);
    }
}

// Main function
int main(int argc, char **argv) {
    JSONParser parser;
    int result;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <JSON string>\n", argv[0]);
        return 1;
    }
    if (json_parse(&parser, argv[1]) == -1) {
        fprintf(stderr, "Error: Invalid JSON string\n");
        return 1;
    }
    result = json_parse_value(&parser);
    if (result == -1) {
        fprintf(stderr, "Error: Invalid JSON string\n");
        return 1;
    }
    json_print(&parser);
    return 0;
}