//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_FILE "dictionary.txt"

typedef struct {
    char word[MAX_WORD_LENGTH];
    int is_correct;
} Word;

void load_dictionary(Word dictionary[], int *size) {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    char line[MAX_WORD_LENGTH];
    int count = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        strcpy(dictionary[count].word, line);
        dictionary[count].is_correct = 1;
        count++;
    }

    fclose(file);
    *size = count;
}

int is_word_correct(char *word, Word dictionary[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return dictionary[i].is_correct;
        }
    }

    return 0;
}

void correct_word(char *word, int is_correct) {
    if (is_correct) {
        printf("%s\n", word);
    } else {
        printf("Incorrect word: %s\n", word);
    }
}

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    Word dictionary[1000];
    int dictionary_size;

    load_dictionary(dictionary, &dictionary_size);

    file = fopen("example.txt", "r");

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *word = strtok(line, " ");

        while (word!= NULL) {
            int is_correct = is_word_correct(word, dictionary, dictionary_size);
            correct_word(word, is_correct);

            word = strtok(NULL, " ");
        }
    }

    fclose(file);

    return 0;
}