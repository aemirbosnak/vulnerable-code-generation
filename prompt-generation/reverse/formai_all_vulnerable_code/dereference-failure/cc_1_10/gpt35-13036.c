//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct File {
    char *name;
    bool isDirectory;
    long long size;
    struct File *next;
} File;

const long long KB = 1024;
const long long MB = 1024 * KB;
const long long GB = 1024 * MB;

void printSize(long long size) {
    if (size >= GB) {
        printf("%.2fGB", (double)size / GB);
    } else if (size >= MB) {
        printf("%.2fMB", (double)size / MB);
    } else if (size >= KB) {
        printf("%.2fKB", (double)size / KB);
    } else {
        printf("%lldB", size);
    }
}

void addFile(File **head, File *file) {
    if (*head == NULL) {
        *head = file;
    } else {
        File *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = file;
    }
}

void listFiles(File *directory, File **head) {
    DIR *dir = opendir(directory->name);
    if (dir != NULL) {
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char *path = malloc(strlen(directory->name) + strlen(entry->d_name) + 2);
                strcpy(path, directory->name);
                strcat(path, "/");
                strcat(path, entry->d_name);
                struct stat st;
                if (stat(path, &st) == 0) {
                    File *file = malloc(sizeof(File));
                    file->name = malloc(strlen(entry->d_name) + 1);
                    strcpy(file->name, entry->d_name);
                    file->isDirectory = S_ISDIR(st.st_mode);
                    file->size = st.st_size;
                    file->next = NULL;
                    addFile(head, file);
                    if (file->isDirectory) {
                        listFiles(file, head);
                    }
                }
                free(path);
            }
        }
        closedir(dir);
    }
}

void printFile(File *file, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("- %s", file->name);
    if (file->isDirectory) {
        printf("/");
    }
    printf(" ");
    printSize(file->size);
    printf("\n");
}

void printDirectory(File *directory, int depth) {
    printf("\n");
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s/\n", directory->name);
    File *current = directory->next;
    while (current != NULL) {
        if (current->isDirectory) {
            printDirectory(current, depth + 1);
        } else {
            printFile(current, depth + 1);
        }
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        exit(1);
    }
    File *directory = malloc(sizeof(File));
    directory->name = malloc(strlen(argv[1]) + 1);
    strcpy(directory->name, argv[1]);
    directory->isDirectory = true;
    directory->size = 0;
    directory->next = NULL;
    File *head = NULL;
    listFiles(directory, &head);
    printDirectory(directory, 0);
    return 0;
}