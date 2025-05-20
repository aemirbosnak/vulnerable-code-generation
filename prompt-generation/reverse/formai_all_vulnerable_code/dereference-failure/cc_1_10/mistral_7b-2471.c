//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BASES 4
#define MIN_SEQUENCE_LENGTH 10
#define MAX_SEQUENCE_LENGTH 100

char bases[BASES][3] = {"A", "C", "G", "T"};

void random_sequence(char *sequence, int length) {
    int random_number;
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        random_number = rand() % BASES;
        sequence[i] = bases[random_number][0];
    }
    sequence[length] = '\0';
}

void base_encode(char *encoded_sequence, char *sequence, int length) {
    int number;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < BASES; j++) {
            if (sequence[i] == bases[j][0]) {
                number = j + 1;
                break;
            }
        }
        encoded_sequence[i] = number % 3 + '0';
    }
    encoded_sequence[length] = '\0';
}

int main() {
    int sequence_length, encoded_sequence_length;
    char sequence[MAX_SEQUENCE_LENGTH + 1], encoded_sequence[MAX_SEQUENCE_LENGTH + 1];

    printf("Enter the length of the DNA sequence (min. %d, max. %d): ", MIN_SEQUENCE_LENGTH, MAX_SEQUENCE_LENGTH);
    scanf("%d", &sequence_length);

    random_sequence(sequence, sequence_length);

    printf("\nGenerated random DNA sequence: %s\n", sequence);

    base_encode(encoded_sequence, sequence, sequence_length);

    printf("\nEncoded ASCII sequence: %s\n", encoded_sequence);

    return 0;
}