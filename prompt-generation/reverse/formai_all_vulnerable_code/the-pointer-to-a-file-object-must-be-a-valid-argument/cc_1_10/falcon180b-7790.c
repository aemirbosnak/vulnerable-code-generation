//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 10000

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

void load_dictionary(struct word *dictionary, int count) {
    FILE *file = fopen("dictionary.txt", "r");
    char line[MAX_WORD_LENGTH];
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character
        dictionary[i].word[strcspn(line, "\n")] = '\0'; // Remove newline character
        dictionary[i].count = 0;
        i++;
    }

    fclose(file);
}

int compare_words(const void *a, const void *b) {
    struct word *word_a = (struct word *) a;
    struct word *word_b = (struct word *) b;

    return strcmp(word_a->word, word_b->word);
}

void spell_check(char *text, struct word *dictionary, int count) {
    char word[MAX_WORD_LENGTH];
    int word_length;
    int i;

    while (*text!= '\0') {
        word[0] = *text;
        word_length = 1;

        while (isalnum(*(text + word_length))) {
            word[word_length] = *(text + word_length);
            word_length++;
        }

        word[word_length] = '\0';

        i = bsearch(&word, dictionary, count, sizeof(struct word), compare_words);

        if (i == count) {
            printf("Unknown word: %s\n", word);
        }
    }
}

int main() {
    struct word dictionary[MAX_WORD_COUNT];
    int count = 0;

    load_dictionary(dictionary, count);

    char text[10000];

    printf("Enter text to spell check: ");
    fgets(text, 10000, stdin);

    spell_check(text, dictionary, count);

    return 0;
}