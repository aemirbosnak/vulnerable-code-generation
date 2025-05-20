//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define LEN 16
#define MAX_TRIES 100

char *genpw(void) {
    char *pw = malloc(LEN + 1);
    int i, j, k;

    srand(time(NULL));

    for (i = 0; i < LEN; i++) {
        j = rand() % 62;
        if (j < 26) {
            k = 'a' + j;
        } else if (j < 52) {
            k = 'A' + j - 26;
        } else {
            k = '0' + j - 52;
        }
        pw[i] = k;
    }

    pw[LEN] = '\0';

    return pw;
}

int main(int argc, char *argv[]) {
    char *pw;
    int i, tries;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <tries>\n", argv[0]);
        return EXIT_FAILURE;
    }

    tries = atoi(argv[1]);

    for (i = 0; i < tries; i++) {
        pw = genpw();
        printf("%s\n", pw);
    }

    return EXIT_SUCCESS;
}