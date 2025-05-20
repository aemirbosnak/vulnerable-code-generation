//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CHUNK_SIZE 10
#define NUM_CHUNKS 30

struct Chunk{
    // Information about the genome chunk
    int chunkNum;
    int chunkSize;
    char* sequence;
};

struct Chunk generateChunk(int num){
    // Function to generate a new genome chunk
    struct Chunk chunk;
    chunk.chunkNum = num+1;
    chunk.chunkSize = CHUNK_SIZE;
    chunk.sequence = (char*)malloc(CHUNK_SIZE*sizeof(char));
    for(int i=0;i<CHUNK_SIZE;i++){
        int base = rand() % 4;
        // Assign a base to the sequence based on the random number generated
        switch(base){
            case 0:chunk.sequence[i] = 'A';
                break;
            case 1:chunk.sequence[i] = 'C';
                break;
            case 2:chunk.sequence[i] = 'G';
                break;
            case 3:chunk.sequence[i] = 'T';
                break;
        }
    }
    return chunk;
}

int main(){
    srand(time(NULL));
    struct Chunk genome[NUM_CHUNKS];
    // Generate all genome chunks
    for(int i=0;i<NUM_CHUNKS;i++){
        genome[i] = generateChunk(i);
    }
    // Display the generated genome sequence
    printf("Genome: ");
    for(int i=0;i<NUM_CHUNKS;i++){
        printf("%s", genome[i].sequence);
    }
    printf("\n");
    return 0;
}