//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *name;
    int value;
    struct Token *next;
} Token;

Token **parse_xml(char *xml_data) {
    Token **head = malloc(sizeof(Token));
    Token *current = *head;

    // Eat the opening <?xml tag
    xml_data = strchr(xml_data, '<');
    xml_data = strchr(xml_data, '>');

    // Iterate over the remaining XML data
    while (xml_data) {
        // Extract the token name
        char *token_name = strchr(xml_data, '<');
        token_name = strchr(token_name, '>');

        // Extract the token value
        int token_value = atoi(strchr(token_name, '=') + 1);

        // Create a new token
        Token *new_token = malloc(sizeof(Token));
        new_token->name = strdup(token_name);
        new_token->value = token_value;
        new_token->next = NULL;

        // Add the new token to the list
        current->next = new_token;
        current = new_token;

        // Eat the closing tag
        xml_data = strchr(xml_data, '<');
        xml_data = strchr(xml_data, '>');
    }

    return head;
}

int main() {
    char *xml_data = "<foo bar=\"123\"><b>hello</b></foo>";
    Token **head = parse_xml(xml_data);

    // Print the tokens
    for (Token *token = head; token; token = token->next) {
        printf("%s: %d\n", token->name, token->value);
    }

    return 0;
}