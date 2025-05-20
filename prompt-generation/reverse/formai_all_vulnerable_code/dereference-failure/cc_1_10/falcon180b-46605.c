//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26
#define NUM_SEQUENCES 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence[length] = '\0';
}

void print_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

void compare_sequences(Sequence *seq1, Sequence *seq2) {
    int match_count = 0;
    for (int i = 0; i < seq1->length && i < seq2->length; i++) {
        if (seq1->sequence[i] == seq2->sequence[i]) {
            match_count++;
        } else {
            break;
        }
    }
    printf("Match count: %d\n", match_count);
}

int main() {
    srand(time(NULL));

    Sequence *sequences = malloc(sizeof(Sequence) * NUM_SEQUENCES);

    for (int i = 0; i < NUM_SEQUENCES; i++) {
        sequences[i].sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
        generate_random_sequence(sequences[i].sequence, rand() % MAX_SEQUENCE_LENGTH + 1);
        sequences[i].length = strlen(sequences[i].sequence);
    }

    int num_matches = 0;

    for (int i = 0; i < NUM_SEQUENCES; i++) {
        for (int j = i + 1; j < NUM_SEQUENCES; j++) {
            compare_sequences(&sequences[i], &sequences[j]);
            num_matches += sequences[i].length == sequences[j].length? 1 : 0;
        }
    }

    printf("Total matches: %d\n", num_matches);

    for (int i = 0; i < NUM_SEQUENCES; i++) {
        free(sequences[i].sequence);
    }
    free(sequences);

    return 0;
}