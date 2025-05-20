//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct FileNode {
    char filename[256];
    struct FileNode* next;
} FileNode;

FileNode* insertFile(FileNode* head, char* filename) {
    FileNode* newNode = malloc(sizeof(FileNode));
    strcpy(newNode->filename, filename);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void synchronizeFiles(FileNode* head) {
    FILE* filePtr;
    char content[MAX_FILES][1024];
    int i = 0;

    for (FileNode* node = head; node; node = node->next) {
        filePtr = fopen(node->filename, "r");
        fscanf(filePtr, "%[^\n]%*c", content[i]);
        fclose(filePtr);
        i++;
    }

    for (i = 0; i < MAX_FILES; i++) {
        for (FileNode* node = head; node; node = node->next) {
            filePtr = fopen(node->filename, "w");
            fprintf(filePtr, "%s", content[i]);
            fclose(filePtr);
        }
    }
}

int main() {
    FileNode* head = NULL;
    insertFile(head, "a.txt");
    insertFile(head, "b.txt");
    insertFile(head, "c.txt");

    synchronizeFiles(head);

    return 0;
}