//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_LETTERS 26
#define MAX_WORD_LENGTH 50
#define NUM_ALIEN_WORDS 10

typedef struct Translation {
    char alienWord[MAX_WORD_LENGTH];
    char englishWord[MAX_WORD_LENGTH];
} Translation;

typedef struct TrieNode {
    struct TrieNode *children[NUM_LETTERS];
    bool isEndOfWord;
    char englishWord[MAX_WORD_LENGTH];
} TrieNode;

TrieNode *createNode(void) {
    TrieNode *newNode = (TrieNode *)malloc(sizeof(TrieNode));
    if (newNode) {
        int i;
        newNode->isEndOfWord = false;
        for (i = 0; i < NUM_LETTERS; i++) {
            newNode->children[i] = NULL;
        }
    }
    return newNode;
}

void insertWord(TrieNode *root, const char *word, const char *englishTranslation) {
    int i;
    int length = strlen(word);
    TrieNode *current = root;

    for (i = 0; i < length; i++) {
        int index = word[i] - 'a';
        if (!current->children[index]) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    
    strcpy(current->englishWord, englishTranslation);
    current->isEndOfWord = true;
}

Translation *generateAlienWords(TrieNode *root, int numWords) {
    int i, j;
    char letters[NUM_LETTERS] = "abcdefghijklmnopqrstuvwxyz";
    Translation *alienWords = (Translation *)malloc(sizeof(Translation) * numWords);

    srand(time(NULL));

    for (i = 0; i < numWords; i++) {
        int length = rand() % (MAX_WORD_LENGTH - 1) + 1;
        char alienWord[MAX_WORD_LENGTH];

        for (j = 0; j < length; j++) {
            alienWord[j] = letters[rand() % NUM_LETTERS];
        }
        alienWord[length] = '\0';

        TrieNode *current = root;
        while (current) {
            int index = alienWord[0] - 'a';
            if (current->children[index] == NULL) {
                break;
            }
            current = current->children[index];

            if (current->isEndOfWord) {
                strcpy(alienWords[i].alienWord, alienWord);
                strcpy(alienWords[i].englishWord, current->englishWord);
                break;
            }
        }
        if (!alienWords[i].alienWord) {
            strcpy(alienWords[i].alienWord, alienWord);
            strcpy(alienWords[i].englishWord, "Unknown");
        }
    }
    return alienWords;
}

void *translateWord(void *arg) {
    Translation *word = (Translation *)arg;
    printf("Translating alien word %s...\n", word->alienWord);
    sleep(rand() % 3 + 1);
    printf("%s: %s\n", word->alienWord, word->englishWord);

    return NULL;
}

int main(void) {
    TrieNode *root = createNode();
    int i;

    insertWord(root, "ab", "hello");
    insertWord(root, "bc", "world");
    insertWord(root, "xyz", "universe");
    insertWord(root, "pqrs", "galaxy");
    insertWord(root, "wxyz", "planet");
    insertWord(root, "hgf", "star");
    insertWord(root, "klmn", "orbit");
    insertWord(root, "efg", "astronaut");
    insertWord(root, "jklmno", "rocket");
    insertWord(root, "stuv", "space");

    Translation *alienWords = generateAlienWords(root, NUM_ALIEN_WORDS);
    pthread_t threads[NUM_ALIEN_WORDS];

    for (i = 0; i < NUM_ALIEN_WORDS; i++) {
        if (pthread_create(&threads[i], NULL, translateWord, &alienWords[i])) {
            fprintf(stderr, "Error creating thread\n");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < NUM_ALIEN_WORDS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(alienWords);
    return 0;
}