//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
};

int main() {
    FILE *file;
    char line[100];
    int num_words = 0;
    struct word *words = malloc(MAX_WORDS * sizeof(struct word));

    file = fopen("english_to_alien.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Error: too many words.\n");
                exit(1);
            }
            strcpy(words[num_words].english, word);
            strcpy(words[num_words].alien, "");
            num_words++;
            word = strtok(NULL, " ");
        }
    }

    fclose(file);

    printf("Enter an English sentence:\n");
    fgets(line, sizeof(line), stdin);

    char *sentence = strtok(line, "\n");
    while (sentence!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(sentence, words[i].english) == 0) {
                printf("%s = %s\n", words[i].english, words[i].alien);
                break;
            }
        }
        if (i == num_words) {
            printf("Unknown word: %s\n", sentence);
        }
        sentence = strtok(NULL, " ");
    }

    free(words);
    return 0;
}