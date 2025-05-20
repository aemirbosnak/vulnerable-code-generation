//FormAI DATASET v1.0 Category: Data recovery tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_FILE_SIZE 1048576 // 1MB max file size

typedef struct data_block {
    int block_num;
    unsigned char block_data[512];
} DataBlock;

void retrieve_data(FILE *image, int start_sector, int num_sectors);
bool validate_file(FILE *file);

int main(int argc, char *argv[]) {
    FILE *image;
    int sector_size = -1;
    char *file_name = NULL;

    // check if command-line args are valid
    if (argc != 2) {
        printf("Usage: ./data_recovery_tool <imagefile>\n");
        exit(EXIT_FAILURE);
    }

    file_name = argv[1];
    
    // validate file
    if (!validate_file(image)) {
        printf("Error: file is not a FAT32 image.\n");
        exit(EXIT_FAILURE);
    }

    // get sector size
    fseek(image, 11, SEEK_SET);
    fread(&sector_size, sizeof(int), 1, image);
    printf("Sector size: %d bytes\n", sector_size);

    // retrieve data blocks starting from sector 20
    retrieve_data(image, 20, 2);

    fclose(image);
    return 0;
}

// retrieve data blocks starting from the specified sector for the specified number of sectors
void retrieve_data(FILE *image, int start_sector, int num_sectors) {
    int i;
    DataBlock *data_blocks = malloc(num_sectors * sizeof(DataBlock));
    fseek(image, start_sector * 512, SEEK_SET);

    // read data blocks
    for (i = 0; i < num_sectors; i++) {
        data_blocks[i].block_num = start_sector + i;
        fread(data_blocks[i].block_data, sizeof(unsigned char), 512, image);
    }

    // print out data blocks
    for (i = 0; i < num_sectors; i++) {
        printf("Block %d:\n", data_blocks[i].block_num);
        printf("%s\n", data_blocks[i].block_data);
    }

    free(data_blocks);
}

// validate file by checking if first three bytes are "FAT"
bool validate_file(FILE *image) {
    char buffer[3] = {'\0'};
    fseek(image, 0, SEEK_SET);

    fread(buffer, sizeof(char), 3, image);
    if (memcmp(buffer, "FAT", 3)) {
        return false;
    }

    return true;
}