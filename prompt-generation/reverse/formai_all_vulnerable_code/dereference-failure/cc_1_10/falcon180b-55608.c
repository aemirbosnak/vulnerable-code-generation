//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

typedef struct {
    char *english;
    char *cat;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void load_words() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    char line[MAX_SENTENCE_LENGTH];
    while (fgets(line, MAX_SENTENCE_LENGTH, file)!= NULL) {
        char *english_word, *cat_word;
        if (sscanf(line, "%s %s", english_word, cat_word)!= 2) {
            printf("Error: invalid line in words.txt\n");
            exit(1);
        }
        words[num_words++] = (Word) {.english = strdup(english_word),.cat = strdup(cat_word)};
    }

    fclose(file);
}

void translate_sentence(char *sentence) {
    char *token;
    char *english_word;
    char *cat_word;
    int i;

    token = strtok(sentence, " ");
    while (token!= NULL) {
        english_word = token;
        cat_word = NULL;

        for (i = 0; i < num_words; i++) {
            if (strcmp(english_word, words[i].english) == 0) {
                cat_word = words[i].cat;
                break;
            }
        }

        if (cat_word == NULL) {
            printf("Meow ");
        } else {
            printf("%s ", cat_word);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
}

int main() {
    load_words();

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    translate_sentence(sentence);

    return 0;
}