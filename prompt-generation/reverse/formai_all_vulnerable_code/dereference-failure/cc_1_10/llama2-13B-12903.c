//LLAMA2-13B DATASET v1.0 Category: File system simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define BLOCK_SIZE 512
#define MAX_FILES 1024
#define MAX_FILE_SIZE 102400

struct file {
    char *name;
    int size;
    int blocks;
    char *data;
};

struct file_system {
    struct file *files;
    int num_files;
};

void create_file(struct file_system *fs, char *name, int size) {
    int i;
    struct file *file;

    if ((file = malloc(sizeof(struct file))) == NULL) {
        perror("malloc");
        exit(1);
    }

    file->name = name;
    file->size = size;
    file->blocks = size / BLOCK_SIZE;
    file->data = malloc(BLOCK_SIZE * file->blocks);

    if (file->data == NULL) {
        perror("malloc");
        free(file);
        exit(1);
    }

    for (i = 0; i < file->blocks; i++) {
        file->data[i] = i % 2 == 0 ? 0x01 : 0x55;
    }

    fs->files = realloc(fs->files, (fs->num_files + 1) * sizeof(struct file));
    fs->files[fs->num_files++] = *file;
}

void delete_file(struct file_system *fs, char *name) {
    int i;

    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            free(fs->files[i].data);
            memset(fs->files[i].data, 0, BLOCK_SIZE * fs->files[i].blocks);
            break;
        }
    }

    if (i == fs->num_files) {
        printf("File not found\n");
    }
}

void read_file(struct file_system *fs, char *name, char *data, int size) {
    int i;

    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            int j;
            for (j = 0; j < size; j++) {
                data[j] = fs->files[i].data[j];
            }
            break;
        }
    }

    if (i == fs->num_files) {
        printf("File not found\n");
    }
}

void write_file(struct file_system *fs, char *name, char *data, int size) {
    int i;

    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            int j;
            for (j = 0; j < size; j++) {
                fs->files[i].data[j] = data[j];
            }
            break;
        }
    }

    if (i == fs->num_files) {
        printf("File not found\n");
    }
}

int main() {
    struct file_system fs;
    char name[32];

    fs.files = malloc(sizeof(struct file));
    fs.num_files = 0;

    printf("Create file\n");
    create_file(&fs, "test.txt", 1024);
    create_file(&fs, "test2.txt", 2048);

    printf("Delete file\n");
    delete_file(&fs, "test2.txt");

    printf("Read file\n");
    char data[1024];
    read_file(&fs, "test.txt", data, 1024);

    printf("Write file\n");
    char new_data[1024];
    write_file(&fs, "test.txt", new_data, 2048);

    return 0;
}