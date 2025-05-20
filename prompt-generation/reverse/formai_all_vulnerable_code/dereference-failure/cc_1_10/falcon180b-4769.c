//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_SIZE 100
#define MAX_DICTIONARY_SIZE 10000

typedef struct {
    char word[MAX_WORD_SIZE];
    bool is_correct;
} Word;

typedef struct {
    Word words[MAX_DICTIONARY_SIZE];
    int num_words;
} Dictionary;

void load_dictionary(Dictionary *dict, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file\n");
        exit(1);
    }
    char line[MAX_WORD_SIZE];
    while (fgets(line, MAX_WORD_SIZE, file)!= NULL) {
        line[strcspn(line, "\n")] = '\0'; // remove newline character
        Word word = {.word = line,.is_correct = true };
        dict->words[dict->num_words++] = word;
    }
    fclose(file);
}

bool is_word(const char *word) {
    int i = 0;
    while (isalnum(word[i])) {
        i++;
    }
    return i > 0;
}

bool is_correct(Word *word) {
    return word->is_correct;
}

void set_correct(Word *word, bool is_correct) {
    word->is_correct = is_correct;
}

void spell_check(const char *filename, Dictionary *dict) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }
    char line[MAX_WORD_SIZE];
    while (fgets(line, MAX_WORD_SIZE, file)!= NULL) {
        line[strcspn(line, "\n")] = '\0'; // remove newline character
        char *word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            if (is_word(word)) {
                bool is_correct = false;
                for (int i = 0; i < dict->num_words; i++) {
                    if (strcmp(dict->words[i].word, word) == 0) {
                        is_correct = true;
                        break;
                    }
                }
                if (!is_correct) {
                    printf("%s: %s\n", filename, word);
                }
            }
            word = strtok(NULL, ",.?!;:");
        }
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        exit(1);
    }
    Dictionary dict;
    load_dictionary(&dict, argv[1]);
    spell_check(argv[2], &dict);
    return 0;
}