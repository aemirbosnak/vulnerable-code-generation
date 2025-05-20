//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

struct XMLParser {
    Node *head;
    char **buffer;
    int bufferSize;
    int position;
    int state;
    enum State {
        START,
        TAG_NAME,
        TAG_CLOSE,
        CONTENT
    } state_enum;
};

void xmlParser_init(struct XMLParser *parser) {
    parser->head = NULL;
    parser->buffer = NULL;
    parser->bufferSize = MAX_BUFFER_SIZE;
    parser->position = 0;
    parser->state = START;
}

void xmlParser_parse(struct XMLParser *parser, char *data) {
    parser->buffer = realloc(parser->buffer, parser->bufferSize * (parser->position + 1));
    parser->buffer[parser->position++] = data;

    switch (parser->state) {
        case START:
            if (data[0] == '<') {
                parser->state = TAG_NAME;
            } else {
                parser->state = CONTENT;
            }
            break;
        case TAG_NAME:
            if (data[0] == '>' && parser->head == NULL) {
                parser->head = malloc(sizeof(Node));
                parser->head->data = strdup(parser->buffer);
                parser->head->next = NULL;
            } else if (data[0] == '>' && parser->head) {
                parser->state = CONTENT;
            } else {
                parser->state = TAG_NAME;
            }
            break;
        case TAG_CLOSE:
            if (data[0] == '>' && parser->head) {
                parser->state = CONTENT;
            } else {
                parser->state = TAG_CLOSE;
            }
            break;
        case CONTENT:
            if (data[0] == '<') {
                parser->state = TAG_NAME;
            } else {
                parser->state = CONTENT;
            }
            break;
    }
}

int main() {
    struct XMLParser parser;
    xmlParser_init(&parser);

    xmlParser_parse(&parser, "<foo>bar</foo>");

    Node *node = parser.head;
    while (node) {
        printf("%s\n", node->data);
        node = node->next;
    }

    return 0;
}