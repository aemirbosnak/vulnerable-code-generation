//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LEN 50

typedef struct {
    char word[WORD_LEN];
    int count;
} word_t;

void toLower(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        if (isupper((unsigned char) str[i]))
            str[i] += 32;
    }
}

int hashFunc(char *str) {
    int hash = 5381;
    int i;
    for (i = 0; str[i]; i++)
        hash = ((hash << 5) + hash) + (int) str[i];
    return hash % MAX_WORDS;
}

word_t *createWord(char *str) {
    word_t *newWord = (word_t *) calloc(1, sizeof(word_t));
    strcpy(newWord->word, str);
    newWord->count = 1;
    return newWord;
}

int findWordIndex(word_t *words, char *str) {
    int hashVal = hashFunc(str);
    int i;
    for (i = 0; i < words[hashVal].count; i++) {
        if (strcmp(words[hashVal].word, str) == 0)
            return i;
    }
    return -1;
}

void incrementWordCount(word_t *words, char *str) {
    int index = findWordIndex(words, str);
    if (index != -1)
        words[index].count++;
}

void addWord(word_t *words, char *str) {
    if (findWordIndex(words, str) == -1) {
        int hashVal = hashFunc(str);
        words[hashVal].count++;
        words[hashVal] = *createWord(str);
    }
}

int main() {
    char str[WORD_LEN];
    FILE *file = fopen("input.txt", "r");
    word_t words[MAX_WORDS];

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(str, WORD_LEN, file)) {
        toLower(str);
        str[strcspn(str, "\n")] = '\0';
        addWord(words, str);
    }

    fclose(file);

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0)
            printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}