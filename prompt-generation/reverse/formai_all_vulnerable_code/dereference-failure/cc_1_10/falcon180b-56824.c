//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char file_name[MAX_FILE_NAME];
    int file_size;
    int deleted;
} file_t;

file_t *files;
int num_files;

void init_files() {
    files = (file_t *) malloc(MAX_FILE_SIZE * sizeof(file_t));
    num_files = 0;
}

void add_file(char *file_name, int file_size) {
    if (num_files >= MAX_FILE_SIZE) {
        printf("Error: Maximum file limit reached.\n");
        return;
    }
    strcpy(files[num_files].file_name, file_name);
    files[num_files].file_size = file_size;
    files[num_files].deleted = 0;
    num_files++;
    printf("File added: %s\n", file_name);
}

void delete_file(char *file_name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].file_name, file_name) == 0) {
            files[i].deleted = 1;
            printf("File deleted: %s\n", file_name);
            return;
        }
    }
    printf("Error: File not found.\n");
}

void recover_files() {
    int i;
    for (i = 0; i < num_files; i++) {
        if (files[i].deleted == 1) {
            printf("Recovering file: %s\n", files[i].file_name);
            files[i].deleted = 0;
        }
    }
}

void print_files() {
    int i;
    for (i = 0; i < num_files; i++) {
        if (files[i].deleted == 0) {
            printf("%s (%d bytes)\n", files[i].file_name, files[i].file_size);
        }
    }
}

int main() {
    init_files();
    add_file("test1.txt", 10);
    add_file("test2.txt", 20);
    delete_file("test1.txt");
    recover_files();
    print_files();
    return 0;
}