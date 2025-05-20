//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILE_SIZE 100000

typedef struct {
    char *filename;
    FILE *file;
    int size;
    char *buffer;
} FileData;

FileData *open_file(char *filename) {
    FileData *data = malloc(sizeof(FileData));
    data->filename = filename;
    data->file = fopen(filename, "rb");
    if (data->file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }
    fseek(data->file, 0, SEEK_END);
    data->size = ftell(data->file);
    rewind(data->file);
    data->buffer = malloc(data->size + 1);
    fread(data->buffer, data->size, 1, data->file);
    data->buffer[data->size] = '\0';
    return data;
}

void close_file(FileData *data) {
    if (data->file!= NULL) {
        fclose(data->file);
    }
    free(data->buffer);
    free(data);
}

void print_file_contents(FileData *data) {
    printf("Contents of file '%s':\n", data->filename);
    printf("%s", data->buffer);
}

int main() {
    char filename[MAX_LINE_SIZE];
    printf("Enter the name of the file you want to recover:\n");
    scanf("%s", filename);
    FileData *data = open_file(filename);
    printf("Do you want to view the contents of the file? (y/n)\n");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        print_file_contents(data);
    }
    printf("Do you want to save the recovered file? (y/n)\n");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        char output_filename[MAX_LINE_SIZE];
        printf("Enter the name of the output file:\n");
        scanf("%s", output_filename);
        FILE *output_file = fopen(output_filename, "wb");
        if (output_file == NULL) {
            printf("Error: Could not open output file '%s'\n", output_filename);
            exit(1);
        }
        fwrite(data->buffer, data->size, 1, output_file);
        fclose(output_file);
        printf("File successfully saved as '%s'\n", output_filename);
    }
    close_file(data);
    return 0;
}