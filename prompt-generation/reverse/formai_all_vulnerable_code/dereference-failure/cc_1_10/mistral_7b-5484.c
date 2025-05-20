//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024

typedef struct {
    char name[256];
    int size;
    char data[1];
} FileHeader;

void read_file_header(FILE *fp, FileHeader *header) {
    fread(header, sizeof(FileHeader), 1, fp);
}

int is_valid_file_header(FileHeader header) {
    if (strcmp(header.name, "MY_FILE_MAGIC") != 0)
        return 0;
    if (header.size > BUF_SIZE * 1023)
        return 0;
    return 1;
}

void recover_file(FILE *input, FILE *output) {
    FileHeader header;
    char buffer[BUF_SIZE];

    while (1) {
        read_file_header(input, &header);
        if (!is_valid_file_header(header)) {
            fseek(input, -(sizeof(FileHeader) + header.size), SEEK_CUR);
            continue;
        }

        fwrite(header.data, header.size, 1, output);

        if (feof(input))
            break;
    }
}

int main(int argc, char *argv[]) {
    FILE *input = fopen(argv[1], "rb");
    FILE *output = fopen(argv[2], "wb");

    if (!input || !output) {
        perror("Error opening files");
        return 1;
    }

    recover_file(input, output);
    fclose(input);
    fclose(output);

    return 0;
}