//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // maximum file size in bytes

typedef struct {
    char filename[100];
    unsigned int filesize;
    unsigned int checksum;
} file_t;

unsigned int calc_checksum(unsigned char* data, int size) {
    unsigned int checksum = 0;
    for (int i = 0; i < size; i++) {
        checksum += data[i];
    }
    return checksum;
}

void read_file(char* filename, unsigned char* data) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    int filesize = ftell(file);
    if (filesize > MAX_FILE_SIZE) {
        printf("Error: file %s is too large\n", filename);
        exit(1);
    }
    rewind(file);
    fread(data, filesize, 1, file);
    fclose(file);
}

void print_file_info(file_t* file) {
    printf("Filename: %s\n", file->filename);
    printf("File size: %d bytes\n", file->filesize);
    printf("Checksum: %08X\n", file->checksum);
}

int main() {
    file_t file;
    printf("Enter filename: ");
    scanf("%s", file.filename);
    unsigned char data[MAX_FILE_SIZE];
    read_file(file.filename, data);
    file.filesize = strlen((char*)data);
    file.checksum = calc_checksum(data, file.filesize);
    print_file_info(&file);
    return 0;
}