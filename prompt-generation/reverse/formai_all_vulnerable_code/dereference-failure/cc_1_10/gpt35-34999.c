//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_SIZE 256
#define MAX_FILE_SIZE 1000000

typedef struct {
    char* path;
    unsigned long size;
} file_t;

typedef struct {
    file_t* files;
    int file_count;
    unsigned long total_size;
} directory_t;

void analyze_directory(char* path, directory_t* dir);
void print_directory(directory_t* dir);
void cleanup_directory(directory_t* dir);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    directory_t dir = {NULL, 0, 0};
    analyze_directory(argv[1], &dir);
    print_directory(&dir);
    cleanup_directory(&dir);
    return 0;
}

void analyze_directory(char* path, directory_t* dir) {
    char sub_path[MAX_PATH_SIZE];
    sprintf(sub_path, "%s/*", path);

    unsigned long total_size = 0;

    FILE* pipe = popen(sub_path, "r");
    if (pipe == NULL) {
        printf("Error: failed to run command\n");
        exit(1);
    }

    while (fgets(sub_path, MAX_PATH_SIZE, pipe) != NULL) {
        sub_path[strcspn(sub_path, "\n")] = 0;

        FILE* file = fopen(sub_path, "rb");
        if (file == NULL) {
            printf("Error: could not open file %s\n", sub_path);
            continue;
        }

        fseek(file, 0, SEEK_END);
        unsigned long size = ftell(file);
        if (size > MAX_FILE_SIZE) {
            printf("Warning: file %s exceeds maximum allowable size\n", sub_path);
            fclose(file);
            continue;
        }

        fseek(file, 0, SEEK_SET);
        char* buffer = (char*)malloc(size);
        if (buffer == NULL) {
            printf("Error: could not allocate buffer for file %s\n", sub_path);
            fclose(file);
            continue;
        }

        if (fread(buffer, size, 1, file) != 1) {
            printf("Error: could not read file %s\n", sub_path);
            fclose(file);
            free(buffer);
            continue;
        }

        fclose(file);

        file_t file_data = {strdup(sub_path), size};
        if (file_data.path == NULL) {
            printf("Error: could not duplicate string %s\n", sub_path);
            free(buffer);
            continue;
        }

        dir->total_size += size;

        file_t* new_files = (file_t*)realloc(dir->files, (dir->file_count + 1) * sizeof(file_t));
        if (new_files == NULL) {
            printf("Error: could not reallocate memory\n");
            free(file_data.path);
            free(buffer);
            continue;
        }

        dir->files = new_files;
        dir->files[dir->file_count++] = file_data;

        free(buffer);
    }

    pclose(pipe);
}

void print_directory(directory_t* dir) {
    printf("Total size of directory: %lu kbytes\n", dir->total_size / 1000);

    for (int i = 0; i < dir->file_count; i++) {
        printf("%-40s %20lu bytes\n", dir->files[i].path, dir->files[i].size);
    }
}

void cleanup_directory(directory_t* dir) {
    for (int i = 0; i < dir->file_count; i++) {
        free(dir->files[i].path);
    }

    free(dir->files);
}