//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

struct JSONParser {
    Node *head;
    char **buffer;
    int bufferSize;
    int position;
    int depth;
};

void parseJSON(struct JSONParser *parser, char *jsonString) {
    parser->head = NULL;
    parser->buffer = NULL;
    parser->bufferSize = 0;
    parser->position = 0;
    parser->depth = 0;

    parser->buffer = malloc(MAX_BUFFER_SIZE);
    parser->bufferSize = MAX_BUFFER_SIZE;

    int i = 0;
    for (i = 0; jsonString[i] != '\0'; i++) {
        switch (jsonString[i]) {
            case '"':
                parser->depth++;
                break;
            case '{' :
            case '[' :
                parser->head = malloc(sizeof(struct Node));
                parser->head->data = malloc(MAX_BUFFER_SIZE);
                parser->head->next = NULL;
                parser->position = i;
                parser->depth++;
                break;
            case '}':
            case ']':
                parser->depth--;
                break;
            default:
                parser->head->data = realloc(parser->head->data, parser->bufferSize * (parser->depth + 1));
                parser->head->data[parser->position] = jsonString[i];
                parser->position++;
                break;
        }
    }

    parser->head->data = realloc(parser->head->data, parser->position + 1);
    parser->head->data[parser->position] = '\0';

    parser->position = 0;
}

int main() {
    char *jsonString = "{ 'name': 'John Doe', 'age': 30 }";
    struct JSONParser *parser = malloc(sizeof(struct JSONParser));
    parseJSON(parser, jsonString);

    printf("Name: %s\n", parser->head->data);
    printf("Age: %d\n", atoi(parser->head->data + 11));

    free(parser);
    free(jsonString);
    return 0;
}