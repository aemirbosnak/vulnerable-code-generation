//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    int file_position;
    FILE *file;
} FILE_DATA;

void init_file_data(FILE_DATA *file_data, char *file_name) {
    strcpy(file_data->file_name, file_name);
    file_data->file_size = 0;
    file_data->file_position = 0;
    file_data->file = NULL;
}

int read_file_header(FILE_DATA *file_data) {
    char file_header[4];
    int bytes_read = 0;

    if (file_data->file_position >= file_data->file_size) {
        return 0;
    }

    bytes_read = fread(file_header, 1, 4, file_data->file);
    if (bytes_read!= 4) {
        return 0;
    }

    if (strcmp(file_header, "ROM") == 0) {
        file_data->file_position += 4;
        return 1;
    }

    return 0;
}

int recover_file(FILE_DATA *file_data) {
    char file_header[4];
    int bytes_read = 0;

    if (file_data->file_position >= file_data->file_size) {
        return 0;
    }

    bytes_read = fread(file_header, 1, 4, file_data->file);
    if (bytes_read!= 4) {
        return 0;
    }

    if (strcmp(file_header, "ROM") == 0) {
        file_data->file_position += 4;
        return 1;
    }

    return 0;
}

int main(int argc, char **argv) {
    FILE_DATA file_data;
    int file_count = 0;

    if (argc!= 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    init_file_data(&file_data, argv[1]);

    if (file_data.file_position == 0) {
        printf("No files found in directory.\n");
        return 1;
    }

    while (recover_file(&file_data)) {
        printf("Recovered file %d: %s\n", ++file_count, file_data.file_name);
    }

    return 0;
}