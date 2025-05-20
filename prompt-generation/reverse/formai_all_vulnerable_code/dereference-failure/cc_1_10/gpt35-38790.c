//FormAI DATASET v1.0 Category: File system simulation ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_SIZE 500 // maximum size of file content
#define MAX_FILE_NAME_LENGTH 20 // max length of file name
#define MAX_DIRECTORY_DEPTH 10 // max directory nesting depth

// different types of file entries in the file system
enum FileEntryType {
    FILE_ENTRYTYPE_FILE = 0, FILE_ENTRYTYPE_DIRECTORY
};

// structure of file system node which will hold information about files and directories
struct FileSystemNode {
    char name[MAX_FILE_NAME_LENGTH];
    enum FileEntryType type;
    char* content;
    struct FileSystemNode* children[MAX_DIRECTORY_DEPTH];
};

// create a new file in the file system
struct FileSystemNode* createNewFile(char* name, char* content) {
    struct FileSystemNode* node = (struct FileSystemNode*)malloc(sizeof(struct FileSystemNode));
    node->type = FILE_ENTRYTYPE_FILE;
    strcpy(node->name, name);
    node->content = (char*)malloc(sizeof(char)*MAX_FILE_SIZE);
    strcpy(node->content, content);
    return node;
}

// create a new directory in the file system
struct FileSystemNode* createNewDirectory(char* name) {
    struct FileSystemNode* node = (struct FileSystemNode*)malloc(sizeof(struct FileSystemNode));
    node->type = FILE_ENTRYTYPE_DIRECTORY;
    strcpy(node->name, name);
    int i;
    for (i = 0; i < MAX_DIRECTORY_DEPTH; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// add a node to the children of a directory
void addChildToDirectory(struct FileSystemNode* parent, struct FileSystemNode* child) {
    int i;
    for (i = 0; i < MAX_DIRECTORY_DEPTH; i++) {
        if (parent->children[i] == NULL) {
            parent->children[i] = child;
            break;
        }
    }
}

// search for a file node in the file system
struct FileSystemNode* searchFile(struct FileSystemNode* root, char* name) {
    if (root == NULL) {
        return NULL;
    }
    if (strcmp(root->name, name) == 0 && root->type == FILE_ENTRYTYPE_FILE) {
        return root;
    }
    int i;
    for (i = 0; i < MAX_DIRECTORY_DEPTH; i++) {
        if (root->children[i] != NULL) {
            struct FileSystemNode* node = searchFile(root->children[i], name);
            if (node != NULL) {
                return node;
            }
        }
    }
    return NULL;
}

// print the content of a file
void printFileContent(struct FileSystemNode* node) {
    if (node == NULL || node->type == FILE_ENTRYTYPE_DIRECTORY) {
        printf("Invalid or directory node passed\n");
        return;
    }
    printf("Content of file %s : %s\n", node->name, node->content);
}

// recursively print the file system tree
void printFileSystem(struct FileSystemNode* root, int depth) {
    if (root == NULL) {
        return;
    }
    int i;
    for (i = 0; i < depth; i++) {
        printf("\t");
    }
    if (root->type == FILE_ENTRYTYPE_FILE) {
        printf("%s (File)\n", root->name);
    }
    else if (root->type == FILE_ENTRYTYPE_DIRECTORY) {
        printf("%s (Directory)\n", root->name);
    }
    for (i = 0; i < MAX_DIRECTORY_DEPTH; i++) {
        if (root->children[i] != NULL) {
            if (root->children[i]->type == FILE_ENTRYTYPE_FILE) {
                for (int j = 0; j <= depth; j++) {
                    printf("\t");
                }
                printf("%s\n", root->children[i]->name);
            }
            else {
                printFileSystem(root->children[i], depth + 1);
            }
        }
    }
}

// main function
int main()
{
    // create the root directory of file system
    struct FileSystemNode* root = createNewDirectory("root");

    // create a sample file
    struct FileSystemNode* file = createNewFile("file1.txt", "This is the content of file1.");

    // add the file to root directory
    addChildToDirectory(root, file);

    // search for the file by name
    struct FileSystemNode* searchedFile = searchFile(root, "file1.txt");

    // print the content of searched file
    printFileContent(searchedFile);

    // recursively print the file system tree
    printFileSystem(root, 0);

    return 0;
}