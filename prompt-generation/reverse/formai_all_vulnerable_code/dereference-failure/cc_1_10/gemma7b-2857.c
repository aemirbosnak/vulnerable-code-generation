//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_DIR_NAME_LEN 255
#define MAX_FILE_NAME_LEN 255

typedef struct Node {
    char name[MAX_FILE_NAME_LEN];
    struct Node* next;
    struct Node* dir;
} Node;

typedef struct FileSystem {
    Node* root;
} FileSystem;

FileSystem* createFileSystem() {
    FileSystem* fs = malloc(sizeof(FileSystem));
    fs->root = NULL;
    return fs;
}

void addFile(FileSystem* fs, char* filename, char* content) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, filename);
    newNode->next = NULL;
    newNode->dir = fs->root;

    if (fs->root == NULL) {
        fs->root = newNode;
    } else {
        Node* current = fs->root;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Store the content in the file
    // (In this example, the content is simply stored in the node's name)
    strcpy(newNode->name, content);
}

void printFiles(FileSystem* fs) {
    Node* current = fs->root;
    while (current) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main() {
    FileSystem* fs = createFileSystem();
    addFile(fs, "test.txt", "This is a file");
    addFile(fs, "directory", "This is a directory");
    addFile(fs, "subdirectory/file.txt", "This is a file in a subdirectory");

    printFiles(fs);

    return 0;
}