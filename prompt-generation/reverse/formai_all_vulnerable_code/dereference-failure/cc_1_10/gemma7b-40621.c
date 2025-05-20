//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FileNode {
    char *name;
    struct FileNode *next;
} FileNode;

void insertFile(FileNode **head, char *name) {
    FileNode *newNode = (FileNode *)malloc(sizeof(FileNode));
    newNode->name = strdup(name);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void backupFiles(FileNode *head) {
    FILE *fp;
    FileNode *curr = head;

    while (curr) {
        fp = fopen(curr->name, "r");
        if (fp) {
            char buffer[1024];
            int readBytes = 0;

            while ((readBytes = fread(buffer, 1, 1024, fp)) > 0) {
                fwrite(buffer, readBytes, 1, stdout);
            }

            fclose(fp);
        }
        curr = curr->next;
    }
}

int main() {
    FileNode *head = NULL;
    insertFile(&head, "file1.txt");
    insertFile(&head, "file2.txt");
    insertFile(&head, "file3.txt");

    backupFiles(head);

    return 0;
}