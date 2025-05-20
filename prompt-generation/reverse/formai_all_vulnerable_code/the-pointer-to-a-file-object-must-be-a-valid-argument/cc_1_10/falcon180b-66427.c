//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int spam_score;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

int is_spam(char *text) {
    int i, score = 0;
    for (i = 0; i < num_words; i++) {
        if (strstr(text, words[i].word)) {
            score += words[i].spam_score;
        }
    }
    return score > 0;
}

void load_words() {
    FILE *fp = fopen("spam_words.txt", "r");
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            int spam_score = 0;
            if (strstr(word, "viagra")!= NULL) {
                spam_score += 10;
            } else if (strstr(word, "cialis")!= NULL) {
                spam_score += 5;
            } else if (strstr(word, "free")!= NULL) {
                spam_score += 3;
            } else if (strstr(word, "money")!= NULL) {
                spam_score += 2;
            }
            num_words++;
            words[num_words - 1].word = strdup(word);
            words[num_words - 1].spam_score = spam_score;
            num_words++;
        }
    }
    fclose(fp);
}

int main() {
    load_words();
    char text[MAX_WORD_LENGTH];
    while (fgets(text, MAX_WORD_LENGTH, stdin)!= NULL) {
        if (is_spam(text)) {
            printf("Spam detected!\n");
        } else {
            printf("No spam detected.\n");
        }
    }
    return 0;
}