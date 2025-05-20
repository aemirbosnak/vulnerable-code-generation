//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 100

struct Word {
    char *word;
    int count;
};

struct Word* createWord(char *word) {
    struct Word *newWord = (struct Word*) malloc(sizeof(struct Word));
    newWord->word = strdup(word);
    newWord->count = 1;
    return newWord;
}

void freeWord(struct Word *word) {
    free(word->word);
    free(word);
}

struct Word* findWord(struct Word *words, char *word) {
    for(int i=0; i<words->count; i++) {
        if(strcmp(words[i].word, word) == 0) {
            return &words[i];
        }
    }
    return NULL;
}

void printWords(struct Word *words) {
    for(int i=0; i<words->count; i++) {
        printf("%s %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *file = fopen("resume.txt", "r");
    char line[MAX_LINE_SIZE];
    struct Word *words = NULL;
    int numWords = 0;

    if(file == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    while(fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, " ");
        while(token!= NULL) {
            struct Word *word = findWord(words, token);
            if(word == NULL) {
                word = createWord(token);
                words = (struct Word*) realloc(words, sizeof(struct Word) * (numWords+1));
                words[numWords] = *word;
                numWords++;
            } else {
                word->count++;
            }
            token = strtok(NULL, " ");
        }
    }

    printWords(words);

    for(int i=0; i<numWords; i++) {
        freeWord(&words[i]);
    }
    free(words);

    return 0;
}