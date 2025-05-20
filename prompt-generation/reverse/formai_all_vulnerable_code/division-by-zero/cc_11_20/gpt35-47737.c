//FormAI DATASET v1.0 Category: File system simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#define MAX_BLOCKS 1000

int main(){
    int block_size, file_size, no_of_blocks_required;
    int i, j, k;
    int allocated_blocks_count = 0;
    int file_allocation_table[MAX_BLOCKS] = {0};

    printf("Enter the Block Size: ");
    scanf("%d", &block_size);

    printf("Enter the File Size: ");
    scanf("%d", &file_size);

    no_of_blocks_required = (file_size / block_size) + (file_size % block_size ? 1 : 0);

    // check if there are enough blocks available
    if(no_of_blocks_required > MAX_BLOCKS){
        printf("Error: Not enough blocks available in the file system.\n");
        return 1;
    }

    // Allocate memory to the blocks
    char** blocks = (char**)malloc(MAX_BLOCKS * sizeof(char*));
    for(i=0; i < MAX_BLOCKS; i++){
        blocks[i] = (char*)malloc(block_size);
    }

    // initialise contents of the blocks
    for(i=0; i < MAX_BLOCKS; i++){
        for(j=0; j < block_size; j++){
            blocks[i][j] = '0';
        }
    }

    // Locate empty blocks and allocate them to the file
    for(i=0; i < MAX_BLOCKS; i++){
        allocated_blocks_count = 0;
        for(j=i; j < MAX_BLOCKS; j++){
            if(allocated_blocks_count == no_of_blocks_required){
                printf("Allocation successful!\n");
                printf("File Allocation Table:\n");
                for(k=0; k < MAX_BLOCKS; k++){
                    if(file_allocation_table[k]){
                        printf("%d\n", k);
                    }
                }

                return 0;
            }

            if(allocated_blocks_count < no_of_blocks_required && file_allocation_table[j] == 0){
                allocated_blocks_count++;
                file_allocation_table[j] = 1;
                for(k=0; k < block_size; k++){
                    blocks[j][k] = '1';
                }
            }

            if(allocated_blocks_count > no_of_blocks_required){
                printf("Error: Not enough blocks available in the file system.\n");
                return 1;
            }
        }
    }

    printf("Error: Not enough blocks available in the file system.\n");
    return 1;
}