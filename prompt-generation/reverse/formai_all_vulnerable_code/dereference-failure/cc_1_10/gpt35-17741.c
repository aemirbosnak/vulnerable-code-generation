//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomize(char *string, int length) {
    for (int i = 0; i < length; i++) {
        int num = rand() % 4;
        switch (num) {
            case 0:
                string[i] = 'A';
                break;
            case 1:
                string[i] = 'C';
                break;
            case 2:
                string[i] = 'G';
                break;
            case 3:
                string[i] = 'T';
                break;
        }
    }
}

void generate(char *sequence, int length, int num) {
    if (num == 0) {
        printf("%s\n", sequence);
        return;
    }
    char *newString = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        switch(sequence[i]) {
            case 'A':
                newString[i] = 'T';
                break;
            case 'C':
                newString[i] = 'G';
                break;
            case 'G':
                newString[i] = 'C';
                break;
            case 'T':
                newString[i] = 'A';
                break;
        }
    }
    newString[length] = '\0';
    generate(newString, length, num-1);
    free(newString);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int length = 10;
    int mutations = 3;
    char *sequence = malloc(length + 1);
    randomize(sequence, length);
    sequence[length] = '\0';
    printf("Original sequence: %s\n", sequence);
    printf("Mutations: %d\n", mutations);
    printf("Mutated sequences:\n");
    generate(sequence, length, mutations);
    free(sequence);
    return 0;
}