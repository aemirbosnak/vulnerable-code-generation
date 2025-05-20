//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define SPAM_THRESHOLD 5

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(char* filename, WordCount* wordCounts, int count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char* word = strtok(line, " \t\r\n");
        while (word!= NULL) {
            int i;
            for (i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    word[i] = '\0';
                }
            }
            int index = hash(word);
            WordCount* wc = &wordCounts[index];
            if (wc->count == 0) {
                strcpy(wc->word, word);
            }
            wc->count++;
            word = strtok(NULL, " \t\r\n");
        }
    }

    fclose(file);
}

int hash(char* word) {
    int hash = 0;
    int i;
    for (i = 0; i < strlen(word); i++) {
        hash += tolower(word[i]);
    }
    return hash % 100;
}

void printWords(WordCount* wordCounts, int count) {
    int i;
    for (i = 0; i < count; i++) {
        if (wordCounts[i].count > SPAM_THRESHOLD) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[100];
    strcpy(filename, argv[1]);

    WordCount wordCounts[100];
    int count = 0;

    readWords(filename, wordCounts, count);
    printWords(wordCounts, count);

    return 0;
}