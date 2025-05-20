//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *english;
    char *cat;
} word_pair;

word_pair dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        char *english_word = strtok(line, " ");
        char *cat_word = strtok(NULL, " ");
        word_pair pair = {english_word, cat_word};
        dictionary[num_words++] = pair;
    }
    fclose(fp);
}

void translate_sentence(char *sentence) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                printf("%s ", dictionary[i].cat);
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

int main() {
    load_dictionary();
    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0';
        translate_sentence(input);
    }
    return 0;
}