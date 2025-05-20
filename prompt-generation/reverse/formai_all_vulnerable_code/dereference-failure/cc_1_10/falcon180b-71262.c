//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

// Alien Language Dictionary
struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} dictionary[MAX_WORDS];

int num_words = 0;

void load_dictionary() {
    FILE *fp;
    char line[MAX_WORD_LENGTH];
    char *word, *translation;

    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        word = strtok(line, ",");
        translation = strtok(NULL, ",");

        strcpy(dictionary[num_words].word, word);
        strcpy(dictionary[num_words].translation, translation);

        num_words++;
    }

    fclose(fp);
}

int find_word(char *word) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    char sentence[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int i, j;
    time_t start_time, end_time;

    load_dictionary();

    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_WORD_LENGTH, stdin);

    // Convert sentence to lowercase
    for (i = 0; i < strlen(sentence); i++) {
        if (isalpha(sentence[i])) {
            sentence[i] = tolower(sentence[i]);
        }
    }

    // Split sentence into words
    i = 0;
    while (i < strlen(sentence)) {
        j = i;
        while (j < strlen(sentence) && isalnum(sentence[j])) {
            j++;
        }

        strncpy(word, &sentence[i], j - i);
        word[j - i] = '\0';

        int index = find_word(word);
        if (index!= -1) {
            printf("%s ", dictionary[index].translation);
        } else {
            printf("%s ", word);
        }

        i = j;
    }

    printf("\n");

    return 0;
}