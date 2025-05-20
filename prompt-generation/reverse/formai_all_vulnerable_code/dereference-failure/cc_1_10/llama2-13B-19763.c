//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1024
#define SPACE_STRING "&nbsp;"

struct Node {
    char *text;
    struct Node *next;
};

struct HTML {
    struct Node *root;
};

void add_node(struct HTML *html, char *text) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->text = text;
    new_node->next = html->root;
    html->root = new_node;
}

void pretty_print(struct HTML *html) {
    char *buffer = (char *)malloc(MAX_LENGTH);
    struct Node *current = html->root;

    *buffer = '\0';

    while (current != NULL) {
        if (current->next == NULL) {
            strcat(buffer, current->text);
            strcat(buffer, "<br>");
        } else {
            strcat(buffer, current->text);
            strcat(buffer, " ");
        }

        current = current->next;
    }

    printf("%s", buffer);

    free(buffer);
}

int main() {
    struct HTML html;

    add_node(&html, "Hello ");
    add_node(&html, "World!");
    add_node(&html, "<br>");
    add_node(&html, "This is a ");
    add_node(&html, "test");
    add_node(&html, "<br>");

    pretty_print(&html);

    return 0;
}