//Falcon2-11B DATASET v1.0 Category: Building a XML Parser ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char tag[10];
    char value[100];
    struct node *next;
} node;

node *createNode(char *tag, char *value) {
    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode->tag, tag);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    return newNode;
}

node *parseXML(char *xml) {
    node *current = NULL;
    node *next = NULL;
    char *token = strtok(xml, " ");
    while (token!= NULL) {
        if (strcmp(token, "<") == 0) {
            if (current == NULL) {
                current = createNode("", "");
                next = current;
            } else {
                next->next = createNode("", "");
                next = next->next;
            }
            token = strtok(NULL, " ");
        } else if (strcmp(token, ">") == 0) {
            token = strtok(NULL, " ");
            if (strcmp(token, "") == 0) {
                next->value[strlen(next->value) - 1] = '\0';
            } else {
                strcpy(next->value, token);
                token = strtok(NULL, " ");
            }
        } else if (strcmp(token, "</") == 0) {
            token = strtok(NULL, " ");
            if (strcmp(token, ">") == 0) {
                token = strtok(NULL, " ");
                if (strcmp(token, "") == 0) {
                    current = current->next;
                } else {
                    next->value[strlen(next->value) - 1] = '\0';
                    current->value[strlen(current->value) - 1] = '\0';
                    strcpy(current->value, next->value);
                    current = current->next;
                }
                token = strtok(NULL, " ");
            }
        } else {
            strcpy(next->value, token);
            token = strtok(NULL, " ");
        }
        next = next->next;
    }
    return current;
}

int main() {
    char xml[] = "<root><child>value1</child><grandchild>value2</grandchild></root>";
    node *root = parseXML(xml);
    printf("Tag: %s\n", root->tag);
    printf("Value: %s\n", root->value);
    node *current = root;
    while (current!= NULL) {
        printf("Tag: %s\n", current->tag);
        printf("Value: %s\n", current->value);
        current = current->next;
    }
    return 0;
}