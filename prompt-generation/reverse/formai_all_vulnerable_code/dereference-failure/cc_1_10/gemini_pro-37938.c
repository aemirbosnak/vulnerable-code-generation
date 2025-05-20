//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *english;
    char *cat;
} word_pair;

word_pair dictionary[] = {
    {"hello", "meow"},
    {"goodbye", "purr"},
    {"thank you", "rub"},
    {"I love you", "headbutt"},
    {"no", "hiss"},
    {"yes", "chirp"},
    {"cat", "meow"},
    {"dog", "woof"},
    {"mouse", "squeak"},
    {"bird", "tweet"},
    {"fish", "blub"},
    {"tree", "scratch"},
    {"flower", "sniff"},
    {"sun", "purr"},
    {"moon", "meow"},
    {"star", "chirp"}
};

int main() {
    char input[100];
    printf("Enter a sentence in English: ");
    gets(input);

    char *output = malloc(strlen(input) + 1);
    *output = '\0';

    char *word = strtok(input, " ");
    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < sizeof(dictionary) / sizeof(word_pair); i++) {
            if (strcmp(word, dictionary[i].english) == 0) {
                strcat(output, dictionary[i].cat);
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(output, word);
        }
        strcat(output, " ");
        word = strtok(NULL, " ");
    }

    printf("Translation: %s\n", output);

    free(output);
    return 0;
}