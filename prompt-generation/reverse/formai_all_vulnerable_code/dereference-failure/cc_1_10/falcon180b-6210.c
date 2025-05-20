//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100
#define ALPHABET_SIZE 26

char words[MAX_WORDS][MAX_WORD_LENGTH];
int word_count;

bool is_valid_sentence(char sentence[]);
void generate_words(void);
void translate_sentence(char sentence[]);

int main() {
    srand(time(NULL));
    generate_words();
    char sentence[MAX_SENTENCE_LENGTH];
    while (true) {
        printf("Enter a sentence to translate: ");
        fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
        if (is_valid_sentence(sentence)) {
            translate_sentence(sentence);
        } else {
            printf("Invalid sentence.\n");
        }
    }
    return 0;
}

bool is_valid_sentence(char sentence[]) {
    int i, j, word_count = 0;
    for (i = 0; i < strlen(sentence); i++) {
        if (isspace(sentence[i])) {
            word_count++;
        }
        if (word_count > 10) {
            return false;
        }
    }
    return true;
}

void generate_words() {
    char ch;
    for (int i = 0; i < MAX_WORDS; i++) {
        do {
            ch = rand() % ALPHABET_SIZE + 'a';
        } while (isalpha(ch) == 0);
        strcpy(words[i], &ch);
    }
    word_count = MAX_WORDS;
}

void translate_sentence(char sentence[]) {
    int i, j, k, word_index;
    for (i = 0, j = 0; i < strlen(sentence); i++) {
        if (isspace(sentence[i])) {
            for (k = 0; k < strlen(sentence) - i; k++) {
                if (isalpha(sentence[i + k])) {
                    word_index = rand() % word_count;
                    strcpy(&sentence[i], words[word_index]);
                    j += strlen(words[word_index]) - 1;
                    i += strlen(words[word_index]) - 1;
                }
            }
        }
    }
}