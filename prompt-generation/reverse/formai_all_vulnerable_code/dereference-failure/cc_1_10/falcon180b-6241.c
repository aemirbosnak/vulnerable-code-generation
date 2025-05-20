//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB

typedef struct {
    char magic[4];
    int version;
    int file_size;
    char file_type[4];
    char file_name[256];
} FileHeader;

typedef struct {
    FileHeader header;
    char data[MAX_FILE_SIZE];
} File;

int read_file(FILE* file, File* file_data) {
    FileHeader header;
    fseek(file, 0, SEEK_SET);
    fread(&header, sizeof(header), 1, file);

    if (strncmp(header.magic, "FILE", 4)!= 0 || header.version!= 1) {
        printf("Invalid file format.\n");
        return 1;
    }

    if (header.file_size > MAX_FILE_SIZE) {
        printf("File is too large.\n");
        return 1;
    }

    file_data->header = header;
    fseek(file, header.file_size, SEEK_SET);
    fread(file_data->data, 1, header.file_size, file);

    return 0;
}

int write_file(FILE* file, File* file_data) {
    FileHeader header = file_data->header;
    fseek(file, 0, SEEK_SET);

    if (fwrite(&header, sizeof(header), 1, file)!= 1) {
        printf("Failed to write file header.\n");
        return 1;
    }

    if (fwrite(file_data->data, 1, header.file_size, file)!= header.file_size) {
        printf("Failed to write file data.\n");
        return 1;
    }

    return 0;
}

int main() {
    FILE* input_file = fopen("input.dat", "rb");
    FILE* output_file = fopen("output.dat", "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    File file_data;
    if (read_file(input_file, &file_data)!= 0) {
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    if (write_file(output_file, &file_data)!= 0) {
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    fclose(input_file);
    fclose(output_file);

    printf("File recovery successful!\n");

    return 0;
}