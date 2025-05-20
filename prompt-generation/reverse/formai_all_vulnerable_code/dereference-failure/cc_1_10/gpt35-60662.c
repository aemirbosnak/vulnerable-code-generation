//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Struct representing the XML node
typedef struct xml_node {
    char* name;
    char* value;
    struct xml_node* children;
    struct xml_node* next;
} xml_node;

// Helper function to create a new XML node
xml_node* create_node(char* name, char* value) {
    xml_node* newNode = (xml_node*) malloc(sizeof(xml_node));
    newNode->name = (char*) malloc(MAX_SIZE * sizeof(char));
    newNode->value = (char*) malloc(MAX_SIZE * sizeof(char));
    strcpy(newNode->name, name);
    strcpy(newNode->value, value);
    newNode->children = NULL;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print an XML node and its children
void print_node(xml_node* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("\t");
    }
    printf("<%s>%s\n", node->name, node->value);
    if (node->children != NULL) {
        xml_node* currChild = node->children;
        while (currChild != NULL) {
            print_node(currChild, depth + 1);
            currChild = currChild->next;
        }
    }
    for (int i = 0; i < depth; i++) {
        printf("\t");
    }
    printf("</%s>\n", node->name);
}

// Main parsing function
void parse_xml(char* xml_string) {
    xml_node* root = NULL;
    xml_node* currNode = NULL;
    int tagStart = -1;
    int currIndex = 0;
    while (xml_string[currIndex] != '\0') {
        if (xml_string[currIndex] == '<') {
            if (xml_string[currIndex + 1] == '/') {
                // Closing tag
                int tagEnd = currIndex + 2;
                while (xml_string[tagEnd] != '>') {
                    tagEnd++;
                }
                char* tagName = (char*) malloc((tagEnd - currIndex - 2) * sizeof(char));
                strncpy(tagName, xml_string + currIndex + 2, tagEnd - currIndex - 2);
                if (strcmp(tagName, currNode->name) != 0) {
                    printf("Error: Mismatched closing tag: </%s>\n", tagName);
                    return;
                }
                currNode = currNode->next;
            } else {
                // Opening tag
                int tagEnd = currIndex + 1;
                while (xml_string[tagEnd] != '>') {
                    tagEnd++;
                }
                char* tagName = (char*) malloc((tagEnd - currIndex - 1) * sizeof(char));
                strncpy(tagName, xml_string + currIndex + 1, tagEnd - currIndex - 1);
                currNode = create_node(tagName, "");
                if (root == NULL) {
                    root = currNode;
                } else {
                    currNode->next = currNode->children;
                    currNode->children = NULL;
                    currNode = currNode->next;
                }
            }
            tagStart = currIndex + 1;
        } else if (xml_string[currIndex] == '>') {
            // Value within tag
            int valueStart = tagStart + 1;
            while (xml_string[valueStart] == ' ' || xml_string[valueStart] == '\n' || xml_string[valueStart] == '\t') {
                valueStart++;
            }
            int valueEnd = currIndex - 1;
            while (xml_string[valueEnd] == ' ' || xml_string[valueEnd] == '\n' || xml_string[valueEnd] == '\t') {
                valueEnd--;
            }
            int valueLen = valueEnd - valueStart + 1;
            char* value = (char*) malloc((valueLen + 1) * sizeof(char));
            strncpy(value, xml_string + valueStart, valueLen);
            value[valueLen] = '\0';
            currNode->value = value;
        }
        currIndex++;
    }
    print_node(root, 0);
}

int main() {
    char* xml_string = "<book>\n\t<title>The Great Gatsby</title>\n\t<author>F. Scott Fitzgerald</author>\n\t<publisher>Charles Scribner's Sons</publisher>\n</book>";
    parse_xml(xml_string);
    return 0;
}