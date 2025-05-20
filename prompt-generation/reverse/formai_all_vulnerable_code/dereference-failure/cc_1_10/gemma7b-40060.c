//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR 10
#define MAX_FILE 20

typedef struct FileSystem
{
    char **dirs;
    char **files;
    int dir_size;
    int file_size;
} FileSystem;

void initialize_fs(FileSystem *fs)
{
    fs->dirs = malloc(MAX_DIR * sizeof(char *));
    fs->files = malloc(MAX_FILE * sizeof(char *));
    fs->dir_size = 0;
    fs->file_size = 0;
}

void add_dir(FileSystem *fs, char *dir_name)
{
    fs->dirs[fs->dir_size++] = dir_name;
}

void add_file(FileSystem *fs, char *file_name)
{
    fs->files[fs->file_size++] = file_name;
}

int main()
{
    FileSystem fs;
    initialize_fs(&fs);

    add_dir(&fs, "home");
    add_dir(&fs, "documents");
    add_dir(&fs, "pictures");

    add_file(&fs, "documents/my_document.txt");
    add_file(&fs, "pictures/my_picture.jpg");

    printf("Directories:");
    for (int i = 0; i < fs.dir_size; i++)
    {
        printf(" %s", fs.dirs[i]);
    }

    printf("\nFiles:");
    for (int i = 0; i < fs.file_size; i++)
    {
        printf(" %s", fs.files[i]);
    }

    return 0;
}