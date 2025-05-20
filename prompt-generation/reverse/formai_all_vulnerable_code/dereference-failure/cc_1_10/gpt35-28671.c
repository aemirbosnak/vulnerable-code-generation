//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char word[50];
    int frequency;
} WordFrequency;

void extractWords(char* filename, WordFrequency** words, int* totalWords);
void countWordFrequencies(char* filename, WordFrequency** words, int* totalWords);
void printWordFrequencies(WordFrequency* words, int totalWords);
void quickSort(WordFrequency* arr, int left, int right);
int partition(WordFrequency* arr, int left, int right);

int main() {
    char filename[] = "example.txt";
    WordFrequency* words = NULL;
    int totalWords = 0;

    extractWords(filename, &words, &totalWords);
    countWordFrequencies(filename, &words, &totalWords);
    quickSort(words, 0, totalWords-1);
    printWordFrequencies(words, totalWords);

    free(words);

    return 0;
}

void extractWords(char* filename, WordFrequency** words, int* totalWords) {
    FILE* fp = fopen(filename, "r");
    char word[50];

    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while(fscanf(fp, "%s", word) != EOF) {
        if(isalpha(word[0])) {
            (*totalWords)++;
            *words = (WordFrequency*)realloc(*words, (*totalWords)*sizeof(WordFrequency));
            strncpy((*words)[*totalWords-1].word, word, 50);
            (*words)[*totalWords-1].frequency = 0;
        }
    }

    fclose(fp);
}

void countWordFrequencies(char* filename, WordFrequency** words, int* totalWords) {
    FILE* fp = fopen(filename, "r");
    char word[50];

    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while(fscanf(fp, "%s", word) != EOF) {
        if(isalpha(word[0])) {
            for(int i=0; i<*totalWords; i++) {
                if(strcmp((*words)[i].word, word) == 0) {
                    (*words)[i].frequency++;
                    break;
                }
            }
        }
    }

    fclose(fp);
}

void printWordFrequencies(WordFrequency* words, int totalWords) {
    printf("Word Frequency Count:\n");
    for(int i=0; i<totalWords; i++) {
        printf("%-20s%d\n", words[i].word, words[i].frequency);
    }
}

void quickSort(WordFrequency* arr, int left, int right) {
    if(left < right) {
        int p = partition(arr, left, right);
        quickSort(arr, left, p-1);
        quickSort(arr, p+1, right);
    }
}

int partition(WordFrequency* arr, int left, int right) {
    WordFrequency pivot = arr[right];
    int i = left-1;

    for(int j=left; j<right; j++) {
        if(arr[j].frequency >= pivot.frequency) {
            i++;
            
            WordFrequency temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    WordFrequency temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;

    return i+1;
}