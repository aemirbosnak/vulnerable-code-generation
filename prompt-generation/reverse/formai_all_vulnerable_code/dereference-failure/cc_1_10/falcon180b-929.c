//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000000

typedef struct tagNode {
    char *name;
    char *value;
    struct tagNode *next;
} tagNode;

tagNode *head = NULL;

void addNode(char *name, char *value) {
    tagNode *newnode = (tagNode*)malloc(sizeof(tagNode));
    if (newnode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newnode->name = strdup(name);
    newnode->value = strdup(value);
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        tagNode *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void printNode(tagNode *node) {
    printf("<%s>", node->name);
    if (node->value!= NULL) {
        printf(" %s", node->value);
    }
    printf("</%s>\n", node->name);
}

void freeNodes() {
    tagNode *temp;
    while (head!= NULL) {
        temp = head;
        head = head->next;
        free(temp->name);
        free(temp->value);
        free(temp);
    }
}

int main() {
    char buffer[MAX_SIZE];
    char *start, *end;
    char *name, *value;
    int len;
    FILE *fp;

    fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("File not found\n");
        exit(0);
    }

    while (fgets(buffer, MAX_SIZE, fp)!= NULL) {
        len = strlen(buffer);
        start = buffer;
        while (isspace(*start)) {
            start++;
        }
        end = start;
        while (!isspace(*end) && end < start + len) {
            end++;
        }
        name = strndup(start, end - start);
        start = end;
        while (isspace(*start)) {
            start++;
        }
        end = start;
        while (isspace(*end) || *end == '>') {
            end++;
        }
        value = strndup(start, end - start);
        addNode(name, value);
    }

    fclose(fp);

    tagNode *temp = head;
    while (temp!= NULL) {
        printNode(temp);
        temp = temp->next;
    }

    freeNodes();

    return 0;
}