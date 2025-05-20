//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char tag[30];
    char content[100];
    struct Node *child;
    struct Node *sibling;
} Node;

Node *root = NULL;
Node *current = NULL;
char *buffer; // Global buffer to store the XML file

// Function to create a new node
Node *newNode(char *tag) {
    Node *node = (Node*) malloc(sizeof(Node));
    strcpy(node->tag, tag);
    node->content[0] = '\0';
    node->child = NULL;
    node->sibling = NULL;
    return node;
}

// Recursive function to parse the XML file
void parseXML(char *start, char *end) {
    char *tagStart, *tagEnd, *contentStart, *contentEnd;
    Node *node, *temp;
    
    tagStart = strchr(start, '<');
    while (tagStart != NULL && tagStart < end) {
        tagEnd = strchr(tagStart, '>');
        if (tagEnd == NULL)
            break;
        
        contentStart = tagEnd + 1;
        if (*contentStart != '\0') {
            contentEnd = strstr(contentStart, "<");
            if (contentEnd == NULL)
                break;
        } else {
            contentEnd = contentStart;
        }
        
        node = newNode(tagStart+1);
        if (root == NULL) {
            root = current = node;
        } else {
            if (current->child == NULL) {
                current->child = node;
            } else {
                temp = current->child;
                while (temp->sibling != NULL)
                    temp = temp->sibling;
                temp->sibling = node;
            }
        }
        current = node;
        
        if (*contentStart != '\0') {
            *contentEnd = '\0';
            strcpy(current->content, contentStart);
            current = current->sibling;
        }
        
        tagStart = strchr(tagEnd, '<');
    }
}

int main() {
    FILE *fp;
    long fileSize;
    
    fp = fopen("xmlfile.xml", "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    rewind(fp);
    
    buffer = (char*) malloc(fileSize + 1);
    fread(buffer, fileSize, 1, fp);
    buffer[fileSize] = '\0';
    
    parseXML(buffer, buffer + fileSize);
    
    fclose(fp);
    free(buffer);
    
    // Display the parsed nodes
    current = root;
    while (current != NULL) {
        printf("<%s>", current->tag);
        if (strlen(current->content) > 0)
            printf("%s", current->content);
        printf("</%s>\n", current->tag);
        current = current->sibling;
    }
    
    return 0;
}