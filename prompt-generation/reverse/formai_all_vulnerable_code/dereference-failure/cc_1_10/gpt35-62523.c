//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 1000

typedef struct _FileEntry {
    char name[MAX_PATH_LENGTH];
    long size;
    struct _FileEntry *next;
} FileEntry;

void addEntry(FileEntry **headRef, const char *name, const long size);
void printEntries(FileEntry *head, const long totalSize);
void freeEntries(FileEntry *head);
void analyzeDirectory(const char *path, FileEntry **headRef, long *totalSizeRef);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    char *path = argv[1];

    FileEntry *head = NULL;
    long totalSize = 0;

    analyzeDirectory(path, &head, &totalSize);
    printEntries(head, totalSize);
    freeEntries(head);

    return 0;
}

void addEntry(FileEntry **headRef, const char *name, const long size) {
    FileEntry *newEntry = (FileEntry *) malloc(sizeof(FileEntry));
    strncpy(newEntry->name, name, MAX_PATH_LENGTH);
    newEntry->size = size;
    newEntry->next = *headRef;
    *headRef = newEntry;
}

void printEntries(FileEntry *head, const long totalSize) {
    printf("%-60s %20s\n", "Name", "Size");

    for (int i = 0; i < 80; i++) putchar('=');
    putchar('\n');

    for (FileEntry *cur = head; cur != NULL; cur = cur->next) {
        printf("%-60s %20ld\n", cur->name, cur->size);
    }

    for (int i = 0; i < 80; i++) putchar('=');
    putchar('\n');

    printf("%-60s %20ld\n", "Total", totalSize);
}

void freeEntries(FileEntry *head) {
    while (head != NULL) {
        FileEntry *next = head->next;
        free(head);
        head = next;
    }
}

void analyzeDirectory(const char *path, FileEntry **headRef, long *totalSizeRef) {
    char command[MAX_PATH_LENGTH + 30];
    sprintf(command, "du -a --block-size=1 \"%s\"", path);
    FILE *duOutput = popen(command, "r");
    if (duOutput == NULL) {
        fprintf(stderr, "Failed to execute command: %s\n", command);
        return;
    }

    char line[MAX_PATH_LENGTH + 30];
    while (fgets(line, MAX_PATH_LENGTH + 30, duOutput) != NULL) {
        line[strlen(line) - 1] = '\0';

        char *sizeStr = strrchr(line, '\t') + 1;
        long size = atol(sizeStr);

        char *name = line + strlen(command) - strlen(path);
        if (name[0] == '/') name++;

        addEntry(headRef, name, size);
        *totalSizeRef += size;
    }

    if (pclose(duOutput) == -1) {
        fprintf(stderr, "Failed to close pipe.\n");
    }
}