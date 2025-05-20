//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word_t {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main() {
    srand(time(NULL));
    struct word_t words[MAX_WORDS];
    int num_words = 0;

    // Load words from file
    FILE *f = fopen("words.txt", "r");
    char line[100];
    while (fgets(line, sizeof(line), f)) {
        char *word = strtok(line, " ");
        while (word) {
            int len = strlen(word);
            if (len <= MAX_WORD_LENGTH) {
                strcpy(words[num_words].word, word);
                words[num_words].count = 0;
                num_words++;
            }
            word = strtok(NULL, " ");
        }
    }
    fclose(f);

    // Generate conspiracy theory
    char theory[1000];
    strcpy(theory, "The ");
    for (int i = 0; i < num_words; i++) {
        strcat(theory, words[i].word);
        if (i < num_words - 1) {
            strcat(theory, ", ");
        }
    }
    strcat(theory, " conspiracy is real.");

    // Print theory
    printf("%s\n", theory);

    return 0;
}