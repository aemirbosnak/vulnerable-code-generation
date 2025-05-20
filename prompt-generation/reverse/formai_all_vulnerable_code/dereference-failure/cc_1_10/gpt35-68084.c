//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 255

struct Node {
    char *tag;
    char **attrs;
    char *value;
    struct Node **children;
};

struct Node *createNode(char *tag) {
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    
    node->tag = strdup(tag);
    node->attrs = NULL;
    node->value = NULL;
    node->children = NULL;
    
    return node;
}

void addAttr(struct Node *node, char *attr) {
    if (node->attrs == NULL) {
        node->attrs = (char**) malloc(sizeof(char*));
        node->attrs[0] = strdup(attr);
    } else {
        int len = 0;
        while (node->attrs[len] != NULL) {
            len++;
        }
        
        node->attrs = (char**) realloc(node->attrs, sizeof(char*) * (len + 1));
        node->attrs[len] = strdup(attr);
    }
}

void setValue(struct Node *node, char *value) {
    node->value = strdup(value);
}

void addChild(struct Node *node, struct Node *child) {
    if (node->children == NULL) {
        node->children = (struct Node**) malloc(sizeof(struct Node*));
        node->children[0] = child;
    } else {
        int len = 0;
        while (node->children[len] != NULL) {
            len++;
        }
        
        node->children = (struct Node**) realloc(node->children, sizeof(struct Node*) * (len + 1));
        node->children[len] = child;
    }
}

void printNode(struct Node *node, int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    
    printf("<%s", node->tag);
    
    if (node->attrs != NULL) {
        int len = 0;
        while (node->attrs[len] != NULL) {
            printf(" %s", node->attrs[len]);
            len++;
        }
    }
    
    if (node->value != NULL) {
        printf(">%s</%s>\n", node->value, node->tag);
    } else if (node->children == NULL) {
        printf("/>\n");
    } else {
        printf(">\n");
        int len = 0;
        while (node->children[len] != NULL) {
            printNode(node->children[len], level + 1);
            len++;
        }
        for (int i = 0; i < level; i++) {
            printf("  ");
        }
        printf("</%s>\n", node->tag);
    }
}

void freeNode(struct Node *node) {
    free(node->tag);
    
    if (node->attrs != NULL) {
        int len = 0;
        while (node->attrs[len] != NULL) {
            free(node->attrs[len]);
            len++;
        }
        free(node->attrs);
    }
    
    if (node->value != NULL) {
        free(node->value);
    }
    
    if (node->children != NULL) {
        int len = 0;
        while (node->children[len] != NULL) {
            freeNode(node->children[len]);
            len++;
        }
        free(node->children);
    }
    
    free(node);
}

int main() {
    FILE *file = fopen("example.xml", "r");
    
    if (file == NULL) {
        printf("Error: Could not read file.\n");
        exit(1);
    }
    
    char buffer[MAX_LENGTH];
    int bufferPos = 0;
    char *currentTag = NULL;
    struct Node *root = NULL;
    struct Node *currentNode = NULL;
    int finished = 0;
    
    while (!finished) {
        char c = fgetc(file);
        
        if (c == EOF) {
            finished = 1;
        } else {
            buffer[bufferPos] = c;
            bufferPos++;
            
            if (c == '<') {
                bufferPos = 1;
                currentTag = NULL;
            } else if (c == '>') {
                buffer[bufferPos - 1] = '\0';
                
                if (buffer[1] == '/') {
                    if (currentNode != NULL) {
                        currentNode = NULL;
                    }
                } else if (buffer[0] == '?') {
                    // ignore
                } else {
                    if (currentTag == NULL) {
                        currentTag = strdup(&buffer[1]);
                        struct Node *node = createNode(currentTag);
                        
                        if (root == NULL) {
                            root = node;
                        } else if (currentNode != NULL) {
                            addChild(currentNode, node);
                        } else {
                            printf("Error: Invalid XML format.\n");
                            exit(1);
                        }
                        
                        currentNode = node;
                    } else {
                        char *attrName = strtok(&buffer[1], " ");
                        char *attrValue = strtok(NULL, " ");
                        while (attrName != NULL && attrValue != NULL) {
                            char attr[MAX_LENGTH];
                            sprintf(attr, "%s=\"%s\"", attrName, attrValue);
                            addAttr(currentNode, attr);
                            attrName = strtok(NULL, " ");
                            attrValue = strtok(NULL, " ");
                        }
                    }
                }
            } else {
                if (currentTag != NULL && currentNode != NULL) {
                    setValue(currentNode, buffer);
                }
            }
        }
    }
    
    fclose(file);
    
    printNode(root, 0);
    
    freeNode(root);
    
    return 0;
}