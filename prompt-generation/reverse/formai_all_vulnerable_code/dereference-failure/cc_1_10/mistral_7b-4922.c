//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100
#define NUM_SEQUENCES 10

void generate_binary(unsigned char *sequence, int length);
void print_binary(unsigned char *sequence, int length);

int main() {
    int i, length, total_time = 0;
    unsigned char *binary_sequence;
    clock_t start, end;

    srand(time(NULL));

    binary_sequence = malloc(MAX_LENGTH * sizeof(unsigned char));

    for (i = 0; i < NUM_SEQUENCES; i++) {
        length = rand() % MAX_LENGTH + 1;
        generate_binary(binary_sequence, length);

        printf("\nBinary Sequence of length %d:\n", length);
        print_binary(binary_sequence, length);

        start = clock();
        scanf("%s", (char *)binary_sequence, length);
        end = clock();

        total_time += (end - start);
    }

    printf("\nTotal time taken: %f seconds\n", (float)total_time / CLOCKS_PER_SEC);

    free(binary_sequence);

    return 0;
}

void generate_binary(unsigned char *sequence, int length) {
    int i;

    for (i = 0; i < length; i++)
        sequence[i] = (rand() % 2) ? '0' : '1';
}

void print_binary(unsigned char *sequence, int length) {
    int i;

    for (i = 0; i < length; i++)
        printf("%c", sequence[i]);
}