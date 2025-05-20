//FormAI DATASET v1.0 Category: HTML beautifier ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char* tag_name;
    struct Node* parent;
    struct Node* children[100];
    int num_children;
    char* text;
} Node;

// Function to strip leading and trailing white space from a string
char* strip(char* str) {
    while (isspace(*str)) str++;
    if (*str == 0) return str;
    char* end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;
    *(end + 1) = 0;
    return str;
}

// Function to create a new node
Node* create_node(char* tag_name, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->tag_name = tag_name;
    node->parent = parent;
    node->num_children = 0;
    node->text = NULL;
    return node;
}

// Function to print the text of a node
void print_text(Node* node) {
    char* text = strip(node->text);
    if (text) printf("%s", text);
}

// Function to print the tag name of a node
void print_tag_name(Node* node) {
    printf("<%s>", node->tag_name);
}

// Asynchronous function to parse HTML and create a hierarchical tree of nodes
void* parse_html_async(void* args) {
    Node* root = create_node("html", NULL);
    Node* current = root;

    char* html = (char*)args;
    int len = strlen(html);

    char buffer[100];
    int i, j = 0;
    for (i = 0; i < len; i++) {
        if (html[i] == '<') {
            buffer[j] = 0;
            current->text = buffer;
            j = 0;

            while (html[i] != '>') {
                i++;
                if (html[i] == '/') {
                    i++;
                    if (current != root) current = current->parent;
                    break;
                } else {
                    if (html[i] == ' ') continue;
                    j = 0;
                    while (html[i] != ' ' && html[i] != '>') buffer[j++] = html[i++];
                    buffer[j] = 0;
                    Node* node = create_node(buffer, current);
                    current->children[current->num_children++] = node;
                    if (html[i] == ' ') {
                        while (html[i] != '>') {
                            i++;
                            if (html[i] == '>') break;
                            if (html[i] == '/' && html[i+1] == '>') {
                                current = current->parent;
                                i++;
                                break;
                            }
                            j = 0;
                            while (html[i] != '=' && html[i] != '>') buffer[j++] = html[i++];
                            buffer[j] = 0;
                            i += 2;
                            j = 0;
                            while (html[i] != ' ' && html[i] != '>') buffer[j++] = html[i++];
                            buffer[j] = 0;
                            node->text = buffer;
                        }
                    } else {
                        current = node;
                    }
                }
            }
        } else {
            buffer[j++] = html[i];
        }
    }

    return root;
}

int main() {
    char* html = "<!DOCTYPE html>\n<html>\n\t<head>\n\t\t<title>My Webpage</title>\n\t</head>\n\t<body>\n\t\t<h1>Welcome to my webpage</h1>\n\t\t<p>This is my first webpage.</p>\n\t\t<ul>\n\t\t\t<li>Item 1</li>\n\t\t\t<li>Item 2</li>\n\t\t</ul>\n\t</body>\n</html>";
    Node* root = parse_html_async(html);

    // Print the tree
    Node* current = root;
    Node* stack[100];
    int top = 0;
    while (current || top > 0) {
        if (current) {
            stack[top++] = current;
            current = current->children[0];
        } else {
            current = stack[--top];
            if (current->tag_name) print_tag_name(current);
            if (current->text) print_text(current);
            if (current->num_children > 0) current = current->children[current->num_children - 1];
            else current = NULL;
        }
    }

    return 0;
}