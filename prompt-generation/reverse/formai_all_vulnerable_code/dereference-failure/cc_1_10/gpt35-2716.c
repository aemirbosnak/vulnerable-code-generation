//FormAI DATASET v1.0 Category: File system simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_SIZE 256
#define FILE_CONTENT_SIZE 1024

typedef struct {
    char name[FILE_NAME_SIZE];
    int size;
    char content[FILE_CONTENT_SIZE];
} file_t;

typedef struct {
    char name[FILE_NAME_SIZE];
    int size;
    file_t *files;
    int num_files;
} directory_t;

void init_directory(directory_t *dir, const char *name) {
    strcpy(dir->name, name);
    dir->size = 0;
    dir->files = NULL;
    dir->num_files = 0;
}

void add_file(directory_t *dir, const char *name, const char *content) {
    if (dir->files == NULL) {
        dir->files = (file_t*)malloc(sizeof(file_t));
    } else {
        dir->files = (file_t*)realloc(dir->files, sizeof(file_t) * (dir->num_files + 1));
    }

    file_t *file = &dir->files[dir->num_files];
    strcpy(file->name, name);
    file->size = strlen(content);
    strcpy(file->content, content);

    dir->num_files++;
    dir->size += file->size;
}

void print_directory(directory_t *dir) {
    printf("%s (%d bytes)\n", dir->name, dir->size);

    for (int i = 0; i < dir->num_files; i++) {
        file_t *file = &dir->files[i];
        printf("  - %s (%d bytes)\n", file->name, file->size);
    }
}

int main() {
    directory_t root_dir;
    init_directory(&root_dir, "root");

    add_file(&root_dir, "file1.txt", "Hello World!");
    add_file(&root_dir, "file2.txt", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.");

    directory_t subdir;
    init_directory(&subdir, "subdir");

    add_file(&subdir, "file3.txt", "Etiam vel dapibus risus, quis lacinia orci.");

    directory_t subdir2;
    init_directory(&subdir2, "subdir2");

    add_file(&subdir2, "file4.txt", "Sed egestas auctor sodales.");

    add_file(&subdir, "file5.txt", "Fusce ut metus libero.");

    add_file(&subdir, "file6.txt", "Nullam tempus, lectus eu ultrices.");

    add_file(&subdir2, "file7.txt", "Nam dictum, nibh nec tincidunt bibendum.");

    add_file(&root_dir, "file8.txt", "Pellentesque vitae urna euismod, sagittis lacus vestibulum.");

    add_file(&root_dir, "file9.txt", "Donec at scelerisque mauris.");

    directory_t subdir3;
    init_directory(&subdir3, "subdir3");

    add_file(&subdir3, "file10.txt", "Nam ullamcorper mauris augue, euismod aliquet libero molestie nec.");

    add_file(&subdir2, "file11.txt", "Vivamus luctus augue a lacus vehicula, ut tristique justo lacinia.");

    add_file(&subdir, "file12.txt", "Phasellus accumsan dignissim nisi id convallis.");

    add_file(&subdir, "file13.txt", "Cras accumsan leo purus, eu tempor sapien rhoncus non.");

    directory_t subdir4;
    init_directory(&subdir4, "subdir4");

    add_file(&subdir4, "file14.txt", "In eget enim sit amet mauris vulputate iaculis vel id neque.");

    add_file(&subdir4, "file15.txt", "Pellentesque ultrices mi non nulla accumsan, eu bibendum enim pellentesque.");

    add_file(&subdir4, "file16.txt", "Duis hendrerit pharetra augue, id mattis tellus rhoncus vel.");

    add_file(&subdir4, "file17.txt", "Morbi iaculis, dolor vel viverra dictum, massa nulla ultrices erat, id sagittis ipsum sapien nec tortor.");

    add_file(&subdir3, "file18.txt", "Fusce et magna mauris.");

    add_file(&root_dir, "file19.txt", "Aenean euismod dolor tincidunt diam consectetur, at fringilla enim vulputate.");

    print_directory(&root_dir);

    free(root_dir.files);
    free(subdir.files);
    free(subdir2.files);
    free(subdir3.files);
    free(subdir4.files);

    return 0;
}