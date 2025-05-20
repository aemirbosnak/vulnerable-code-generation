//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAB_SIZE 4

struct Node {
    char *data;
    struct Node *next;
};

struct Node *beautify(char *html) {
    struct Node *root = NULL;
    char *token = NULL;
    char *text = NULL;
    char *tag = NULL;
    int i = 0;

    while (html != NULL && *html != '\0') {
        if (*html == '<') {
            token = html + 1;
            while (*token != '>' && *token != '\0') {
                if (*token == ' ') {
                    i++;
                }
                token++;
            }
            tag = token;
            text = NULL;
            while (*token != '\0' && *token != '>') {
                text = token;
                token++;
            }
            if (*token == '>') {
                struct Node *node = (struct Node *) malloc(sizeof(struct Node));
                node->data = text;
                node->next = root;
                root = node;
            }
        } else if (*html == '>') {
            text = html + 1;
            while (*text != '\0' && *text != '<') {
                if (*text == ' ') {
                    i++;
                }
                text++;
            }
            if (*text == '<') {
                struct Node *node = (struct Node *) malloc(sizeof(struct Node));
                node->data = text;
                node->next = root;
                root = node;
            }
        } else {
            text = html;
        }
        html = strchr(html, '\0') + 1;
    }
    return root;
}

int main() {
    char html[] = "<html><body>Hello World!</body></html>";
    struct Node *node = beautify(html);
    printf("%s\n", node->data);
    return 0;
}