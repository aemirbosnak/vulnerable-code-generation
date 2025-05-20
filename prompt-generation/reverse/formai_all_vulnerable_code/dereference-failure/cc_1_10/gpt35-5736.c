//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct Word {
    char* word_str;
    int frequency;
} Word;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

char* sanitize(char* word) {
    char* sanitized = malloc(MAX_WORD_LENGTH * sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (isalpha(word[i]) || word[i] == '\'') {
            sanitized[j++] = tolower(word[i]);
        }
    }
    sanitized[j] = '\0';
    return sanitized;
}

int search_word(char* word, Word* word_list, int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, word_list[i].word_str) == 0) {
            return i;
        }
    }
    return -1;
}

void sort_words(Word* word_list, int num_words) {
    for (int i = 0; i < num_words-1; i++) {
        for (int j = 0; j < num_words-i-1; j++) {
            if (word_list[j].frequency < word_list[j+1].frequency) {
                Word temp = word_list[j];
                word_list[j] = word_list[j+1];
                word_list[j+1] = temp;
            }
        }
    }
}

int main() {
    char* file_path = "input.txt";
    FILE* file = fopen(file_path, "r");

    if (file == NULL) {
        error("Error opening file");
    }

    char c;
    char* buffer = malloc(MAX_WORD_LENGTH * sizeof(char));
    int i = 0, j = 0;
    Word* word_list = malloc(MAX_WORDS * sizeof(Word));
    int num_words = 0;

    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c) || c == '\'') {
            buffer[i++] = c;
        } else {
            if (i > 0) {
                buffer[i] = '\0';
                char* sanitized = sanitize(buffer);
                int index = search_word(sanitized, word_list, num_words);
                if (index == -1) {
                    if (num_words < MAX_WORDS) {
                        Word new_word;
                        new_word.word_str = sanitized;
                        new_word.frequency = 1;
                        word_list[num_words++] = new_word;
                    } else {
                        error("Too many words!");
                    }
                } else {
                    word_list[index].frequency++;
                }
                i = 0;
            }
        }
    }

    if (i > 0) {
        buffer[i] = '\0';
        char* sanitized = sanitize(buffer);
        int index = search_word(sanitized, word_list, num_words);
        if (index == -1) {
            if (num_words < MAX_WORDS) {
                Word new_word;
                new_word.word_str = sanitized;
                new_word.frequency = 1;
                word_list[num_words++] = new_word;
            } else {
                error("Too many words!");
            }
        } else {
            word_list[index].frequency++;
        }
    }

    sort_words(word_list, num_words);

    for (int i = 0; i < num_words; i++) {
        printf("%d %s\n", word_list[i].frequency, word_list[i].word_str);
    }

    for (int i = 0; i < num_words; i++) {
        free(word_list[i].word_str);
    }
    free(word_list);
    free(buffer);
    fclose(file);

    return 0;
}