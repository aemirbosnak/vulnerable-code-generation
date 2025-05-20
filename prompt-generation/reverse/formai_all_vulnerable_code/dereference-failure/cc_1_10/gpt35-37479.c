//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LEN 50
#define MAX_ATT_LEN 50
#define MAX_CONTENT_LEN 500

struct XMLNode {
    char tag[MAX_TAG_LEN];
    struct Attribute *attributes;
    char content[MAX_CONTENT_LEN];
    struct XMLNode *children;
};

struct Attribute {
    char name[MAX_ATT_LEN];
    char value[MAX_ATT_LEN];
    struct Attribute *next;
};

int parseXML(struct XMLNode *root, const char *fileName);
void addAttribute(struct Attribute **head, const char *name, const char *value);
void addChild(struct XMLNode **head, const char *tag, const char *content);

int main(void) {
    struct XMLNode rootNode;
    rootNode.children = NULL;
    parseXML(&rootNode, "sample.xml");

    return 0;
}

int parseXML(struct XMLNode *root, const char *fileName) {
    FILE *fp;
    char ch;
    int tagIndex = 0, attIndex = 0, contentIndex = 0, isParsingTag = 0, isParsingAtt = 0, isParsingContent = 0;

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    struct XMLNode *currentNode = root;

    while ((ch = fgetc(fp)) != EOF) {
        switch (ch) {
            case '<':
                isParsingTag = 1;
                isParsingAtt = 0;
                isParsingContent = 0;
                tagIndex = 0;
                break;

            case '>':
                isParsingTag = 0;
                if (currentNode->children != NULL) {
                    currentNode = currentNode->children;
                }
                addChild(&(currentNode->children), currentNode->tag, currentNode->content);
                currentNode->attributes = NULL;
                currentNode->children = NULL;
                break;

            case ' ':
                isParsingAtt = 1;
                isParsingTag = 0;
                addAttribute(&(currentNode->attributes), currentNode->tag, currentNode->content);
                attIndex = 0;
                break;

            case '/':
                currentNode->tag[tagIndex] = '\0';
                if (currentNode->children != NULL) {
                    currentNode = currentNode->children;
                }
                addChild(&(currentNode->children), currentNode->tag, currentNode->content);
                currentNode->attributes = NULL;
                currentNode->children = NULL;
                break;

            default:
                if (isParsingTag) {
                    currentNode->tag[tagIndex++] = ch;
                } else if (isParsingAtt) {
                    currentNode->attributes->name[attIndex++] = ch;
                } else {
                    isParsingContent = 1;
                    currentNode->content[contentIndex++] = ch;
                }
                break;
        }
    }

    fclose(fp);

    return 0;
}

void addAttribute(struct Attribute **head, const char *name, const char *value) {
    struct Attribute *newAttribute = (struct Attribute*)malloc(sizeof(struct Attribute));
    strcpy(newAttribute->name, name);
    strcpy(newAttribute->value, value);
    newAttribute->next = NULL;

    if (*head == NULL) {
        *head = newAttribute;
    } else {
        struct Attribute *currentAttribute = *head;
        while (currentAttribute->next != NULL) {
            currentAttribute = currentAttribute->next;
        }
        currentAttribute->next = newAttribute;
    }
}

void addChild(struct XMLNode **head, const char *tag, const char *content) {
    struct XMLNode *newNode = (struct XMLNode*)malloc(sizeof(struct XMLNode));
    strcpy(newNode->tag, tag);
    strcpy(newNode->content, content);
    newNode->attributes = NULL;
    newNode->children = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct XMLNode *currentNode = *head;
        while (currentNode->children != NULL) {
            currentNode = currentNode->children;
        }
        currentNode->children = newNode;
    }
}