//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    char* sequence = (char*) malloc(sizeof(char) * 1000);
    int length = 0;

    if (argc < 2) {
        printf("Usage: %s <sequence>\n", argv[0]);
        return 1;
    }

    strncpy(sequence, argv[1], 1000);
    length = strlen(sequence);

    if (length == 0) {
        printf("Empty sequence.\n");
        return 1;
    }

    printf("Genome Sequencing Simulator\n");
    printf("Length: %d\n", length);
    printf("Sequence: %s\n", sequence);

    char* forward = (char*) malloc(sizeof(char) * 1000);
    char* reverse = (char*) malloc(sizeof(char) * 1000);

    strncpy(forward, sequence, 1000);
    strncpy(reverse, sequence, 1000);

    for (int i = 0; i < length; i++) {
        if (isupper(forward[i])) {
            forward[i] = tolower(forward[i]);
        }
        if (isupper(reverse[i])) {
            reverse[i] = tolower(reverse[i]);
        }
    }

    printf("Forward Sequence: %s\n", forward);
    printf("Reverse Sequence: %s\n", reverse);

    free(sequence);
    free(forward);
    free(reverse);

    return 0;
}