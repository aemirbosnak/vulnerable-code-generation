//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIR_NAME_LEN 255
#define MAX_FILE_NAME_LEN 255

typedef struct Node {
    char *name;
    struct Node *next;
    struct Node *dir;
    FILE *fp;
} Node;

Node *newNode(char *name) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->name = strdup(name);
    node->next = NULL;
    node->dir = NULL;
    node->fp = NULL;
    return node;
}

void insertDir(Node *node, char *dirName) {
    Node *dirNode = newNode(dirName);
    if (node->dir == NULL) {
        node->dir = dirNode;
    } else {
        insertDir(node->dir, dirName);
    }
}

void insertFile(Node *node, char *fileName) {
    Node *fileNode = newNode(fileName);
    if (node->dir == NULL) {
        insertDir(node, "");
    }
    insertDir(node->dir, fileName);
}

void listDir(Node *node) {
    if (node->dir) {
        printf("%s\n", node->dir->name);
        listDir(node->dir);
    }
}

int main() {
    Node *root = newNode("");
    insertDir(root, "home");
    insertDir(root, "work");
    insertFile(root, "home/a.txt");
    insertFile(root, "work/b.txt");
    listDir(root);
    return 0;
}