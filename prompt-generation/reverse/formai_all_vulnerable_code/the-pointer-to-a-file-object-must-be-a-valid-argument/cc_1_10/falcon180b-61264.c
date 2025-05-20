//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_words(Word words[], int *num_words) {
    FILE *file = fopen("words.txt", "r");
    char line[MAX_WORD_LENGTH];
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        strcpy(words[i].word, line);
        words[i].is_correct = true;
        i++;
    }

    *num_words = i;
    fclose(file);
}

void spell_check(char text[], Word words[], int num_words, FILE *output_file) {
    char word[MAX_WORD_LENGTH];
    int word_length;
    bool found_error = false;

    while ((word_length = fscanf(stdin, "%s", word))!= EOF) {
        if (word_length > 0 && word_length <= MAX_WORD_LENGTH) {
            word[word_length] = '\0';
            bool is_correct = true;

            for (int i = 0; i < num_words; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    is_correct = true;
                    break;
                }
            }

            if (!is_correct) {
                fprintf(output_file, "Possible spelling error: %s\n", word);
                found_error = true;
            }
        }
    }

    if (!found_error) {
        fprintf(output_file, "No spelling errors found.\n");
    }
}

int main() {
    Word words[MAX_WORDS];
    int num_words;

    load_words(words, &num_words);

    char input_text[1000000];
    printf("Enter text to spell check: ");
    fgets(input_text, sizeof(input_text), stdin);

    FILE *output_file = fopen("output.txt", "w");

    spell_check(input_text, words, num_words, output_file);

    fclose(output_file);

    return 0;
}