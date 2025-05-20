//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compare(const void *a, const void *b) {
    WordFrequency *word1 = (WordFrequency *) a;
    WordFrequency *word2 = (WordFrequency *) b;
    return strcmp(word1->word, word2->word);
}

void read_file(FILE *file, WordFrequency *words, int *word_count) {
    char buffer[1000];
    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        int length = strlen(buffer);
        for (int i = 0; i < length; i++) {
            if (isalpha(buffer[i])) {
                char word[MAX_WORD_LENGTH];
                int j = 0;
                while (isalpha(buffer[i])) {
                    word[j++] = tolower(buffer[i]);
                    i++;
                }
                word[j] = '\0';
                WordFrequency *found = bsearch(word, words, *word_count, sizeof(WordFrequency), compare);
                if (found == NULL) {
                    found = &words[*word_count];
                    strcpy(found->word, word);
                    found->frequency = 1;
                    (*word_count)++;
                } else {
                    found->frequency++;
                }
            }
        }
    }
}

void write_frequencies(WordFrequency *words, int word_count) {
    qsort(words, word_count, sizeof(WordFrequency), compare);
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }
    WordFrequency words[MAX_WORDS];
    int word_count = 0;
    read_file(file, words, &word_count);
    fclose(file);
    write_frequencies(words, word_count);
    return 0;
}