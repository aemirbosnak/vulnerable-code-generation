//FormAI DATASET v1.0 Category: HTML beautifier ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 100

typedef struct Node {
    char line[MAX_LINE_LENGTH];
    struct Node* next;
} Node;

void insert(Node** head, char* line) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->line, line);
    new_node->next = (*head);
    (*head) = new_node;
}

void print_list(Node* node) {
    while (node != NULL) {
        printf("%s\n", node->line);
        node = node->next;
    }
}

void beautify(html) {
    int i, j, indent_level = 0;
    char* token;
    char* tokens[1000];
    Node* beautified_lines = NULL;
    Node* current_line = NULL;
    
    token = strtok(html, "\n");
    while (token) {
        tokens[j++] = token;
        token = strtok(NULL, "\n");
    }
    
    for (i = 0; i < j; i++) {
        if (strstr(tokens[i], "</") && indent_level > 0) {
            indent_level--;
        }
        
        for (j = 0; j < indent_level; j++) {
            insert(&beautified_lines, "\t");
        }
        insert(&beautified_lines, tokens[i]);
        
        if (strstr(tokens[i], "<") && !strstr(tokens[i], "</")) {
            indent_level++;
        }
    }
    
    current_line = beautified_lines;
    while (current_line->next != NULL) {
        current_line = current_line->next;
    }
    
    print_list(beautified_lines);
}

int main() {
    char html[MAX_LINE_LENGTH * 10] = "<html>\n<head>\n<title>Example</title>\n</head>\n<body>\n<h1>Hello, World!</h1>\n</body>\n</html>";
    beautify(html);
    return 0;
}