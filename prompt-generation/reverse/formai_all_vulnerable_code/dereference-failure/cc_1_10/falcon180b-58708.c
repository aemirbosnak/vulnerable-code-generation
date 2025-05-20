//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct {
    char *english;
    char *cat;
} Word;

int main() {
    FILE *fp;
    char line[256];
    Word words[MAX_WORDS];
    int num_words = 0;
    
    // Load dictionary
    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }
    
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_words >= MAX_WORDS) {
            printf("Error: Dictionary is too large.\n");
            fclose(fp);
            return 2;
        }
        
        char *token = strtok(line, " ");
        if (token == NULL)
            continue;
        
        Word w;
        w.english = strdup(token);
        token = strtok(NULL, " ");
        if (token == NULL) {
            printf("Error: Invalid dictionary entry.\n");
            fclose(fp);
            return 3;
        }
        w.cat = strdup(token);
        
        words[num_words++] = w;
    }
    
    fclose(fp);
    
    // Translate input
    char input[256];
    printf("Enter a sentence to translate: ");
    fgets(input, sizeof(input), stdin);
    
    char *token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].english) == 0) {
                printf("%s ", words[i].cat);
                break;
            }
        }
        
        if (i == num_words)
            printf("%s ", token);
        
        token = strtok(NULL, " ");
    }
    
    printf("\n");
    
    return 0;
}