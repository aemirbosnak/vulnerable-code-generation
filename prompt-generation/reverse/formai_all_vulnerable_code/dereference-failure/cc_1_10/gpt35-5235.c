//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 50
#define MAX_ATTRIBUTE_COUNT 50
#define MAX_ATTRIBUTE_NAME_LENGTH 50
#define MAX_ATTRIBUTE_VALUE_LENGTH 100
#define MAX_NODE_CHILDREN 50

typedef struct Attribute {
    char name[MAX_ATTRIBUTE_NAME_LENGTH];
    char value[MAX_ATTRIBUTE_VALUE_LENGTH];
} Attribute;

typedef struct Node {
    char tag[MAX_TAG_LENGTH];
    Attribute attributes[MAX_ATTRIBUTE_COUNT];
    int attributeCount;
    char value[MAX_ATTRIBUTE_VALUE_LENGTH];
    int childrenCount;
    struct Node* children[MAX_NODE_CHILDREN];
} Node;

typedef struct StackNode {
    Node* node;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* head;
    int size;
} Stack;

Node* parseXml(char* xmlString) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->head = NULL;
    stack->size = 0;
    Node* root = NULL;

    int i = 0;
    while (xmlString[i] != '\0') {
        if (xmlString[i] == '<') {
            i++;
            int j = i;
            while (xmlString[j] != ' ' && xmlString[j] != '>' && xmlString[j] != '\0') {
                j++;
            }
            char* tag = (char*) malloc((j - i + 1) * sizeof(char));
            strncpy(tag, xmlString + i, j - i);
            tag[j - i] = '\0';
            i = j;

            if (xmlString[i] == ' ') {
                i++;
                int k = 0;
                while (xmlString[i] != '>' && xmlString[i] != '\0') {
                    int l = i;
                    while (xmlString[l] != '=' && xmlString[l] != '>' && xmlString[l] != '\0') {
                        l++;
                    }
                    char* attrName = (char*) malloc((l - i + 1) * sizeof(char));
                    strncpy(attrName, xmlString + i, l - i);
                    attrName[l - i] = '\0';
                    i = l;

                    if (xmlString[i] == '=') {
                        i++;
                        if (xmlString[i] == '\"' || xmlString[i] == '\'') {
                            char quoteChar = xmlString[i];
                            i++;
                            int m = i;
                            while (xmlString[m] != quoteChar && xmlString[m] != '\0') {
                                m++;
                            }
                            char* attrValue = (char*) malloc((m - i + 1) * sizeof(char));
                            strncpy(attrValue, xmlString + i, m - i);
                            attrValue[m - i] = '\0';
                            i = m + 1;

                            Attribute attribute = {
                                .name = attrName,
                                .value = attrValue
                            };
                            Node* node = (Node*) malloc(sizeof(Node));
                            strcpy(node->tag, tag);
                            node->attributes[node->attributeCount] = attribute;
                            node->attributeCount += 1;

                            if (stack->size == 0) {
                                root = node;
                            } else {
                                Node* parent = stack->head->node;
                                parent->children[parent->childrenCount] = node;
                                parent->childrenCount += 1;
                            }

                            StackNode* stackNode = (StackNode*) malloc(sizeof(StackNode));
                            stackNode->node = node;
                            stackNode->next = stack->head;
                            stack->head = stackNode;
                            stack->size += 1;

                            free(attrValue);
                        }
                    }

                    free(attrName);
                }
                i++;
            }

            if (xmlString[i] != '/') {
                i = j + 1;
            } else {
                StackNode* stackNode = stack->head;
                stack->head = stack->head->next;
                stack->size -= 1;
                free(stackNode->node);
                free(stackNode);
                i = j + 2;
            }

            free(tag);
        } else {
            int j = i;
            while (xmlString[j] != '<' && xmlString[j] != '\0') {
                j++;
            }
            char* value = (char*) malloc((j - i + 1) * sizeof(char));
            strncpy(value, xmlString + i, j - i);
            value[j - i] = '\0';
            i = j;

            Node* node = stack->head->node;
            strcpy(node->value, value);
            free(value);
        }
    }

    free(stack);

    return root;
}

void printXml(Node* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }

    printf("<%s", node->tag);
    for (int i = 0; i < node->attributeCount; i++) {
        printf(" %s=\"%s\"", node->attributes[i].name, node->attributes[i].value);
    }
    if (strlen(node->value) == 0 && node->childrenCount == 0) {
        printf("/>\n");
    } else {
        printf(">");
        if (strlen(node->value) != 0) {
            printf("%s", node->value);
        }
        printf("\n");
        for (int i = 0; i < node->childrenCount; i++) {
            printXml(node->children[i], depth + 1);
        }
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("</%s>\n", node->tag);
    }
}

int main() {
    char* xmlString = "<books><book year=\"2010\"><title>C Programming</title><author>Robert C. Martin</author></book><book year=\"2012\"><title>Java Programming</title><author>Joshua Bloch</author></book></books>";
    Node* root = parseXml(xmlString);
    printXml(root, 0);
    return 0;
}