//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Define nucleotides 
#define A 0
#define C 1
#define G 2
#define T 3

// Define function to shuffle an array
void shuffle(int *arr, int n){
    for(int i=0;i<n;i++){
        int j = i + rand()%(n-i);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main(){
    srand(time(NULL)); // Seed for random number generation

    int n; // Length of DNA sequence
    printf("Enter the length of DNA sequence: ");
    scanf("%d",&n);

    int *dna_sequence = (int*)malloc(sizeof(int)*n); // Allocate memory for DNA sequence

    // Initialize DNA sequence with random nucleotides
    for(int i=0;i<n;i++){
        dna_sequence[i] = rand()%4;
    }

    printf("Original DNA Sequence: ");
    for(int i=0;i<n;i++){
        printf("%c",dna_sequence[i]==A?'A':(dna_sequence[i]==C?'C':(dna_sequence[i]==G?'G':'T'))); // Print the nucleotides
    }
    printf("\n");

    // Create a coverage array to track how many times each nucleotide was sequenced
    int coverage[4] = {0,0,0,0};

    // Sequencing
    for(int i=0;i<n;i++){
        double r = (double)rand()/RAND_MAX; // Generate a random number between 0 and 1
        
        if(r<=0.9){ // Base is correctly sequenced with probability 0.9
            coverage[dna_sequence[i]]++; // Increase coverage for that nucleotide
        }
        else{ // Base is incorrectly sequenced with probability 0.1
            int wrong_bases[3] = {A,C,G,T}; // Array of the other three nucleotides
            wrong_bases[dna_sequence[i]] = -1; // Set the correct nucleotide to -1
            
            shuffle(wrong_bases,3); // Shuffle the array of wrong nucleotides
            
            // Choose a random wrong nucleotide to sequence instead
            for(int j=0;j<3;j++){
                if(wrong_bases[j]!=-1){
                    dna_sequence[i] = wrong_bases[j];
                    coverage[dna_sequence[i]]++; // Increase coverage for that nucleotide
                    break;
                }
            }
        }
    }

    printf("Sequenced DNA Sequence: ");
    for(int i=0;i<n;i++){
        printf("%c",dna_sequence[i]==A?'A':(dna_sequence[i]==C?'C':(dna_sequence[i]==G?'G':'T'))); // Print the nucleotides
    }
    printf("\n");

    // Print coverage for each nucleotide
    printf("Coverage:\n");
    printf("A: %d\n",coverage[A]);
    printf("C: %d\n",coverage[C]);
    printf("G: %d\n",coverage[G]);
    printf("T: %d\n",coverage[T]);

    free(dna_sequence); // Free memory allocated for DNA sequence

    return 0;
}