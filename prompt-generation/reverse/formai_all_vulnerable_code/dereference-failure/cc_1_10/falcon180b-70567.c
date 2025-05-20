//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define MAX_VOCABULARY 100
#define MAX_WORD_LENGTH 10
#define MAX_SENTENCE_LENGTH 100

struct Vocabulary {
    char *english;
    char *alien;
};

struct Vocabulary vocabulary[MAX_VOCABULARY];
int vocabulary_size = 0;

void load_vocabulary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading vocabulary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *english_word = strtok(line, " ");
        char *alien_word = strtok(NULL, " ");

        if (english_word == NULL || alien_word == NULL) {
            printf("Invalid vocabulary entry: %s\n", line);
            continue;
        }

        struct Vocabulary *new_vocabulary = (struct Vocabulary *)malloc(sizeof(struct Vocabulary));
        strcpy(new_vocabulary->english, english_word);
        strcpy(new_vocabulary->alien, alien_word);
        vocabulary[vocabulary_size++] = *new_vocabulary;
    }

    fclose(file);
}

void translate_sentence(char *sentence) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < vocabulary_size; i++) {
            if (strcmp(token, vocabulary[i].english) == 0) {
                printf("%s ", vocabulary[i].alien);
                break;
            }
        }

        if (i == vocabulary_size) {
            printf("UNKNOWN WORD: %s\n", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <vocabulary_file> <sentence>\n", argv[0]);
        exit(1);
    }

    load_vocabulary(argv[1]);
    translate_sentence(argv[2]);

    return 0;
}