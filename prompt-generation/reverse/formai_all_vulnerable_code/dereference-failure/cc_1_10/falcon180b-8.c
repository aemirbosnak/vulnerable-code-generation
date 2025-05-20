//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 10000000
#define BUFFER_SIZE 1024

struct file_header {
    char magic_number[4];
    int file_size;
    int num_records;
    int record_size;
};

struct record {
    int id;
    char name[20];
    char address[50];
    int phone_number;
};

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    struct file_header header;
    struct record *records;

    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", argv[1]);
        exit(1);
    }

    fread(&header, sizeof(struct file_header), 1, input_file);

    if (strcmp(header.magic_number, "DATA")!= 0) {
        printf("Invalid file format.\n");
        exit(1);
    }

    records = (struct record *) malloc(header.num_records * sizeof(struct record));
    if (records == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    fseek(input_file, sizeof(struct file_header), SEEK_SET);
    for (int i = 0; i < header.num_records; i++) {
        fread(&records[i], header.record_size, 1, input_file);
    }

    output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", argv[2]);
        exit(1);
    }

    fwrite(&header, sizeof(struct file_header), 1, output_file);
    for (int i = 0; i < header.num_records; i++) {
        fwrite(&records[i], header.record_size, 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Data recovery successful.\n");

    return 0;
}