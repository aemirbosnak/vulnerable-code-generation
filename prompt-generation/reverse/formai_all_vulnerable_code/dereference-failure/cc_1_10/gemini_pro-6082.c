//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our custom XML parser
typedef struct XMLParser {
    char *input;
    int index;
} XMLParser;

// Initializes the XML parser with the input string
XMLParser* initParser(char *input) {
    XMLParser *parser = malloc(sizeof(XMLParser));
    parser->input = input;
    parser->index = 0;
    return parser;
}

// Parses the next tag from the input
char* parseTag(XMLParser *parser) {
    char *tag = malloc(sizeof(char) * 100);
    int i = 0;

    // Skip whitespace
    while (parser->input[parser->index] == ' ') {
        parser->index++;
    }

    // Look for the start of the tag
    if (parser->input[parser->index] == '<') {
        parser->index++;
    }

    // Read the tag name
    while (parser->input[parser->index] != ' ' && parser->input[parser->index] != '>') {
        tag[i++] = parser->input[parser->index++];
    }

    // Null-terminate the tag
    tag[i] = '\0';

    // Skip whitespace
    while (parser->input[parser->index] == ' ') {
        parser->index++;
    }

    // Check for the end of the tag
    if (parser->input[parser->index] == '>') {
        parser->index++;
    }

    return tag;
}

// Parses the next text node from the input
char* parseText(XMLParser *parser) {
    char *text = malloc(sizeof(char) * 100);
    int i = 0;

    // Skip whitespace
    while (parser->input[parser->index] == ' ') {
        parser->index++;
    }

    // Read the text node
    while (parser->input[parser->index] != '<') {
        text[i++] = parser->input[parser->index++];
    }

    // Null-terminate the text node
    text[i] = '\0';

    return text;
}

// Parses the XML document
void parseDocument(XMLParser *parser) {
    char *tag;
    char *text;

    // Continue parsing until the end of the input
    while (parser->index < strlen(parser->input)) {
        // Look for a tag or text node
        if (parser->input[parser->index] == '<') {
            // Parse the tag
            tag = parseTag(parser);

            // Check if the tag is a closing tag
            if (tag[0] == '/') {
                // Skip the closing tag
                parser->index += strlen(tag) + 1;
            } else {
                // Parse the text node
                text = parseText(parser);

                // Print the tag and text node
                printf("<%s>%s</%s>\n", tag, text, tag);

                // Free the memory allocated for the tag and text node
                free(tag);
                free(text);
            }
        } else {
            // Skip the text node
            parser->index++;
        }
    }
}

int main() {
    // Input XML document
    char *input = "<root>\n<child>Hello</child>\n<child>World</child>\n</root>";

    // Initialize the XML parser
    XMLParser *parser = initParser(input);

    // Parse the XML document
    parseDocument(parser);

    // Free the memory allocated for the XML parser
    free(parser);

    return 0;
}