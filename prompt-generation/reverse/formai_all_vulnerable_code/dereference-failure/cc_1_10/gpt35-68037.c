//FormAI DATASET v1.0 Category: Data recovery tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

struct file_header {
    char filename[100];
    int size;
};

enum error_codes {
    SUCCESS = 0,
    FILE_NOT_FOUND = 1,
    BLOCK_READ_ERROR = 2,
    FILE_WRITE_ERROR = 3
};

int main() {
    char* input_file = "input.bin";
    char* output_directory = "./output";
    
    // Open the input file as binary
    FILE* input = fopen(input_file, "rb");
    
    if (input == NULL) {
        printf("Error: Input file not found\n");
        return FILE_NOT_FOUND;
    }
    
    // Create the output directory if it doesn't exist
    char* mkdir_cmd = malloc(strlen(output_directory) + 7);
    sprintf(mkdir_cmd, "mkdir -p %s", output_directory);
    system(mkdir_cmd);
    
    // Read the number of files stored in the input file
    int num_files = 0;
    fread(&num_files, sizeof(int), 1, input);
    
    for (int i = 0; i < num_files; i++) {
        // Read the file header
        struct file_header header;
        fread(&header, sizeof(struct file_header), 1, input);
        
        // Calculate the number of blocks to read for this file
        int num_blocks = header.size / BLOCK_SIZE;
        if (header.size % BLOCK_SIZE != 0) num_blocks++;
        
        // Open the output file for writing
        char* output_file = malloc(strlen(output_directory) + strlen(header.filename) + 2);
        sprintf(output_file, "%s/%s", output_directory, header.filename);
        FILE* output = fopen(output_file, "wb");
        if (output == NULL) {
            printf("Error: Could not create output file %s\n", output_file);
            return FILE_WRITE_ERROR;
        }
        
        // Read each block of the file and write it to the output file
        for (int j = 0; j < num_blocks; j++) {
            char block[BLOCK_SIZE];
            int bytes_read = fread(block, 1, BLOCK_SIZE, input);
            if (bytes_read != BLOCK_SIZE && j != num_blocks-1) {
                printf("Error: Could not read block %d for file %s\n", j, header.filename);
                fclose(input);
                fclose(output);
                return BLOCK_READ_ERROR;
            }
            fwrite(block, 1, bytes_read, output);
        }
        
        fclose(output);
        printf("Recovered file %s\n", header.filename);
    }
    
    fclose(input);
    printf("Data recovery complete\n");
    
    return SUCCESS;
}