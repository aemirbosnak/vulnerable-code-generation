//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 128

typedef struct Node {
    char tag[MAX_TAG_LENGTH];
    char content[MAX_LINE_LENGTH];
    struct Node *next;
} Node;

Node* createNode(const char* tag, const char* content) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->tag, tag, MAX_TAG_LENGTH);
    strncpy(newNode->content, content, MAX_LINE_LENGTH);
    newNode->next = NULL;
    return newNode;
}

void freeNode(Node* node) {
    free(node);
}

void appendNode(Node** head, const char* tag, const char* content) {
    Node* newNode = createNode(tag, content);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printXML(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("<%s>%s</%s>\n", current->tag, current->content, current->tag);
        current = current->next;
    }
}

void parseLine(const char* line, Node** list) {
    char tag[MAX_TAG_LENGTH], content[MAX_LINE_LENGTH];
    if (sscanf(line, "<%127[^>]>%1023[^<]</%127[^>]", tag, content, tag) == 3) {
        appendNode(list, tag, content);
    }
}

void parseXMLFile(const char* filename, Node** list) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parseLine(line, list);
    }
    
    fclose(file);
}

void freeList(Node* head) {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        freeNode(current);
        current = nextNode;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Node* xmlList = NULL;
    parseXMLFile(argv[1], &xmlList);

    printf("Parsed XML:\n");
    printXML(xmlList);

    freeList(xmlList);
    return EXIT_SUCCESS;
}