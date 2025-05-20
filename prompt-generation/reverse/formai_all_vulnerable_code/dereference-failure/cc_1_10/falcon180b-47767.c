//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_CHAR 100

typedef struct {
    char english[MAX_CHAR];
    char cat[MAX_CHAR];
} word_t;

word_t words[MAX_WORDS];
int num_words = 0;

void load_words() {
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    char line[MAX_CHAR];
    while (fgets(line, MAX_CHAR, fp)!= NULL) {
        char *token = strtok(line, ",");
        strcpy(words[num_words].english, token);
        token = strtok(NULL, ",");
        strcpy(words[num_words].cat, token);
        num_words++;
    }

    fclose(fp);
}

char *translate_sentence(char *sentence) {
    char *result = malloc(strlen(sentence) + 1);
    strcpy(result, sentence);

    char *token = strtok(result, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                strcpy(token, words[i].cat);
                break;
            }
        }

        if (i == num_words) {
            printf("Warning: unknown word '%s'\n", token);
        }

        token = strtok(NULL, " ");
    }

    return result;
}

int main() {
    load_words();

    char sentence[MAX_CHAR];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_CHAR, stdin);

    char *translated_sentence = translate_sentence(sentence);
    printf("Translated sentence: %s\n", translated_sentence);

    free(translated_sentence);

    return 0;
}