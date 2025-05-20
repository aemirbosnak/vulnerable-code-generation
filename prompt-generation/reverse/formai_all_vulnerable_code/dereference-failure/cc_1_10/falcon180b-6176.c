//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_FILE_SIZE 100000

typedef struct {
    char file_name[MAX_FILE_NAME];
    char file_path[MAX_FILE_NAME];
    int file_size;
} file_t;

void backup_file(file_t *file) {
    FILE *input_file, *output_file;
    char buffer[MAX_FILE_SIZE];
    int bytes_read;

    input_file = fopen(file->file_path, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open file '%s' for reading.\n", file->file_path);
        exit(1);
    }

    output_file = fopen(file->file_name, "wb");
    if (output_file == NULL) {
        printf("Error: Could not open file '%s' for writing.\n", file->file_name);
        exit(1);
    }

    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, input_file)) > 0) {
        if (fwrite(buffer, 1, bytes_read, output_file)!= bytes_read) {
            printf("Error: Could not write to file '%s'.\n", file->file_name);
            exit(1);
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("File '%s' backed up successfully to '%s'.\n", file->file_path, file->file_name);
}

int main() {
    int num_files;
    char input_line[MAX_FILE_NAME];
    file_t *files = (file_t *)malloc(sizeof(file_t));

    printf("Welcome to the cheerful file backup system!\n");
    printf("How many files would you like to backup?\n");
    scanf("%d", &num_files);

    printf("Enter the file paths for each file:\n");
    for (int i = 0; i < num_files; i++) {
        scanf("%s", input_line);
        strcpy(files[i].file_path, input_line);
        strcpy(files[i].file_name, input_line);
        files[i].file_size = 0;
    }

    printf("Files to be backed up:\n");
    for (int i = 0; i < num_files; i++) {
        printf("File %d: %s\n", i+1, files[i].file_name);
    }

    printf("Enter the backup directory:\n");
    scanf("%s", input_line);
    strcpy(files[0].file_name, input_line);
    strcat(files[0].file_name, "\\");

    for (int i = 0; i < num_files; i++) {
        backup_file(&files[i]);
    }

    free(files);

    printf("All files backed up successfully!\n");

    return 0;
}