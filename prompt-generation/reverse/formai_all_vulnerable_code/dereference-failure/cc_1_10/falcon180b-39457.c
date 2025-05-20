//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char *english;
    char *alien;
} word_t;

word_t words[MAX_WORDS];
int num_words = 0;

void load_words(void) {
    FILE *fp = fopen("words.txt", "r");
    char line[MAX_WORD_LEN];

    while (fgets(line, MAX_WORD_LEN, fp)!= NULL) {
        char *english = strtok(line, ",");
        char *alien = strtok(NULL, ",");

        words[num_words].english = strdup(english);
        words[num_words].alien = strdup(alien);

        num_words++;
    }

    fclose(fp);
}

void translate_sentence(char *sentence) {
    char *token = strtok(sentence, " ");

    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                break;
            }
        }

        if (i == num_words) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    load_words();

    char input[MAX_WORD_LEN];

    while (1) {
        printf("Enter a sentence to translate: ");
        fgets(input, MAX_WORD_LEN, stdin);

        translate_sentence(input);
    }

    return 0;
}