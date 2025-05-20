//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char *word;
    int frequency;
};

struct word words[MAX_WORDS];
int num_words;

void init_words() {
    FILE *file = fopen("words.txt", "r");
    char line[MAX_WORD_LENGTH + 1];
    char *word;
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, " \n");
        while (word!= NULL) {
            if (strlen(word) > 0) {
                struct word *w = &words[i];
                w->word = strdup(word);
                w->frequency = 0;
                i++;
                if (i >= MAX_WORDS) {
                    break;
                }
            }
            word = strtok(NULL, " \n");
        }
    }

    fclose(file);
    num_words = i;
}

void generate_theory() {
    srand(time(NULL));
    int i, j;
    char theory[MAX_WORD_LENGTH * 10];
    theory[0] = '\0';

    for (i = 0; i < num_words; i++) {
        j = rand() % num_words;
        strcat(theory, words[j].word);
        strcat(theory, " ");
    }

    printf("Random Conspiracy Theory: %s\n", theory);
}

int main() {
    init_words();
    generate_theory();

    return 0;
}