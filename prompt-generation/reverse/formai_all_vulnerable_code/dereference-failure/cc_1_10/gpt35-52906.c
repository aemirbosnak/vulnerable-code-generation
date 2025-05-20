//FormAI DATASET v1.0 Category: Text Summarizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_COUNT 1000
#define SUMMARIZED_STRING_COUNT 5

char* Lowercase(char* str) {
    char* res = (char*)malloc(sizeof(char) * strlen(str));
    for(int i=0; i<strlen(str); i++)
        res[i] = tolower(str[i]);
    res[strlen(str)] = '\0';
    return res;    
}

void appendToString(char *source, char* destination, int n) {
    for (int i = 0; i < n; i++) {
        destination[i] = source[i];
    }
    destination[n] = '\0';
}

// Returns the string with maximum number of words.
char* countWords(char** sentences, int sentenceCount) {
    int maxWordCount = 0, wordCount = 0;
    char* maxWordCountSentence = NULL;
    for (int i = 0; i < sentenceCount; ++i) {
        wordCount = 0;
        // Count number of words in current sentence.
        for (int j = 0; j < strlen(sentences[i]); ++j)
            if (sentences[i][j] == ' ')
                wordCount++;
        // Check if current sentence has maximum words among all sentences.
        if (wordCount > maxWordCount) {
            maxWordCount = wordCount;
            maxWordCountSentence = sentences[i];
        }
    }
    return maxWordCountSentence;
}

// Removes punctuation marks from a sentence and converts it to lowercase.
char* removePunctuation(char* sentence) {
    char* noPunctuationSentence = (char*)malloc(sizeof(char) * strlen(sentence));
    int j = 0;
    for(int i=0; i<strlen(sentence); i++) {
        if(isalpha(sentence[i])) {
            noPunctuationSentence[j] = tolower(sentence[i]);
            j++;
        }
    }
    noPunctuationSentence[j] = '\0';
    return noPunctuationSentence;    
}

// Returns the sum of count of each word in a string.
int getScore(char* sentence, char** keywords, int keywordCount) {
    char* lowercaseSentence = Lowercase(sentence);
    int score = 0;
    char* word = strtok(lowercaseSentence, " ");
    while (word != NULL) {
        for(int i=0; i<keywordCount; i++) {
            if(strcmp(keywords[i],word) == 0) {
                score++;
                break;
            }
        }
        word = strtok(NULL, " ");
    }
    return score;
}

char** getKeywords(char** sentences, int sentenceCount, int* keywordCount) {
    char* maxWordCountSentence = countWords(sentences, sentenceCount);
    char* noPunctuationSentence = removePunctuation(maxWordCountSentence);
    
    char* word = strtok(noPunctuationSentence, " ");
    char** keywords = (char**)malloc(sizeof(char*) * MAX_STRING_COUNT);
    int count = 0;
    while(word != NULL) {
        keywords[count] = word;
        count++;
        word = strtok(NULL, " ");
    }
    *keywordCount = count;
    return keywords;
}

int compare(const void *pa, const void *pb) {
    int a = *(const int*) pa;
    int b = *(const int*) pb;
    return a<b;
}

char** summarize(char** sentences, int sentenceCount) {
    int keywordCount = 0;
    char** keywords = getKeywords(sentences, sentenceCount, &keywordCount);
    int scores[sentenceCount];
    
    for(int i=0; i<sentenceCount; i++) {
        char* lowercaseSentence = Lowercase(sentences[i]);
        scores[i] = getScore(lowercaseSentence, keywords, keywordCount);
    }
    
    int maxScoresIndex[sentenceCount];
    for(int i=0; i<sentenceCount; i++) {
        maxScoresIndex[i] = i;
    }
    qsort(maxScoresIndex, sentenceCount, sizeof(int), compare);
    
    char** summarizedSentences = (char**)malloc(sizeof(char*) * SUMMARIZED_STRING_COUNT);
    for(int i=0; i<SUMMARIZED_STRING_COUNT; i++)
        summarizedSentences[i] = (char*)malloc(sizeof(char) * strlen(sentences[maxScoresIndex[sentenceCount-SUMMARIZED_STRING_COUNT+i]]));
    
    for(int i=sentenceCount-SUMMARIZED_STRING_COUNT; i<sentenceCount; i++) {
        appendToString(sentences[maxScoresIndex[i]], summarizedSentences[i-(sentenceCount-SUMMARIZED_STRING_COUNT)], strlen(sentences[maxScoresIndex[i]]));
    }
    return summarizedSentences;
}

int main() {
    char* sentences[MAX_STRING_COUNT] = {""};
    int sentenceCount = 0;
    char input[MAX_STRING_COUNT];
    
    printf("Enter your text here: \n");
    while(1) {
        gets(input);
        if(strcmp(input,"") == 0)
            break;
        for(int i=0; i<strlen(input); i++) {
            sentences[sentenceCount][i] = input[i];
        }
        sentenceCount++;
    }

    char** summarizedSentences = summarize(sentences, sentenceCount);
    printf("Summarized Text\n");
    for(int i=0; i<SUMMARIZED_STRING_COUNT; i++)
        printf("%d: %s\n", i+1, summarizedSentences[i]);
}