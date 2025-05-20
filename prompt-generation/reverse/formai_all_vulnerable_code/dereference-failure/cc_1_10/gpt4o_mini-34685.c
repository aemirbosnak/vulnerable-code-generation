//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LENGTH 100
#define MAX_CONTENT_LENGTH 256

typedef struct Node {
    char tagName[MAX_TAG_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    struct Node *next;
} Node;

Node *createNode(const char *tagName, const char *content) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->tagName, tagName);
    strcpy(newNode->content, content);
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node **head, const char *tagName, const char *content) {
    Node *newNode = createNode(tagName, content);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("Tag: %s\n", temp->tagName);
        printf("Content: %s\n\n", temp->content);
        temp = temp->next;
    }
}

void parseXML(FILE *file) {
    char line[512];
    char tag[MAX_TAG_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    Node *head = NULL;

    while (fgets(line, sizeof(line), file)) {
        char *openTag = strchr(line, '<');
        char *closeTag = strchr(line, '>');
        char *contentStart = closeTag + 1;
        char *contentEnd = strchr(contentStart, '<');

        if (openTag && closeTag && contentStart && contentEnd) {
            strncpy(tag, openTag + 1, closeTag - openTag - 1);
            tag[closeTag - openTag - 1] = '\0';

            strncpy(content, contentStart, contentEnd - contentStart);
            content[contentEnd - contentStart] = '\0';

            appendNode(&head, tag, content);
        }
    }

    printList(head);
    freeList(head);
}

int main() {
    const char *fileName = "example.xml";
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening the file: %s\n", fileName);
        return EXIT_FAILURE;
    }

    printf("Welcome to the Simple XML Parser!\n");
    printf("Parsing the XML file: %s\n", fileName);
    parseXML(file);
    fclose(file);

    printf("Thank you for using the XML Parser. Have a peaceful day!\n");
    return EXIT_SUCCESS;
}