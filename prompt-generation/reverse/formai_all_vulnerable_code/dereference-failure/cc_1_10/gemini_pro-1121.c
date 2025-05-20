//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1000000

struct file_info {
    char name[100];
    char path[100];
    time_t last_modified;
    int size;
    char data[MAX_FILE_SIZE];
};

struct file_info files[MAX_FILES];
int num_files = 0;

void add_file(char *name, char *path, time_t last_modified, int size, char *data) {
    if (num_files >= MAX_FILES) {
        fprintf(stderr, "Error: Too many files\n");
        return;
    }

    strcpy(files[num_files].name, name);
    strcpy(files[num_files].path, path);
    files[num_files].last_modified = last_modified;
    files[num_files].size = size;
    memcpy(files[num_files].data, data, size);

    num_files++;
}

int compare_files(struct file_info *file1, struct file_info *file2) {
    if (strcmp(file1->name, file2->name) != 0) {
        return strcmp(file1->name, file2->name);
    } else if (strcmp(file1->path, file2->path) != 0) {
        return strcmp(file1->path, file2->path);
    } else if (file1->last_modified != file2->last_modified) {
        return file1->last_modified - file2->last_modified;
    } else if (file1->size != file2->size) {
        return file1->size - file2->size;
    } else {
        return memcmp(file1->data, file2->data, file1->size);
    }
}

void sort_files() {
    qsort(files, num_files, sizeof(struct file_info), (int (*)(const void *, const void *))compare_files);
}

void print_files() {
    for (int i = 0; i < num_files; i++) {
        printf("%s\n", files[i].name);
        printf("%s\n", files[i].path);
        printf("%ld\n", files[i].last_modified);
        printf("%d\n", files[i].size);
        printf("%s\n\n", files[i].data);
    }
}

int main() {
    // Add some files to the synchronizer
    add_file("file1.txt", "/home/user/file1.txt", time(NULL), 100, "This is file 1");
    add_file("file2.txt", "/home/user/file2.txt", time(NULL), 200, "This is file 2");
    add_file("file3.txt", "/home/user/file3.txt", time(NULL), 300, "This is file 3");

    // Sort the files
    sort_files();

    // Print the files
    print_files();

    return 0;
}