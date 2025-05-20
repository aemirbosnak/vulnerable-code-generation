//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Defining the DNA base letters
#define DNA_BASES "ATGC"

//Function to generate random DNA sequence with predefined length
char* generate_sequence(int length){
    char* sequence = malloc(sizeof(char) * (length+1));  //Allocating memory for sequence array
    int i;
    for(i=0; i<length; i++){
        sequence[i] = DNA_BASES[rand()%4]; //Generating base letters randomly
    }
    sequence[length]='\0';  //Adding null character to mark end of the sequence
    return sequence;
}

//Function to generate configuration parameters
void generate_config(int* read_length, int* coverage, int* num_reads, int* error_rate){
    printf("Enter read length (>=10 and <=100): ");
    scanf("%d", read_length);  //Taking user input for read length
    printf("Enter coverage (>=1 and <=50): ");
    scanf("%d", coverage);  //Taking user input for coverage
    printf("Enter number of reads (>=50 and <=100000): ");
    scanf("%d", num_reads);  //Taking user input for number of reads
    printf("Enter error rate (>=0 and <=5): ");
    scanf("%d", error_rate);  //Taking user input for error rate
}

//Main function to simulate genome sequencing
int main(){
    srand(time(0));  //Initializing random number generator with time
    printf("Welcome to Genome Sequencing Simulator!\n");

    int read_length, coverage, num_reads, error_rate;
    generate_config(&read_length, &coverage, &num_reads, &error_rate); //Generating configuration parameters

    printf("Generating reference genome sequence...\n");
    char* reference_genome = generate_sequence(num_reads*read_length*coverage); //Generating reference genome sequence
    printf("Reference genome generated successfully!\n");

    printf("Generating reads from reference genome...\n");
    char** reads = malloc(sizeof(char*) * num_reads);  //Allocating memory for multi-dimensional array to store reads
    int i,j;
    for(i=0; i<num_reads; i++){
        reads[i] = malloc(sizeof(char) * (read_length+1));
        int start_index = rand() % (strlen(reference_genome)-read_length);  //Selecting random index to start read from reference genome
        strncpy(reads[i], reference_genome + start_index, read_length);  //Extracting read from reference genome
        reads[i][read_length] = '\0';  //Adding null character to mark end of the read

        //Adding errors to the read using error rate
        for(j=0; j<read_length; j++){
            if((rand()%100) < error_rate*10){
                reads[i][j] = DNA_BASES[rand()%4];  //Generating random base letter to replace the original base letter
            }
        }
    }
    printf("Reads generated successfully!\n");

    //Printing the generated reference genome and reads for verification
    printf("Reference Genome: %s\n", reference_genome);
    printf("Reads:\n");
    for(i=0; i<num_reads; i++){
        printf("%s\n", reads[i]);
    }

    //Freeing the memory allocated for arrays
    free(reference_genome);
    for(i=0; i<num_reads; i++){
        free(reads[i]);
    }
    free(reads);

    return 0;
}