//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 50

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char path[MAX_FILE_NAME_LENGTH];
    int is_dir;
} file_t;

void print_file_info(file_t* file) {
    printf("Name: %s\n", file->name);
    printf("Path: %s\n", file->path);
    printf("Is Directory: %d\n\n", file->is_dir);
}

int compare_files(const void* a, const void* b) {
    file_t* file1 = (file_t*)a;
    file_t* file2 = (file_t*)b;

    int result = strcmp(file1->name, file2->name);
    if (result == 0) {
        result = strcmp(file1->path, file2->path);
    }

    return result;
}

int main() {
    int num_files;
    printf("Enter the number of files to synchronize: ");
    scanf("%d", &num_files);

    if (num_files > MAX_FILES) {
        printf("Error: Maximum number of files exceeded.\n");
        return 1;
    }

    file_t files[num_files];

    int i;
    for (i = 0; i < num_files; i++) {
        printf("Enter file %d information:\n", i+1);
        printf("Name: ");
        scanf("%s", files[i].name);
        printf("Path: ");
        scanf("%s", files[i].path);
        printf("Is Directory? (y/n): ");
        char is_dir_input;
        scanf(" %c", &is_dir_input);
        files[i].is_dir = is_dir_input == 'y'? 1 : 0;
    }

    qsort(files, num_files, sizeof(file_t), compare_files);

    for (i = 0; i < num_files; i++) {
        print_file_info(&files[i]);
    }

    return 0;
}