//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum size of elements and attributes
#define MAX_ELEMENT_SIZE 200
#define MAX_ATTRIBUTE_SIZE 50

// Define the node structure for the XML tree
typedef struct node_t {
    char tag[MAX_ELEMENT_SIZE];
    char value[MAX_ELEMENT_SIZE];
    struct node_t* children;
    struct node_t* next;
} node;

// Define the attribute structure for parsing XML attributes
typedef struct attribute_t {
    char name[MAX_ATTRIBUTE_SIZE];
    char value[MAX_ATTRIBUTE_SIZE];
} attribute;

// Define utility function to skip white space in the input stream
void skip_whitespace(FILE* fp) {
    int c = fgetc(fp);
    while (isspace(c)) {
        c = fgetc(fp);
    }
    ungetc(c, fp);
}

// Define utility function to read a tag from the input stream
void read_tag(FILE* fp, char* buffer) {
    skip_whitespace(fp);
    fscanf(fp, "%[^<> ]", buffer);
}

// Define utility function to read a value from the input stream
void read_value(FILE* fp, char* buffer) {
    fscanf(fp, "%[^<]", buffer);
}

// Define utility function to read an attribute from the input stream
void read_attribute(FILE* fp, attribute* attr) {
    skip_whitespace(fp);
    fscanf(fp, "%[^=]=\"%[^\"]\"", attr->name, attr->value);
}

// Define recursive function to parse an XML node
node* parse_node(FILE* fp) {
    char buffer[MAX_ELEMENT_SIZE];
    node* new_node = (node*)malloc(sizeof(node));
    new_node->children = NULL;
    new_node->next = NULL;
    read_tag(fp, buffer);
    strcpy(new_node->tag, buffer);
    while (1) {
        skip_whitespace(fp);
        int c = fgetc(fp);
        if (c == '<') {
            c = fgetc(fp);
            if (c == '/') {
                fseek(fp, -2, SEEK_CUR);
                return new_node;
            } else {
                fseek(fp, -2, SEEK_CUR);
                node* child_node = parse_node(fp);
                if (new_node->children == NULL) {
                    new_node->children = child_node;
                } else {
                    node* current_node = new_node->children;
                    while (current_node->next != NULL) {
                        current_node = current_node->next;
                    }
                    current_node->next = child_node;
                }
            }
        } else if (c == '>') {
            if (new_node->value[0] != '\0') {
                skip_whitespace(fp);
                read_value(fp, new_node->value);
            }
        } else if (c == '/') {
            new_node->value[0] = '\0';
            return new_node;
        } else if (isalpha(c)) {
            fseek(fp, -1, SEEK_CUR);
            attribute attr;
            read_attribute(fp, &attr);
            // Store the attribute in the value field for now
            strcpy(new_node->value, attr.name);
            // Allocate memory for a new node to store the attribute value
            node* attr_node = (node*)malloc(sizeof(node));
            strcpy(attr_node->tag, attr.name);
            strcpy(attr_node->value, attr.value);
            attr_node->children = NULL;
            attr_node->next = NULL;
            // Add the attribute node as a child of the current node
            if (new_node->children == NULL) {
                new_node->children = attr_node;
            } else {
                node* current_node = new_node->children;
                while (current_node->next != NULL) {
                    current_node = current_node->next;
                }
                current_node->next = attr_node;
            }
        }
    }
}

// Define function to print an XML node and its children recursively
void print_node(node* n) {
    printf("<%s", n->tag);
    // Print any attribute nodes
    node* current_node = n->children;
    while (current_node != NULL && strcmp(current_node->tag, n->value) == 0) {
        printf(" %s=\"%s\"", current_node->tag, current_node->value);
        current_node = current_node->next;
    }
    printf(">");
    // Print the value if it's not an attribute
    if (strcmp(n->value, n->tag) != 0) {
        printf("%s", n->value);
    }
    // Print any child nodes
    current_node = n->children;
    while (current_node != NULL) {
        if (strcmp(current_node->tag, n->value) != 0) {
            printf("\n");
            print_node(current_node);
        }
        current_node = current_node->next;
    }
    printf("</%s>\n", n->tag);
}

// Define main function to parse and print an XML file
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: xml_parser FILENAME\n");
        return 1;
    }
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file \"%s\"\n", argv[1]);
        return 1;
    }
    node* root_node = parse_node(fp);
    fclose(fp);
    print_node(root_node);
    return 0;
}