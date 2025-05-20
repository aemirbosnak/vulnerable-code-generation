//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAB_SIZE 4
#define MAX_LINE_LEN 1024
#define MAX_INDENT 8

struct node {
    char *text;
    struct node *prev, *next;
};

struct node *html_beautify(char *input) {
    struct node *head, *current, *prev;
    char *line, *token, *next_token;
    int i, j, tab_count = 0;

    // Create the head node
    head = (struct node *) malloc(sizeof(struct node));
    head->text = strdup(input);
    head->prev = NULL;
    head->next = NULL;

    // Tokenize the input
    line = strtok(head->text, "\n");
    while (line != NULL && line[0] != '\0') {
        // Remove leading and trailing whitespaces
        while (isspace(line[0])) {
            line++;
        }
        while (isspace(line[strcspn(line, "\n")])) {
            line[strcspn(line, "\n")] = '\0';
        }

        // Check if the line is empty
        if (strlen(line) == 0) {
            continue;
        }

        // Find the next token
        token = strtok(line, " ");
        while (token != NULL && token[0] != '\0') {
            next_token = strtok(NULL, " ");
            if (next_token == NULL) {
                break;
            }
            token = next_token;
        }

        // Add the token to the current node
        if (current == NULL) {
            current = (struct node *) malloc(sizeof(struct node));
            current->text = strdup(token);
            current->prev = NULL;
            current->next = head;
            head->prev = current;
        } else {
            current->next = (struct node *) malloc(sizeof(struct node));
            current->next->text = strdup(token);
            current->next->prev = current;
            current = current->next;
        }

        // Increment the tab count
        tab_count += strcspn(line, "\n") - strlen(line);

        // Check if the line is a tag
        if (strncmp(line, "<", 1) == 0) {
            // Add the tag to the current node
            current->next = (struct node *) malloc(sizeof(struct node));
            current->next->text = strdup(line);
            current->next->prev = current;
            current = current->next;
        }
    }

    // Indent the nodes
    for (i = 0; i < tab_count; i++) {
        for (j = 0; j < TAB_SIZE; j++) {
            current->next->text = (char *) realloc(current->next->text, strlen(current->next->text) + 1 + j);
            current->next->text[strlen(current->next->text) + 1 + j] = ' ';
        }
        current = current->next;
    }

    return head;
}

int main() {
    char input[] = "<html><body><p>This is a <b>beautified</b> paragraph.</p></body></html>";
    struct node *html = html_beautify(input);
    printf("%s\n", html->text);
    free(html);
    return 0;
}