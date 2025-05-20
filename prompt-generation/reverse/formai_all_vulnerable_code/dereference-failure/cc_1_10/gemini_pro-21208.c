//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1024 * 1024

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    time_t timestamp;
    size_t size;
    char data[MAX_FILE_SIZE];
} file_t;

file_t files[MAX_FILES];
int num_files = 0;

void add_file(const char *name, const char *data, size_t size) {
    if (num_files >= MAX_FILES) {
        fprintf(stderr, "Error: Too many files. Maximum number of files is %d.\n", MAX_FILES);
        return;
    }

    if (strlen(name) >= MAX_FILE_NAME_LENGTH) {
        fprintf(stderr, "Error: File name is too long. Maximum file name length is %d characters.\n", MAX_FILE_NAME_LENGTH);
        return;
    }

    if (size > MAX_FILE_SIZE) {
        fprintf(stderr, "Error: File size is too large. Maximum file size is %d bytes.\n", MAX_FILE_SIZE);
        return;
    }

    strcpy(files[num_files].name, name);
    files[num_files].timestamp = time(NULL);
    files[num_files].size = size;
    memcpy(files[num_files].data, data, size);

    num_files++;
}

void remove_file(const char *name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_files) {
        fprintf(stderr, "Error: File not found.\n");
        return;
    }

    for (; i < num_files - 1; i++) {
        files[i] = files[i + 1];
    }

    num_files--;
}

void list_files() {
    int i;

    for (i = 0; i < num_files; i++) {
        printf("%s (%d bytes, %s)\n", files[i].name, files[i].size, ctime(&files[i].timestamp));
    }
}

void backup_files(const char *filename) {
    FILE *fp;
    int i;

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s for writing.\n", filename);
        return;
    }

    fwrite(&num_files, sizeof(int), 1, fp);
    for (i = 0; i < num_files; i++) {
        fwrite(files[i].name, sizeof(char), MAX_FILE_NAME_LENGTH, fp);
        fwrite(&files[i].timestamp, sizeof(time_t), 1, fp);
        fwrite(&files[i].size, sizeof(size_t), 1, fp);
        fwrite(files[i].data, sizeof(char), files[i].size, fp);
    }

    fclose(fp);
}

void restore_files(const char *filename) {
    FILE *fp;
    int i;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s for reading.\n", filename);
        return;
    }

    fread(&num_files, sizeof(int), 1, fp);
    for (i = 0; i < num_files; i++) {
        fread(files[i].name, sizeof(char), MAX_FILE_NAME_LENGTH, fp);
        fread(&files[i].timestamp, sizeof(time_t), 1, fp);
        fread(&files[i].size, sizeof(size_t), 1, fp);
        fread(files[i].data, sizeof(char), files[i].size, fp);
    }

    fclose(fp);
}

int main() {
    char *command;
    char *filename;
    char *data;
    size_t size;

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %s %d", filename, data, &size);
            add_file(filename, data, size);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%s", filename);
            remove_file(filename);
        } else if (strcmp(command, "list") == 0) {
            list_files();
        } else if (strcmp(command, "backup") == 0) {
            scanf("%s", filename);
            backup_files(filename);
        } else if (strcmp(command, "restore") == 0) {
            scanf("%s", filename);
            restore_files(filename);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}