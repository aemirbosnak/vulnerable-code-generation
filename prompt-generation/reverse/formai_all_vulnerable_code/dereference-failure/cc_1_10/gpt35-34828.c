//FormAI DATASET v1.0 Category: Data recovery tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512 // Block size for reading data from file

int main()
{
    char filename[100];
    printf("Enter the name of the file to recover: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    // Check if file is already corrupted
    fseek(fp, 0, SEEK_END);
    long int filesize = ftell(fp);
    if (filesize % BLOCK_SIZE != 0) {
        printf("The file is corrupted and cannot be recovered\n");
        fclose(fp);
        return 1;
    }
    rewind(fp);

    int num_blocks = filesize / BLOCK_SIZE;
    char** blocks = (char**)malloc(num_blocks * sizeof(char*));
    for (int i = 0; i < num_blocks; i++) {
        blocks[i] = (char*)malloc(BLOCK_SIZE * sizeof(char));
        fread(blocks[i], BLOCK_SIZE, 1, fp);
    }

    fclose(fp);

    // Recover the file
    char recovered_filename[100] = "recovered_";
    strcat(recovered_filename, filename);
    FILE* recovered_fp = fopen(recovered_filename, "wb");
    for (int i = 0; i < num_blocks; i++) {
        fwrite(blocks[i], BLOCK_SIZE, 1, recovered_fp);
    }

    fclose(recovered_fp);

    // Free memory
    for (int i = 0; i < num_blocks; i++) {
        free(blocks[i]);
    }
    free(blocks);

    printf("File successfully recovered as %s\n", recovered_filename);

    return 0;
}