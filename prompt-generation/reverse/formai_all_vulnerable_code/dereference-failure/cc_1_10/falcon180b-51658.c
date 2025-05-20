//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000 // maximum file size in bytes

// function to read a file and return its contents as a string
char *read_file(char *filename) {
    FILE *file;
    long file_size;
    char *file_contents = NULL;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: file is too large\n");
        exit(1);
    }

    rewind(file);
    file_contents = malloc(file_size + 1);
    fread(file_contents, file_size, 1, file);
    file_contents[file_size] = '\0';

    fclose(file);
    return file_contents;
}

// function to write a string to a file
void write_file(char *filename, char *contents) {
    FILE *file;

    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fwrite(contents, strlen(contents), 1, file);
    fclose(file);
}

// function to create a backup of a file
void backup_file(char *filename) {
    char *backup_filename;
    char *contents;

    // create backup filename
    backup_filename = malloc(strlen(filename) + 5);
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");

    // read contents of file
    contents = read_file(filename);

    // write contents to backup file
    write_file(backup_filename, contents);

    // free memory
    free(contents);
    free(backup_filename);
}

int main() {
    char filename[100];

    // prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // backup file
    backup_file(filename);

    printf("Backup complete\n");
    return 0;
}