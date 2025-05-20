//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char *english;
    char *alien;
} WordPair;

int main() {
    FILE *dictionaryFile;
    char line[MAX_WORD_LENGTH];
    WordPair words[MAX_WORDS];
    int numWords = 0;
    
    dictionaryFile = fopen("dictionary.txt", "r");
    if (dictionaryFile == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }
    
    while (fgets(line, MAX_WORD_LENGTH, dictionaryFile)!= NULL) {
        char *englishWord = strtok(line, ",");
        char *alienWord = strtok(NULL, ",");
        
        if (englishWord == NULL || alienWord == NULL) {
            printf("Error: invalid line in dictionary file.\n");
            return 1;
        }
        
        words[numWords].english = strdup(englishWord);
        words[numWords].alien = strdup(alienWord);
        numWords++;
    }
    
    fclose(dictionaryFile);
    
    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);
    
    char *token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].alien);
                break;
            }
        }
        
        if (i == numWords) {
            printf("Unknown word: %s\n", token);
        }
        
        token = strtok(NULL, " ");
    }
    
    printf("\n");
    
    return 0;
}