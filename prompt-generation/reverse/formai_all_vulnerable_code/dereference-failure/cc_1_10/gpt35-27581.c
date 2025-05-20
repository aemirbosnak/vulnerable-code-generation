//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

// Define a structure to represent a file or directory
typedef struct node {
    char name[256];
    long size;
    struct node* next;
} node;

// Define a function to recursively search for files and directories
node* analyzeDirectory(char* directoryPath) {
    node* head = NULL;
    node* current = NULL;
    DIR* directory = opendir(directoryPath);
    struct dirent* entry;
    while ((entry = readdir(directory))) {
        // Ignore the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char fullPath[512];
        sprintf(fullPath, "%s/%s", directoryPath, entry->d_name);
        struct stat st;
        if (stat(fullPath, &st) == 0) {
            if (S_ISREG(st.st_mode)) {
                // If this is a regular file, add it to the list
                node* newNode = (node*)malloc(sizeof(node));
                if (newNode == NULL) {
                    printf("Failed to allocate memory\n");
                    exit(1);
                }
                strcpy(newNode->name, entry->d_name);
                newNode->size = st.st_size;
                newNode->next = NULL;
                if (head == NULL) {
                    head = newNode;
                    current = newNode;
                } else {
                    current->next = newNode;
                    current = newNode;
                }
            } else if (S_ISDIR(st.st_mode)) {
                // If this is a directory, analyze its contents recursively
                node* subdirectoryNodes = analyzeDirectory(fullPath);
                node* currentNode = subdirectoryNodes;
                while (currentNode != NULL) {
                    node* newNode = (node*)malloc(sizeof(node));
                    if (newNode == NULL) {
                        printf("Failed to allocate memory\n");
                        exit(1);
                    }
                    strcpy(newNode->name, entry->d_name);
                    newNode->size = currentNode->size;
                    newNode->next = NULL;
                    if (head == NULL) {
                        head = newNode;
                        current = newNode;
                    } else {
                        current->next = newNode;
                        current = newNode;
                    }
                    currentNode = currentNode->next;
                }
                // Free the memory allocated for subdirectoryNodes
                currentNode = subdirectoryNodes;
                while (currentNode != NULL) {
                    node* nextNode = currentNode->next;
                    free(currentNode);
                    currentNode = nextNode;
                }
            }
        }
    }
    closedir(directory);
    return head;
}

// Define a function to print the list of files and directories with their sizes
void printList(node* head) {
    printf("Name\tSize\n");
    node* current = head;
    while (current != NULL) {
        printf("%s\t%ld\n", current->name, current->size);
        current = current->next;
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s directoryPath\n", argv[0]);
        exit(1);
    }
    char* directoryPath = argv[1];
    node* head = analyzeDirectory(directoryPath);
    printList(head);
    // Free the memory allocated for the linked list
    node* current = head;
    while (current != NULL) {
        node* next = current->next;
        free(current);
        current = next;
    }
    return 0;
}