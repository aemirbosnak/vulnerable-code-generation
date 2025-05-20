//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_CHARS 50

struct word {
    char *english;
    char *cat;
    int count;
};

int main() {
    struct word words[MAX_WORDS];
    int num_words = 0;
    FILE *fp;
    char line[MAX_CHARS];
    char *token;
    char *cat_word;

    fp = fopen("cat_words.txt", "r");
    if (fp == NULL) {
        printf("Error opening cat_words.txt file\n");
        exit(1);
    }

    while (fgets(line, MAX_CHARS, fp)!= NULL) {
        token = strtok(line, ",");
        cat_word = strtok(NULL, ",");
        if (num_words >= MAX_WORDS) {
            printf("Too many words in cat_words.txt file\n");
            exit(1);
        }
        words[num_words].english = strdup(token);
        words[num_words].cat = strdup(cat_word);
        words[num_words].count = 0;
        num_words++;
    }

    fclose(fp);

    printf("Enter a sentence to translate into Cat:\n");
    fgets(line, MAX_CHARS, stdin);
    token = strtok(line, " ");

    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].cat);
                words[i].count++;
                break;
            }
        }
        if (i == num_words) {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}