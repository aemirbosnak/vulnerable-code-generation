//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void count_words(FILE* infile, FILE* outfile) {
    char word[100];
    int word_count[100];
    int num_words = 0;
    int max_word_length = 0;

    while (fscanf(infile, "%s", word)!= EOF) {
        num_words++;
        word_count[num_words] = 0;
        max_word_length = (int)strlen(word);
    }

    for (int i = 0; i < num_words; i++) {
        fseek(infile, 0, SEEK_SET);
        while (fscanf(infile, "%s", word)!= EOF) {
            if (strcmp(word, word_count[i]) == 0) {
                word_count[i]++;
            }
        }
    }

    for (int i = 0; i < num_words; i++) {
        fprintf(outfile, "%s\t%d\n", word_count[i], word_count[i]);
    }

    fclose(infile);
    fclose(outfile);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }

    FILE* infile = fopen(argv[1], "r");
    if (infile == NULL) {
        fprintf(stderr, "Could not open input file: %s\n", argv[1]);
        exit(1);
    }

    FILE* outfile = fopen(argv[2], "w");
    if (outfile == NULL) {
        fprintf(stderr, "Could not create output file: %s\n", argv[2]);
        exit(1);
    }

    count_words(infile, outfile);

    fclose(infile);
    fclose(outfile);

    return 0;
}