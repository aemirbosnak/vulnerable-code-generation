//Falcon-180B DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} WordCount;

int main() {
    char line[MAX_LINE_LENGTH];
    FILE *file;
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    WordCount words[MAX_WORD_LENGTH];
    int numWords = 0;
    int i;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            if (strlen(word) > MAX_WORD_LENGTH) {
                printf("Error: Word exceeds maximum length.\n");
                return 1;
            }
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, words[i].word) == 0) {
                    words[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                words[numWords].word = strdup(word);
                words[numWords].count = 1;
                numWords++;
            }
            word = strtok(NULL, " ");
        }
    }
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
    return 0;
}