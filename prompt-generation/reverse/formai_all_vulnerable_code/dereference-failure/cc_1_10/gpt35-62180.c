//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DNA_LENGTH 100
#define MUTATION_RATE 0.05

char randomLetter(){
    return "ACGT"[rand()%4];
}

char* generateDNA(){
    char* dna = malloc(sizeof(char) * (DNA_LENGTH+1));
    for(int i=0; i<DNA_LENGTH; i++)
        dna[i] = randomLetter();
    dna[DNA_LENGTH] = '\0';
    return dna;
}

void mutate(char* dna, double mutationRate){
    for(int i=0; i<DNA_LENGTH; i++){
        if((double)rand()/RAND_MAX < mutationRate){
            dna[i] = randomLetter();
        }
    }
}

//Compare two DNA sequences and return the number of mismatches found.
int compare(char* dna1, char* dna2){
    int errors = 0;
    for(int i=0; i<DNA_LENGTH && dna1[i] != '\0' && dna2[i] != '\0'; i++){
        if(dna1[i] != dna2[i])
            errors++;
    }
    return errors;
}

int main(){
    srand(time(NULL));
    
    //Generate two random DNA sequences
    char* dna1 = generateDNA();
    char* dna2 = generateDNA();
    
    //Simulate mutations
    mutate(dna1, MUTATION_RATE);
    mutate(dna2, MUTATION_RATE);
    
    //Print out the original and mutated DNA sequences
    printf("DNA sequence 1: %s\nMutated sequence 1: %s\n\n", dna1, generateDNA());
    printf("DNA sequence 2: %s\nMutated sequence 2: %s\n\n", dna2, generateDNA());
    
    //Compare the two sequences and print out the number of mismatches
    int errors = compare(dna1, dna2);
    printf("The two DNA sequences have %d mismatches.\n", errors);
    
    free(dna1);
    free(dna2);
    
    return 0;
}