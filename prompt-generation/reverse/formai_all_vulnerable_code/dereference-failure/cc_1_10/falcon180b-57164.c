//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAG_LENGTH 100
#define MAX_VALUE_LENGTH 1000

// Node structure for the XML tree
typedef struct {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct node *next;
} Node;

// Function to create a new node
Node* createNode(char* tag, char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->tag, tag);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    return newNode;
}

// Function to print the XML tree
void printTree(Node* root) {
    Node* current = root;
    while (current!= NULL) {
        printf("<%s>%s</%s>\n", current->tag, current->value, current->tag);
        current = current->next;
    }
}

// Function to parse the XML input
Node* parseXML(char* xml) {
    Node* root = NULL;
    Node* current = NULL;
    char* startTag = NULL;
    int inTag = 0;
    char* value = NULL;
    int valueLength = 0;

    // Loop through each character in the XML input
    for (int i = 0; xml[i]!= '\0'; i++) {
        char c = tolower(xml[i]);

        // If we encounter the start of a tag
        if (c == '<') {
            inTag = 1;
            startTag = &xml[i];
        }
        // If we encounter the end of a tag
        else if (c == '>') {
            inTag = 0;

            // If we have a complete tag, create a new node
            if (startTag!= NULL && strlen(startTag) > 0 && value!= NULL && strlen(value) > 0) {
                current = createNode(strdup(startTag), strdup(value));
                value = NULL;
                valueLength = 0;
            }

            // Reset the start tag pointer
            startTag = NULL;
        }
        // If we are inside a tag, accumulate the value
        else if (inTag) {
            if (value == NULL) {
                value = &xml[i];
            }
            else {
                value = realloc(value, strlen(value) + 1 + strlen(&xml[i]) + 1);
                strcat(value, &xml[i]);
            }
            valueLength++;
        }
    }

    // If we have a partial tag at the end of the input, create a new node
    if (inTag && startTag!= NULL && strlen(startTag) > 0 && value!= NULL && strlen(value) > 0) {
        current = createNode(strdup(startTag), strdup(value));
        value = NULL;
        valueLength = 0;
    }

    // Return the root node of the XML tree
    return root;
}

// Main function to read XML input from a file and parse it
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <xml_file>\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char inputBuffer[1000000];
    fread(inputBuffer, sizeof(char), sizeof(inputBuffer), inputFile);
    fclose(inputFile);

    Node* root = parseXML(inputBuffer);
    printTree(root);

    return 0;
}