//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_THEORIES 100
#define MAX_WORDS 50
#define WORD_LIST_FILE "word_list.txt"

typedef struct {
    char words[MAX_WORDS][MAX_WORDS];
    int num_words;
} theory;

void generate_theory(theory* t) {
    FILE* fp = fopen(WORD_LIST_FILE, "r");
    if (fp == NULL) {
        printf("Error: could not open word list file.\n");
        exit(1);
    }

    char line[MAX_WORDS];
    int num_words = 0;

    while (fgets(line, MAX_WORDS, fp)!= NULL) {
        if (num_words >= MAX_WORDS) {
            break;
        }

        char* word = strtok(line, " ");
        while (word!= NULL) {
            strcpy(t->words[num_words], word);
            num_words++;
            word = strtok(NULL, " ");
        }
    }

    fclose(fp);

    t->num_words = num_words;
}

void print_theory(theory* t) {
    int num_sentences = rand() % 5 + 1;

    for (int i = 0; i < num_sentences; i++) {
        int sentence_length = rand() % 10 + 1;
        char sentence[sentence_length + 1];

        for (int j = 0; j < sentence_length; j++) {
            int word_index = rand() % t->num_words;
            strcat(sentence, t->words[word_index]);
            strcat(sentence, " ");
        }

        sentence[sentence_length] = '\0';
        printf("%s\n", sentence);
    }
}

int main() {
    srand(time(NULL));

    theory* t = malloc(sizeof(theory));
    generate_theory(t);

    for (int i = 0; i < MAX_THEORIES; i++) {
        print_theory(t);
    }

    free(t);

    return 0;
}