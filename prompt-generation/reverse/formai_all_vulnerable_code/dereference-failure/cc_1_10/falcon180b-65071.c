//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 1000
#define MAX_FILE_SIZE 1000000
#define VIRUS_SIGNATURE "myvirus"

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char *file_content;
    size_t file_size;
} File;

void load_file(const char *file_path, File *file) {
    FILE *fp = fopen(file_path, "rb");

    if (fp == NULL) {
        printf("Error: Could not open file %s\n", file_path);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file->file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    file->file_content = malloc(file->file_size + 1);
    if (file->file_content == NULL) {
        printf("Error: Could not allocate memory for file content\n");
        exit(1);
    }

    fread(file->file_content, file->file_size, 1, fp);
    fclose(fp);

    strncpy(file->file_name, file_path, MAX_FILE_NAME_LENGTH - 1);
    file->file_name[MAX_FILE_NAME_LENGTH - 1] = '\0';
}

int is_infected(const File *file) {
    char *content_ptr = file->file_content;
    size_t content_size = file->file_size;

    while (content_size > strlen(VIRUS_SIGNATURE)) {
        if (memcmp(content_ptr, VIRUS_SIGNATURE, strlen(VIRUS_SIGNATURE)) == 0) {
            return 1;
        }
        content_ptr++;
        content_size--;
    }

    return 0;
}

void print_file_info(const File *file) {
    if (is_infected(file)) {
        printf("Infected file: %s\n", file->file_name);
    } else {
        printf("Clean file: %s\n", file->file_name);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    File file;
    load_file(argv[1], &file);

    print_file_info(&file);

    free(file.file_content);
    return 0;
}