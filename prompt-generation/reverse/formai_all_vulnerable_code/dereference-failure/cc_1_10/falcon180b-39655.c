//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *words;
    int num_words;
} MessageFrequency;

void init_message_frequency(MessageFrequency *mf) {
    mf->words = malloc(MAX_WORD_LENGTH * sizeof(WordFrequency));
    mf->num_words = 0;
}

void add_word(MessageFrequency *mf, char *word) {
    WordFrequency *wf = NULL;
    int i;

    for (i = 0; i < mf->num_words; i++) {
        if (strcmp(mf->words[i].word, word) == 0) {
            wf = &mf->words[i];
            break;
        }
    }

    if (wf == NULL) {
        mf->words[mf->num_words].word = strdup(word);
        mf->words[mf->num_words].frequency = 1;
        mf->num_words++;
    } else {
        wf->frequency++;
    }
}

int is_spam(MessageFrequency *mf) {
    int i;
    int spam_words = 0;

    for (i = 0; i < mf->num_words; i++) {
        if (mf->words[i].frequency >= 5) {
            spam_words++;
        }
    }

    return spam_words >= 3;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char message[MAX_MESSAGE_LENGTH];
    MessageFrequency mf;

    srand(time(NULL));

    init_message_frequency(&mf);

    if (argc == 1) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(message, MAX_MESSAGE_LENGTH, fp)!= NULL) {
        char *word = strtok(message, " \t\n\r\f\v");

        while (word!= NULL) {
            add_word(&mf, word);
            word = strtok(NULL, " \t\n\r\f\v");
        }
    }

    fclose(fp);

    if (is_spam(&mf)) {
        printf("Possible spam detected.\n");
    } else {
        printf("No spam detected.\n");
    }

    free(mf.words);

    return 0;
}