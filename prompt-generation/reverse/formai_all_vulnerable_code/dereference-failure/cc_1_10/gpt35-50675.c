//FormAI DATASET v1.0 Category: Data recovery tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

void checkArgs(int argc, char *argv[]);
void checkFile(FILE *file);
void writeFile(FILE *file, char *filename);

int main(int argc, char *argv[]) {
    checkArgs(argc, argv);
    
    char *filename = argv[1];
    
    // Open the file and check that it exists
    FILE *file = fopen(filename, "r");
    checkFile(file);
    
    // Seek to the end of the file to get its length
    fseek(file, 0L, SEEK_END);
    long int fileSize = ftell(file);
    rewind(file);
    
    // Calculate the number of blocks in the file
    int numBlocks = fileSize / BLOCK_SIZE;
    if (fileSize % BLOCK_SIZE != 0) {
        numBlocks++;
    }
    
    // Allocate memory to hold the blocks
    char **blocks = (char **)malloc(numBlocks * sizeof(char *));
    for (int i = 0; i < numBlocks; i++) {
        blocks[i] = (char *)malloc(BLOCK_SIZE * sizeof(char));
    }
    
    // Read in the blocks from the file
    int i = 0;
    int bytesRead;
    while ((bytesRead = fread(blocks[i], 1, BLOCK_SIZE, file)) > 0) {
        i++;
    }
    
    // Prompt the user for the filename to save the recovered file as
    printf("Enter the filename to write the recovered file as: ");
    char recoveredFilename[256];
    scanf("%s", recoveredFilename);
    
    // Open the new file to write to
    FILE *recoveredFile = fopen(recoveredFilename, "w");
    
    // Write the blocks to the new file
    for (int i = 0; i < numBlocks; i++) {
        if (fwrite(blocks[i], 1, BLOCK_SIZE, recoveredFile) != BLOCK_SIZE) {
            printf("Error writing block %d to file", i);
            exit(1);
        }
    }
    
    printf("File successfully recovered!\n");
    
    // Free the memory used by the block pointers
    for (int i = 0; i < numBlocks; i++) {
        free(blocks[i]);
    }
    free(blocks);
    
    // Close the files
    fclose(file);
    fclose(recoveredFile);
    
    return 0;
}

void checkArgs(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
}

void checkFile(FILE *file) {
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
}