//FormAI DATASET v1.0 Category: Data recovery tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int valid; // 0 for invalid, 1 for valid
    char data[30];
} DataBlock;

void readBlocks(DataBlock* blocks, int num_blocks, FILE* fp){
    for(int i=0; i<num_blocks; i++){
        if(fread(&(blocks[i]), sizeof(DataBlock), 1, fp) != 1){
            printf("Error reading block %d\n", i);
            exit(1);
        }
    }
}

void writeBlocks(DataBlock* blocks, int num_blocks, FILE* fp){
    for(int i=0; i<num_blocks; i++){
        if(fwrite(&(blocks[i]), sizeof(DataBlock), 1, fp) != 1){
            printf("Error writing block %d\n", i);
            exit(1);
        }
    }
}

void recoverData(DataBlock* blocks, int num_blocks){
    int num_valid_blocks = 0;
    for(int i=0; i<num_blocks; i++){
        if(blocks[i].valid == 1){
            num_valid_blocks++;
        }
    }
    if(num_valid_blocks == 0){
        printf("No valid data blocks in file\n");
        return;
    }
    char* recovered_data = malloc(num_valid_blocks*30*sizeof(char));
    int index = 0;
    for(int i=0; i<num_blocks; i++){
        if(blocks[i].valid == 1){
            strcpy(&(recovered_data[index*30]), blocks[i].data);
            index++;
        }
    }
    printf("Recovered data: %s\n", recovered_data);
    free(recovered_data);
}

int main(int argc, char* argv[]){
    // input arguments: file name and number of blocks
    if(argc < 3 || atoi(argv[2]) < 1){
        printf("Usage: %s filename num_blocks\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    int num_blocks = atoi(argv[2]);

    // open file
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("Unable to open file %s\n", filename);
        return 1;
    }

    // allocate memory for blocks
    DataBlock* blocks = malloc(num_blocks*sizeof(DataBlock));
    if(blocks == NULL){
        printf("Memory allocation error\n");
        return 1;
    }

    // read blocks from file
    readBlocks(blocks, num_blocks, fp);

    // close file
    fclose(fp);

    // recover data from valid blocks
    recoverData(blocks, num_blocks);

    // free memory
    free(blocks);

    return 0;
}