//FormAI DATASET v1.0 Category: Text Summarizer ; Style: statistical
// C Text Summarizer - Statistical Style

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

#define MAX_WORD_LEN 50
#define MAX_SENTENCES 100

char* readFile(char *filename);
int countWords(char *content);
int countSentences(char *content);
int countCharacters(char *content, char ch);
bool isEndOfSentence(char ch);
void tokenize(char *content, char **tokens, int *numTokens);
int getNextSentence(char *content, char *sentenceBuffer, int startIndex);
int countOccurrences(char *content, char *str, bool caseSensitive);
bool isCommonWord(char *word);
int getScore(int i, int j, int *scores, int **graph, int *path);
bool updatePath(int i, int j, int score, int *path, int *bestPath);
void summarizeText(char *content, int numSentences);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s file_name.txt\n", argv[0]);
        return 1;
    }
    char *content = readFile(argv[1]);
    if(content == NULL) {
        printf("Error reading file: %s\n", argv[1]);
        return 1;
    }
    int numWords = countWords(content);
    int numSentences = countSentences(content);
    summarizeText(content, numSentences);
    free(content);
    return 0;
}

char* readFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        return NULL;
    }
    fseek(fp, 0, SEEK_END); 
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET); 
    char *content = (char*) malloc(fileSize + 1);
    fread(content, fileSize, 1, fp);
    fclose(fp);
    content[fileSize] = '\0';
    return content;
}

int countWords(char *content) {
    int len = strlen(content);
    int numWords = 0;
    for(int i = 0; i < len - 1; i++) {
        if(isspace(content[i]) && !isspace(content[i + 1])) {
            numWords++;
        }
    }
    return numWords + 1;
}

int countSentences(char *content) {
    int len = strlen(content);
    int numSentences = 0;
    for(int i = 0; i < len; i++) {
        if(isEndOfSentence(content[i]) && !isEndOfSentence(content[i + 1])) {
            numSentences++;
        }
    }
    return numSentences + 1;
}

int countCharacters(char *content, char ch) {
    int len = strlen(content);
    int count = 0;
    for(int i = 0; i < len; i++) {
        if(content[i] == ch) {
            count++;
        }
    }
    return count;
}

bool isEndOfSentence(char ch) {
    if(ch == '.' || ch == '?' || ch == '!') {
        return true;
    }
    return false;
}

void tokenize(char *content, char **tokens, int *numTokens) {
    int i = 0, j = 0;
    int len = strlen(content);
    while(i < len) {
        while(isspace(content[i])) i++;
        int start = i;
        while(!isspace(content[i]) && i < len) i++;
        int end = i;
        if(end - start > 0) {
            tokens[j] = (char*) malloc((end - start + 1) * sizeof(char));
            memcpy(tokens[j], content + start, end - start);
            tokens[j][end - start] = '\0';
            j++;
        }
    }
    *numTokens = j;
}

int getNextSentence(char *content, char *sentenceBuffer, int startIndex) {
    int len = strlen(content);
    int j = 0;
    for(int i = startIndex; i < len; i++) {
        sentenceBuffer[j] = content[i];
        j++;
        if(isEndOfSentence(content[i]) && !isEndOfSentence(content[i + 1])) {
            sentenceBuffer[j] = '\0';
            return i + 1;
        }
    }
    sentenceBuffer[j] = '\0';
    return -1;
}

int countOccurrences(char *content, char *str, bool caseSensitive) {
    int len = strlen(content);
    int strLen = strlen(str);
    int count = 0, j;
    for(int i = 0; i < len - strLen; i++) {
        for(j = 0; j < strLen; j++) {
            if(caseSensitive && content[i + j] != str[j]) {
                break;
            }
            else if(!caseSensitive && tolower(content[i + j]) != tolower(str[j])) {
                break;
            }            
        }
        if(j == strLen) {
            count++;
        }
    }
    return count;
}

bool isCommonWord(char *word) {
    // Add your common words list here
    char *commonWords[] = {"a", "an", "the", "and", "or", "but", "is", "are", "to", "for"};
    int numWords = 10;
    for(int i = 0; i < numWords; i++) {
        if(strcmp(word, commonWords[i]) == 0) {
            return true;
        }
    }
    return false;
}

int getScore(int i, int j, int *scores, int **graph, int *path) {
    if(i == j) {
        return 0;
    }
    if(graph[i][j] != -1) {
        return graph[i][j];
    }
    int maxScore = 0;
    for(int k = i + 1; k < j; k++) {
        int score = getScore(i, k, scores, graph, path) + getScore(k, j, scores, graph, path);
        if(updatePath(i, j, score, path, scores)) {
            maxScore = score;
        }
    }
    graph[i][j] = maxScore;
    return maxScore;
}

bool updatePath(int i, int j, int score, int *path, int *bestPath) {
    if(score > bestPath[j]) {
        bestPath[j] = score;
        path[j] = i;
        return true;
    }
    return false;
}

void summarizeText(char *content, int numSentences) {
    char *sentenceBuffer = (char*) malloc(MAX_SENTENCES * 100 * sizeof(char));
    int startIndex = 0, numTokens;
    char *tokens[MAX_WORD_LEN];
    int **graph = (int**) calloc(numSentences, sizeof(int*));
    int *scores = (int*) calloc(numSentences, sizeof(int));
    int *path = (int*) calloc(numSentences, sizeof(int));
    int *bestPath = (int*) calloc(numSentences, sizeof(int));
    for(int i = 0; i < numSentences; i++) {
        graph[i] = (int*) calloc(numSentences, sizeof(int));
        for(int j = 0; j < numSentences; j++) {
            graph[i][j] = -1;
        }
    }
    startIndex = getNextSentence(content, sentenceBuffer, startIndex);
    while(startIndex != -1) {
        tokenize(sentenceBuffer, tokens, &numTokens);
        for(int i = 0; i < numTokens; i++) {
            if(!isCommonWord(tokens[i])) {
                for(int j = i + 1; j < numTokens; j++) {
                    if(!isCommonWord(tokens[j])) {
                        int count = countOccurrences(content, tokens[i], false)
                                  + countOccurrences(content, tokens[i], true)
                                  + countOccurrences(content, tokens[j], false)
                                  + countOccurrences(content, tokens[j], true);
                        int score = count / (countWords(sentenceBuffer) * 1.0);
                        int sentIndexI = (startIndex / MAX_SENTENCES) - 1;
                        int sentIndexJ = (startIndex + getNextSentence(content, sentenceBuffer, startIndex)) / MAX_SENTENCES - 1;
                        scores[sentIndexI] += score;
                        scores[sentIndexJ] += score;
                        graph[sentIndexI][sentIndexJ] = score;
                        graph[sentIndexJ][sentIndexI] = score;
                    }
                }
            }
        }
        startIndex = getNextSentence(content, sentenceBuffer, startIndex);
    }
    getScore(0, numSentences - 1, scores, graph, path);
    int index = numSentences - 1;
    while(index != -1) {
        int start = index * MAX_SENTENCES;
        int end = start + getNextSentence(content, sentenceBuffer, start);
        printf("%.*s", end - start, content + start);
        index = path[index];
    }
    free(sentenceBuffer);
    for(int i = 0; i < numSentences; i++) {
        free(graph[i]);
    }
    free(graph);
    free(scores);
    free(path);
    free(bestPath);
}