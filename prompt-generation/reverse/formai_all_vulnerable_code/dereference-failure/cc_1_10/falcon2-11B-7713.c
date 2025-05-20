//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char* word;
    int length;
} Word;

typedef struct {
    Word* words;
    int size;
} Dictionary;

void shuffle_words(Dictionary* dict) {
    srand(time(NULL));
    for (int i = dict->size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Word tmp = dict->words[i];
        dict->words[i] = dict->words[j];
        dict->words[j] = tmp;
    }
}

int search_word(Dictionary* dict, char* word) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    Dictionary* dict = malloc(sizeof(Dictionary));
    if (dict == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    dict->words = malloc(sizeof(Word) * 10);
    if (dict->words == NULL) {
        perror("malloc");
        free(dict);
        exit(EXIT_FAILURE);
    }
    dict->size = 10;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        Word w;
        w.length = rand() % 100;
        w.word = malloc(w.length + 1);
        if (w.word == NULL) {
            perror("malloc");
            free(dict->words[i].word);
            free(dict->words[i].word);
            free(dict->words[i].word);
            exit(EXIT_FAILURE);
        }
        for (int j = 0; j < w.length; j++) {
            w.word[j] = rand() % 255;
        }
        w.word[w.length] = '\0';
        dict->words[i] = w;
    }
    shuffle_words(dict);

    char* query_word = malloc(100);
    if (query_word == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    printf("Enter a word to search: ");
    fgets(query_word, 100, stdin);
    int result = search_word(dict, query_word);
    if (result!= -1) {
        printf("%s found at index %d\n", query_word, result);
    } else {
        printf("%s not found\n", query_word);
    }
    free(query_word);
    free(dict->words);
    free(dict);
    return 0;
}