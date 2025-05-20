//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000

struct word {
    char word[100];
    int count;
};

void read_words(struct word *words) {
    FILE *file = fopen("words.txt", "r");
    char line[100];
    int i = 0;

    while (fgets(line, sizeof(line), file)) {
        words[i].word[strcspn(line, "\n")] = '\0';
        strcpy(words[i].word, line);
        words[i].count = 0;
        i++;
    }

    fclose(file);
}

int compare_words(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void spell_check(char *text, struct word *words) {
    char *token = strtok(text, " \t\r\n\f\v,.?!;:");
    while (token!= NULL) {
        int i = 0;
        while (i < MAX_WORDS && strcmp(token, words[i].word)!= 0) {
            i++;
        }

        if (i == MAX_WORDS) {
            printf("Unknown word: %s\n", token);
        } else {
            words[i].count++;
        }

        token = strtok(NULL, " \t\r\n\f\v,.?!;:");
    }
}

void print_misspelled_words(struct word *words) {
    qsort(words, MAX_WORDS, sizeof(struct word), compare_words);

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main() {
    struct word words[MAX_WORDS];
    read_words(words);

    char text[100000];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    spell_check(text, words);
    print_misspelled_words(words);

    return 0;
}