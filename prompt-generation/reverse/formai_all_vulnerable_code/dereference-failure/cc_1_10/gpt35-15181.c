//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Ada Lovelace
// This program recovers deleted files from a disk image file
// in the style of Ada Lovelace

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char signature[8];
    unsigned int filesize;
} __attribute__((packed)) Header;

int main(int argc, char** argv) {

    // Check if the user provided a file name
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }

    // Open the disk image file
    FILE* f = fopen(argv[1], "rb");
    if (f == NULL) {
        printf("Could not open file: %s\n", argv[1]);
        return -1;
    }

    // Read the header data
    Header header;
    fread(&header, sizeof(Header), 1, f);

    // Check if the file has the right signature
    if (strncmp(header.signature, "DISKIMG", 8) != 0) {
        printf("Invalid file signature\n");
        return -1;
    }

    // Get the file size
    unsigned int filesize = header.filesize;

    // Allocate memory for the file data
    unsigned char* data = (unsigned char *) malloc(filesize);
    if (data == NULL) {
        printf("Could not allocate memory\n");
        return -1;
    }

    // Read the file data
    fread(data, sizeof(unsigned char), filesize, f);

    // Close the file
    fclose(f);

    // Print the recovered file data
    for (unsigned int i = 0; i < filesize; i++) {
        printf("%c", data[i]);
    }

    // Free the memory
    free(data);

    return 0;
}