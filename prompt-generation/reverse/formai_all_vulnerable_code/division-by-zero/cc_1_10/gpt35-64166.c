//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    
    int genomeLength, numNucleotides;
    printf("Enter length of genome: ");
    scanf("%d",&genomeLength);
    printf("Enter number of nucleotides (A,T,C,G): ");
    scanf("%d",&numNucleotides);
    
    char nucleotides[4]={'A','T','C','G'};
    
    //initialize random seed
    srand(time(NULL));
    
    //generate random genome sequence
    char genome[genomeLength+1];
    for(int i=0; i<genomeLength; i++){
        int n=rand()%numNucleotides;
        genome[i]=nucleotides[n];
    }
    genome[genomeLength]='\0';
    
    //print genome sequence
    printf("Genome sequence: %s\n",genome);
    
    //calculate nucleotide frequency
    int freq[4]={0};
    for(int i=0; i<genomeLength; i++){
        char n=genome[i];
        if(n=='A'){
            freq[0]++;
        }
        else if(n=='T'){
            freq[1]++;
        }
        else if(n=='C'){
            freq[2]++;
        }
        else if(n=='G'){
            freq[3]++;
        }
    }
    
    //print nucleotide frequency
    printf("Nucleotide frequency:\n");
    printf("A: %d\n",freq[0]);
    printf("T: %d\n",freq[1]);
    printf("C: %d\n",freq[2]);
    printf("G: %d\n",freq[3]);
    
    return 0;
}