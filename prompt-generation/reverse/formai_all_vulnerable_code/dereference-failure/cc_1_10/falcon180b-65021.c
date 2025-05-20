//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void add_word(char* new_word) {
    strcpy(words[num_words].word, new_word);
    words[num_words].is_correct = true;
    num_words++;
}

bool is_correct_word(char* word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i].word) == 0) {
            return words[i].is_correct;
        }
    }
    return false;
}

void load_dictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file %s\n", filename);
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        add_word(word);
    }
    fclose(file);
}

void save_dictionary(char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open dictionary file %s for writing\n", filename);
        exit(1);
    }
    int i;
    for (i = 0; i < num_words; i++) {
        fprintf(file, "%s\n", words[i].word);
    }
    fclose(file);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s [load|save] [dictionary_file]\n", argv[0]);
        return 1;
    }
    char* mode = argv[1];
    char* filename = argv[2];
    if (strcmp(mode, "load") == 0) {
        load_dictionary(filename);
    } else if (strcmp(mode, "save") == 0) {
        save_dictionary(filename);
    } else {
        printf("Error: invalid mode '%s'\n", mode);
        return 1;
    }
    return 0;
}