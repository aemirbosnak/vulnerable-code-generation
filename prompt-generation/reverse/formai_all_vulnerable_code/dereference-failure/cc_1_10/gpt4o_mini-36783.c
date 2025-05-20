//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define MAX_TAG_NAME 256

// Structure to hold XML tags
typedef struct XMLNode {
    char tagName[MAX_TAG_NAME];
    char content[MAX_BUFFER];
    struct XMLNode *next;
} XMLNode;

// Function prototypes
XMLNode* create_new_node(const char* tagName, const char* content);
void free_node(XMLNode* node);
void parse_xml(const char* filename);
void print_xml_structure(XMLNode* head);
void skip_whitespace(FILE *file);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    parse_xml(argv[1]);
    return EXIT_SUCCESS;
}

// Function to create a new XML node
XMLNode* create_new_node(const char* tagName, const char* content) {
    XMLNode* newNode = (XMLNode*)malloc(sizeof(XMLNode));
    if (!newNode) {
        perror("Failed to allocate memory for XMLNode");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->tagName, tagName, MAX_TAG_NAME);
    strncpy(newNode->content, content, MAX_BUFFER);
    newNode->next = NULL;
    return newNode;
}

// Function to free a node
void free_node(XMLNode* node) {
    free(node);
}

// Function to skip whitespace characters
void skip_whitespace(FILE *file) {
    char c;
    while ((c = fgetc(file)) != EOF && (c == ' ' || c == '\n' || c == '\r' || c == '\t'));
    ungetc(c, file); // Push back the character
}

// Function to parse XML file
void parse_xml(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char tagName[MAX_TAG_NAME];
    char content[MAX_BUFFER];
    int inTag = 0;
    int pos = 0;
    int c;
    
    XMLNode* head = NULL;
    XMLNode* tail = NULL;

    while ((c = fgetc(file)) != EOF) {
        if (c == '<') {
            // Handle closing tag or opening tag
            skip_whitespace(file);
            if ((c = fgetc(file)) == '/') {
                // Skip the closing '/'
                // Read the tag until '>'
                while ((c = fgetc(file)) != EOF && c != '>') {}
            } else {
                // It's an opening tag
                ungetc(c, file); // Push back the character
                fscanf(file, "%255s", tagName);

                // Read until the closing '>'
                skip_whitespace(file);
                if ((c = fgetc(file)) != '>') {
                    fprintf(stderr, "Error: Expected '>' after tag name in file %s\n", filename);
                    fclose(file);
                    return;
                }

                // Now to read content until another '<'
                pos = 0;
                while ((c = fgetc(file)) != EOF && c != '<') {
                    if (pos < MAX_BUFFER - 1) {
                        content[pos++] = c;
                    }
                }
                content[pos] = '\0'; // Null terminate the content

                // Create a new node and link it
                XMLNode* newNode = create_new_node(tagName, content);
                if (head == NULL) {
                    head = newNode;
                } else {
                    tail->next = newNode;
                }
                tail = newNode;
                if (c == EOF) break; // Reached end of file
                ungetc(c, file); // Push back the character for next iteration
            }
        }
    }

    fclose(file);

    // Print the parsed XML structure
    print_xml_structure(head);

    // Free allocated memory
    XMLNode* current = head;
    while (current != NULL) {
        XMLNode* next = current->next;
        free_node(current);
        current = next;
    }
}

// Function to print the structure of parsed XML
void print_xml_structure(XMLNode* head) {
    printf("Parsed XML Structure:\n");
    XMLNode* current = head;
    while (current != NULL) {
        printf("Tag: %s, Content: %s\n", current->tagName, current->content);
        current = current->next;
    }
}