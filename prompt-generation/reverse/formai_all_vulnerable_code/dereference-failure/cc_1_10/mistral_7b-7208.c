//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char c;
    int count;
} t_rle_char;

void rle_encode(unsigned char *input, size_t size, t_rle_char **output) {
    size_t i = 0;
    t_rle_char *rle_data = malloc(size * sizeof(t_rle_char));

    while (i < size) {
        int j = i + 1;

        if (input[i] == input[j] && j < size) {
            rle_data[i].count++;
            i++;
        } else {
            rle_data[i].c = input[i];
            if (i != 0) {
                rle_data[i].count = i - (i - 1);
            }
            i++;
        }
    }

    *output = rle_data;
}

void rle_decode(t_rle_char *input, size_t size, unsigned char *output) {
    size_t i = 0;

    while (i < size) {
        if (input[i].count > 0) {
            int j = 0;
            while (input[i].count-- > 0) {
                output[i + j++] = input[i].c;
            }
            i += input[i].count;
        } else {
            output[i++] = input[i].c;
        }
    }
}

int main() {
    unsigned char input[] = {'A', 'A', 'B', 'B', 'C', 'C', 'C', 'C'};
    size_t size = sizeof(input) / sizeof(input[0]);

    t_rle_char *rle_data;
    unsigned char output[size];

    rle_encode(input, size, &rle_data);
    rle_decode(rle_data, size, output);

    for (size_t i = 0; i < size; i++) {
        printf("output[%zu] = %c\n", i, output[i]);
    }

    free(rle_data);

    return 0;
}