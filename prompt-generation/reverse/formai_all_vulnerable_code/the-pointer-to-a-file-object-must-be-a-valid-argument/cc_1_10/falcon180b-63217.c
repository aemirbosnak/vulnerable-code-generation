//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOCABULARY 5000
#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Vocabulary;

Vocabulary vocabulary[MAX_VOCABULARY];
int vocabulary_size = 0;

void load_vocabulary(char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[MAX_WORD_LENGTH + 1];
    int i = 0;

    while (fgets(line, MAX_WORD_LENGTH, fp)) {
        line[strcspn(line, "\n")] = '\0';
        strcpy(vocabulary[i].word, line);
        vocabulary[i].count = 1;
        i++;
    }

    fclose(fp);
}

void update_vocabulary(char *word) {
    for (int i = 0; i < vocabulary_size; i++) {
        if (strcmp(word, vocabulary[i].word) == 0) {
            vocabulary[i].count++;
            return;
        }
    }

    if (vocabulary_size >= MAX_VOCABULARY) {
        printf("Vocabulary is full.\n");
        return;
    }

    strcpy(vocabulary[vocabulary_size].word, word);
    vocabulary[vocabulary_size].count = 1;
    vocabulary_size++;
}

void translate_sentence(char *sentence) {
    char word[MAX_WORD_LENGTH];
    char *token = strtok(sentence, " ");

    while (token!= NULL) {
        if (strlen(token) > MAX_WORD_LENGTH) {
            printf("Word too long: %s\n", token);
            return;
        }

        for (int i = 0; i < strlen(token); i++) {
            if (!isalpha(token[i])) {
                printf("Invalid character in word: %s\n", token);
                return;
            }
        }

        update_vocabulary(token);

        strcpy(word, token);
        printf("%s -> %s\n", word, word);

        token = strtok(NULL, " ");
    }
}

int main() {
    load_vocabulary("vocabulary.txt");

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    translate_sentence(sentence);

    return 0;
}