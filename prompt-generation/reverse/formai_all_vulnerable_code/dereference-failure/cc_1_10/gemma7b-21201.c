//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct Node {
    char name[20];
    struct Node* next;
    struct Node* dir;
} Node;

Node* newNode(char* name) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->next = NULL;
    node->dir = NULL;
    return node;
}

void addDir(Node* node, char* dirName) {
    Node* dirNode = newNode(dirName);
    node->dir = dirNode;
}

void addFile(Node* dirNode, char* fileName) {
    Node* fileNode = newNode(fileName);
    dirNode->dir = fileNode;
}

int main() {
    Node* root = newNode("root");
    addDir(root, "home");
    addDir(root, "work");
    addDir(root, "games");
    addDir(root, "music");

    addFile(root->dir->dir, "my_photo.jpg");
    addFile(root->dir->dir, "my_song.mp3");
    addFile(root->dir->dir, "documents.txt");

    FILE* file = fopen("documents.txt", "r");
    if (file) {
        printf("Content of documents.txt:\n");
        char line[200];
        while (fgets(line, 200, file) != NULL) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Error opening file.\n");
    }

    return 0;
}