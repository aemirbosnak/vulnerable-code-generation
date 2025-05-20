//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LEN 50

struct Word {
    char word[WORD_LEN];
    int frequency;
};

int compare(const void *a, const void *b) {
    struct Word *wordA = (struct Word *) a;
    struct Word *wordB = (struct Word *) b;
    return strcmp(wordA->word, wordB->word);
}

void search(char *filename, char *keyword) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    char buffer[1000];
    int keywordLen = strlen(keyword);
    char *word = malloc(keywordLen + 1);
    strcpy(word, keyword);
    tolower(word);

    int numWords = 0;
    struct Word words[MAX_WORDS];
    while (fgets(buffer, 1000, file)!= NULL) {
        char *token = strtok(buffer, " \t\n\r\f\v,.?!;:");
        while (token!= NULL) {
            struct Word *wordPtr = bsearch(word, words, numWords, sizeof(struct Word), compare);
            if (wordPtr == NULL) {
                wordPtr = &words[numWords++];
                strcpy(wordPtr->word, token);
                wordPtr->frequency = 1;
            } else {
                wordPtr->frequency++;
            }
            token = strtok(NULL, " \t\n\r\f\v,.?!;:");
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(struct Word), compare);

    printf("Search results for keyword '%s':\n", keyword);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    char keyword[50];
    printf("Enter keyword: ");
    scanf("%s", keyword);

    search(filename, keyword);

    return 0;
}