//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 200

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} word_freq_pair;

int count_words(FILE *file, word_freq_pair **word_list) {
    int max_words = 1000, num_words = 0;
    *word_list = malloc(max_words * sizeof(word_freq_pair));

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        // Remove any trailing punctuation from the word
        int len = strlen(word);
        while (len > 0 && ispunct(word[len - 1])) {
            len--;
            word[len] = '\0';
        }

        // Convert the word to lowercase
        for (int i = 0; i < len; i++) {
            word[i] = tolower(word[i]);
        }

        // Check if the word already exists in the list
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp((*word_list)[i].word, word) == 0) {
                // Increment the frequency of the word
                (*word_list)[i].frequency++;
                found = 1;
                break;
            }
        }

        // If the word is not in the list, add it
        if (!found) {
            if (num_words >= max_words) {
                max_words *= 2;
                *word_list = realloc(*word_list, max_words * sizeof(word_freq_pair));
            }

            strcpy((*word_list)[num_words].word, word);
            (*word_list)[num_words].frequency = 1;
            num_words++;
        }
    }

    return num_words;
}

int compare_pairs(const void *p1, const void *p2) {
    int freq1 = ((word_freq_pair *)p1)->frequency;
    int freq2 = ((word_freq_pair *)p2)->frequency;

    if (freq1 != freq2) {
        return freq2 - freq1;
    } else {
        return strcmp(((word_freq_pair *)p1)->word, ((word_freq_pair *)p2)->word);
    }
}

void print_word_freq_pairs(word_freq_pair *pairs, int num_pairs) {
    for (int i = 0; i < num_pairs; i++) {
        printf("%s: %d\n", pairs[i].word, pairs[i].frequency);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open file %s\n", argv[1]);
        exit(1);
    }

    word_freq_pair *word_list;
    int num_words = count_words(file, &word_list);

    qsort(word_list, num_words, sizeof(word_freq_pair), compare_pairs);

    print_word_freq_pairs(word_list, num_words);

    fclose(file);

    return 0;
}