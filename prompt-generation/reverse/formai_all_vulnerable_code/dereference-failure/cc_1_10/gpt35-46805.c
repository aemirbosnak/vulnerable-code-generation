//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100

char *generateSequence(int length) {
    char *sequence = (char*)malloc(sizeof(char) * length);
    int i;
    for(i = 0; i < length; i++) {
        int randNum = rand() % 4;
        if(randNum == 0) sequence[i] = 'A';
        else if(randNum == 1) sequence[i] = 'T';
        else if(randNum == 2) sequence[i] = 'C';
        else sequence[i] = 'G';
    }
    return sequence;
}

void printSequence(char *sequence, int length) {
    int i;
    for(i = 0; i < length; i++) printf("%c", sequence[i]);
    printf("\n");
}

void insertMutation(char *sequence, int length, int mutationSite) {
    int randNum = rand() % 3;
    if(randNum == 0) {
        if(sequence[mutationSite] == 'A') sequence[mutationSite] = 'T';
        else sequence[mutationSite] = 'A';
    }
    else if(randNum == 1) {
        if(sequence[mutationSite] == 'C') sequence[mutationSite] = 'G';
        else sequence[mutationSite] = 'C';
    }
    else {
        int randNum2 = rand() % 2;
        if(randNum2 == 0) sequence[mutationSite] = 'A';
        else sequence[mutationSite] = 'C';
        
    }
}

int main() {
    srand(time(NULL));
    
    int length = rand() % MAX_LENGTH + 1;
    char *sequence = generateSequence(length);
    
    printf("Initial genome sequence:\n");
    printSequence(sequence, length);
    
    int numMutations = rand() % length + 1;
    int i;
    for(i = 0; i < numMutations; i++) {
        int mutationSite = rand() % length;
        insertMutation(sequence, length, mutationSite);
    }
    
    printf("Mutated genome sequence:\n");
    printSequence(sequence, length);
    
    free(sequence);
    return 0;
}