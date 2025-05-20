//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compare_words(const void *a, const void *b) {
    const Word *word1 = a;
    const Word *word2 = b;
    return strcmp(word1->word, word2->word);
}

void count_words(char *text, Word words[MAX_WORDS]) {
    char *word;
    char *saveptr;
    int i = 0;
    word = strtok_r(text, " \t\n\r\f\v,.?!;:\"'()[]{}<>", &saveptr);
    while (word!= NULL && i < MAX_WORDS) {
        strcpy(words[i].word, word);
        words[i].count = 1;
        i++;
        word = strtok_r(NULL, " \t\n\r\f\v,.?!;:\"'()[]{}<>", &saveptr);
    }
}

void print_word_counts(Word words[MAX_WORDS], int num_words) {
    qsort(words, num_words, sizeof(Word), compare_words);
    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *file;
    char filename[50];
    char text[100000];
    Word words[MAX_WORDS];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int filesize = ftell(file);
    rewind(file);

    fread(text, 1, filesize, file);
    fclose(file);

    count_words(text, words);
    print_word_counts(words, MAX_WORDS);

    return 0;
}