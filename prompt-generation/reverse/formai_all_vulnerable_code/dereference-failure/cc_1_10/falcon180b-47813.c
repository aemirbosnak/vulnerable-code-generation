//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char *english;
    char *alien;
} word_pair;

word_pair words[MAX_WORDS];
int num_words = 0;

void add_word(char *english, char *alien) {
    if (num_words >= MAX_WORDS) {
        printf("Error: Too many words!\n");
        exit(1);
    }
    words[num_words].english = strdup(english);
    words[num_words].alien = strdup(alien);
    num_words++;
}

void load_words(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    char line[1000];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *english = strtok(line, " \t\n\r\f\v");
        char *alien = strtok(NULL, " \t\n\r\f\v");
        if (english == NULL || alien == NULL) {
            printf("Error: Invalid line in file %s\n", filename);
            exit(1);
        }
        add_word(english, alien);
    }
    fclose(fp);
}

void save_words(char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < num_words; i++) {
        fprintf(fp, "%s %s\n", words[i].english, words[i].alien);
    }
    fclose(fp);
}

void translate_sentence(char *sentence) {
    char *token = strtok(sentence, " \t\n\r\f\v");
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
        token = strtok(NULL, " \t\n\r\f\v");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    load_words("words.txt");
    char input[1000];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        translate_sentence(input);
    }
    save_words("words.txt");
    return 0;
}