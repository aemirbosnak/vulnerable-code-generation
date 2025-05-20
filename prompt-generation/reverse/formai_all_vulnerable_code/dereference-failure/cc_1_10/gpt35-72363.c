//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

struct word {
    char text[50];
    int count;
};

struct word words[MAX_WORDS];

int count_words(char *text) {
    int count = 0;
    char *word, *state;

    for (word = strtok_r(text, " \t\n", &state); word; word = strtok_r(NULL, " \t\n", &state)) {
        if (isalpha(word[0])) {
            int i;

            for (i = 0; word[i]; i++) {
                word[i] = tolower(word[i]);
            }

            for (i = 0; i < count; i++) {
                if (strcmp(words[i].text, word) == 0) {
                    words[i].count++;
                    break;
                }
            }

            if (i == count) {
                if (count == MAX_WORDS) {
                    fprintf(stderr, "Too many unique words\n");
                    exit(1);
                }

                strcpy(words[count].text, word);
                words[count].count = 1;
                count++;
            }
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    char text[100000];
    int count, i;

    if (argc != 2) {
        fprintf(stderr, "Usage: wordcount <filename>\n");
        exit(1);
    }

    FILE *f = fopen(argv[1], "r");

    if (!f) {
        perror("fopen");
        exit(1);
    }

    if (fgets(text, sizeof(text), f) == NULL) {
        perror("fgets");
        exit(1);
    }

    count = count_words(text);

    printf("Word Frequencies\n");
    printf("----------------\n");

    for (i = 0; i < count; i++) {
        printf("%-20s %d\n", words[i].text, words[i].count);
    }

    fclose(f);
    return 0;
}