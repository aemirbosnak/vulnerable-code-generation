//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 1024

typedef struct FileEntry {
    char name[256];
    long size;
    time_t timestamp;
} FileEntry;

FileEntry files[MAX_FILES];

void backup_file(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return;
    }

    long file_size = 0;
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);

    if (file_size > MAX_FILE_SIZE) {
        return;
    }

    FileEntry new_file = {0};
    strcpy(new_file.name, filename);
    new_file.size = file_size;
    new_file.timestamp = time(NULL);

    int i = 0;
    for (i = 0; i < MAX_FILES; i++) {
        if (files[i].name[0] == '\0') {
            files[i] = new_file;
            break;
        }
    }

    fclose(fp);
}

int main() {
    backup_file("my_file.txt");
    backup_file("another_file.doc");

    return 0;
}