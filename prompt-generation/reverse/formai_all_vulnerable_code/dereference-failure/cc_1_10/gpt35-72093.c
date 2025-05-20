//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char* word;
    int freq;
} WordFreq;

int cmpfunc(const void* a, const void* b) {
    return ((WordFreq*)b)->freq - ((WordFreq*)a)->freq;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: ./wordfreq <filename>\n");
        return 1;
    }
    
    FILE* fp = fopen(argv[1], "r");
    
    if (!fp) {
        printf("Error opening file!\n");
        return 1;
    }
    
    char buffer[100];
    WordFreq* words = malloc(100 * sizeof(WordFreq));
    int n = 0;
    
    while (fscanf(fp, "%s", buffer) != EOF) {
        char* word = strdup(buffer);
        
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        
        int found = 0;
        
        for (int i = 0; i < n; i++) {
            if (!strcmp(words[i].word, word)) {
                words[i].freq += 1;
                found = 1;
                break;
            }
        }
        
        if (!found) {
            words[n].word = word;
            words[n].freq = 1;
            n++;
            
            if (n % 100 == 0) {
                words = realloc(words, (n + 100) * sizeof(WordFreq));
            }
        }
    }
    
    fclose(fp);
    
    qsort(words, n, sizeof(WordFreq), cmpfunc);
    
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", words[i].word, words[i].freq);
        free(words[i].word);
    }
    
    free(words);
    return 0;
}