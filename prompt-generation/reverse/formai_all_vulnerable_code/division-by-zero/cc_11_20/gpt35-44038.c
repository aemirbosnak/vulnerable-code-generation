//FormAI DATASET v1.0 Category: Text Summarizer ; Style: ultraprecise
#include<stdio.h> 
#include<string.h> 
#define MAX_INPUT_SIZE 1000 
#define MAX_OUTPUT_SIZE 1000 

void text_summarizer(char* input, int inputSize, char* output, int outputSize) 
{ 
    int i,j; 

    // Removing extra spaces and new lines from the input text 
    for(i=0; i<inputSize-1; i++) 
    { 
        if(input[i]==' ' && input[i+1]==' ') 
        { 
            for(j=i; j<inputSize; j++) 
            { 
                input[j] = input[j+1]; 
            } 
            inputSize--; 
            i--; 
        } 
        else if(input[i]==' ' && input[i+1]=='\n') 
        { 
            for(j=i; j<inputSize; j++) 
            { 
                input[j] = input[j+1]; 
            } 
            inputSize--; 
            i--; 
        } 
    } 

    // Counting the number of sentences in the input text 
    int sentenceCount=0; 
    for(i=0; input[i]!='\0'; i++) 
    { 
        if(input[i]=='.' || input[i]=='?' || input[i]=='!') 
        { 
            sentenceCount++; 
        } 
    } 

    // Computing the number of words in each sentence 
    int wordCount[sentenceCount]; 
    int k=0; 
    int count=0; 
    for(i=0; input[i]!='\0'; i++) 
    { 
        count++; 
        if(input[i]==' ' || input[i]=='\n' || input[i]=='.' || 
           input[i]=='?' || input[i]=='!') 
        { 
            wordCount[k] = count-1; 
            count=0; 
            k++; 
        } 
    } 

    // Analyzing the input text to generate the summary 
    k=0; 
    int wordsRemaining, numSentences, summaryIndex=0; 
    char summary[MAX_OUTPUT_SIZE]; 
    for(i=0; input[i]!='\0' && k<sentenceCount; i++) 
    { 
        wordsRemaining = summaryIndex; 
        numSentences = k+1; 
        while(numSentences<=sentenceCount) 
        { 
            int averageWordCount=0; 
            for(j=k; j<numSentences; j++) 
            { 
                averageWordCount += wordCount[j]; 
            } 
            averageWordCount = (averageWordCount + numSentences-k-1)/(numSentences-k); 
            if(wordsRemaining+averageWordCount<=outputSize-1) 
            { 
                for(j=k; j<numSentences; j++) 
                { 
                    while(input[i]!=' ' && input[i]!='\n' && input[i]!='.' && 
                          input[i]!='?' && input[i]!='!') 
                    { 
                        output[summaryIndex] = input[i]; 
                        summaryIndex++; 
                        i++; 
                    } 
                    output[summaryIndex] = input[i]; 
                    summaryIndex++; 
                } 
                output[summaryIndex++] = ' '; 
                k = numSentences; 
            } 
            else 
            { 
                numSentences++; 
            } 
        } 
    } 

    // Adding the last sentence in the summary 
    while(input[i]!='\0') 
    { 
        output[summaryIndex] = input[i]; 
        summaryIndex++; 
        i++; 
    } 

    output[summaryIndex] = '\0'; 
} 

int main() 
{ 
    char input[MAX_INPUT_SIZE]; 
    char output[MAX_OUTPUT_SIZE]; 

    printf("Enter the text that needs to be summarized: \n"); 
    fgets(input, MAX_INPUT_SIZE, stdin); 

    int inputSize = strlen(input); 
    int outputSize = MAX_OUTPUT_SIZE; 

    text_summarizer(input, inputSize, output, outputSize); 

    printf("The summarized text is: \n"); 
    printf("%s", output); 

    return 0; 
}