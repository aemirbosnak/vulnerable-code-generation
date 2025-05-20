//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_DIR_SIZE 1024

typedef struct Directory {
    char name[256];
    struct Directory* next;
    long size;
    long freeSpace;
} Directory;

Directory* insertDirectory(Directory* head, char* name) {
    Directory* newNode = (Directory*)malloc(sizeof(Directory));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->size = 0;
    newNode->freeSpace = MAX_DIR_SIZE * 100;

    if (head == NULL) {
        head = newNode;
    } else {
        Directory* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newNode;
    }

    return head;
}

long analyzeDisk(Directory* head) {
    long totalSize = 0;
    long totalFreeSpace = MAX_DIR_SIZE * 100;
    Directory* current = head;

    while (current) {
        struct stat sb;
        stat(current->name, &sb);
        current->size = sb.st_size;
        current->freeSpace = MAX_DIR_SIZE * 100 - current->size;

        totalSize += current->size;
        totalFreeSpace -= current->freeSpace;

        current = current->next;
    }

    return totalSize;
}

int main() {
    Directory* head = NULL;

    insertDirectory(&head, "/home/user");
    insertDirectory(&head, "/home/user/Documents");
    insertDirectory(&head, "/home/user/Pictures");
    insertDirectory(&head, "/home/user/Music");

    long totalSize = analyzeDisk(head);

    printf("Total size of disk space used: %ld bytes\n", totalSize);

    return 0;
}