//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size in bytes

struct FileHeader {
    char magic[4];
    int fileSize;
};

struct FileHeader readHeader(FILE *file) {
    struct FileHeader header;
    fseek(file, 0, SEEK_SET);
    fread(&header, sizeof(struct FileHeader), 1, file);
    return header;
}

void writeHeader(FILE *file, struct FileHeader header) {
    fseek(file, 0, SEEK_SET);
    fwrite(&header, sizeof(struct FileHeader), 1, file);
}

int main() {
    char filename[100];
    printf("Enter the name of the file to recover: ");
    scanf("%s", filename);

    FILE *inputFile = fopen(filename, "rb");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    struct FileHeader header = readHeader(inputFile);
    if (header.magic[0]!= 'H' || header.magic[1]!= 'E' || header.magic[2]!= 'A' || header.magic[3]!= 'D') {
        printf("Error: Invalid file format.\n");
        return 2;
    }

    if (header.fileSize > MAX_FILE_SIZE) {
        printf("Error: File size too large.\n");
        return 3;
    }

    char *data = malloc(header.fileSize + 1); // Allocate memory for file data and null terminator
    fread(data, header.fileSize, 1, inputFile);
    data[header.fileSize] = '\0'; // Add null terminator

    printf("Recovered file data:\n%s\n", data);

    writeHeader(inputFile, header); // Write the header back to the input file
    rewind(inputFile); // Rewind the input file to the beginning

    fwrite(data, header.fileSize, 1, inputFile); // Write the recovered data to the input file
    fclose(inputFile);

    printf("File recovery complete!\n");
    return 0;
}