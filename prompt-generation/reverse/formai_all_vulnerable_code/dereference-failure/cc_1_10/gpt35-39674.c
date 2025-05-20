//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000

char *generate_random_sequence(int length);
void mutate_sequence(char *sequence);
void print_sequence(char *sequence);

int main()
{
    srand(time(NULL));

    int sequence_length = rand() % MAX_SEQUENCE_LENGTH + 1;
    char *sequence = generate_random_sequence(sequence_length);

    printf("Original Sequence:\n");
    print_sequence(sequence);
    printf("\n");

    printf("Mutated Sequence:\n");
    mutate_sequence(sequence);
    print_sequence(sequence);
    printf("\n");

    free(sequence);

    return 0;
}

char *generate_random_sequence(int length) 
{
    char *sequence = (char *) malloc(sizeof(char) * (length + 1));

    for (int i = 0; i < length; i++) {
        switch (rand() % 4) {
            case 0:
                sequence[i] = 'A';
                break;
            case 1:
                sequence[i] = 'C';
                break;
            case 2:
                sequence[i] = 'G';
                break;
            case 3:
                sequence[i] = 'T';
                break;
        }
    }
    sequence[length] = '\0';

    return sequence;
}

void mutate_sequence(char *sequence) 
{
    int mutation_count = rand() % (strlen(sequence) / 2) + 1;

    for (int i = 0; i < mutation_count; i++) {
        int index = rand() % strlen(sequence);
        char base = sequence[index];
        while (sequence[index] == base) {
            switch (rand() % 3) {
                case 0:
                    sequence[index] = 'A';
                    break;
                case 1:
                    sequence[index] = 'C';
                    break;
                case 2:
                    sequence[index] = 'G';
                    break;
                case 3:
                    sequence[index] = 'T';
                    break;
            }
        }
    }
}

void print_sequence(char *sequence) 
{
    for (int i = 0; i < strlen(sequence); i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
}