//FormAI DATASET v1.0 Category: Data recovery tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

// This program reads from a binary file (hard drive image) and extracts deleted files
// that are marked as deleted in the file system but can still be recovered.

// Header for a file, used to locate the file's data in the hard drive image
typedef struct {
    unsigned char signature[8];
    unsigned int size;
    unsigned char reserved[9];
    unsigned char type;
    unsigned char data[12];
} __attribute__((packed)) FileHeader;

// Returns the total number of blocks used by the given file (including the header block)
int get_num_blocks(FileHeader* header) {
    int size = header->size;
    int num_blocks = size / BLOCK_SIZE;
    if (size % BLOCK_SIZE != 0) {
        num_blocks++;
    }
    return num_blocks;
}

// Recovers a file identified by the given file header from the hard drive image
void recover_file(FILE* image, FileHeader* header) {
    char filename[13];
    memcpy(filename, header->data, 12);
    filename[12] = '\0';

    printf("File '%s' found! Recovering...\n", filename);

    int num_blocks = get_num_blocks(header);
    FILE* output = fopen(filename, "wb");
    if (output == NULL) {
        printf("Error opening output file!\n");
        return;
    }

    // Write all blocks to output file
    for (int i = 0; i < num_blocks; i++) {
        unsigned char block[BLOCK_SIZE];
        fseek(image, (header->data[12] << 5) * 512 + i * BLOCK_SIZE, SEEK_SET);
        fread(block, BLOCK_SIZE, 1, image);
        fwrite(block, BLOCK_SIZE, 1, output);
    }

    fclose(output);
    printf("File recovered to '%s'\n", filename);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s [image]\n", argv[0]);
        return 1;
    }

    FILE* image = fopen(argv[1], "rb");
    if (image == NULL) {
        printf("Error opening image file!\n");
        return 1;
    }

    // Search for all deleted files in the image
    int num_files = 0;
    FileHeader* headers = NULL;
    int image_size = -1;

    while (1) {
        FileHeader header;
        fread(&header, sizeof(FileHeader), 1, image);

        // If header is empty, end of file
        if (header.signature[0] == '\0') {
            break;
        }

        // If file is deleted, add it to the list
        if (header.signature[0] == 0xE5) {
            if (headers == NULL) {
                headers = malloc(sizeof(FileHeader));
            } else {
                headers = realloc(headers, (num_files + 1) * sizeof(FileHeader));
            }

            memcpy(&headers[num_files], &header, sizeof(FileHeader));
            num_files++;
        }

        // Save the size of the hard drive image
        if (image_size == -1) {
            fseek(image, 0, SEEK_END);
            image_size = ftell(image);
        }
    }

    // Recover all deleted files
    for (int i = 0; i < num_files; i++) {
        recover_file(image, &headers[i]);
    }

    free(headers);
    fclose(image);

    if (num_files == 0) {
        printf("No deleted files found!\n");
    } else {
        printf("All deleted files recovered!\n");
    }

    return 0;
}