//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main(int argc, char** argv){
    if(argc != 2){
        printf("Usage: ./wordcount <filename>\n");
        return 1;
    }

    char* filename = argv[1];
    FILE* inputFile = fopen(filename, "r");

    if(inputFile == NULL){
        printf("Error opening file %s\n", filename);
        return 1;
    }
    
    printf("Starting the C Word Frequency counter...\n\n");

    char word[MAX_WORD_LENGTH + 1] = "";
    int wordCount = 0, uniqueWordCount = 0;
    int* wordFrequency = calloc(1, sizeof(int));
    int c;
    while((c = fgetc(inputFile)) != EOF){
        if(isalpha(c)){
            word[strlen(word)] = tolower(c);
        }
        else if(strlen(word) > 0){
            wordCount++;
            int found = 0;
            for(int i = 0; i < uniqueWordCount; i++){
                if(strcmp(word, &filename[i*MAX_WORD_LENGTH]) == 0){
                    wordFrequency[i]++;
                    found = 1;
                    break;
                }
            }
            if(!found){
                uniqueWordCount++;
                wordFrequency = realloc(wordFrequency, uniqueWordCount * sizeof(int));
                memset(&filename[(uniqueWordCount - 1)*MAX_WORD_LENGTH], '\0', MAX_WORD_LENGTH);
                strcpy(&filename[(uniqueWordCount - 1)*MAX_WORD_LENGTH], word);
                wordFrequency[uniqueWordCount - 1] = 1;
            }
            memset(word, '\0', MAX_WORD_LENGTH + 1);
        }
    }

    fclose(inputFile);

    printf("Total number of words in %s: %d\n", filename, wordCount);

    printf("Unique words:\n");
    for(int i = 0; i < uniqueWordCount; i++){
        printf("%s: %d\n", &filename[i * MAX_WORD_LENGTH], wordFrequency[i]);
    }

    free(wordFrequency);

    printf("\nThank you for using the C Word Frequency counter!\n");

    return 0;
}