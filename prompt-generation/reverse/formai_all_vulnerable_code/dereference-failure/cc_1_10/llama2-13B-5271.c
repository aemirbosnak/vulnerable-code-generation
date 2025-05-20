//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAB_SIZE 4
#define LINE_BREAK 10

struct node {
    char *text;
    struct node *next;
};

struct node *beautify(char *html) {
    struct node *root = NULL;
    char *text = html;

    while (*text != 0) {
        if (*text == '<') {
            char *start = text;
            text = strchr(text, '>');
            if (text != NULL) {
                *text = 0; // terminate the tag
                struct node *node = malloc(sizeof(struct node));
                node->text = start;
                node->next = root;
                root = node;
            }
        } else if (*text == ' ') {
            // remove excess spaces
            while (*text == ' ') {
                text++;
            }
        }
    }

    return root;
}

int main() {
    char html[] = "<html><body><p>Hello<i>world</i>!</p></body></html>";
    struct node *root = beautify(html);

    char *out = NULL;
    char *tmp = root->text;
    while (tmp != NULL) {
        out = strcat(out, tmp);
        tmp = root->next->text;
    }

    printf("%s\n", out);

    return 0;
}