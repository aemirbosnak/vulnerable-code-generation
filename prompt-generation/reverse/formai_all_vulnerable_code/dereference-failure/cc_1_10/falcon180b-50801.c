//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000

typedef struct {
    char *file_name;
    char *file_content;
} File;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage:./data_recovery_tool <file_name>\n");
        exit(1);
    }

    char *file_name = argv[1];
    char *file_content = NULL;
    int file_content_length = 0;

    FILE *input_file = fopen(file_name, "rb");
    if (input_file == NULL) {
        printf("Error: Could not open file '%s'\n", file_name);
        exit(1);
    }

    fseek(input_file, 0, SEEK_END);
    file_content_length = ftell(input_file);
    rewind(input_file);

    file_content = malloc(file_content_length + 1);
    if (file_content == NULL) {
        printf("Error: Could not allocate memory\n");
        exit(1);
    }

    fread(file_content, file_content_length, 1, input_file);
    fclose(input_file);

    File *file_data = malloc(sizeof(File));
    if (file_data == NULL) {
        printf("Error: Could not allocate memory\n");
        exit(1);
    }

    file_data->file_name = strdup(file_name);
    file_data->file_content = file_content;

    printf("File name: %s\n", file_data->file_name);
    printf("File content:\n%s\n", file_data->file_content);

    free(file_data->file_name);
    free(file_data->file_content);
    free(file_data);

    return 0;
}