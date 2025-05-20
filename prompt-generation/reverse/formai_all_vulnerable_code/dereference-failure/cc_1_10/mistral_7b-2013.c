//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100000
#define LEN 50

typedef struct {
    char base;
    int count;
} base_count;

void seq_read(char *seq, int *len) {
    int i = 0;
    char c;

    while (1) {
        c = getchar();
        if (feof(stdin)) break;

        if (isspace(c)) {
            seq[i] = '\0';
            *len = i;
            break;
        }

        if (*len >= LEN - 1) {
            fprintf(stderr, "Sequence too long\n");
            exit(1);
        }

        seq[*len] = toupper(c);
        (*len)++;
        i++;
    }
}

void seq_print(char *seq) {
    int i = 0;

    while (seq[i] != '\0') {
        putchar(seq[i]);
        i++;
    }
}

void bases_count(char *seq, base_count *bc) {
    int i = 0, len = strlen(seq);

    bc[0].base = 'A';
    bc[0].count = 0;
    bc[1].base = 'C';
    bc[1].count = 0;
    bc[2].base = 'G';
    bc[2].count = 0;
    bc[3].base = 'T';
    bc[3].count = 0;

    while (i < len) {
        switch (seq[i]) {
            case 'A': bc[0].count++; break;
            case 'C': bc[1].count++; break;
            case 'G': bc[2].count++; break;
            case 'T': bc[3].count++; break;
            default: fprintf(stderr, "Invalid base\n"); exit(1);
        }
        i++;
    }
}

int main() {
    char seq[N];
    int len;
    base_count bases[4];

    seq_read(seq, &len);
    seq_print(seq);
    printf("\n");

    bases_count(seq, bases);

    printf("Base counts:\n");
    for (int i = 0; i < 4; i++) {
        printf("%c: %d\n", bases[i].base, bases[i].count);
    }

    return 0;
}