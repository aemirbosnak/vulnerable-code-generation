//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    bool is_correct;
} Word;

char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    char *text = NULL;
    if (file) {
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        rewind(file);
        text = malloc(file_size + 1);
        if (text) {
            fread(text, file_size, 1, file);
            text[file_size] = '\0';
        }
        fclose(file);
    }
    return text;
}

void tokenize(char *text, Word *words) {
    char *token = strtok(text, ",.!?;:\"'");
    int word_count = 0;
    while (token!= NULL && word_count < MAX_WORDS) {
        int len = strlen(token);
        if (len > 0 && len <= MAX_WORD_LEN) {
            strcpy(words[word_count].word, token);
            words[word_count].is_correct = false;
            word_count++;
        }
        token = strtok(NULL, ",.!?;:\"'");
    }
}

void check_spelling(Word *words) {
    char *dictionary = read_file("dictionary.txt");
    if (dictionary) {
        for (int i = 0; i < MAX_WORDS; i++) {
            bool found = false;
            char *word = words[i].word;
            int len = strlen(word);
            for (int j = 0; j < strlen(dictionary); j++) {
                if (tolower(word[j]) == tolower(dictionary[j])) {
                    found = true;
                    break;
                }
            }
            if (found) {
                words[i].is_correct = true;
            }
        }
        free(dictionary);
    }
}

void print_results(Word *words) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (!words[i].is_correct) {
            printf("%s\n", words[i].word);
        }
    }
}

int main() {
    char text[MAX_WORD_LEN * 1000];
    printf("Enter text to spell check:\n");
    fgets(text, sizeof(text), stdin);
    Word words[MAX_WORDS];
    tokenize(text, words);
    check_spelling(words);
    print_results(words);
    return 0;
}