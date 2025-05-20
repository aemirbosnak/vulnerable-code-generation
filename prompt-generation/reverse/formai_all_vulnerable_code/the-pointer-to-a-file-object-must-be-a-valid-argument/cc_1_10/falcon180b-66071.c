//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 1000
#define MAX_SUGGESTIONS 5

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
int num_words_in_dictionary = 0;

void load_dictionary(char* filename) {
    FILE* file = fopen(filename, "r");
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        line[strcspn(line, "\n")] = '\0';
        dictionary[num_words_in_dictionary].word[0] = tolower(line[0]);
        strncpy(dictionary[num_words_in_dictionary].word + 1, line + 1, MAX_WORD_LENGTH - 1);
        dictionary[num_words_in_dictionary].is_correct = true;
        num_words_in_dictionary++;
    }
    fclose(file);
}

bool is_word_in_dictionary(char* word) {
    int i;
    for (i = 0; i < num_words_in_dictionary; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return true;
        }
    }
    return false;
}

void get_suggests(char* word, char* suggests[MAX_SUGGESTIONS]) {
    int i, j;
    for (i = 0; i < num_words_in_dictionary; i++) {
        if (strncmp(dictionary[i].word, word, strlen(word)) == 0) {
            suggests[0] = dictionary[i].word;
            return;
        }
    }
    for (i = 0; i < num_words_in_dictionary; i++) {
        for (j = 0; j < strlen(word); j++) {
            if (tolower(word[j])!= tolower(dictionary[i].word[j])) {
                break;
            }
        }
        if (j == strlen(word)) {
            strcpy(suggests[0], dictionary[i].word);
            return;
        }
    }
}

int main() {
    char text[1000];
    char word[MAX_WORD_LENGTH];
    char suggests[MAX_SUGGESTIONS][MAX_WORD_LENGTH];
    int i, j, k;
    load_dictionary("dictionary.txt");
    printf("Enter text to spell check:\n");
    fgets(text, 1000, stdin);
    i = 0;
    while (i < strlen(text)) {
        if (isalpha(text[i])) {
            j = i;
            while (isalpha(text[j])) {
                j++;
            }
            strncpy(word, text + i, j - i);
            word[j - i] = '\0';
            k = 0;
            get_suggests(word, suggests);
            if (strcmp(word, suggests[0])!= 0) {
                printf("Possible correction for '%s': %s\n", word, suggests[0]);
            }
            i = j;
        } else {
            i++;
        }
    }
    return 0;
}