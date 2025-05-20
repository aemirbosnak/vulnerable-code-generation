//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SYSTEM_SIZE 1000
#define MAX_FILE_NAME_SIZE 50

typedef struct {
    char name[MAX_FILE_NAME_SIZE];
    int size;
} File;

typedef struct {
    File* files[MAX_FILE_SYSTEM_SIZE];
    int num_files;
} FileSystem;

int create_file(FileSystem* fs, char* name, int size) {
    if (fs->num_files >= MAX_FILE_SYSTEM_SIZE) {
        printf("Error: Maximum number of files reached.\n");
        return -1;
    }

    File* file = malloc(sizeof(File));
    strcpy(file->name, name);
    file->size = size;

    fs->files[fs->num_files] = file;
    fs->num_files++;

    printf("File \"%s\" created.\n", name);
    return 0;
}

int delete_file(FileSystem* fs, char* name) {
    int i;

    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            free(fs->files[i]);

            fs->files[i] = fs->files[fs->num_files - 1];
            fs->num_files--;

            printf("File \"%s\" deleted.\n", name);
            return 0;
        }
    }

    printf("Error: File not found.\n");
    return -1;
}

int rename_file(FileSystem* fs, char* old_name, char* new_name) {
    int i;

    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i]->name, old_name) == 0) {
            strcpy(fs->files[i]->name, new_name);

            printf("File \"%s\" renamed to \"%s\".\n", old_name, new_name);
            return 0;
        }
    }

    printf("Error: File not found.\n");
    return -1;
}

int main() {
    FileSystem fs;
    fs.num_files = 0;

    create_file(&fs, "test.txt", 10);
    create_file(&fs, "sample.txt", 20);

    rename_file(&fs, "test.txt", "new_test.txt");

    delete_file(&fs, "new_test.txt");

    return 0;
}