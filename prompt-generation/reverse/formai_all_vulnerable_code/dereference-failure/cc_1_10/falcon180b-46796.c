//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define MAX_WORDS 100

typedef struct {
    char *word;
    int length;
} Word;

int compareWords(const void *a, const void *b) {
    Word *wordA = (Word *)a;
    Word *wordB = (Word *)b;

    return strcmp(wordA->word, wordB->word);
}

int isPalindrome(char *word) {
    int length = strlen(word);
    int i = 0;
    int j = length - 1;

    while (i < j) {
        if (tolower(word[i])!= tolower(word[j])) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

void findPalindromes(char *sentence, Word **palindromes, int *count) {
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        int length = strlen(token);
        if (length > 1 && isPalindrome(token)) {
            Word *newWord = malloc(sizeof(Word));
            newWord->word = strdup(token);
            newWord->length = length;

            qsort(palindromes, *count, sizeof(Word *), compareWords);
            Word **last = &palindromes[*count - 1];

            if (strcmp(newWord->word, (*last)->word)!= 0) {
                (*last) = newWord;
                (*count)++;
            } else {
                free(newWord->word);
                free(newWord);
            }
        }
        token = strtok(NULL, " ");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char sentence[MAX_LENGTH];
    strcpy(sentence, argv[1]);

    Word *palindromes[MAX_WORDS];
    int count = 0;

    findPalindromes(sentence, palindromes, &count);

    printf("Number of palindromes found: %d\n", count);

    for (int i = 0; i < count; i++) {
        printf("%s (%d characters)\n", palindromes[i]->word, palindromes[i]->length);
    }

    return 0;
}