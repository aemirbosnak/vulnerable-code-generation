//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

struct word_t {
    char word[MAX_WORD_LEN];
    int count;
};

void read_file(FILE *file, struct word_t words[]) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            words[i].count = 1;
            i++;
        } else if (isdigit(ch)) {
            words[i - 1].count++;
        }
    }
}

void translate(struct word_t words[], int n) {
    printf("Alien Language Translation:\n");
    for (int i = 0; i < n; i++) {
        if (words[i].count > 1) {
            printf("%s -> %s\n", words[i].word, words[i].word);
        } else {
            printf("%s -> %s\n", words[i].word, "unknown");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        exit(1);
    }

    struct word_t words[MAX_WORDS];
    int n = 0;

    read_file(file, words);
    fclose(file);

    translate(words, n);

    return 0;
}