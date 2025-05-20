//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH + 1];
    int frequency;
};

struct word *generate_word(void) {
    struct word *word = malloc(sizeof(struct word));
    if (word == NULL) {
        fprintf(stderr, "Error: Out of memory.\n");
        exit(1);
    }
    word->word[0] = '\0';
    word->frequency = 0;
    return word;
}

void add_word(struct word *word, const char *add_word) {
    if (strlen(add_word) >= MAX_WORD_LENGTH - 1) {
        fprintf(stderr, "Error: Word is too long.\n");
        exit(1);
    }
    strcat(word->word, add_word);
    word->frequency++;
}

void generate_words(struct word *words, int num_words) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open words.txt.\n");
        exit(1);
    }
    char line[MAX_WORD_LENGTH + 1];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        line[strcspn(line, "\n")] = '\0';
        for (int i = 0; i < num_words; i++) {
            struct word *word = generate_word();
            add_word(word, line);
            words[i] = *word;
        }
    }
    fclose(file);
}

void print_words(struct word *words, int num_words) {
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(void) {
    srand(time(NULL));
    int num_words = rand() % 10 + 1;
    struct word words[MAX_WORDS];
    generate_words(words, num_words);
    print_words(words, num_words);
    return 0;
}