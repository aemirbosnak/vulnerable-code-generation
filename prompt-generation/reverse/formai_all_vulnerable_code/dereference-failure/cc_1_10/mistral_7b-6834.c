//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define TABLE_SIZE 101

typedef struct {
    char key[50];
    char file[50];
} hash_table;

unsigned long hash(const unsigned char *str, unsigned long table_size) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % table_size;
}

void consult(char *clue) {
    int i;
    hash_table table[TABLE_SIZE];

    for (i = 0; i < TABLE_SIZE; i++) {
        strcpy(table[i].key, " ");
        strcpy(table[i].file, " ");
    }

    strcpy(table[hash(clue, TABLE_SIZE)].key, clue);
    strcpy(table[hash(clue, TABLE_SIZE)].file, "suspects.txt");

    printf("The clue '%s' points to the file '%s'\n", clue, table[hash(clue, TABLE_SIZE)].file);
}

int main(int argc, char *argv[]) {
    int opt;
    char *clue;

    opterr = 0;

    while ((opt = getopt_long(argc, argv, "c:", &clue, NULL)) != -1) {
        if (opt != 'c') {
            fprintf(stderr, "Usage: %s -c <clue>\n", argv[0]);
            exit(EXIT_FAILURE);
        }

        if (strlen(clue) > 50) {
            fprintf(stderr, "Error: Clue too long\n");
            exit(EXIT_FAILURE);
        }

        consult(clue);
    }

    return EXIT_SUCCESS;
}