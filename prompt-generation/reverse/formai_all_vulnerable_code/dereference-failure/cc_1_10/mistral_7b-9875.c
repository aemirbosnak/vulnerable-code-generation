//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIEN_ALPHABET_SIZE 26

const char alien_alphabet[ALIEN_ALPHABET_SIZE] = {'&', '*', '%', '^', '#', '@', '&', '+', '&', '!', '&', '|', '&', '&', '&', '&', '&', '&', '&', '&'};

struct alien_word {
    char *english;
    char *alien;
    int length;
};

void translate_word(struct alien_word *word) {
    int i;
    for (i = 0; i < word->length; i++) {
        putchar(alien_alphabet[((int)alien_alphabet[*(word->alien + i)] - 64) % ALIEN_ALPHABET_SIZE]);
        putchar(alien_alphabet[((int)alien_alphabet[*(word->alien + i)] - 64) % ALIEN_ALPHABET_SIZE]);
    }
    putchar(' ');
}

void load_dictionary(struct alien_word **words, int *num_words, char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[256];
    char *token, *word, *alien_word;
    int i = 0;
    if (fp == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, " ");
        word = strdup(token);
        alien_word = strtok(NULL, " ");
        if (i >= *num_words) {
            *num_words *= 2;
            *words = realloc(*words, sizeof(struct alien_word) * (*num_words));
        }
        (*words)[i].english = word;
        (*words)[i].alien = alien_word;
        (*words)[i].length = strlen(alien_word);
        i++;
    }
    fclose(fp);
}

int main(int argc, char *argv[]) {
    int num_words;
    struct alien_word *words;
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dictionary>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    load_dictionary(&words, &num_words, argv[1]);

    for (i = 0; i < num_words; i++) {
        printf("%s: ", words[i].english);
        translate_word(&words[i]);
        printf("%s\n", words[i].english);
    }

    for (i = 0; i < num_words; i++) {
        free(words[i].english);
        free(words[i].alien);
    }
    free(words);

    return EXIT_SUCCESS;
}