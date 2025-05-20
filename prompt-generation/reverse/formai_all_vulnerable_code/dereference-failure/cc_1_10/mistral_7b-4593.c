//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_PATH 256
#define MAX_FILENAME 50

typedef struct FileNode {
    char name[MAX_FILENAME];
    int isDirectory;
    struct FileNode *next;
} FileNode;

void traverseDirectory(char path[MAX_PATH]);
void printDirectoryContent(FileNode *head);
FileNode *createFileNode(char *name, int isDirectory);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    traverseDirectory(argv[1]);
    return 0;
}

void traverseDirectory(char path[MAX_PATH]) {
    DIR *dir;
    struct dirent *entry;
    FileNode *head = NULL;

    if ((dir = opendir(path)) != NULL) {
        chdir(path);

        while ((entry = readdir(dir)) != NULL) {
            FileNode *newNode = createFileNode(entry->d_name, entry->d_type == DT_DIR);
            if (newNode != NULL) {
                newNode->next = head;
                head = newNode;
            }
        }

        closedir(dir);
        chdir("..");
        printDirectoryContent(head);
        free(head);
    } else {
        perror("Error opening directory");
    }
}

void printDirectoryContent(FileNode *head) {
    FileNode *current = head;

    while (current != NULL) {
        printf("%s%s\n", current->name, current->isDirectory ? "/" : "");
        current = current->next;
    }
}

FileNode *createFileNode(char *name, int isDirectory) {
    FileNode *newNode = (FileNode *) malloc(sizeof(FileNode));

    if (newNode != NULL) {
        strcpy(newNode->name, name);
        newNode->isDirectory = isDirectory;
        newNode->next = NULL;
    }

    return newNode;
}