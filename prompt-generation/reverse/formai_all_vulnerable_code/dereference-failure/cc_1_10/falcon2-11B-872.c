//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int genome_size = 1000000; // Size of the genome
int read_length = 100; // Length of each read
int error_rate = 0.1; // Error rate of the sequencing process

// Function to simulate sequencing process
void simulate_sequencing(char* output_file, int read_num, int error_num) {
    FILE* fptr = fopen(output_file, "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return;
    }

    srand(time(NULL));

    // Generate random reads
    char* reads[read_num];
    for (int i = 0; i < read_num; i++) {
        char read[read_length];
        for (int j = 0; j < read_length; j++) {
            read[j] = (char)('A' + rand() % 4);
        }
        reads[i] = read;
    }

    // Generate errors
    char* errors[error_num];
    for (int i = 0; i < error_num; i++) {
        char error[read_length];
        for (int j = 0; j < read_length; j++) {
            int r = rand() % 100;
            if (r < error_rate * read_length) {
                error[j] = (char)('N'); // Insertion or deletion error
            } else {
                error[j] = (char)('A' + rand() % 4); // Substitution error
            }
        }
        errors[i] = error;
    }

    // Print the reads and errors
    for (int i = 0; i < read_num; i++) {
        fprintf(fptr, "%s\n", reads[i]);
    }
    for (int i = 0; i < error_num; i++) {
        fprintf(fptr, "%s\n", errors[i]);
    }

    fclose(fptr);
}

int main(int argc, char* argv[]) {
    if (argc!= 5) {
        printf("Usage: %s <output_file> <read_num> <error_num> <error_rate>\n", argv[0]);
        return 1;
    }

    char* output_file = argv[1];
    int read_num = atoi(argv[2]);
    int error_num = atoi(argv[3]);
    double error_rate = atof(argv[4]);
    error_rate /= 100.0; // Convert to percentage

    simulate_sequencing(output_file, read_num, error_num);

    return 0;
}