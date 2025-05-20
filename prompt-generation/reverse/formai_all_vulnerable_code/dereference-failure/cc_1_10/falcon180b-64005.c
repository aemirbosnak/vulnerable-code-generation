//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void read_file(FILE *file, char *filename) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (i >= MAX_WORD_LENGTH) {
                printf("Error: Word is too long.\n");
                exit(1);
            }
            filename[i++] = tolower(ch);
        } else {
            filename[i] = '\0';
            i = 0;
        }
    }
    if (i > 0) {
        filename[i] = '\0';
        i = 0;
    }
}

int compare_words(const void *a, const void *b) {
    const WordFrequency *word1 = a;
    const WordFrequency *word2 = b;
    return strcmp(word1->word, word2->word);
}

void print_word_frequencies(WordFrequency *word_frequencies, int num_words) {
    qsort(word_frequencies, num_words, sizeof(WordFrequency), compare_words);
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", word_frequencies[i].word, word_frequencies[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <word>\n", argv[0]);
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    char filename[MAX_WORD_LENGTH];
    read_file(file, filename);
    fclose(file);
    char word[MAX_WORD_LENGTH];
    strcpy(word, argv[2]);
    WordFrequency word_frequencies[MAX_WORDS];
    int num_words = 0;
    FILE *output_file = fopen("word_frequencies.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }
    while (fgets(filename, MAX_WORD_LENGTH, file)!= NULL) {
        if (strstr(filename, word)!= NULL) {
            num_words++;
            if (num_words >= MAX_WORDS) {
                printf("Error: Too many words found.\n");
                exit(1);
            }
            int word_length = strlen(filename);
            strncpy(word_frequencies[num_words - 1].word, filename, MAX_WORD_LENGTH - 1);
            word_frequencies[num_words - 1].word[word_length] = '\0';
            word_frequencies[num_words - 1].count++;
        }
    }
    fclose(file);
    fclose(output_file);
    print_word_frequencies(word_frequencies, num_words);
    return 0;
}