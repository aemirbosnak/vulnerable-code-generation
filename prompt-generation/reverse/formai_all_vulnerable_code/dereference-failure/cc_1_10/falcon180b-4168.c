//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define ALIEN_VOCABULARY_SIZE 26
#define EARTH_VOCABULARY_SIZE 26

struct word {
    char *english;
    char *alien;
};

struct word vocabulary[MAX_WORDS];
int vocabulary_size = 0;

void load_vocabulary(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open vocabulary file.\n");
        exit(1);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *english = strtok(line, " ");
        char *alien = strtok(NULL, " ");

        if (english == NULL || alien == NULL) {
            printf("Error: invalid line in vocabulary file.\n");
            exit(1);
        }

        vocabulary[vocabulary_size].english = strdup(english);
        vocabulary[vocabulary_size].alien = strdup(alien);
        vocabulary_size++;
    }

    fclose(file);
}

void generate_alien_vocabulary() {
    for (int i = 0; i < ALIEN_VOCABULARY_SIZE; i++) {
        char alien_char = 'a' + i;
        char earth_char = 'a' + (i % EARTH_VOCABULARY_SIZE);

        struct word *word = &vocabulary[i];
        word->english = malloc(MAX_WORD_LENGTH);
        word->alien = malloc(MAX_WORD_LENGTH);

        sprintf(word->english, "%c", earth_char);
        sprintf(word->alien, "%c", alien_char);
    }
}

void translate_sentence(char *sentence) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int index = -1;
        for (int i = 0; i < vocabulary_size; i++) {
            if (strcmp(token, vocabulary[i].english) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            printf("Unknown word: %s\n", token);
        } else {
            printf("%s ", vocabulary[index].alien);
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
    generate_alien_vocabulary();

    translate_sentence(argv[2]);

    return 0;
}