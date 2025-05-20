//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1000

void print_menu() {
    printf("Genome Sequencing Simulator Menu:\n");
    printf("1. Input DNA Sequence\n");
    printf("2. Display Sequence\n");
    printf("3. Mutate Sequence\n");
    printf("4. Get Reverse Complement\n");
    printf("5. Transcribe to RNA\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

char get_random_nucleotide() {
    int r = rand() % 4;
    return (r == 0) ? 'A' : (r == 1) ? 'T' : (r == 2) ? 'C' : 'G';
}

void mutate_sequence(char* sequence, int mutations) {
    int length = strlen(sequence);
    for (int i = 0; i < mutations; i++) {
        int pos = rand() % length;
        char new_nucleotide;
        do {
            new_nucleotide = get_random_nucleotide();
        } while (new_nucleotide == sequence[pos]); // Ensure a mutation occurs

        sequence[pos] = new_nucleotide;
    }
}

void reverse_complement(char* sequence, char* rev_comp) {
    int length = strlen(sequence);
    for (int i = 0; i < length; i++) {
        switch (sequence[length - 1 - i]) {
            case 'A': rev_comp[i] = 'T'; break;
            case 'T': rev_comp[i] = 'A'; break;
            case 'C': rev_comp[i] = 'G'; break;
            case 'G': rev_comp[i] = 'C'; break;
            default: rev_comp[i] = 'N'; break; // Unknown nucleotide
        }
    }
    rev_comp[length] = '\0';
}

void transcribe_to_rna(char* sequence, char* rna) {
    int length = strlen(sequence);
    for (int i = 0; i < length; i++) {
        rna[i] = (sequence[i] == 'T') ? 'U' : sequence[i];
    }
    rna[length] = '\0';
}

int main() {
    srand(time(0));
    char dna_sequence[MAX_LENGTH];
    char rev_comp[MAX_LENGTH];
    char rna_sequence[MAX_LENGTH];

    int option;
    int mutations = 0;

    do {
        print_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter a DNA sequence (only A, T, C, G): ");
                scanf("%s", dna_sequence);
                break;
            case 2:
                printf("Current DNA Sequence: %s\n", dna_sequence);
                break;
            case 3:
                printf("Enter number of mutations: ");
                scanf("%d", &mutations);
                mutate_sequence(dna_sequence, mutations);
                printf("Sequence after mutation: %s\n", dna_sequence);
                break;
            case 4:
                reverse_complement(dna_sequence, rev_comp);
                printf("Reverse Complement: %s\n", rev_comp);
                break;
            case 5:
                transcribe_to_rna(dna_sequence, rna_sequence);
                printf("Transcribed RNA: %s\n", rna_sequence);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 6);

    return 0;
}