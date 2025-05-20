//MISTRAL-7B DATASET v1.0 Category: Cryptographic hash function ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ROUNDS 10
#define WORD_SIZE 4
#define RAVEN_WORD_SIZE 3
#define BITS_PER_BYTE 8
#define WORD_BITS (WORD_SIZE * BITS_PER_BYTE)
#define RAVEN_WORD_BITS (RAVEN_WORD_SIZE * BITS_PER_BYTE)
#define RIGHT_ROTATE(x, n) ((x >> n) | (x << (WORD_BITS - n)))
#define RAVEN_RIGHT_ROTATE(x, n) ((x >> n) | (x << (RAVEN_WORD_BITS - n)))

// Raven, the mystical bird, shall crush the input data
typedef struct {
    unsigned char data[WORD_SIZE][WORD_SIZE];
} Raven;

void raven_process_word(Raven *raven, unsigned char *word) {
    for (int i = 0; i < RAVEN_WORD_SIZE; ++i) {
        unsigned char raven_word[WORD_SIZE];
        for (int j = 0; j < WORD_SIZE; ++j) {
            raven_word[j] = RIGHT_ROTATE(word[j], i);
            raven->data[i / WORD_SIZE][i % WORD_SIZE] ^= raven_word[j];
        }
    }
}

void raven_hash(unsigned char *input, unsigned char *output, size_t length) {
    Raven raven;
    memset(&raven, 0, sizeof(Raven));

    for (size_t i = 0; i < length; i += WORD_BITS) {
        unsigned char word[WORD_SIZE];
        memcpy(word, input + i, WORD_BITS / BITS_PER_BYTE);
        raven_process_word(&raven, word);
    }

    for (int round = 0; round < ROUNDS; ++round) {
        unsigned char temp[WORD_SIZE];
        for (int i = 0; i < WORD_SIZE; ++i) {
            for (int j = 0; j < WORD_SIZE; ++j) {
                int row = i / WORD_SIZE, col = i % WORD_SIZE;
                int index = (round % 2) * WORD_SIZE + j;

                temp[i] = raven.data[row][(col + RIGHT_ROTATE(col, index)) % WORD_SIZE];
            }
        }

        memmove(&raven, &temp, sizeof(Raven));
    }

    for (int i = 0; i < WORD_SIZE; ++i) {
        for (int j = 0; j < WORD_SIZE; ++j) {
            output[i * WORD_SIZE + j] = raven.data[i][j];
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    size_t length = strlen(argv[1]);
    unsigned char *input = malloc(length);
    memcpy(input, argv[1], length);

    unsigned char output[WORD_SIZE][WORD_SIZE];
    raven_hash(input, output, length);

    for (int i = 0; i < WORD_SIZE; ++i) {
        for (int j = 0; j < WORD_SIZE; ++j) {
            printf("%02X%02X", output[i][j], output[i][j + 1]);
        }
        printf(" ");
    }
    printf("\n");

    free(input);
    return 0;
}