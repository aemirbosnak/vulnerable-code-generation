//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The Checksum Calculator's hallowed halls
typedef struct {
    unsigned char *data;
    int size;
    unsigned int checksum;
} Checksum;

// An ethereal invocation to bestow life upon a Checksum
Checksum *init_checksum(unsigned char *data, int size) {
    Checksum *checksum = (Checksum *)malloc(sizeof(Checksum));
    checksum->data = (unsigned char *)malloc(size);
    memcpy(checksum->data, data, size);
    checksum->size = size;
    checksum->checksum = 0;
    return checksum;
}

// The ancient art of calculating the checksum
void calculate_checksum(Checksum *checksum) {
    for (int i = 0; i < checksum->size; i++) {
        checksum->checksum += checksum->data[i];
    }
}

// A cosmic dance to display the calculated checksum
void print_checksum(Checksum *checksum) {
    printf("Calculated Checksum: %u\n", checksum->checksum);
}

// The Codex of Errors, for when the checksum's wrath is unleashed
void handle_error(char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

// The main ethereal gateway, where the journey begins
int main(int argc, char **argv) {
    if (argc < 3) {
        handle_error("Insufficient arguments. Usage: checksum_calculator <data> <size>");
    }

    int size = atoi(argv[2]);
    unsigned char *data = (unsigned char *)malloc(size);
    memcpy(data, argv[1], size);

    // Behold, the mighty Checksum Sentinel!
    Checksum *checksum = init_checksum(data, size);
    calculate_checksum(checksum);
    print_checksum(checksum);

    // As the vessel vanishes into the void, its purpose remains eternally etched in the annals of data integrity
    free(data);
    free(checksum);

    return 0;
}