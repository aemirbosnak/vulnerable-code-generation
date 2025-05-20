//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 100
#define MAX_ALPHABET_SIZE 26

// Function to generate a random DNA sequence of given length
void generate_sequence(char *sequence, int length) {
    int i;
    for (i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence[length] = '\0';
}

// Function to print a DNA sequence with medieval-style formatting
void print_sequence(char *sequence) {
    int i;
    for (i = 0; i < strlen(sequence); i++) {
        printf("%c", sequence[i]);
        if ((i + 1) % 50 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Function to simulate genome sequencing with errors
void simulate_sequencing(char *sequence, int error_rate) {
    int i;
    for (i = 0; i < strlen(sequence); i++) {
        if (rand() % 100 < error_rate) {
            sequence[i] = 'N';
        }
    }
}

int main() {
    srand(time(NULL));

    int sequence_length = MAX_SEQUENCE_LENGTH;
    int error_rate = 0;

    printf("Enter the desired sequence length (1-%d): ", MAX_SEQUENCE_LENGTH);
    scanf("%d", &sequence_length);

    printf("Enter the desired error rate (0-100): ");
    scanf("%d", &error_rate);

    char sequence[MAX_SEQUENCE_LENGTH + 1];
    generate_sequence(sequence, sequence_length);

    printf("Original DNA Sequence:\n");
    print_sequence(sequence);

    simulate_sequencing(sequence, error_rate);

    printf("Sequenced DNA Sequence (with %d%% error rate):\n", error_rate);
    print_sequence(sequence);

    return 0;
}