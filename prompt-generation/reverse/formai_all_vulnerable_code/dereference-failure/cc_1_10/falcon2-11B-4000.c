//Falcon2-11B DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file_info {
    char* filename;
    int file_size;
    char* buffer;
};

struct file_info* new_file(char* filename, int file_size) {
    struct file_info* file = (struct file_info*)malloc(sizeof(struct file_info));
    file->filename = strdup(filename);
    file->file_size = file_size;
    file->buffer = (char*)malloc(file_size);
    return file;
}

void read_file(struct file_info* file) {
    FILE* fp = fopen(file->filename, "r");
    fseek(fp, 0, SEEK_END);
    file->file_size = ftell(fp);
    rewind(fp);

    file->buffer = (char*)malloc(file->file_size);
    fread(file->buffer, 1, file->file_size, fp);
    fclose(fp);
}

void write_file(struct file_info* file) {
    FILE* fp = fopen(file->filename, "w");
    fwrite(file->buffer, 1, file->file_size, fp);
    fclose(fp);
}

void open_file(struct file_info* file) {
    read_file(file);
}

void save_file(struct file_info* file) {
    write_file(file);
}

void close_file(struct file_info* file) {
    free(file->buffer);
    free(file->filename);
    free(file);
}

void edit_file(struct file_info* file) {
    char* edit_string = "This is a simple text editor.";

    printf("File: %s\n", file->filename);
    printf("File size: %d bytes\n", file->file_size);
    printf("Contents:\n");
    for (int i = 0; i < file->file_size; i++) {
        printf("%c", file->buffer[i]);
    }
    printf("\n");

    printf("Enter edit string: ");
    fgets(file->buffer, file->file_size, stdin);

    file->buffer[file->file_size - 1] = '\0'; // remove trailing newline

    printf("File contents after editing:\n");
    for (int i = 0; i < file->file_size; i++) {
        printf("%c", file->buffer[i]);
    }
    printf("\n");

    save_file(file);
}

int main() {
    struct file_info* file = new_file("test.txt", 100);
    open_file(file);
    edit_file(file);
    close_file(file);
    return 0;
}