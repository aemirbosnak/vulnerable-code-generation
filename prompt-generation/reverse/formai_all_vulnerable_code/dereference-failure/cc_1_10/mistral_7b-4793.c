//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1024
#define BUFFER_SIZE 256

typedef struct Node {
    char data;
    struct Node *next;
} Node;

Node *sanitized_string = NULL;

void push(char data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = sanitized_string;
    sanitized_string = new_node;
}

void pop() {
    if (sanitized_string != NULL) {
        Node *temp = sanitized_string;
        sanitized_string = sanitized_string->next;
        free(temp);
    }
}

void decode_percent_encoding(char *input, int length) {
    int i = 0;
    char hex;
    for (; i < length; i++) {
        if (input[i] == '%') {
            if (i + 2 < length) {
                hex = (input[i + 1] - '0') * 16;
                hex += (input[i + 2] - '0');
                if (isxdigit(input[i + 1]) && isxdigit(input[i + 2])) {
                    push(hex);
                    i += 2;
                }
            }
        } else {
            push(input[i]);
        }
    }
}

void sanitize_url(char *input, int length) {
    int i = 0;
    if (length > MAX_INPUT_LENGTH) {
        fprintf(stderr, "Input too long.\n");
        return;
    }

    for (; i < length; i++) {
        switch (input[i]) {
            case '%':
                decode_percent_encoding(input, length);
                break;
            case '?':
            case '#':
                push(input[i]);
                break;
            case '/':
                if (i > 0 && sanitized_string->data != '/') {
                    push('/');
                }
                break;
            case '&':
                if (i > 0 && sanitized_string->data != '&') {
                    push('&');
                }
                break;
            case '{':
            case '}':
            case '[':
            case ']':
            case '|':
                fprintf(stderr, "Invalid character: %c\n", input[i]);
                return;
            default:
                push(input[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char input[MAX_INPUT_LENGTH] = {0};
    strcpy(input, argv[1]);

    sanitize_url(input, strlen(input));

    printf("Sanitized URL: ");
    while (sanitized_string != NULL) {
        printf("%c", sanitized_string->data);
        pop();
    }
    printf("\n");

    while (sanitized_string != NULL) {
        Node *temp = sanitized_string;
        sanitized_string = sanitized_string->next;
        free(temp);
    }

    return 0;
}