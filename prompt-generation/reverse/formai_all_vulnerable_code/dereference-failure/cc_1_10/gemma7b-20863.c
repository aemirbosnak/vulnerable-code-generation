//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024 * 1024

typedef struct FileEntry {
    char *filename;
    int size;
    time_t timestamp;
} FileEntry;

void write_file_entry(FILE *fp, FileEntry *file_entry) {
    fprintf(fp, "%s\n", file_entry->filename);
    fprintf(fp, "%d\n", file_entry->size);
    fprintf(fp, "%ld\n", file_entry->timestamp);
}

FileEntry *read_file_entry(FILE *fp) {
    FileEntry *file_entry = malloc(sizeof(FileEntry));
    file_entry->filename = malloc(MAX_FILE_SIZE);
    file_entry->size = 0;
    file_entry->timestamp = 0;

    fscanf(fp, "%s\n", file_entry->filename);
    fscanf(fp, "%d\n", &file_entry->size);
    fscanf(fp, "%ld\n", &file_entry->timestamp);

    return file_entry;
}

int main() {
    FILE *fp = fopen("backup.txt", "w");

    FileEntry *file_entry = malloc(sizeof(FileEntry));
    file_entry->filename = malloc(MAX_FILE_SIZE);
    file_entry->size = 1024;
    file_entry->timestamp = time(NULL);

    write_file_entry(fp, file_entry);

    fclose(fp);

    fp = fopen("backup.txt", "r");

    file_entry = read_file_entry(fp);

    printf("Filename: %s\n", file_entry->filename);
    printf("Size: %d\n", file_entry->size);
    printf("Timestamp: %ld\n", file_entry->timestamp);

    free(file_entry->filename);
    free(file_entry);

    return 0;
}