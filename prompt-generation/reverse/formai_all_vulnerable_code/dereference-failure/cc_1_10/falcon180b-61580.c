//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef struct {
    int start_block;
    int num_blocks;
    char data[BLOCK_SIZE];
} FileEntry;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    FILE *image_file = fopen(argv[1], "rb");
    if (image_file == NULL) {
        printf("Error: Could not open image file.\n");
        return 1;
    }

    fseek(image_file, 0, SEEK_END);
    int image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    FileEntry *entries = malloc(image_size / BLOCK_SIZE);
    if (entries == NULL) {
        printf("Error: Could not allocate memory for entries.\n");
        fclose(image_file);
        return 1;
    }

    int num_entries = 0;
    while (fread(&entries[num_entries], sizeof(FileEntry), 1, image_file)!= 0) {
        num_entries++;
    }

    fclose(image_file);

    printf("Number of files: %d\n", num_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("File %d:\n", i + 1);
        printf("  Start block: %d\n", entries[i].start_block);
        printf("  Number of blocks: %d\n", entries[i].num_blocks);
        printf("  Data:\n");
        for (int j = 0; j < entries[i].num_blocks; j++) {
            printf("    ");
            for (int k = 0; k < BLOCK_SIZE; k++) {
                printf("%c", entries[i].data[j * BLOCK_SIZE + k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}