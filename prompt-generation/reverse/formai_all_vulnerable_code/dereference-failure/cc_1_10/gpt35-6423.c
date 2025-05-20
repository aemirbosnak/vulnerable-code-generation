//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAG_NAME_LEN 100
#define MAX_ATT_NAME_LEN 100
#define MAX_ATT_VALUE_LEN 100

// Structure to hold attributes
struct attribute {
    char name[MAX_ATT_NAME_LEN];
    char value[MAX_ATT_VALUE_LEN];
};

// Structure to hold a node in the XML tree
struct xml_node {
    char tag[MAX_TAG_NAME_LEN];
    struct attribute **attributes;
    struct xml_node **children;
    int num_attributes;
    int num_children;
    char text[1000];
};

// Function to parse XML string and build the tree
struct xml_node *build_tree(char *xml_str) {
    struct xml_node *root = malloc(sizeof(struct xml_node));
    root->num_attributes = 0;
    root->num_children = 0;
    memset(root->tag, 0, MAX_TAG_NAME_LEN);
    memset(root->text, 0, 1000);
    
    char *start = xml_str;
    char tag[MAX_TAG_NAME_LEN];
    char att[MAX_ATT_NAME_LEN];
    char value[MAX_ATT_VALUE_LEN];
    int att_index = 0;
    int value_index = 0;
    int parsing_tag = 0;
    int parsing_att = 0;
    int parsing_value = 0;
    root->children = malloc(sizeof(struct xml_node*));
    root->attributes = NULL;
    int child_index = 0;
    struct xml_node *current = NULL;
    while (*start != '\0') {
        if (*start == '<') {    // Start of a tag
            if (*(start + 1) == '/') {    // End tag
                current->text[strlen(current->text) - 1] = '\0';
                current = root;
                child_index--;
            }
            else {    // Start tag
                parsing_tag = 1;
                memset(tag, 0, MAX_TAG_NAME_LEN);
                current->children = realloc(current->children, sizeof(struct xml_node*) * (child_index + 1));
                current->children[child_index] = malloc(sizeof(struct xml_node));
                current = current->children[child_index];
                memset(current->tag, 0, MAX_TAG_NAME_LEN);
                memset(current->text, 0, 1000);
                current->attributes = NULL;
                current->num_attributes = 0;
                current->num_children = 0;
                child_index++;
            }
        }
        else if (*start == '>') {    // End of tag
            parsing_tag = 0;
            parsing_att = 0;
            parsing_value = 0;
        }
        else if (parsing_tag) {    // Parsing tag name
            if (isalnum(*start)) {
                strncat(tag, start, 1);
            }
            else if (*start == ' ') {    // Start of attribute
                parsing_att = 1;
                current->num_attributes++;
                current->attributes = realloc(current->attributes, sizeof(struct attribute*) * current->num_attributes);
                current->attributes[current->num_attributes - 1] = malloc(sizeof(struct attribute));
                memset(current->attributes[current->num_attributes - 1]->name, 0, MAX_ATT_NAME_LEN);
                memset(current->attributes[current->num_attributes - 1]->value, 0, MAX_ATT_VALUE_LEN);
                strncpy(current->attributes[current->num_attributes - 1]->name, att, att_index);
                att_index = 0;
            }
            else if (*start == '/') {    // Self-closing tag
                current->num_children = -1;
                parsing_tag = 0;
            }
        }
        else if (parsing_att) {    // Parsing attribute name
            if (isalnum(*start)) {
                strncat(att, start, 1);
            }
            else if (*start == '=') {
                parsing_value = 1;
            }
        }
        else if (parsing_value) {    // Parsing attribute value
            if (*start != '"' && *start != '\'') {
                if (value_index < MAX_ATT_VALUE_LEN - 1) {
                    strncat(value, start, 1);
                    value_index++;
                }
            }
            else {
                strncpy(current->attributes[current->num_attributes - 1]->value, value, value_index);
                value_index = 0;
                parsing_value = 0;
            }
        }
        else {    // Parsing text content
            if (current->num_children == -1) {
                current->text[strlen(current->text) - 1] = '\0';
                current = root;
                child_index--;
                current->num_children = child_index;
            }
            if (*start != '\n' && *start != ' ') {
                strncat(current->text, start, 1);
            }
        }
        start++;
    }
    return root;
}

// Function to print the tree (inorder traversal)
void print_tree(struct xml_node *node) {
    printf("<%s", node->tag);
    if (node->num_attributes > 0) {
        for (int i = 0; i < node->num_attributes; i++) {
            printf(" %s=\"%s\"", node->attributes[i]->name, node->attributes[i]->value);
        }
    }
    printf(">");
    if (strcmp(node->text, "") != 0) {
        printf("%s", node->text);
    }
    if (node->num_children > 0) {
        for (int i = 0; i < node->num_children; i++) {
            print_tree(node->children[i]);
        }
    }
    printf("</%s>", node->tag);
}

int main(void) {
    char *xml_str = "<bookstore>\n<book category=\"cooking\">\n<title lang=\"en\">Everyday Italian</title>\n<author>Giada De Laurentiis</author>\n<year>2005</year>\n<price>30.00</price>\n</book>\n<book category=\"children\">\n<title lang=\"en\">Harry Potter</title>\n<author>J.K. Rowling</author>\n<year>2005</year>\n<price>29.99</price>\n</book>\n</bookstore>";
    struct xml_node *root = build_tree(xml_str);
    print_tree(root);
    return 0;
}