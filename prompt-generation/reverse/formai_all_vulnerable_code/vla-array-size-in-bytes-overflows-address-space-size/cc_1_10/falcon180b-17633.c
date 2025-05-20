//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100000

struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
};

void readFile(FILE *file, struct WordCount *wordCounts, int numWords) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (i >= numWords) {
                printf("Error: too many words in file.\n");
                exit(1);
            }
            wordCounts[i].word[0] = tolower(ch);
            int j = 1;
            while ((ch = fgetc(file))!= EOF && isalnum(ch)) {
                if (j >= MAX_WORD_LENGTH) {
                    printf("Error: word too long.\n");
                    exit(1);
                }
                wordCounts[i].word[j] = tolower(ch);
                j++;
            }
            wordCounts[i].word[j] = '\0';
            i++;
        }
    }
}

void countWords(struct WordCount *wordCounts, int numWords) {
    for (int i = 0; i < numWords; i++) {
        wordCounts[i].count = 0;
    }
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    readFile(file, wordCounts, numWords);
    fclose(file);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    int numWords;
    printf("Enter number of words to count: ");
    scanf("%d", &numWords);
    struct WordCount wordCounts[numWords];
    countWords(wordCounts, numWords);
    return 0;
}