//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct Node {
    char name[20];
    struct Node** children;
    struct Node* parent;
} Node;

Node** directory;

void createDirectory(char* name)
{
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->children = NULL;
    newNode->parent = directory;

    directory = newNode;
}

void createFile(char* name)
{
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->children = NULL;
    newNode->parent = directory;

    directory = newNode;
}

void listDirectory()
{
    for (Node* node = directory; node; node = node->children)
    {
        printf("%s\n", node->name);
    }
}

int main()
{
    createDirectory("root");
    createDirectory("home");
    createDirectory("documents");
    createDirectory("pictures");

    createFile("my-document.txt");
    createFile("photo.jpg");

    listDirectory();

    return 0;
}