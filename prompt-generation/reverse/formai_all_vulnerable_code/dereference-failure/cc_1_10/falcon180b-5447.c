//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    int i = 0;
    Word words[MAX_WORDS];

    // Open input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read words from file
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            words[i].count = 1;
            i++;
        }
    }

    // Close input file
    fclose(fp);

    // Spell check
    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            Word *word = (Word*)malloc(sizeof(Word));
            word->word[0] = tolower(ch);
            word->count = 0;

            for (int j = 0; j < i; j++) {
                if (strcmp(word->word, words[j].word) == 0) {
                    word->count = words[j].count;
                    break;
                }
            }

            if (word->count == 0) {
                printf("%s is not a valid word.\n", word->word);
            }

            free(word);
        }
    }

    // Close dictionary file
    fclose(fp);

    return 0;
}