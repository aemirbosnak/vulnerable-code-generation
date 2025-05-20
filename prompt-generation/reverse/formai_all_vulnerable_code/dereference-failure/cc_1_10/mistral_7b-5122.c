//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100
#define MAX_NAME_WORDS 10
#define MAX_FILES 50

typedef struct File {
    char name[MAX_NAME_LENGTH];
    int size;
    struct File* next;
} File;

typedef struct Node {
    char incantation[MAX_NAME_LENGTH];
    File* file;
    struct Node* next;
} Node;

File* files = NULL;
Node* nodes = NULL;

void createFile(char* name, int size, char* incantation) {
    File* newFile = (File*) malloc(sizeof(File));
    strcpy(newFile->name, name);
    newFile->size = size;
    newFile->next = files;
    files = newFile;

    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->incantation, incantation);
    newNode->file = newFile;
    newNode->next = nodes;
    nodes = newNode;
}

void openFile(char* incantation) {
    Node* currentNode = nodes;
    while (currentNode != NULL) {
        int match = 1;
        int i;
        for (i = 0; i < strlen(incantation); i++) {
            if (isalpha(currentNode->incantation[i]) && toupper(incantation[i]) != toupper(currentNode->incantation[i])) {
                match = 0;
                break;
            }
        }
        if (match) {
            printf("Opening file: %s\n", currentNode->file->name);
            printf("File size: %d bytes\n", currentNode->file->size);
            free(currentNode);
            nodes = currentNode->next;
            return;
        }
        currentNode = currentNode->next;
    }
    printf("Incorrect incantation.\n");
}

int main() {
    createFile("An apple a day keeps the doctor away", 1024, "An apple a day");
    createFile("A stitch in time saves nine", 2048, "A stitch in time");
    createFile("A watched pot never boils", 512, "A watched pot");

    openFile("An apple a day");
    openFile("A stitch in time");
    openFile("A watched pot");
    openFile("A watched kettle"); // Incorrect incantation

    return 0;
}