//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

struct word_t {
    char *english;
    char *alien;
};

int main() {
    struct word_t words[MAX_WORDS];
    int num_words = 0;

    FILE *english_file = fopen("english.txt", "r");
    if (english_file == NULL) {
        printf("Error opening English file.\n");
        return 1;
    }

    FILE *alien_file = fopen("alien.txt", "w");
    if (alien_file == NULL) {
        printf("Error opening Alien file.\n");
        return 1;
    }

    char line[MAX_WORD_LEN];
    while (fgets(line, MAX_WORD_LEN, english_file)!= NULL) {
        char *word_start = line;
        while (isspace(*word_start)) {
            word_start++;
        }
        char *word_end = word_start;
        while (!isspace(*word_end)) {
            word_end++;
        }
        *word_end = '\0';
        char english_word[MAX_WORD_LEN];
        strncpy(english_word, word_start, MAX_WORD_LEN);
        english_word[MAX_WORD_LEN - 1] = '\0';

        char alien_word[MAX_WORD_LEN];
        sprintf(alien_word, "%d", num_words);
        num_words++;

        words[num_words - 1].english = strdup(english_word);
        words[num_words - 1].alien = strdup(alien_word);
    }

    for (int i = 0; i < num_words; i++) {
        fprintf(alien_file, "%s %s\n", words[i].english, words[i].alien);
    }

    fclose(english_file);
    fclose(alien_file);

    return 0;
}