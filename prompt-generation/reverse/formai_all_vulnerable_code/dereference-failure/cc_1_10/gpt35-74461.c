//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_SIZE 50
#define MAX_ATTR_SIZE 50
#define MAX_VALUE_SIZE 1000

struct node {
    char tag[MAX_TAG_SIZE];
    char attr[MAX_ATTR_SIZE];
    char value[MAX_VALUE_SIZE];
    struct node* child;
    struct node* sibling;
};

struct node* parseXML(char* xml) {
    struct node* root = NULL;
    struct node* curr = NULL;
    char tag[MAX_TAG_SIZE], attr[MAX_ATTR_SIZE], value[MAX_VALUE_SIZE];
    int i = 0;
    while (xml[i] != '\0') {
        if (xml[i] == '<') {
            i++;
            int j = 0;
            while (xml[i] != '>') {
                tag[j] = xml[i];
                i++; j++;
            }
            tag[j] = '\0';
            curr = (struct node*) malloc(sizeof(struct node));
            strcpy(curr->tag, tag);
            curr->child = NULL;
            curr->sibling = NULL;
            if (root == NULL) {
                root = curr;
            } else {
                curr->sibling = root->child;
                root->child = curr;
            }
        } else {
            if (xml[i] == '/') {
                root = root->sibling;
            } else if (xml[i] == '=') {
                i++;
                int j = 0;
                while (xml[i] != '\"') {
                    attr[j] = xml[i];
                    i++; j++;
                }
                attr[j] = '\0';
                i += 2;
                j = 0;
                while (xml[i] != '\"') {
                    value[j] = xml[i];
                    i++; j++;
                }
                value[j] = '\0';
                strcpy(curr->attr, attr);
                strcpy(curr->value, value);
            }
            i++;
        }
    }
    return root;
}

void printXML(struct node* root) {
    if (root == NULL) {
        return;
    }
    printf("<%s %s=\"%s\"", root->tag, root->attr, root->value);
    if (root->child == NULL) {
        printf("/>\n");
        printXML(root->sibling);
    } else {
        printf(">\n");
        printXML(root->child);
        printf("</%s>\n", root->tag);
        printXML(root->sibling);
    }
}

int main() {
    char xml[] = "<root>\n"
                 "  <person name=\"John\" age=\"30\" />\n"
                 "  <person name=\"Jane\" age=\"25\" />\n"
                 "</root>\n";
    struct node* root = parseXML(xml);
    printXML(root);
    return 0;
}