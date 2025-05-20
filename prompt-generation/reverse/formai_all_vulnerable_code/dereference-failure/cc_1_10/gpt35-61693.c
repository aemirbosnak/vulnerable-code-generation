//FormAI DATASET v1.0 Category: Text Summarizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_SENTENCE_LENGTH 2000
#define MAX_OUTPUT_SENTENCES 3

typedef struct {
    char* sentence;
    int score;
} SentenceNode;

SentenceNode* sentenceNodes[MAX_OUTPUT_SENTENCES];

char* readInputFile(char* fileName);
void summarizeText(char* text);
char* getNextWord(char* sentence, int* position);
int getWordCount(char* sentence);
int getScore(char* sentence);
void addSentenceNode(char* sentence, int score);
void sortSentenceNodes();
void printSummary();

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please provide input file name as a command line argument\n");
        return 0;
    }
    char* text = readInputFile(argv[1]);
    summarizeText(text);
    free(text);
    return 0;
}

char* readInputFile(char* fileName) {
    FILE* inputFile = fopen(fileName, "r");
    if(inputFile == NULL) {
        printf("Could not open input file\n");
        exit(0);
    }
    fseek(inputFile, 0, SEEK_END);
    int fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);
    char* text = (char*)malloc(fileSize * sizeof(char));
    fread(text, sizeof(char), fileSize, inputFile);
    fclose(inputFile);
    return text;
}

void summarizeText(char* text) {
    char sentence[MAX_SENTENCE_LENGTH];
    strcpy(sentence, "");
    int sentenceCount = 0;
    for(int i = 0; text[i] != '\0'; i++) {
        sentence[strlen(sentence)] = text[i];
        if(text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentenceCount++;
            sentence[strlen(sentence)] = '\0'; // add null terminator to sentence
            int score = getScore(sentence);
            if(sentenceCount <= MAX_OUTPUT_SENTENCES) {
                addSentenceNode(sentence, score);
            } else {
                sortSentenceNodes();
                if(score > sentenceNodes[0]->score) {
                    free(sentenceNodes[0]->sentence);
                    sentenceNodes[0]->sentence = (char*)malloc(strlen(sentence) * sizeof(char));
                    strcpy(sentenceNodes[0]->sentence, sentence);
                    sentenceNodes[0]->score = score;
                }
            }
            strcpy(sentence, ""); // reset the sentence
        }
    }
    printSummary();
}

char* getNextWord(char* sentence, int* position) {
    char* word = (char*)malloc(MAX_WORD_LENGTH * sizeof(char));
    int i = *position, j = 0;
    while(sentence[i] != '\0' && sentence[i] != ' ' && j < MAX_WORD_LENGTH) {
        if(isalnum(sentence[i])) {
            word[j++] = tolower(sentence[i]);
        }
        i++;
    }
    word[j] = '\0';
    *position = i;
    return word;
}

int getWordCount(char* sentence) {
    int count = 0;
    int position = 0;
    while(position < strlen(sentence)) {
        char* word = getNextWord(sentence, &position);
        if(strlen(word) > 0 && strcmp(word, "the") != 0 && strcmp(word, "a") != 0 && strcmp(word, "an") != 0) {
            count++;
        }
        free(word);
    }
    return count;
}

int getScore(char* sentence) {
    int wordCount = getWordCount(sentence);
    if(wordCount == 0) {
        return 0;
    }
    char* firstWord = getNextWord(sentence, &(int){0});
    int score = strlen(firstWord) * wordCount;
    free(firstWord);
    return score;
}

void addSentenceNode(char* sentence, int score) {
    SentenceNode* node = (SentenceNode*)malloc(sizeof(SentenceNode));
    node->sentence = (char*)malloc(strlen(sentence) * sizeof(char));
    strcpy(node->sentence, sentence);
    node->score = score;
    sentenceNodes[score > 0 ? MAX_OUTPUT_SENTENCES - score : 0] = node;
}

void sortSentenceNodes() {
    for(int i = 0; i < MAX_OUTPUT_SENTENCES - 1; i++) {
        for(int j = i + 1; j < MAX_OUTPUT_SENTENCES; j++) {
            if(sentenceNodes[i]->score > sentenceNodes[j]->score) {
                SentenceNode* temp = sentenceNodes[i];
                sentenceNodes[i] = sentenceNodes[j];
                sentenceNodes[j] = temp;
            }
        }
    }
}

void printSummary() {
    for(int i = MAX_OUTPUT_SENTENCES - 1; i >= 0; i--) {
        if(sentenceNodes[i] != NULL) {
            printf("%s\n", sentenceNodes[i]->sentence);
            free(sentenceNodes[i]->sentence);
            free(sentenceNodes[i]);
        }
    }
}