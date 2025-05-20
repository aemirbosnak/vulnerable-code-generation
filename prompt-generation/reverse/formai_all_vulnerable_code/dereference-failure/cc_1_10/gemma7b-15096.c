//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIR_NAME_LEN 255
#define MAX_FILE_NAME_LEN 255

typedef struct Node {
    char dir_name[MAX_DIR_NAME_LEN];
    struct Node* next;
} DirNode;

typedef struct File {
    char file_name[MAX_FILE_NAME_LEN];
    int size;
    struct File* next;
} FileNode;

DirNode* insert_dir(DirNode* head, char* dir_name) {
    DirNode* new_node = malloc(sizeof(DirNode));
    strcpy(new_node->dir_name, dir_name);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        DirNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }

    return head;
}

FileNode* insert_file(FileNode* head, char* file_name, int size) {
    FileNode* new_node = malloc(sizeof(FileNode));
    strcpy(new_node->file_name, file_name);
    new_node->size = size;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        FileNode* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }

    return head;
}

void traverse(DirNode* head) {
    DirNode* current = head;
    while (current) {
        printf("%s\n", current->dir_name);
        traverse(current->next);
    }
}

int main() {
    DirNode* root = insert_dir(NULL, "home");
    insert_dir(root, "documents");
    insert_dir(root, "pictures");

    FileNode* files = insert_file(NULL, "picture.jpg", 10000);
    insert_file(files, "document.txt", 5000);

    traverse(root);

    return 0;
}