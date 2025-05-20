//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct JsonParser {
    Node* head;
    int state;
    char currentKey[255];
    char currentValue[255];
    FILE* file;
} JsonParser;

JsonParser* parser_init(FILE* file) {
    JsonParser* parser = malloc(sizeof(JsonParser));
    parser->head = NULL;
    parser->state = 0;
    parser->currentKey[0] = '\0';
    parser->currentValue[0] = '\0';
    parser->file = file;
    return parser;
}

void parser_parse(JsonParser* parser) {
    char c;
    while ((c = fgetc(parser->file)) != EOF) {
        switch (parser->state) {
            case 0:
                if (c == '{') {
                    parser->state = 1;
                } else if (c == '"') {
                    parser->state = 2;
                } else if (c == ',') {
                    parser->state = 4;
                }
                break;
            case 1:
                if (c == '"') {
                    parser->state = 3;
                }
                break;
            case 2:
                if (c == ':') {
                    parser->state = 5;
                } else if (c == '"') {
                    parser->state = 4;
                }
                break;
            case 3:
                strcpy(parser->currentKey, "");
                while ((c = fgetc(parser->file)) != '"') {
                    strcat(parser->currentKey, c);
                }
                parser->state = 4;
                break;
            case 4:
                if (c == ',') {
                    parser->state = 0;
                } else if (c == '}') {
                    parser->state = 6;
                }
                break;
            case 5:
                strcpy(parser->currentValue, "");
                while ((c = fgetc(parser->file)) != ':') {
                    strcat(parser->currentValue, c);
                }
                parser->state = 4;
                break;
            case 6:
                printf("Key: %s, Value: %s\n", parser->currentKey, parser->currentValue);
                parser->state = 0;
                break;
        }
    }
}

int main() {
    FILE* file = fopen("data.json", "r");
    JsonParser* parser = parser_init(file);
    parser_parse(parser);
    fclose(file);
    return 0;
}