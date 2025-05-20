//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1024

typedef struct Token {
    char *lexeme;
    int line_number;
    struct Token *next;
} Token;

Token *parse_xml(char *xml_data) {
    Token *head = NULL;
    char *xml_ptr = xml_data;
    char *token_start = NULL;
    int line_number = 1;

    while (xml_ptr) {
        switch (*xml_ptr) {
            case '<':
                token_start = xml_ptr;
                break;
            case '>':
                if (token_start) {
                    Token *new_token = malloc(sizeof(Token));
                    new_token->lexeme = strdup(token_start);
                    new_token->line_number = line_number;
                    new_token->next = head;
                    head = new_token;
                }
                break;
            case '\n':
                line_number++;
                break;
        }
        xml_ptr++;
    }

    return head;
}

int main() {
    char *xml_data = "<foo><b>hello, world</b></foo>";
    Token *head = parse_xml(xml_data);

    while (head) {
        printf("Lexeme: %s, Line Number: %d\n", head->lexeme, head->line_number);
        head = head->next;
    }

    return 0;
}