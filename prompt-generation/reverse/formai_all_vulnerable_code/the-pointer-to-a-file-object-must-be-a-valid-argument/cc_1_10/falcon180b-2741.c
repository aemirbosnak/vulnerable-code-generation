//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} word_t;

word_t words[MAX_WORDS];
int num_words = 0;

void load_words(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",.!?;:");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].frequency++;
                    break;
                }
            }
            if (i == num_words) {
                strcpy(words[num_words].word, token);
                words[num_words].frequency = 1;
                num_words++;
            }
            token = strtok(NULL, ",.!?;:");
        }
    }
    fclose(file);
}

int is_spam(char *message) {
    int i, j;
    int spam_score = 0;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            for (j = 0; j < num_words; j++) {
                if (strcmp(message + i, words[j].word) == 0) {
                    spam_score += words[j].frequency;
                    break;
                }
            }
        }
    }
    return spam_score > 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <training_data> <message>\n", argv[0]);
        return 1;
    }
    load_words(argv[1]);
    char *message = argv[2];
    if (is_spam(message)) {
        printf("Spam\n");
    } else {
        printf("Not spam\n");
    }
    return 0;
}