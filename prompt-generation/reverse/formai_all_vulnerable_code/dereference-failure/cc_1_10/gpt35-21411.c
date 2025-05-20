//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define HASH_TABLE_SIZE 100

struct WordFreq {
    char word[MAX_WORD_LEN];
    int freq;
    struct WordFreq* next;
};

struct WordFreq* hashTable[HASH_TABLE_SIZE];

int hash(char* str) {
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        sum += str[i];
    }
    return sum % HASH_TABLE_SIZE;
}

void addWord(char* word) {
    int index = hash(word);
    struct WordFreq* curr = hashTable[index];
    while (curr != NULL) {
        if (strcmp(curr->word, word) == 0) {
            curr->freq++;
            return;
        }
        curr = curr->next;
    }
    struct WordFreq* newWord = malloc(sizeof(struct WordFreq));
    strcpy(newWord->word, word);
    newWord->freq = 1;
    newWord->next = hashTable[index];
    hashTable[index] = newWord;
}

void printFreq() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        struct WordFreq* curr = hashTable[i];
        while (curr != NULL) {
            printf("%s: %d\n", curr->word, curr->freq);
            curr = curr->next;
        }
    }
}

void processFile(char* fileName) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", fileName);
        exit(1);
    }
    char word[MAX_WORD_LEN] = "";
    int wordLength = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            if (wordLength < MAX_WORD_LEN) {
                word[wordLength++] = tolower(c);
            }
        } else {
            if (wordLength > 0) {
                word[wordLength] = '\0';
                addWord(word);
                memset(word, 0, MAX_WORD_LEN);
                wordLength = 0;
            }
        }
    }
    if (wordLength > 0) {
        word[wordLength] = '\0';
        addWord(word);
    }
    fclose(fp);
}

int main() {
    memset(hashTable, 0, sizeof(hashTable));
    char fileName[] = "example.txt";
    processFile(fileName);
    printFreq();
    return 0;
}