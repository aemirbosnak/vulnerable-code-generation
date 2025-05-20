//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The XML parser structure
typedef struct xml_parser {
    char *data;
    int len;
    int pos;
} xml_parser;

// Initialize the XML parser
void xml_init(xml_parser *parser, char *data, int len) {
    parser->data = data;
    parser->len = len;
    parser->pos = 0;
}

// Get the next character from the XML data
char xml_getc(xml_parser *parser) {
    if (parser->pos < parser->len) {
        return parser->data[parser->pos++];
    } else {
        return '\0';
    }
}

// Unget the last character from the XML data
void xml_ungetc(xml_parser *parser) {
    if (parser->pos > 0) {
        parser->pos--;
    }
}

// Skip whitespace characters
void xml_skip_whitespace(xml_parser *parser) {
    char c;
    do {
        c = xml_getc(parser);
    } while (c == ' ' || c == '\t' || c == '\n' || c == '\r');
    xml_ungetc(parser);
}

// Get the next token from the XML data
char *xml_get_token(xml_parser *parser) {
    char *token;
    int len;
    char c;

    xml_skip_whitespace(parser);
    c = xml_getc(parser);
    if (c == '<') {
        // Start of a tag
        token = malloc(1);
        *token = '\0';
        while ((c = xml_getc(parser)) != '>' && c != '\0') {
            len = strlen(token);
            token = realloc(token, len + 2);
            token[len] = c;
            token[len + 1] = '\0';
        }
    } else if (c == '"') {
        // Start of a string
        token = malloc(1);
        *token = '\0';
        while ((c = xml_getc(parser)) != '"' && c != '\0') {
            len = strlen(token);
            token = realloc(token, len + 2);
            token[len] = c;
            token[len + 1] = '\0';
        }
    } else {
        // Start of a word
        token = malloc(1);
        *token = '\0';
        while ((c = xml_getc(parser)) != ' ' && c != '\t' && c != '\n' && c != '\r' && c != '<' && c != '"' && c != '\0') {
            len = strlen(token);
            token = realloc(token, len + 2);
            token[len] = c;
            token[len + 1] = '\0';
        }
        xml_ungetc(parser);
    }

    return token;
}

// Parse the XML data
void xml_parse(xml_parser *parser) {
    char *token;
    while ((token = xml_get_token(parser)) != NULL) {
        // Process the token
        if (!strcmp(token, "name")) {
            // Start of a name tag
            token = xml_get_token(parser);
            printf("Name: %s\n", token);
        } else if (!strcmp(token, "age")) {
            // Start of an age tag
            token = xml_get_token(parser);
            printf("Age: %s\n", token);
        } else if (!strcmp(token, "email")) {
            // Start of an email tag
            token = xml_get_token(parser);
            printf("Email: %s\n", token);
        } else {
            // Ignore the token
        }

        // Free the token
        free(token);
    }
}

// Main function
int main(int argc, char **argv) {
    // Get the XML data from the first argument
    char *data = argv[1];
    int len = strlen(data);

    // Initialize the XML parser
    xml_parser parser;
    xml_init(&parser, data, len);

    // Parse the XML data
    xml_parse(&parser);

    return 0;
}