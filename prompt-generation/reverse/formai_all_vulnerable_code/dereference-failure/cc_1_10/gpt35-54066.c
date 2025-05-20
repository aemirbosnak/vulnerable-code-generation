//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000
#define MUTATION_RATE 0.01

//function to randomly generate a genome with 4 different bases (A, C, G, T)
char* generate_genome(){
    char* genome = (char*)malloc((GENOME_LENGTH+1)*sizeof(char));
    int i;
    for(i=0; i<GENOME_LENGTH; i++){
        int base = rand()%4;
        switch(base){
            case 0: genome[i] = 'A'; break;
            case 1: genome[i] = 'C'; break;
            case 2: genome[i] = 'G'; break;
            case 3: genome[i] = 'T'; break;
        }
    }
    genome[GENOME_LENGTH] = '\0';
    return genome;
}

//function to simulate base mutations in a genome
void mutate_genome(char* genome){
    int i;
    for(i=0; i<GENOME_LENGTH; i++){
        double mutation_probability = (double)rand()/RAND_MAX;
        if(mutation_probability <= MUTATION_RATE){
            int base = rand()%4;
            switch(base){
                case 0: genome[i] = 'A'; break;
                case 1: genome[i] = 'C'; break;
                case 2: genome[i] = 'G'; break;
                case 3: genome[i] = 'T'; break;
            }
        }
    }
}

//function to print a genome
void print_genome(char* genome){
    int i;
    for(i=0; i<GENOME_LENGTH; i++){
        printf("%c", genome[i]);
    }
    printf("\n");
}

int main(){
    //seed the random number generator
    srand(time(NULL));
    
    //generate a reference genome
    printf("Generating reference genome...\n");
    char* reference_genome = generate_genome();
    print_genome(reference_genome);
    
    //simulate mutations
    int num_mutations = 100;
    printf("Simulating mutations...\n");
    int i;
    for(i=0; i<num_mutations; i++){
        int mutation_position = rand()%GENOME_LENGTH;
        char original_base = reference_genome[mutation_position];
        char* new_genome = (char*)malloc((GENOME_LENGTH+1)*sizeof(char));
        int j;
        for(j=0; j<mutation_position; j++){
            new_genome[j] = reference_genome[j];
        }
        int base = rand()%4;
        switch(base){
            case 0: new_genome[mutation_position] = 'A'; break;
            case 1: new_genome[mutation_position] = 'C'; break;
            case 2: new_genome[mutation_position] = 'G'; break;
            case 3: new_genome[mutation_position] = 'T'; break;
        }
        for(j=mutation_position+1; j<GENOME_LENGTH; j++){
            new_genome[j] = reference_genome[j];
        }
        new_genome[GENOME_LENGTH] = '\0';
        
        //mutate the genome
        mutate_genome(new_genome);
        
        printf("Original Base: %c, New Base: %c\n", original_base, new_genome[mutation_position]);
        
        free(reference_genome);
        reference_genome = new_genome;
    }
    
    printf("Final genome:\n");
    print_genome(reference_genome);
    
    free(reference_genome);
    
    return 0;
}